#include <stdio.h>
#include <stdlib.h>

#define QUARTER 0.25
#define DIME 0.10
#define NICKEL 0.05
#define PENNY 0.01

#define NUM_TEST_CASES 5 


void updateMessageWithChange(char** message, double price){

    int num_quarters = 0;
    int num_dimes = 0;
    int num_nickels = 0;
    int num_pennies = 0;

    if (price / QUARTER){
        num_quarters = price / QUARTER;
        price -= QUARTER * num_quarters;
    }

    if (price / DIME){
        num_dimes = price / DIME;
        price -= DIME * num_dimes;
    }

    if (price / NICKEL){
        num_nickels = price / NICKEL;
        price -= NICKEL * num_nickels;
    }

    num_pennies = price * 100;

    
    sprintf(*message, "%d quarters , %d dimes , %d nickels , %d pennies", num_quarters, num_dimes, num_nickels, num_pennies);
}




int main(){

    double test_cases[NUM_TEST_CASES] = {
        0.49,
        1.27,
        0.75,
        1.31,
        0.83
    };

    for (int i = 0; i < NUM_TEST_CASES; i++){
        double test_case = test_cases[i];

        char *message = malloc(sizeof(char) * 50);
        updateMessageWithChange(&message, test_case);

        printf("Change for [%.2f]: %s\n", test_case, message);
        free(message);
    }


    return 0;
}