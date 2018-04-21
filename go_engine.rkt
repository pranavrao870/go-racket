#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)
(define-ffi-definer define-master (ffi-lib "/home/sumitc/CS152/Project/go-racket/gnugo-3.8/engine/libmaster"))
(require "board_utilities.rkt")

(define total-moves 0)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Once the subtree to be explored has been
;; decided, we explore that subtree through a
;; (sort of) random  playout, based on some
;; heuristics. Once we have explored to a
;; substantial depth, we check which player has
;; greater territory. We grant the player with
;; larger territory the win.
;; @param : init-board (starting state for sim)
;;          init-move (move made to reach this
;;                     state)
;;          init-player (who made this move)
;;          time (how long to run playout)
;; @return : territory of each player after
;;           playout.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(clear_board)

(define (run-simulation init-board init-player init-move max-depth time)
  (define depth 0)
  (define start-time (current-inexact-milliseconds))
  (define current-board init-board)
  (define current-move init-move)
  (define current-player init-player)
  (define current-captures (cons (total_white_capture) (total_black_capture)))
  (define (run)
    (define (gen-next-board stone)
      (define (manhattan-move i)
        (cond ((= i 0) #f)
              (else
               (let* ((rel-x (- (random 6) 2))
                      (rel-y (- (random 6) 2))
                      (x (car current-move))
                      (y (cdr current-move)))
                 (cond ((not (on-board? (cons (+ x rel-x)
                                              (+ y rel-y)))) (manhattan-move (sub1 i)))
                       (else (let ((play (try_move (+ x rel-x) (+ y rel-y) stone)))
                               (cond ((= play 1) (begin
                                                   (set! current-move
                                                         (cons (+ rel-x x)
                                                               (+ rel-y y)))
                                                   #t))
                                     (else (manhattan-move (sub1 i)))))))))))

      (define (random-move)
        (let* ((x (random size))
               (y (random size))
               (play (try_move x y stone)))
          (cond ((= play 1) (set! current-move (cons x y)))
                (else (random-move)))))
      
      (let ((rand (random)))
        (cond ((> 0.3 rand) (if (manhattan-move 25) (void) (random-move)))
              (else (random-move)))))

    (define (update-current-board)
      (set! current-board
            (build-list size
                        (lambda (x) (build-list size (lambda (y) (board_pos x y)))))))
    
    (cond ((or (> depth max-depth)
               (> (- (current-inexact-milliseconds) start-time) time))
           (list (count-territories current-board) (cons (- (total_white_capture)
                                                            (car current-captures))
                                                         (- (total_black_capture)
                                                            (cdr current-captures)))))
          (else (begin (gen-next-board current-player)
                       (update-current-board)
                       (set! depth (add1 depth))
                       (set! current-player (if (= current-player 1) 2 1))
                       (run)))))
  (define (restore i)
    (cond ((>= i depth) (void))
          (else (begin (undo_previous_move) (restore (add1 i))))))
  (define this-run (run))
  (begin (restore 0) this-run))
(define ib '((0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 2 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)
             (0 0 0 0 0 0 0 0 0)))
(try_move 4 4 2)
(define im (cons 4 4))

(define (test i j)
  (cond ((> i j) (void))
        (else (begin (displayln (run-simulation ib 1 im 60 10000))
                     (test (add1 i) j)))))

  