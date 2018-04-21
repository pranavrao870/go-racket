#lang racket

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
  (define size (length board))
  (define (board-pos x y)
    (list-ref (list-ref board x) y))
  (define (on-board? num)
    (and (>= num 0) (< num (* size size))))
  (define (num->index n)
    (cons (quotient n size) (remainder n size)))
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
    
(count-territories '((0 0 0 0 0) (2 0 2 2 2) (1 2 2 2 1) (1 1 0 1 1) (0 0 0 0 0)))                  
    