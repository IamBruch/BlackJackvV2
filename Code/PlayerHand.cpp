//
// Created by emmas on 29. 6. 2025.
//

#include "PlayerHand.h"

#include <iostream>

PlayerHand::PlayerHand() : sumOfCards(0), chips(0) {}

PlayerHand::PlayerHand(int amountOfChips) : sumOfCards(0), chips(amountOfChips) {}

int PlayerHand::getSum() const {return sumOfCards;}

void PlayerHand::showHand() const {
    std::cout << std::endl;
    for (Card c : handCards){
        std::cout << c.toString() << std::endl;
    }
    std::cout << std::endl;
}

void PlayerHand::clearHand() {
    handCards.clear();
    sumOfCards = 0;
}

void PlayerHand::hit(Deck& deck){
    Card drawnCard = deck.drawCard();
    handCards.push_back(drawnCard);
    updateSum();
}

void PlayerHand::updateSum() {
    sumOfCards = 0;

    for (const Card& c : handCards){
        int value = c.getNum();
        if (value > 10) value = 10;

        sumOfCards += value;
    }
}