#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

typedef struct hand_t hand_t;
struct hand_t{
    card_t cards[21];
    int num_cards;
};

#endif // HAND_H_INCLUDED
