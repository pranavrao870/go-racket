#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)


(provide (all-defined-out))

(define-ffi-definer define-master (ffi-lib "./libmaster"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Definitions of functions exported from gnugo 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Undo a move on the board.
;; @param : void
;; @return : void
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define-master undo_previous_move (_fun -> _void))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Clear the entire board.
;; @param : void
;; @return : void
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define-master clear_board (_fun -> _void))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Get the entity at a particular intersection
;; on the board.
;; @param : integers i, j which specify a
;; coordinate on the board.
;; @return : integer. 0 -> Empty,
;;                    1 -> White,
;;                    2 -> Black.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define-master board_pos (_fun _int _int -> _int))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Attempt a move at a particular intersection
;; @param : integers i, j and color
;; @return : integer. 0 -> invalid move,
;;                    1 -> valid move.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define-master try_move (_fun _int _int _int -> _int))


(define size 9)

(define (on-board? num)
  (and (>= num 0) (< num (* size size))))

(define (num->index n)
  (cons (quotient n size) (remainder n size)))

(define-syntax-rule (@ i j board)
  (cond ((list? board) (list-ref (list-ref board i) j))
        ((vector? board) (vector-ref (vector-ref board i) j))
        (else (error "Expected list/vector in macro @"))))

(define-syntax-rule (place : board i j -> val)
  (cond ((vector? board) (vector-set! (vector-ref board i) j val))
        (else (error "Expected vector in macro set"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Count territories of each
;; player using DFS on the graph
;; generated from the board.
;; @param : Board as a list of
;; lists.
;; @return : Territories occupied
;; by both parties.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (count-territories board)
  (define (board-pos x y)
    (list-ref (list-ref board x) y))
  (define (make-graph)
    (define (fill-adjacent num)
      (define left (if (= (modulo num size) 0) -1 (sub1 num)))
      (define right (if (= (modulo (add1 num) size) 0) -1 (add1 num)))
      (filter on-board? (list left
                              right
                              (- num size)
                              (+ num size))))
    (build-list (* size size) fill-adjacent))
  (define marked (make-vector (* size size) #f))
  (define graph (make-graph))
  (define wt 0)
  (define bt 0)
  (define white? #f)
  (define black? #f)
  (define cfree 0)
  (define (dfs s)
    (define x (car (num->index s)))
    (define y (cdr (num->index s)))
      (cond ((vector-ref marked s) (void))
            ((= (board-pos x y) 1) (set! white? #t))
            ((= (board-pos x y) 2) (set! black? #t))
            (else (begin (vector-set! marked s #t)
                         (set! cfree (add1 cfree))
                         (for-each dfs (list-ref graph s))))))
  (begin (for-each (lambda (x) (begin (set! white? #f)
                                      (set! black? #f)
                                      (set! cfree 0)
                                      (dfs x)
                                      (set! wt (if (and white? (not black?))
                                                   (+ wt cfree)
                                                   wt))
                                      (set! bt (if (and black? (not white?))
                                                   (+ bt cfree)
                                                   bt))))
                     (build-list (* size size) values))
         (cons wt bt)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compare two board states for
;; similarity. This is done using
;; the sequence alignment
;; algorithm.
;; @param : Two boards
;; @return : Index specifying the
;; closeness.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (similar board1 board2)
  (define b1 (flatten board1))
  (define b2 (flatten board2))
  (define len (length b1))
  (define m (length board1))
  (define n (length board2))
  (define match-cost '((0 1 1) (1 0 3) (1 3 0)))
  (define del 2)
  (define table (build-vector (add1 m)
                              (lambda (x)
                                (build-vector
                                 (add1 n)
                                 (lambda (y)
                                   (cond ((= 0 y) (* del x))
                                         ((= 0 x) (* del y))
                                         (else -1)))))))
  (define (memo-align i j)
    (cond ((or (< i 0) (< j 0)) 0)
          ((>= (@ i j table) 0) (@ i j table))
          (else (let ((bst (min (+ (@ (@ (sub1 i) (sub1 j) board1)
                                      (@ (sub1 i) (sub1 j) board2)
                                      match-cost)
                                   (memo-align (sub1 i) (sub1 j)))
                                (+ del (memo-align (sub1 i) j))
                                (+ del (memo-align i (sub1 j))))))
                  (begin (place : table i j -> bst) bst)))))
  (memo-align m n))

