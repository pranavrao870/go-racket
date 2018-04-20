#lang racket

(require "board_utilities.rkt")

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


;;;;;;;;;;;;;;;;;;;;;;;;;;;
;struct for storing the mini-max tree
;bsc refers to black score
;wsc refers to white score (territoris + capture)
;the turn refers to which color (black or white) is the
;node trying to optimize(black is 2 and white is 1)
;select refers to the best branch which optimizes the turn
;;;;;;;;;;;;;;;;;;;;;;;;;;;
(struct mm_node (turn select sub-trees wsc bsc move))


(define (generate-move last-move)
    (let* ((x (random 9))
       (y (random 9)))
       (cons x y)))

(define (getcapture board_pos)
  0)

(define (next-turn turn)
  (if (= turn 1) 2 1))

(define (best-branch li turn)
  (define (helper curr best-till)
    (if (= turn 1)
        (if (< (car best-till) (mm_node-wsc curr))
            (cons (mm_node-wsc curr) (cons (mm_node-bsc curr) curr))
            best-till)
        (if (< (cadr best-till) (mm_node-bsc curr))
            (cons (mm_node-wsc curr) (cons (mm_node-bsc curr) curr))
            best-till)))
    (foldr helper (cons -1 (cons -1 0)) li))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;The function which build as mini-max tree and returns it
;@param wc bc - the captured white and black stoned tillnow
;@param turn black(2) or white(1)
;@param max-depth and current-depth
;@param last-move (not used now but maybe useful for some heuristic later on)
;@return the node contructed
;Note that at the time of calling this function, the board_pos
;must have the configuration at which the mini-max has to be evaluated
;when the function returns, the configuration will be the same
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (build-minimax wc bc turn max-depth curr-depth last-move)
  (define capture_points 1)
  (define num-tries 0)
  (define branching-fac 5)
  (define max-num-tries (* 10 branching-fac))
  (define moves-tried '())
  (define sub-trees '())
  (define (terr-counter)
    (let*
        ([terrs (count-territories board_pos)]
         [wt (+ (* capture_points wc) (car terrs))]
         [bt (+ (* capture_points bc) (cdr terrs))])
      (mm_node turn -1 '() wt bt last-move)))
  (define (helper iter)
    (begin
      (set! num-tries (+ 1 num-tries))
      (cond
        [(> num-tries max-num-tries) (terr-counter)]
        [(<= iter branching-fac)
         (let*
             ([move (generate-move last-move)])
           (if (equal? (member move moves-tried) #f)
               (let*
                   ([tmp (set! moves-tried (cons move moves-tried))]
                    [retval (try_move board_pos turn move)])
                 (if (= retval 1)
                     (let*
                         ([wc-new (getcapture 1 board_pos)]
                          [bc-new (getcapture 2 board_pos)]
                          [turn-new (next-turn turn)]
                          [tree (build-minimax wc-new bc-new turn-new max-depth
                                               (+ curr-depth 1) move)]
                          [tmp (set! sub-trees (cons tree sub-trees))]
                          [tmp (undo_previous_move board_pos)])
                       (helper (+ iter 1)))
                     (helper iter)))
               (helper iter)))]
        [(> iter branching-fac)
         (let*
             ([best (best-branch sub-trees turn)]
              [wsc (car best)]
              [bsc (cadr best)]
              [select (cddr best)])
           (mm_node turn select sub-trees wsc bsc last-move))])))

  (cond
    [(= curr-depth max-depth) (terr-counter)]
    [else (helper 1)]))
