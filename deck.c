#include "deck.h"
#include "card.h"
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
deck_t initializeDeck(deck_t deck){
    int cntSuit = 0;
    int cntValue = 0;
    int posCard=0;
    int sizSuit = 0;
    int sizValue = 0;
    sizSuit = sizeof(ArrCardSuitName)/sizeof(ArrCardSuitName[0]);
    sizValue = sizeof(ArrCardValues)/sizeof(ArrCardValues[0])-1;
    for(cntSuit = 0; cntSuit < sizSuit;cntSuit++){
        card_t card;
        card.Suit = cntSuit;
        for(cntValue = 0; cntValue<sizValue;cntValue++){
          card.Value = cntValue;
          posCard = cntValue+(cntSuit*sizValue);
          deck.Cards[posCard] = card;
        }
    }
    return deck;
}
//Knuth Shuffle
deck_t shuffleDeck(deck_t deck){
    /* Initialize random number generator */
    time_t t;
    srand((unsigned) time(&t));
    int sizDeck = 0;
    int lcv = 0;
    int rnd = 0;
    int cntShuffle = rand() % 4;
    card_t tmpCard;
    sizDeck = sizeof(deck.Cards)/sizeof(deck.Cards[0]);

    for(lcv = sizDeck-1; lcv > 0; lcv--){
        rnd = (rand() % lcv+1);
        tmpCard = deck.Cards[lcv];
        deck.Cards[lcv] = deck.Cards[rnd];
        deck.Cards[rnd] = tmpCard;
    }
    return deck;
}

void printDeck(deck_t deck){
    int cntCards = 0;
    int sizDeck = 0;
    sizDeck = sizeof(deck.Cards)/sizeof(deck.Cards[0]);
    for(cntCards=0;cntCards<sizDeck;cntCards++){
        print_card(deck.Cards[cntCards]);
    }
}
