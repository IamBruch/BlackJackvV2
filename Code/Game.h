//
// Created by emmas on 29. 6. 2025.
//

#ifndef BLACKJACKV2_GAME_H
#define BLACKJACKV2_GAME_H

#include "Deck.h"
#include "PlayerHand.h"
#include "DealerHand.h"
#include "DataManager.h"

class Game {
private:
    Deck deck;
    PlayerHand playerHand;
    DealerHand dealerHand;
    bool isBet = false;
    int betAmount = 0;
    bool gameRunning;
    DataManager dataManager;

    bool isLoggedin = false;
public:

    Game();
    void initializeDeck();
    void startGame();
    bool bet(int amount);

    void playerTurn();
    void dealerTurn();
    void loop();
    void playerWin();
    void dealerWin();
    bool playAgain();

};


#endif //BLACKJACKV2_GAME_H
