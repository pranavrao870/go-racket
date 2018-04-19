#lang racket

(require ffi/unsafe)
(require ffi/unsafe/define)
(require 2htdp/image)
(require 2htdp/universe)

(define-ffi-definer define-master (ffi-lib "/home/sumitc/CS152/Project/go-racket/gnugo-3.8/engine/libmaster"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Definitions of functions exported from gnugo 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Undo a move on the board.
; @param : void
; @return : void
(define-master undo_previous_move (_fun -> _void))

; Clear the entire board.
; @param : void
; @return : void
(define-master clear_board (_fun -> _void))

; Get the entity at a particular intersection on the board
; @param : integers i, j which specify a coordinate on the board
; @return : integer. 0 -> Empty, 1 -> White, 2 -> Black
(define-master board_pos (_fun _int _int -> _int))

; Attempt a move at a particular intersection
; @param : integers i, j and color
; @return : integer. 0 -> invalid move, 1 -> valid move.
(define-master try_move (_fun _int _int _int -> _int))



;This will be the main file for the go game
;this will instatiate the go board and the
;go engine
; Make a frame by instantiating the frame% class

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Board representation
;0 -> No stone present
;1 -> White Stone
;2 -> Black Stone
(define board (build-vector 9 (lambda (x) (build-vector 9 (lambda (x) 0)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Useful macros
(define-syntax-rule (access i j)
  (vector-ref (vector-ref board i) j))

(define-syntax-rule (update i j val)
  (vector-set! (vector-ref board i) j val)) 


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Definitions for all the images
;used in the UI

;In the universe model (http://docs.racket-lang.org/teachpack/2htdpuniverse.html#%28part._scene%29)
;you have to specify a set of frames and using event handlers like
;on-tick (passing of time) on-click and so on, you have to transition to other frames.
;they call these frames worldstate for some reason. Don't know much about them

;Intro should be the first frame
(define board-img (scale (/ 400 2209) (bitmap "Go_board_9x9.png")))
(define black-stone (circle 15 "solid" "black"))
(define white-stone (circle 15 "solid" "white"))
(define go-text (text/font "GO" 50 "black" "Gill Sans" "modern" "normal" "bold" #f))
(define pick-color-text (text/font "PICK COLOR" 20 "black"
                              "Gill Sans" "modern" "normal"
                              "bold" #f))
(define stone-choice (above (crop 0 0 80 40 (circle 40 "solid" "black"))
                            (crop 0 40 80 40 (circle 40 "solid" "white"))))
(define intro
  (overlay/offset stone-choice
                  0 -50
                  (overlay/offset pick-color-text 0 50
                                  (overlay (rectangle 350 350
                                                      "outline"
                                                      "black")
                                           (overlay/offset go-text 0 135
                                                           (empty-scene
                                                            400 400
                                                            (color 220 179 92)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Interactions



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;Enforce rules

;;Return a list of positions where ko can happen
;(define (eye i j stone-type)
;  (cond ((and (> i 0) (> j 0) (< j 8) (< i 8))
;         (and (= (access (add1 i) j) stone-type)
;              (= (access (sub1 i) j) stone-type)
;              (= (access i (add1 j)) stone-type)
;              (= (access i (sub1 j)) stone-type)))
;        ((and (= i 0) (= j 0))
;         (and (= (access (add1 i) j) stone-type)
;              (= (access i (add1 j)) stone-type)))
;        ((and (= i 0) (= j 8))
;         (and (= (access (add1 i) j) stone-type)
;              (= (access i (sub1 j)) stone-type)))
;        ((and (= i 8) (= j 0))
;         (and (= (access (sub1 i) j) stone-type)
;              (= (access i (add1 j)) stone-type)))
;        ((and (= i 8) (= j 8))
;         (and (= (access (sub1 i) j) stone-type)
;              (= (access i (sub1 j)) stone-type)))
;        ((= i 0)
;         (and (= (access (add1 i) j) stone-type)
;              (= (access i (sub1 j)) stone-type)
;              (= (access i (add1 j)) stone-type)))
;        ((= i 8)
;         (and (= (access (sub1 i) j) stone-type)
;              (= (access i (sub1 j)) stone-type)
;              (= (access i (add1 j)) stone-type)))
;        ((= j 0)
;         (and (= (access (add1 i) j) stone-type)
;              (= (access (sub1 i)  j) stone-type)
;              (= (access i (add1 j)) stone-type)))
;        ((= j 8)
;         (and (= (access (add1 i) j) stone-type)
;              (= (access (sub1 i) j) stone-type)
;              (= (access i (sub1 j)) stone-type)))
;        (else (error "Incorrect Indices"))))
;        
;              
;(define (detect-ko)
;  (define (other-type stone-type)
;    (cond ((= stone-type 1) 2)
;          ((= stone-type 2) 1)))
;  (define (pattern-detect i j stone-type)
;    (define (pattern1)
;      (cond ((and (> 7 j) (> j 0) (> i 0) (> 8 i))
;             (and (= (access (sub1 i) (add1 j)) (other-type stone-type))
;                  (= (access (add1 i) (add1 j)) (other-type stone-type))
;                  (= (access i (+ j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern2)
;      (cond ((and (> 7 i) (> j 0) (> i 0) (> 8 j))
;             (and (= (access (add1 i) (sub1 j)) (other-type stone-type))
;                  (= (access (add1 i) (add1 j)) (other-type stone-type))
;                  (= (access (+ i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern3)
;      (cond ((and (> 8 j) (> j 1) (> i 0) (> 8 i))
;             (and (= (access (sub1 i) (sub1 j)) (other-type stone-type))
;                  (= (access (add1 i) (sub1 j)) (other-type stone-type))
;                  (= (access i (- j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern4)
;      (cond ((and (> 8 j) (> j 0) (> i 1) (> 8 i))
;             (and (= (access (sub1 i) (sub1 j)) (other-type stone-type))
;                  (= (access (sub1 i) (add1 j)) (other-type stone-type))
;                  (= (access (- i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern5)
;      (cond ((and (= i 0) (< j 7) (> j 0))
;             (and (= (access (add1 i) (add1 j)) (other-type stone-type))
;                  (= (access i (+ j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern6)
;      (cond ((and (= i 0) (> j 1) (< j 8))
;             (and (= (access (add1 i) (sub1 j)) (other-type stone-type))
;                  (= (access i (- j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern7)
;      (cond ((and (= i 8) (< j 7) (> j 0))
;             (and (= (access (sub1 i) (add1 j)) (other-type stone-type))
;                  (= (access i (+ j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern8)
;      (cond ((and (= i 8) (> j 1) (< j 8))
;             (and (= (access (sub1 i) (sub1 j)) (other-type stone-type))
;                  (= (access i (- j 2)) (other-type stone-type))))
;            (else #f)))
;    (define (pattern9)
;      (cond ((and (= j 0) (< i 7) (> i 0))
;             (and (= (access (add1 i) (add1 j)) (other-type stone-type))
;                  (= (access (+ i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern10)
;      (cond ((and (= j 0) (> i 1) (< i 8))
;             (and (= (access (sub1 i) (add1 j)) (other-type stone-type))
;                  (= (access (- i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern11)
;      (cond ((and (= j 8) (> i 1) (< i 8))
;             (and (= (access (sub1 i) (sub1 j)) (other-type stone-type))
;                  (= (access (- i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern12)
;      (cond ((and (= j 8) (> i 0) (< i 7))
;             (and (= (access (add1 i) (sub1 j)) (other-type stone-type))
;                  (= (access (+ i 2) j) (other-type stone-type))))
;            (else #f)))
;    (define (pattern13)
;      (cond ((and (= i 0) (= j 1))
;             (= (access 1 0) (other-type stone-type)))
;            (else #f)))
;    (define (pattern14)
;      (cond ((and (= i 1) (= j 0))
;             (= (access 0 1) (other-type stone-type)))
;            (else #f)))
;    (define (pattern15)
;      (cond ((and (= i 8) (= j 7))
;             (= (access 7 8) (other-type stone-type)))
;            (else #f)))
;    (define (pattern16)
;      (cond ((and (= i 7) (= j 8))
;             (= (access 8 7) (other-type stone-type)))
;            (else #f)))
;    (define (pattern17)
;      (cond ((and (= i 0) (= j 7))
;             (= (access 1 8) (other-type stone-type)))
;            (else #f)))
;    (define (pattern18)
;      (cond ((and (= i 7) (= j 0))
;             (= (access 8 1) (other-type stone-type)))
;            (else #f)))
;    (define (pattern19)
;      (cond ((and (= i 1) (= j 8))
;             (= (access 0 7) (other-type stone-type)))
;            (else #f)))
;    (define (pattern20)
;      (cond ((and (= i 8) (= j 1))
;             (= (access 0 7) (other-type stone-type)))
;            (else #f)))
;    (cond ((eye i j stone-type)
;           (or (pattern1) (pattern2) (pattern3) (pattern4)
;               (pattern5) (pattern6) (pattern7) (pattern8)
;               (pattern9) (pattern10) (pattern11) (pattern12)
;               (pattern13) (pattern14) (pattern15) (pattern16)
;               (pattern17) (pattern18) (pattern19) (pattern20)))
;          (else #f)))
;  (define (traverse-board i j stone-type lst)
;    (cond ((= i 9) lst)
;          ((= j 9) (traverse-board (add1 i) j stone-type lst))
;          ((and (= (vector-ref (vector-ref board i) j) 0)
;                (pattern-detect i j stone-type))
;           (traverse-board i (add1 j) (cons (cons i j) lst)))
;          (else (traverse-board i (add1 j) stone-type lst))))
;  (append (traverse-board 0 0 1 '()) (traverse-board 0 0 2 '())))
