//
// Created by emmas on 29. 6. 2025.
//

#ifndef BLACKJACKV2_PLAYERHAND_H
#define BLACKJACKV2_PLAYERHAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>

class PlayerHand {
protected:
    std::vector<Card> handCards;
    int sumOfCards;
public:
    PlayerHand();

    int getSum() const;
    void showHand() const;

    void hit(Deck& deck);
    void updateSum();
};


#endif //BLACKJACKV2_PLAYERHAND_H
