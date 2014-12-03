#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED
#include "card.h"
typedef struct hand_t hand_t;
struct hand_t {
    card_t cards[21];
    int num_cards;
};

hand_t empty_hand();
void print_hand(hand_t);
void add_card_to_hand(hand_t*,card_t);
int blackjack_value(hand_t);
#endif // HAND_H_INCLUDED
