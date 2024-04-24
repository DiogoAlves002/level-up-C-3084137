#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void printFrame(int first, int second){
    char type;
    char first_print = ' ';
    
    int total = first + second;

    if (first == 10){
        type = 'X'; 
    } else if (total == 10){
        first_print = first + '0';
        type = '/';
    } else {
        first_print = first + '0';
        type = second + '0';
    }
    
    printf("| %c|%c|\n", first_print, type);
    printf("| %2d |\n", total);
}



int main(){
    srand(time(NULL));   // Initialization of RNG

    char frame_type;

    int first_frame = rand() % 11;
    int second_frame = rand() % (11 - first_frame);

    printFrame(first_frame, second_frame);

    return 0;
}