#include "shoe.h"
#include "card.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

shoe_t initial_shoe(int num_decks){
    int cntDeck = 0;
    int cntSuit = 0;
    int cntValue = 0;
    int posCard=0;
    int sizSuit = 0;
    int sizValue = 0;
    shoe_t shoe;
    shoe.cards = malloc(num_decks * DEFAULT_DECK_SIZE * sizeof(card_t));
    shoe.num_decks = num_decks;
    shoe.next_card = 0;
    sizSuit = sizeof(ArrCardSuitName)/sizeof(ArrCardSuitName[0]);
    sizValue = sizeof(ArrCardValues)/sizeof(ArrCardValues[0]);
    for(cntDeck = 0; cntDeck < num_decks; cntDeck++){
        for(cntSuit = 0; cntSuit < sizSuit;cntSuit++){
            card_t card;
            card.Suit = cntSuit;
            for(cntValue = 0; cntValue<sizValue;cntValue++){
              card.Value = cntValue;
              posCard = cntValue+(cntSuit*sizValue);
              shoe.cards[posCard] = card;
            }
        }
    }

    reshuffle(&shoe);

    return shoe;
}

card_t draw_card(shoe_t *shoe){
    card_t card;
    if (shoe->next_card >= shoe->num_decks * DEFAULT_DECK_SIZE){
        shoe->next_card = 0;
        reshuffle(shoe);
    }
    card = shoe->cards[shoe->next_card];
    shoe->next_card++;
    return card;
}

int cards_left(shoe_t shoe){
    return (shoe.num_decks * DEFAULT_DECK_SIZE)-shoe.next_card;
}

//Knuth Shuffle
 void reshuffle(shoe_t *shoe){
    printf("SHUFFLING\n");
    /* Initialize random number generator */
    //time_t t;
    //srand((unsigned) time(&t));
    srand(time(0));
    int sizShoe = shoe->num_decks * DEFAULT_DECK_SIZE;
    int lcv = 0;
    int rnd = 0;
    card_t tmpCard;

    for(lcv = sizShoe-1; lcv > 0; lcv--){
        rnd = (rand() % lcv);
        if(lcv != rnd){
            tmpCard = shoe->cards[lcv];
            shoe->cards[lcv] = shoe->cards[rnd];
            shoe->cards[rnd] = tmpCard;
        }
    }
}

void free_shoe(shoe_t *shoe){
    free(shoe);
}
/*
void printShoe(deck_t deck){
    int cntCards = 0;
    int sizDeck = 0;
    sizDeck = sizeof(deck.Cards)/sizeof(deck.Cards[0]);
    for(cntCards=0;cntCards<sizDeck;cntCards++){
            printf("%d. ", cntCards+1);
        print_card(deck.Cards[cntCards]);
    }
}
*/
