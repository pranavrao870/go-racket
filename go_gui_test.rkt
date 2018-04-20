#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)
(require 2htdp/image)
(require 2htdp/universe)

(define-ffi-definer define-master (ffi-lib "/home/sumitc/CS152/Project/go-racket/gnugo-3.8/engine/libmaster"))

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
;; Size of the board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define size 9)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Min and Max coordinates on
;; the board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define min-xy 25)
(define max-xy 375)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Converts the coordinates of
;; point of click to indices on
;; the board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (click-pos->index x y)
  (cons (exact-round (/ (* (- x min-xy) (sub1 size)) (- max-xy min-xy)))
        (exact-round (/ (* (- y min-xy) (sub1 size)) (- max-xy min-xy)))))

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
(define board-img (scale (/ 400 2209) (bitmap "Go_board_9x9.png")))
(define stone-radius 20)
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;This function generates the best possible move given the board_pos and for the
;clr(1 for white and 2 black)
;or else return (-1 -1) if there is no possible move and wants to pass
(define (generate_move board_pos clr)
  (define (tryh i j)
    (if (check_valid i j clr board_pos) (cons i j)
        (cond
          [(< i (vector-length board_pos)) (tryh (+ 1 i) j)]
          [(< j (vector-length board_pos)) (tryh i (+ j 1))]
          [else (cons -1 -1)])))
  (tryh 1 1))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;this checks if the board is already filled at that position
;is yes return true, else check the complicated rules like ko, dragon and so on
(define (check_valid x y clr board_pos)
  (if (equal? (2d_vec_get board_pos x y) 0) #t #f))


(define board_state%
  (class object%

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;Stores the moves such that we can get the latest move by (car moves)
    ;The moves are of the form (cx, cy, ply) where plyr is 1 or 2
    (define moves '())
    (define 1_player #t)  ;;if the game is two player then this is false
    (define 1_player_clr 2)  ;;which color has the 1st playr chose (black by default)
    (define turn 1)  ;;can be 1 or 2 depending on whose turn(starting with always one)
    (define error_msg "")  ;;the error msg will be stored here
    (define last_mv_pass #f)
    (define state 0)

    (define/public (set_1_player! val)
      (begin
        (display val)
        (newline)
        (set! state 1)
        (set! 1_player val)))

    (define/public (set_1_player_clr! clr)
      (begin
        (display clr)
        (newline)
        (set! state 2)
        (set! 1_player_clr clr)))

    (define (get_plyr_clr plyr)
      (if (= plyr 1) 1_player_clr
          (if (= 1 1_player_clr) 2 1)))  ;;gives the color of the current player

    (define (next-turn)
      (cond ((= 1 turn) (begin (set! turn 2) (void)))
            ((= 2 turn) (begin (set! turn 1) (void)))))

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

    (define/public (on_mouse x y)
      (define (try-move-at bx by current-turn)
        (define try-result (try_move bx by current-turn))
        (cond ((= try-result 1) (set! moves (cons (list x y current-turn) moves)))
              (else (void))))
      (cond
        [(= state 0)
         (cond
           [(and (in_range x xlp1 xhp1) (in_range y ylp1 yhp1)) (set_1_player! #t)]
           [(and (in_range x xlp2 xhp2) (in_range y ylp2 yhp2)) (set_1_player! #f)])]
        [(= state 1)
         (cond
           [(and (in_range x xlp1 xhp1) (in_range y ylp1 yhp1)) (set_1_player_clr! 2)]
           [(and (in_range x xlp2 xhp2) (in_range y ylp2 yhp2)) (set_1_player_clr! 1)])]
        ((= state 2)
         (let* ((indices (click-pos->index x y))
                (current-turn turn)
                (xx (car (index->click-pos (car indices) (cdr indices)))))
           (begin (next-turn)
                  (try_move (car indices)
                            (cdr indices)
                            current-turn))))))

    (super-new)))

;(define go_board (new board_state%))
;
;(define (render board)
;  (send board to_draw))
;
;(define (try_mouse board x y click)
;  (cond
;    [(equal? click "button-down" ) (begin
;                                     (send board on_mouse x y)
;                                     board)]
;    [else board]))
;
;(big-bang go_board
;  (to-draw render)
;  (on-mouse try_mouse))

(define (loop i j)
  (cond ((>= i j) (void))
        (else (begin (try_move 1 3 2) ( (undo_previous_move) (loop (+ i 1) j)))))
