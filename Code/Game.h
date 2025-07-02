//
// Created by emmas on 29. 6. 2025.
//

#ifndef BLACKJACKV2_GAME_H
#define BLACKJACKV2_GAME_H

#include "Deck.h"
#include "PlayerHand.h"
#include "DealerHand.h"

class Game {
    Deck deck;
    PlayerHand playerHand;
    DealerHand dealerHand;
    bool gameRunning;
public:

    Game();
    void initializeDeck();
    void startGame();
    void bet(int amount);

    void playerTurn();
    void dealerTurn();
    void loop();
    void playerWin();
    void dealerWin();
    bool playAgain();

};


#endif //BLACKJACKV2_GAME_H
