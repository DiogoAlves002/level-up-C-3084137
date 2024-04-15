#include <stdio.h>


void printHailstoneSequence(int start_value){
    int len = 1;

    printf("Hailstone sequence: ");

    while (start_value > 1){
        printf("%d, ", start_value);
        if (start_value % 2 == 0){
            start_value /= 2;
        } else {
            start_value = (start_value * 3 ) + 1;
        }

        len ++;
    }

    printf("%d\n", start_value);

    printf("Sequence length: %d\n", len);
}





int main(){
    
    int start_value;

    printf("Starting value: ");
    scanf("%d", &start_value);  

    printHailstoneSequence(start_value);


    return 0;
}