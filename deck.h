#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include "card.h"
typedef struct deck_t deck_t;
struct deck_t{
    card_t Cards[52];
};
deck_t initializeDeck(deck_t deck);
void printDeck(deck_t deck);
#endif // DECK_H_INCLUDED