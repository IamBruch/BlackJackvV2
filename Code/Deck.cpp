//
// Created by emmas on 28. 6. 2025.
//

#include "Deck.h"

#include <iostream>
#include <random>
#include <algorithm>

Deck::Deck() {
    for (int s = HEARTS; s <= CLUBS; s++){
        for (int n = 1; n <= 13; n++){
            int x = n;
            if (x > 10){
                x = 10;
            }
            cards.emplace_back(static_cast<Suit>(s), x);
        }
    }

    shuffle();
}

Card Deck::drawCard(){
    if (cards.empty()){
        std::cout << "Deck is empty!" << std::endl; //this prob wont happen at blackjack LOL
        return Card(CLUBS, 0);
    }

    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

void Deck::shuffle(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards.begin(), cards.end(), gen);
}