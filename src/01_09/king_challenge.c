#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printBoard(int *king){
    for (int row = 7; row >= 0; row--){
        for (int col = 0; col < 8; col++){
            if (row == king[0] && col == king[1]){
                printf("K ");
                continue;
            }

            printf(". ");
        }
        printf("\n");
    }
}

int isOutOfBounds(int *king){
    if (king[0] < 0 || king[0] > 7 || king[1] < 0 || king[1] > 7 ){
        return 1;
    }

    return 0;
}


void moveKingRandom(int * king){
    int col_step = rand() % 3 - 1; // between -1 and 1
    int row_step = rand() % 3 - 1; // between -1 and 1

    king[0] += col_step;
    king[1] += row_step;
}


int main(){

    int initial_x = 4;
    int initial_y = 3;

    int king[2] = {initial_y, initial_x};

    int turn = 1;

    srand(time(NULL));   // Initialization of RNG

    printf("Start\n");
    printBoard(king);

    moveKingRandom(king);

    while (!isOutOfBounds(king)){
        printf("Turn %d\n", turn++);
        printBoard(king);
        
        moveKingRandom(king);
    }

    printf("The king wandered off the grid after %d turns\n", turn);

    return 0;
}