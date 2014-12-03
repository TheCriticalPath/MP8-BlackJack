/*
https://github.com/TheCriticalPath/MP8-BlackJack.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "card.h"
#include "shoe.h"
#include "hand.h"
#define DEFAULT_BANK_AMOUNT 1000.00
#define TEST true
void print_greeting();
void initialize_game(shoe_t*,double *);
void get_bet(double*,double);
void get_num_decks(int*);
void print_info(double , shoe_t );
char get_user_action();
/* Enumerations */

int main()
{
    //shoe_t shoe = initial_shoe(DEFAULT_DECK_COUNT);
    hand_t player;
    hand_t dealer;

    char action;
    bool isBlackJack;


    shoe_t shoe;
    double stake;
    double bet = 0;
    print_greeting();
    initialize_game(&shoe,&stake);
    print_info(stake,shoe);
    get_bet(&bet,stake);
    while (bet > 0 && stake > 0) {
        isBlackJack = false;
        player = empty_hand();
        dealer = empty_hand();

        add_card_to_hand(&player,draw_card(&shoe));
        add_card_to_hand(&dealer,draw_card(&shoe));
        add_card_to_hand(&player,draw_card(&shoe));
        add_card_to_hand(&dealer,draw_card(&shoe));

        printf("The dealer is showing ");
        print_card(dealer.cards[0]);
        printf("\n");
        printf("Your cards:\n");
        print_hand(player);
        if (blackjack_value(player) == 21){
            isBlackJack = true;
        }else{
            action = get_user_action();
            while (action == 'H'){
                add_card_to_hand(&player,draw_card(&shoe));
                printf("Your cards:\n");
                print_hand(player);
                if (blackjack_value(player) >= 21){
                    break;
                }else{
                    action = get_user_action();
                }
            }
        }
        //finish out players hand.
        if(blackjack_value(player) <= 21){
        //play dealers hand
            if(!isBlackJack){
                while(blackjack_value(dealer) < 17){
                    add_card_to_hand(&dealer,draw_card(&shoe));
                }
            }
            if(blackjack_value(dealer) > 21){
                printf("Dealer busts.  You win %.2lf\n",bet);
                stake += bet;
            }else if (blackjack_value(dealer) == blackjack_value(player)){
                printf("Game is a push!\n");
            }else if (blackjack_value(dealer) < blackjack_value(player)){
                 if(isBlackJack){
                    printf("Blackjack!  You win %.2lf\n",bet*1.5);
                    stake += (bet * 1.5);
                 }else{
                    printf("Dealer had %d\n",blackjack_value(dealer));
                    printf("You win %.2lf\n",bet);
                    stake += (bet );
                 }
            }else{
                printf("Dealer wins with %d\n", blackjack_value(dealer));
                stake -= bet;
            }

        } else {
            printf("You busted. You lose.\n");
            stake -= bet;
        }
        //check score

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
               printf("You won $%.2lf! Great job beating the Dealer.",stake);
            }else if(bet < 0) {
               printf("Not bad! You still have $%.2lf. Better to quit before you lose it all.",stake);
            }
        }
    }
    return 0;
}


void initialize_game(shoe_t* shoe,double* stake){
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
char get_user_action(){
    char action;
    printf("Do you want to (H)it or (S)tand? ");
    scanf (" %c",&action); // space before %c to ignore whitespace.
    getchar( ); //remove \n from input
    action = toupper(action);
    while (action != 'H' && action != 'S'){
        printf("Invalid entry.\n");
        printf("Do you want to (H)it or (S)tand? ");
        scanf (" %c",&action); // space before %c to ignore whitespace.
        action = toupper(action);
    }
    return action;
}
void get_bet(double* bet,double stake){
    printf("Enter your bet (negative to quit): ");
    scanf("%lf",bet);
    getchar( ); //remove \n from input
    while ((*bet) == 0 || (*bet) > stake){
        printf("Invalid entry.\n");
        printf("Enter your bet (negative to quit): ");
        scanf("%lf",bet);
        getchar( ); //remove \n from input
    }
}

void print_greeting(){
  printf("Welcome to Blackjack!\n\n");
}

void print_info(double stake, shoe_t shoe){
    printf("Your stake is: $%.2lf\n", stake);
    printf("Cards left in shoe: %d\n", cards_left(shoe));
}
