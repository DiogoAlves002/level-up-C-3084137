#include <stdio.h>
#include <string.h>

int main(){

    char *initial_deck = "ABCDEFGHIJKLMNOPQRSTVUWXYZ";
    char *shuffled_deck = initial_deck;

    int deck_len = strlen(initial_deck);
    int half_len = deck_len / 2;

    printf("Original deck: %s\n", initial_deck);

    
    char temp[deck_len];
    temp[0] = initial_deck[0];
    temp[deck_len - 1] = initial_deck[deck_len - 1];


    int it = 0;
    while ( it == 0 || shuffled_deck != initial_deck){
        it++;

        int e = 1;
        for (int i = 1; i < half_len - 1; i ++){
            temp[e] = shuffled_deck[half_len + i - 1];
            temp[e + 1] = shuffled_deck[i];
            e += 2;
        }

        shuffled_deck = temp;

        printf("%d: %s\n", it, shuffled_deck);



        // debug
        if (it == 30){
            break;
        }
    }

    printf("Deck restored after %d iterations\n", it);


    return 0;
}