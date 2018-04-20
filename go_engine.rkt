#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)
(define-ffi-definer define-master (ffi-lib "/home/sumitc/CS152/Project/go-racket/gnugo-3.8/engine/libmaster"))
(require board_utilities)
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

(define visited-states null)

(define total-moves 0)

(define (run-simulation init time player)
  (define depth 0)
  (define start-time (current-inexact-milliseconds))
  (define current-board init)
  (define (run)
    (define (similarity-with-old-board)
      (cond ((null? visited-states) #f)
            (else (let ((similar? (foldl () #f visited-states)))
                    (begin (if (not similar?) (cons (value of result of run) visited-states))
                           similar?)))))
    (define (gen-next-board)
      (let ((rand (random)))
        (cond ((> 0.2 rand) 111);; Find and play legal move within three hamming distance.
              ((and (> (+ total-moves depth) 20)
                    (> rand 0.2) (> 0.3 rand)) 111);;; Find and play random move not in the first two
              (else )))) ;;; Find and play random move anywhere
    (cond ((> (- (current-inexact-milliseconds) start-time) time)
           (let ((terr (count-territories current-board)))
             (cond ((= player 1) (if (> (car terr) (cdr terr)) 1 0))
                   ((= player 2) (if (< (car terr) (cdr terr)) 1 0)))))
          (else (begin (gen-next-board)
                       (update-current-board)
                       (set! depth (add1 depth))
                       (cond (;;; Traverse the table to find a similar config which
                              ;;; has a one in it. If not, If all are very far then add
                              ;;; this board to the set and run
                              ))))))
  (define (restore i)
    (cond ((>= i depth) (void))
          (else (undo_previous_move))))
  (begin (restore 0) (run)))
  