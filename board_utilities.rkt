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

(define-master total_white_capture (_fun -> _int))

(define-master total_black_capture (_fun -> _int))

(define-master _x (_fun _int -> _int))
(define-master _y (_fun _int -> _int))

(define-master find_lib (_fun _int _int (o : (_list o _int 54)) ;; MAXLIBS = 54
                              -> (r : _int)
                              -> (values r o)))

(define (find-lib-wrapper i j)
  (define-values (total lst) (find_lib i j))
  (map (lambda (pos) (cons (_x pos) (_y pos))) (take lst total)))

(define size 9)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Calculate the scores for each, given the list
;; (wt bt wc bc). Higher weight is attached to
;; capture because that causes an immediate
;; increase in score.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (calculate-scores lst)
  (cons (+ (* 0.65 (third lst)) (* 0.35 (first lst)))
        (+ (* 0.65 (fourth lst)) (* 0.35 (second lst)))))
   
(define (on-board? num)
  (cond ((cons? num) (and (< (car num) size)
                          (>= (car num) 0)
                          (< (cdr num) size)
                          (>= (cdr num) 0)))
        ((number? num) (and (>= num 0) (< num (* size size)))) 
        (else (error "expected number/pair"))))

(define (num->index n)
  (cons (quotient n size) (remainder n size)))

(define-syntax-rule (@ i j board)
  (cond ((list? board) (list-ref (list-ref board i) j))
        ((vector? board) (vector-ref (vector-ref board i) j))
        (else (error "Expected list/vector in macro @"))))

(define-syntax-rule (place : board i j -> val)
  (cond ((vector? board) (vector-set! (vector-ref board i) j val))
        (else (error "Expected vector in macro set"))))

(define (board->2dlist)
  (build-list size (lambda (x) (build-list size (lambda (y) (board_pos x y))))))

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
         (list wt bt)))

