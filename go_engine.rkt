#lang racket

(require "board_utilities.rkt")

(provide ai)

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

(define (run-simulation init-board init-player prev-move max-depth)
  (define depth 0)
  (define current-board init-board)
  (define prev-move prev-move)
  (define current-player init-player)
  (define current-captures (cons (total_white_capture) (total_black_capture)))
  (define (run)
    (define (gen-next-board stone)
      (define (manhattan-move i)
        (cond ((= i 0) #f)
              (else
               (let* ((rel-x (- (random 6) 2))
                      (rel-y (- (random 6) 2))
                      (x (car prev-move))
                      (y (cdr prev-move)))
                 (cond ((not (on-board? (cons (+ x rel-x)
                                              (+ y rel-y)))) (manhattan-move (sub1 i)))
                       (else (let ((play (try_move (+ x rel-x) (+ y rel-y) stone)))
                               (cond ((= play 1) (begin
                                                   (set! prev-move
                                                         (cons (+ rel-x x)
                                                               (+ rel-y y)))
                                                   #t))
                                     (else (manhattan-move (sub1 i)))))))))))

      (define (random-move)
        (let* ((x (random size))
               (y (random size))
               (play (try_move x y stone)))
          (cond ((= play 1) (set! prev-move (cons x y)))
                (else (random-move)))))

      (let ((rand (random)))
        (cond ((> 0.3 rand) (if (manhattan-move 25) (void) (random-move)))
              (else (random-move)))))

    (define (update-current-board)
      (set! current-board (board->2dlist)))
    
    (cond ((> depth max-depth)
           (append (count-territories current-board) (list (- (total_white_capture)
                                                              (car current-captures))
                                                           (- (total_black_capture)
                                                              (cdr current-captures)))))

          (else (begin (gen-next-board current-player)
                       (update-current-board)
                       (set! depth (add1 depth))
                       (set! current-player (next-turn current-player))
                       (run)))))
  (define (restore i)
    (cond ((>= i depth) (void))
          (else (begin (undo_previous_move) (restore (add1 i))))))
  (define this-run (run))
  (begin (restore 0) this-run))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; struct for storing the mini-max tree
;; bsc : black score
;; wsc : white score (check calculate-scores)
;; turn : color (black or white) for which the
;;        node trying to optimize.
;; select : best branch according to minimax
;;          which optimizes the turn.
;; sub-trees : list of subtrees of this tree.
;; move : the last move made to reach this state
;; tplays : total playouts made passing through
;;          this node.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(struct mm_node (turn select sub-trees wsc bsc move tplays))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Since we don't want to miss out on capturing
;; opponents pieces. So based on the last move
;; we check whether there is a chance to capture
;; by counting the liberties. Also, we don't want
;; to fill our own liberties.
;; @param : previous move and the turn of
;;          current player.
;; @return : new move.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (generate-move last-move turn)
  (define choose-move (random))
  (define their-libs (find-lib-wrapper (car last-move)
                                       (cdr last-move)))
  (cond ((and (< choose-move 0.5) (<= (length their-libs) 3)) (car their-libs))
        (else (let ((x (random size))
                    (y (random size))
                    (my-libs (remove-duplicates
                              (append*
                               (map
                                (lambda (x)
                                  (cond ((= turn (board_pos (first x) (second x)))
                                         (find-lib-wrapper (first x) (second x)))
                                        (else '()))) (cartesian-product (build-list size values) (build-list size values)))))))
                (if (and (member (cons x y) my-libs)
                         (<= (length my-libs) 2)
                         (< choose-move 0.7))
                    (generate-move last-move turn)
                    (cons x y))))))

(define (getcapture turn)
  (cond
    ((= turn 1) (total_white_capture))
    ((= turn 2) (total_black_capture))))

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; The function which builds mini-max tree.
;; @param turn : black(2) or white(1)
;; @param max-depth and current-depth
;; @param last-move 
;; @return : An mm_node containing complete
;;           information about the minimax tree.
;; Note that at the time of calling this function,
;; the board_pos must have the configuration at
;; which the mini-max has to be evaluated when
;; the function returns, the configuration will
;; be the same.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (build-minimax turn max-depth curr-depth last-move)
  (define num-tries 0)
  (define branching-fac 5)
  (define max-num-tries (* 10 branching-fac))
  (define moves-tried '())
  (define sub-trees '())
  (define (terr-counter)
    (let*
        ((wc (getcapture 1))
         (bc (getcapture 2))
         (scores (calculate-scores
                  (append (list wc bc)
                          (count-territories (board->2dlist)))))
         (wt (car scores))
         (bt (cdr scores)))
      (mm_node turn -1 '() wt bt last-move 1)))
  (define (helper iter)
    (begin
      (set! num-tries (+ 1 num-tries))
      (cond
        ((> num-tries max-num-tries) (terr-counter))
        ((<= iter branching-fac)
         (let* ((move (generate-move last-move turn)))
           (if (equal? (member move moves-tried) #f)
               (let*
                   ((tmp (set! moves-tried (cons move moves-tried)))
                    (retval (try_move (car move) (cdr move) turn)))
                 (if (= retval 1)
                     (let*
                         ((turn-new (next-turn turn))
                          (tree (build-minimax turn-new max-depth
                                               (+ curr-depth 1) move))
                          (tmp (set! sub-trees (cons tree sub-trees)))
                          (tmp (undo_previous_move)))
                       (helper (+ iter 1)))
                     (helper iter)))
               (helper iter))))
        ((> iter branching-fac)
         (let*
             ((best (best-branch sub-trees turn))
              (wsc (car best))
              (bsc (cadr best))
              (select (cddr best)))
           (mm_node turn select sub-trees wsc bsc last-move (foldl
                                                             (lambda (x y)
                                                               (+ y (mm_node-tplays x)))
                                                             0 sub-trees)))))))

  (cond
    ((= curr-depth max-depth) (terr-counter))
    (else (helper 1))))

(define (sim-for-time
         total-time
         init-board
         init-player
         prev-move
         max-depth)
  (define current-time (current-inexact-milliseconds))
  (define results '())
  (define (loop)
    (cond ((< total-time (- (current-inexact-milliseconds) current-time)) (void))
          (else (begin (set! results (cons (run-simulation init-board
                                                           init-player
                                                           prev-move
                                                           max-depth)
                                           results))
                       (loop)))))
  (begin (loop)
         (let ((len (length results)))
           (foldl (lambda (x y) (map (lambda (i j) (+ i j)) x y))
                  (list 0 0 0 0) 
                  (map (lambda (x) (map (lambda (y) (/ y len)) x)) results)))))

(define (update tree move-list)
  (cond ((null? move-list)
         ;; Possibly make a new node and simulate for approx 2/3 of the moves left.
         (let* ((next-move (generate-move
                            (mm_node-move tree)
                            (mm_node-turn tree)))
                (attempt (try_move (car next-move) (cdr next-move))))
           (cond ((= attempt 1) ;; simulate
                  (let* ((sim-result
                          (sim-for-time
                           200
                           (board->2dlist)
                           (next-turn (mm_node-turn tree))
                           (mm_node-move tree)
                           (/ (* 2 (- (* size size) total-moves)) 3)))
                         (scores (calculate-scores sim-result))
                         (new-node (mm_node
                                    (next-turn (mm_node-turn tree))
                                    -1
                                    '()
                                    (car scores)
                                    (cdr scores)
                                    next-move
                                    1)))
                    ;; Because pranav said that we keep the scores of the best branch
                    ;; over here, since there is only one (newly created) branch. We just
                    ;; update with it's scores.
                    (mm_node (mm_node-turn tree) new-node (list new-node) (car scores) (cdr scores) (mm_node-move tree) 2))) 
                 (else tree)))) ;; Don't simulate if try_move returns 0. I guess it is there to make my life easy.
        (else (begin (try_move (car (car move-list)) (cdr (car move-list)) (mm_node-turn tree))
                     (let* ((updated-subtrees
                             (map
                              (lambda (x)
                                (if (equal? (mm_node-move x)
                                            (car move-list))
                                    (update x (cdr move-list))
                                    x))
                              (mm_node-sub-trees tree)))
                            (best (best-branch updated-subtrees (mm_node-turn tree)))
                            (wsc (car best))
                            (bsc (cdr best))
                            (select (cddr best)))
                       (begin (undo_previous_move)
                              (mm_node (mm_node-turn tree)
                                       select
                                       updated-subtrees
                                       wsc bsc (mm_node-move tree) (add1 mm_node-tplays))))))))
;; BOTH THESE PROCEDURES INCLUDE TOPMOST MOVE (OVERALL LAST MOVE)
(define (mm-move-list tree lst)
  (cond ((mm_node? (mm_node-select tree))
         (mm-move-list (mm_node-select tree)
                       (append lst ((list (mm_node-move tree))))))
        (else (append lst (list (mm_node-move tree))))))

(define (uct-formula x tree)
  (define (expression xi n ni)
    (+ xi (sqrt (/ (log n) ni))))
  ;; For foldl.
  (define (add-scores t1 t2)
    (cond ((null? t2) (cons (mm_node-wsc t1) (mm_node-bsc t1)))
          (else (cons (+ (mm_node-wsc t1) (car t2)) (+ (mm_node-bsc t1) (cdr t2))))))
  (cond ((null? mm_node-sub-trees x)
         (expression (if (= (mm_node-turn tree) 1)
                         (- (mm_node-wsc x) (mm_node-bsc x))
                         (- (mm_node-bsc x) (mm_node-wsc x)))
                     (mm_node-tplays tree)
                     (mm_node-tplays x)))
        (else (let* ((sum-of-scores (foldl add-scores null (mm_node-sub-trees x)))
                     (white-score (/ (car sum-of-scores) (length (mm_node-sub-trees x))))
                     (black-score (/ (cdr sum-of-scores) (length (mm_node-sub-trees x)))))
                (expression (if (= (mm_node-turn tree) 2)
                                (- black-score white-score)
                                (- white-score black-score))
                            (mm_node-tplays tree)
                            (mm_node-tplays x))))))

(define (uct-move-list tree lst)
  (cond ((not (null? (mm_node-sub-trees tree)))
         (let ((best-score-tree
                (foldl (lambda (x y) (if (null? y) x
                                         (if (> (uct-formula x tree)
                                                (uct-formula y tree)) x y)))
                       null (mm_node-sub-trees tree))))
           (uct-move-list best-score-tree (append lst (list mm_node-move tree)))))
        (else (append lst (list mm_node-move tree)))))

(define (ai last-move turn time)
  (define search-tree (build-minimax turn 6 0 last-move))
  (define start-time (current-inexact-milliseconds))
  (define mm-path (mm-move-list search-tree '()))
  (define (select-best)
    (define best-node (foldl (lambda (x y) (if (null? y) x
                                         (if (> (uct-formula x search-tree)
                                                (uct-formula y search-tree)) x y)))
                       null (mm_node-sub-trees search-tree)))
    (mm_node-move best-node))
  (define (run)
    (cond ((> (- (current-inexact-milliseconds) start-time) time) (select-best))
          (else (let ((uct-path (uct-move-list search-tree '())))
                  (begin (set! search-tree (update search-tree (cdr uct-path)))
                         (run))))))
  (begin (set! search-tree (update search-tree (cdr mm-path)))
         (run)))
