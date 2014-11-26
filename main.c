#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "card.h"
#include "deck.h"
#define DEFAULT_NUM_DECKS 1
#define DEFAULT_BANK_AMOUNT 1000
/* Enumerations */

int main()
{
    deck_t deck;
    initializeDeck(deck);
    card_t card;
    card.Suit = Clubs;
    card.Value = Ace_11;
    print_card(card);
    printDeck(deck);
        printf("Hello world!\n");
    return 0;
}

