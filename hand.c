#include "hand.h"
#include "card.h"
#include <stdbool.h>
#include <stdio.h>
hand_t empty_hand(){
    hand_t hand;
    hand.num_cards = 0;
    return hand;
}
void print_hand(hand_t hand){
    int lcv;
    for(lcv = 0; lcv < hand.num_cards; lcv++){
        print_card(hand.cards[lcv]);
    }
    printf("Score = %d\n",blackjack_value(hand));
}
void add_card_to_hand(hand_t *hand, card_t card){
    hand->cards[hand->num_cards] = card;
    hand->num_cards++;
}
int blackjack_value(hand_t hand){
    int total;
    int lcv;
    int value;
    bool isAce;
    total = 0;
    isAce = false;
    for(lcv = 0; lcv < hand.num_cards; lcv++){
        value = points(hand.cards[lcv]);
        if (value == 1){
            isAce = true;
        }
        total += value;
    }
    return (isAce && total <= 11) ? total + 10 : total;
}
