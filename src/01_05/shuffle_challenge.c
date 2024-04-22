#include <stdio.h>
#include <string.h>

int main(){

    char *initial_deck = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    size_t deck_len = strlen(initial_deck);
    size_t half_len = deck_len / 2;

    char shuffled_deck[deck_len];
    strcpy(shuffled_deck, initial_deck); 


    printf("Original deck: %s len %ld\n", initial_deck, deck_len);

    
    char temp[deck_len];



    int it = 0;
    while ( it == 0 || strcmp(shuffled_deck, initial_deck)  != 0 ){
        it++;

            
        int shuffled_idx = 0;
        for (int initial_idx = 0; initial_idx < half_len; initial_idx++){
            
            temp[shuffled_idx] = shuffled_deck[initial_idx];
            temp[shuffled_idx + 1] = shuffled_deck[half_len + initial_idx];
            shuffled_idx += 2;
        }

        strncpy(shuffled_deck, temp, deck_len); 

        printf("%2d: %s\n", it, shuffled_deck);


        // debug
        if (it == 50){
            printf("NOT FOUND\n");
            break;
        }
    }

    printf("Deck restored after %d iterations\n", it);


    return 0;
}