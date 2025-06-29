//
// Created by emmas on 28. 6. 2025.
//

#ifndef BLACKJACKV2_CARD_H
#define BLACKJACKV2_CARD_H

#include <string>

enum Suit {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
};

class Card {
private:
    Suit suit;
    int number;

public:
    Card(Suit s, int n);

    Suit getSuit() const;
    int getNum() const;

    std::string toString() const;
};



#endif //BLACKJACKV2_CARD_H
