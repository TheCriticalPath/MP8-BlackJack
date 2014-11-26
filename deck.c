#include "deck.h"
#include "card.h"
#include <stdlib.h>
#include <ctype.h>
deck_t initializeDeck(deck_t deck){
    int cntSuit = 0;
    int cntValue = 0;
    for(cntSuit = 0; cntSuit < sizeof(ArrCardSuitName)/sizeof(ArrCardSuitName[0]);cntSuit++){
        card_t card;
        card.Suit = cntSuit;
        for(cntValue = 0; cntValue<sizeof(ArrCardValues)/sizeof(ArrCardValues[0])-1;cntValue++){
          card.Value = cntValue;
          deck.Cards[cntValue+(cntSuit*sizeof(ArrCardValues)/sizeof(ArrCardValues[0]))] = card;
        }
    }
    return deck;
}

void printDeck(deck_t deck){
    int cntCards = 0;
    for(cntCards=0;cntCards<sizeof(deck)/sizeof(deck[0]);cntCards++){
        print_card(deck.Cards[cntCards]);
    }
}
