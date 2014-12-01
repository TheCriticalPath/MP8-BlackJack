/*
https://github.com/TheCriticalPath/MP8-BlackJack.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "card.h"
#include "shoe.h"
#define DEFAULT_BANK_AMOUNT 1000
#define TEST true
/* Enumerations */

int main()
{

    shoe_t shoe = initial_shoe(DEFAULT_DECK_COUNT);
    if (TEST){
        //printShoe(shoe);
        printf("Value of first card: %i\n",points(shoe.cards[0]));
        print_card(shoe.cards[0]);
    }
    return 0;
}

