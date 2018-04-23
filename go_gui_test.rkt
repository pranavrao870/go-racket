#lang racket

(require 2htdp/image)
(require 2htdp/universe)
(require "board_utilities.rkt")
(require "go_engine.rkt")

(clear_board)

(define (2d_vec_set! vec x y val)
  (vector-set! (vector-ref vec x) y val))

(define (2d_vec_get vec x y)
  (vector-ref (vector-ref vec (- x 1)) (- y 1)))

(define (2d_vec_init r c val)
  (build-vector r (lambda (num) (make-vector c val))))

(define (in_range val low high)
  (and (<= val high) (<= low val)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Size of the board.(imported form the board_utils)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;(define size 9)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Min and Max coordinates on
;; the board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define min-xy 25)
(define max-xy 353)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Converts the coordinates of
;; point of click to indices on
;; the board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (click-pos->index x y)
  (let*
      ([x (exact-round (/ (* (- x min-xy) (sub1 size)) (- max-xy min-xy)))]
       [y (exact-round (/ (* (- y min-xy) (sub1 size)) (- max-xy min-xy)))])
    (if (and (in_range x 0 8) (in_range y 0 8)) (cons x y)
        (cons #f #f))))
    

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Converts indices on board
;; back to coordinates on the
;; frame.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (index->click-pos x y)
  (cons (+ 25 (* x (/ (- max-xy min-xy) (sub1 size))))
        (+ 25 (* y (/ (- max-xy min-xy) (sub1 size))))))

(define xlp1 177)
(define xhp1 220)
(define ylp1 224)
(define yhp1 243)
(define xlp2 177)
(define xhp2 220)
(define ylp2 255)
(define yhp2 275)
(define undo-pass (beside (text/font "Undo        " 20 "black"
                                     "Gill Sans" "modern" "normal"
                                     "bold" #f)
                          (text/font "      Pass" 20 "black"
                                     "Gill Sans" "modern" "normal"
                                     "bold" #f)))
(define board-img (above (scale (/ 380 2209) (bitmap "Go_board_9x9.png")) undo-pass ))
(define stone-radius 17)
(define black-stone (circle stone-radius "solid" "black"))
(define white-stone (circle stone-radius "solid" "white"))
(define go-text (text/font "GO" 50 "black" "Gill Sans" "modern" "normal" "bold" #f))
(define pick-color-text (text/font "PICK COLOR" 20 "black"
                                   "Gill Sans" "modern" "normal"
                                   "bold" #f))
(define stone-choice (above (crop 0 0 80 40 (circle 40 "solid" "black"))
                            (crop 0 40 80 40 (circle 40 "solid" "white"))))
(define player-choice (above (text/font "1 PLAYER" 20 "black"
                                        "Gill Sans" "modern" "normal"
                                        "bold" #f)
                             (text/font "2 PLAYER" 20 "black"
                                        "Gill Sans" "modern" "normal"
                                        "bold" #f)))

(define (undo-click x y)
  (and (in_range x 91 135) (in_range y 388 397)))

(define (pass-click x y)
  (and (in_range x 248 292) (in_range y 388 397)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;This function generates the best possible move given the board_pos and for the
;clr(1 for white and 2 black)
;or else return (-1 -1) if there is no possible move and wants to pass
;(define (generate_move board_pos clr)
;  (define (tryh i j)
;    (if (check_valid i j clr board_pos) (cons i j)
;        (cond
;          [(< i (vector-length board_pos)) (tryh (+ 1 i) j)]
;          [(< j (vector-length board_pos)) (tryh i (+ j 1))]
;          [else (cons -1 -1)])))
;  (tryh 1 1))


(define board_state%
  (class object%
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;Stores the moves such that we can get the latest move by (car moves)
    ;The moves are of the form (cx, cy, ply) where plyr is 1 or 2
    (define moves '())
    (define 1_player #t)  ;;if the game is two player then this is false
    (define turn 2)  ;;can be 1 or 2 depending on the color, as the color is important
    (define 1_player_clr 1) ;;the black plays first always, in 2 player this is easy
    ;;but in 1 player, the player can choose whether he is black
    ;;or the computer is black
    ;;if now black color turn then it is true else it is fasle
    (define error_msg "")  ;;the error msg will be stored here
    (define last_mv_pass #f)
    (define state 0)
    (define start-phase #t) ;;in case the player is playing against the computer then this
    ;;defines the first few standard moves
    (define corner-picked -1)
    (define last-non-pass (cons 1 1))
    (define now-classy-move #f)

    (define/public (set_1_player! val)
      (begin
        (display val)
        (newline)
        (set! state (if val 1 2))
        (set! 1_player val)))

    (define/public (set_1_player_clr! clr)
      (begin
        (display clr)
        (newline)
        (set! state 2)
        (set! 1_player_clr clr)
        (if (= 1 1_player_clr) (comp-move!) (void))))

    (define (next-turn)
      (cond ((= 1 turn) (begin (set! turn 2) (void)))
            ((= 2 turn) (begin (set! turn 1) (void)))))

    (define (comp-move!)
      (cond
        [start-phase (34-corner-strategy)]
        [(< (length moves) 3) (begin
                                (set! start-phase #t)
                                (34-corner-strategy))]
        [else (let*
                ((ai-clr (if (= 1 1_player_clr) 2 1))
                 (aimove (ai last-non-pass ai-clr 2000))
                 (temp (next-turn)))
                (try-move-at (car aimove) (cdr aimove) ai-clr))]))

    (define (custom-pos val)
      (if (> val 3) -1 1))

    (define (build-corner)
      (define cx (car corner-picked))
      (define cy (cdr corner-picked))
      (let*
          ([tryx (+ cx (* 2 (custom-pos cx)))]
           [tryy cy])
        (if (try-move-at tryx tryy turn)
            (next-turn)
            (let*
                ([tryx cx]
                 [tryy (+ cy (* 2 (custom-pos cy)))])
              (if (try-move-at tryx tryy turn)
                  (next-turn)
                  (let*
                      ([tryx (- cx (* 1 (custom-pos cx)))]
                       [tryy (+ cy (* 2 (custom-pos cy)))])
                    (if (try-move-at tryx tryy turn)
                        (next-turn)
                        (let*
                            ([tryx (+ cx (* 2 (custom-pos cx)))]
                             [tryy (- cy (* 1 (custom-pos cy)))])
                          (if (try-move-at tryx tryy turn)
                              (next-turn)
                              (let*
                                  ([tryx (+ cx (* 2 (custom-pos cx)))]
                                   [tryy cy])
                                (if (try-move-at tryx tryy turn)
                                    (next-turn)
                                    (let*
                                        ([tryx cx]
                                         [tryy (+ cy (* 2 (custom-pos cy)))])
                                      (if (try-move-at tryx tryy turn)
                                          (next-turn)
                                          (begin
                                            (set! start-phase #f)
                                            (comp-move!)))))))))))))))

    (define (pick-corner first_att)
      (let*
          ([tryx (+ 2 (* 4 (quotient first_att 2)))]
           [tryy (+ 2 (* 4 (remainder first_att 2)))])
        (if (try-move-at tryx tryy turn)
            (begin (set! corner-picked (cons tryx tryy)))
            (pick-corner (random 4)))))
            

    (define (34-corner-strategy)
      (cond
        [(> (length moves) 12) (begin
                                 (set! start-phase #f)
                                 (comp-move!))]
        [(< (length moves) 2) (begin
                                (pick-corner (random 4))
                                (next-turn))]
        [else (build-corner)]))

    (define (to_draw_start)
      (overlay/offset
       player-choice
       0 -50
       (overlay
        (rectangle 350 350
                   "outline"
                   "black")
        (overlay/offset
         go-text 0 135
         (empty-scene
          400 400
          (color 220 179 92))))))

    (define (to_draw_pick_col)
      (overlay/offset
       stone-choice
       0 -50
       (overlay/offset
        pick-color-text 0 50
        (overlay
         (rectangle 350 350
                    "outline"
                    "black")
         (overlay/offset
          go-text 0 135
          (empty-scene
           400 400
           (color 220 179 92)))))))

    (define (to_draw_board)
      (define (overlay-stones i j img)
        (cond ((= i 9) (overlay-stones 0 (+ j 1) img))
              ((= j 9) img)
              (else (let ((item (board_pos i j))
                          (pixel (index->click-pos i j)))
                      (cond ((= 1 item)
                             (overlay-stones (+ i 1)
                                             j
                                             (overlay/xy white-stone
                                                         (+ stone-radius (- (car pixel)))
                                                         (+ stone-radius (- (cdr pixel)))
                                                         img)))
                            ((= 2 item)
                             (overlay-stones (+ i 1)
                                             j
                                             (overlay/xy black-stone
                                                         (+ stone-radius (- (car pixel)))
                                                         (+ stone-radius (- (cdr pixel)))
                                                         img)))
                            (else (overlay-stones (+ i 1) j img)))))))
      (overlay-stones 0 0 board-img))

    (define (to_draw_end)
      (text (symbol->string 'The_end) 40 'red))

    (define (end_game)
      (begin
        (set! state 3)
        (set! error_msg "The game is over now")))

    (define/public (to_draw)
      (cond
        [(= state 0) (to_draw_start)]
        [(= state 1) (to_draw_pick_col)]
        [(= state 2) (to_draw_board)]
        [else (to_draw_end)]))

    (define (try-move-at bx by current-turn)
      (define try-result (try_move bx by current-turn))
      (cond ((= try-result 1) (begin
                                (set! moves (cons (list bx by current-turn) moves))
                                #t))
            (else #f)))

    (define/public (to-check-ai)
      (if now-classy-move
          (begin
            (set! now-classy-move #f)
             (comp-move!))
          (void)))
    
    (define/public (on_mouse x y)
      (cond
        [(= state 0)
         (cond
           [(and (in_range x xlp1 xhp1) (in_range y ylp1 yhp1)) (set_1_player! #t)]
           [(and (in_range x xlp2 xhp2) (in_range y ylp2 yhp2)) (set_1_player! #f)])]
        [(= state 1)
         (cond
           [(and (in_range x xlp1 xhp1) (in_range y ylp1 yhp1)) (set_1_player_clr! 2)]
           [(and (in_range x xlp2 xhp2) (in_range y ylp2 yhp2)) (set_1_player_clr! 1)])]
        [(and (= state 2) (undo-click x y) (> (length moves) 1))
         (if 1_player
             (begin
               (undo_previous_move)
               (undo_previous_move)
               (set! moves (cddr moves))
               (set! last_mv_pass #f))
             (begin
               (undo_previous_move)
               (next-turn)
               (set! moves (cdr moves))))]
        [(and (= state 2) (pass-click x y))
         (if last_mv_pass (end_game)
             (if 1_player
                 (begin
                   (set! last_mv_pass #t)
                   (end_game)
                   (next-turn))
                 (begin
                   (set! last_mv_pass #t)
                   (set! moves (cons '(-1 -1 turn) moves))
                   (next-turn))))]
        [(and (= state 2) (not 1_player))
         (let* ((indices (click-pos->index x y)))
           (if (equal? (car indices) #f) (void)
               (let*
                   ((current-turn turn)
                    (valid-move (try-move-at (car indices) (cdr indices) current-turn)))
                 (if valid-move (next-turn) (void)))))]
        [(and (= state 2) 1_player)
         (let* ((indices (click-pos->index x y)))
           (if (equal? (car indices) #f) (void)
               (let*
                   ((current-turn turn)
                    (valid-move (try-move-at (car indices) (cdr indices) current-turn)))
                 (if valid-move
                     (begin
                       (next-turn)
                       (set! last-non-pass indices)
                       (set! now-classy-move #t))
                     (void)))))]))

    (super-new)))

(define go_board (new board_state%))

(define (render board)
  (send board to_draw))

(define (check-ai board)
  (begin
    (send board to-check-ai)
    board))

(define (try_mouse board x y click)
  (cond
    [(equal? click "button-down" ) (begin
                                     (send board on_mouse x y)
                                     board)]
    [else board]))

(big-bang go_board
  (to-draw render)
  (on-tick check-ai)
  (on-mouse try_mouse))
