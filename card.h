#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

typedef enum Suit_Enum{
    Hearts,
    Diamonds,
    Spades,
    Clubs
} Card_Suits;
typedef enum Value_Enum{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
} Card_Values;

/* Constants */
const int ArrCardValues[] = {1,2,3,4,5,6,7,8,9,10,10,10,10,11};
const char* ArrCardValueName[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const char* ArrCardSuitName[] = {"Hearts","Diamonds","Spades","Clubs"};
/* Structures */
typedef struct card_t card_t;
struct card_t{
    Card_Suits Suit;
    Card_Values Value;
};
/* Prototypes */
void print_card(card_t);
int points(card_t);

#endif // CARD_H_INCLUDED
