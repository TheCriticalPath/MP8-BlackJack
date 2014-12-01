#ifndef SHOE_H_INCLUDED
#define SHOE_H_INCLUDED
#define DEFAULT_DECK_SIZE 52
#define DEFAULT_DECK_COUNT 1
#include "shoe.h"
#include "card.h"
typedef struct shoe_t shoe_t;
struct shoe_t {
    int num_decks;
    int next_card;
    card_t *cards;
    //card_t* cards = malloc(DEFAULT_DECK_COUNT * DEFAULT_DECK_SIZE * sizeof(card_t));
};
shoe_t initial_shoe(int);
void reshuffle(shoe_t *shoe);
card_t draw_card(shoe_t *shoe);
int cards_left(shoe_t shoe);
void free_shoe(shoe_t *shoe);
#endif // SHOE_H_INCLUDED
