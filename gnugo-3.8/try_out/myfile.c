#include "board.h"
#include "liberty.h"
#include "sgftree.h"

int get_token_at_pos(int i, int j){
    return board[POS(i,j)];
}
int place_move(int i, int j, int stone_type){
    trymove(POS(i,j), stone_type,"Making a move",NO_MOVE);
}
int main(){
    clear_board();
    printf("%d\n", MAX_BOARD);
    trymove(POS(2,3),1,"White",NO_MOVE);
    trymove(POS(3,4),1,"White",NO_MOVE);
    trymove(POS(4,3),1,"White",NO_MOVE);
    trymove(POS(3,2),1,"White",NO_MOVE);
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            printf("%u ", board[POS(i,j)]);
        }
        printf("\n");
    }
    printf("%d\n", is_legal(POS(3,3),2));
}
