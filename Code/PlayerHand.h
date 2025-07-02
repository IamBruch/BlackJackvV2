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
    int chips;
public:
    PlayerHand();
    explicit PlayerHand(int amountOfChips);

    int getSum() const;

    int getChips() const;
    int minusChips(int amount);
    int plusChips(int amount);

    void showHand() const;
    void clearHand();

    void hit(Deck& deck);
    void updateSum();
};


#endif //BLACKJACKV2_PLAYERHAND_H
