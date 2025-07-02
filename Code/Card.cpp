//
// Created by emmas on 28. 6. 2025.
//

#include "Card.h"

#include <string>

Card::Card(Suit s, int n) : suit(s), number(n) {}

Suit Card::getSuit() const {return suit;}
int Card::getNum() const {return number;}

std::string Card::toString() const {
    std::string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    return suits[suit] + " of " + std::to_string(number);
}