#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)
(define-ffi-definer define-master (ffi-lib "/home/sumitc/CS152/Project/go-racket/gnugo-3.8/engine/libmaster"))
(require "board_utilities.rkt")
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

(define total-moves 0)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Once the subtree to be explored has been
;; decided, we explore that subtree through a
;;(sort of) random  playout, based on some
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

(define (run-simulation init-board init-player init-move time)
  (define depth 0)
  (define start-time (current-inexact-milliseconds))
  (define current-board init-board)
  (define current-move init-move)
  (define current-player init-player)
  (define (run)
    (define (gen-next-board stone)
      (define (hamming-move i)
        (cond ((= i 0) #f)
              (else
               (let* ((rel-x (- (random 6) 2))
                      (rel-y (- (random 6) 2))
                      (x (car current-move))
                      (y (cdr current-move))
                      (pos (+ (* 9 (+ x rel-x)) (+ y rel-y))))
                 (cond ((not (on-board? pos)) (hamming-move (sub1 i)))
                       (else (let ((play (try_move (+ x rel-x) (+ y rel-y) stone)))
                               (cond ((= play 1) (begin
                                                   (set! current-move
                                                         (cons (+ rel-x x)
                                                               (+ rel-y y)))
                                                   #t))
                                     (else (hamming-move (sub1 i) stone))))))))))

      (define (random-move)
        (let* ((x (random 9))
               (y (random 9))
               (play (try_move x y stone)))
          (cond ((= play 1) (set! current-move (cons x y)))
                (else (random-move)))))
      
      (let ((rand (random)))
        (cond ((> 0.3 rand) (if (hamming-move 25) (void) (random-move)))
              (else (random-move)))))

    (define (update-current-board)
      (set! current-board
            (build-list size
                        (lambda (x) (build-list size (lambda (y) (board_pos x y)))))))
    
    (cond ((> (- (current-inexact-milliseconds) start-time) time)
           (count-territories current-board))
          (else (begin (gen-next-board current-player)
                       (update-current-board)
                       (set! depth (add1 depth))
                       (set! current-player (if (= current-player 1) 2 1))
                       (run)))))
  (define (restore i)
    (cond ((>= i depth) (void))
          (else (undo_previous_move))))
  (begin (restore 0) (run)))
  