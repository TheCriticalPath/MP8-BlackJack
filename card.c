#include "card.h"
#include <stdio.h>

void print_card(card_t card){
    printf("%s of %s\n",ArrCardValueName[card.Value],ArrCardSuitName[card.Suit]);
}
