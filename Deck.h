//
// Created by emmas on 28. 6. 2025.
//

#ifndef BLACKJACKV2_DECK_H
#define BLACKJACKV2_DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    Card drawCard();
    void shuffle();
};


#endif //BLACKJACKV2_DECK_H
