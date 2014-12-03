/*
https://github.com/TheCriticalPath/MP8-BlackJack.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "card.h"
#include "shoe.h"
#define DEFAULT_BANK_AMOUNT 1000
#define TEST true
void print_greeting();
void initialize_game(shoe_t*,int *);
void get_bet(int*,int);
void get_num_decks(int*);
void print_info(int , shoe_t );
/* Enumerations */

int main()
{

    //shoe_t shoe = initial_shoe(DEFAULT_DECK_COUNT);
    shoe_t shoe;
    int stake;
    int bet = 0;
    print_greeting();
    initialize_game(&shoe,&stake);
    print_info(stake,shoe);
    get_bet(&bet,stake);
    while (bet > 0 && stake > 0) {


        stake -= bet;

        if(stake <= 0 ){
            printf("You're busted!  Goodbye!");
        }else{
            print_info(stake,shoe);
            get_bet(&bet,stake);
            while (bet == 0 || bet > stake){
                printf("Invalid entry.\n");
                get_bet(&bet,stake);
            }

            if(bet < 0 && stake > DEFAULT_BANK_AMOUNT) {
               printf("You won $%i! Great job beating the Dealer.",stake);
            }else if(bet < 0) {
               printf("Not bad! You still have $%i. Better to quit before you lose it all.",stake);
            }
        }
    }
    return 0;
}


void initialize_game(shoe_t* shoe,int* stake){
    int deckCount = 0;
    get_num_decks(&deckCount);
    (*shoe) = initial_shoe(deckCount);
    (*stake) = DEFAULT_BANK_AMOUNT;
}
void get_num_decks(int *deckCount){
    printf("How many decks do you wish to play with (1-10)? ");
    scanf("%i",deckCount);
    getchar( ); //remove \n from input
    while((*deckCount) < 1 || (*deckCount) > 10){
        printf("Invalid entry.\n");
        printf("How many decks do you wish to play with (1-10)? ");
        scanf("%i",deckCount);
        getchar( ); //remove \n from input
    }
}

void get_bet(int* bet,int stake){
    printf("Enter your bet (negative to quit): ");
    scanf("%i",bet);
    getchar( ); //remove \n from input
    while ((*bet) == 0 || (*bet) > stake){
        printf("Invalid entry.\n");
        printf("Enter your bet (negative to quit): ");
        scanf("%i",bet);
        getchar( ); //remove \n from input
    }
}

void print_greeting(){
  printf("Welcome to Blackjack!\n\n");
}

void print_info(int stake, shoe_t shoe){
    printf("Your stake is: $%d\n", stake);
    printf("Cards left in shoe: %d\n", cards_left(shoe));
}
