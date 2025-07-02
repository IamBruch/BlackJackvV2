//
// Created by emmas on 29. 6. 2025.
//

#include "Game.h"
#include <iostream>

Game::Game() : gameRunning(false) {
    initializeDeck();
    playerHand.plusChips(100);
}

void Game::initializeDeck() {
    deck = Deck();
}

void Game::startGame(){
    gameRunning = true;
    char choice;
    if (!isLoggedin) {
        dataManager.login();
        isLoggedin = true;

        std::cout << "Do u want to gamble? (y/n): ";
        std::cin >> choice;
    }

    playerHand.hit(deck);
    dealerHand.hit(deck);
    playerHand.hit(deck);
    dealerHand.hit(deck);



    if (choice == 'y') {
        isBet = true;
        std::cout << "Enter bet amount: ";
        int betAmount;
        std::cin >> betAmount;
        bet(betAmount);
    }

    std::cout << "Your cards: ";
    playerHand.showHand();
    dealerHand.showFirstCard();

    loop();
}

bool Game::bet(int amount) {
    if (amount > playerHand.getChips()) {
        std::cout << "You don't have enough chips to bet that amount!" << std::endl;
        return false;
    }

    playerHand.minusChips(amount);
    betAmount = amount;
    return true;
}

void Game::playerTurn(){
    char choice;
    bool playerTurnEnd = false;

    while (!playerTurnEnd && playerHand.getSum() < 21){
        std::cout << "Hit or stand? (h/s): ";
        std::cin >> choice;

        if (choice == 'h'){
            playerHand.hit(deck);
            std::cout << "Your cards: ";
            playerHand.showHand();
        } else if (choice == 's'){
            playerTurnEnd = true;
        }

    }
}

void Game::dealerTurn(){
    while (dealerHand.getSum() < 17){
        dealerHand.hit(deck);
    }

    std::cout << "Dealer's final hand: ";
    dealerHand.showHand();
}

void Game::loop(){
    while (gameRunning) {
        playerTurn();

        if (playerHand.getSum() > 21) {
            dealerWin();
            break;
        }
        dealerTurn();

        if (dealerHand.getSum() > 21) {
            playerWin();
        } else if (playerHand.getSum() > dealerHand.getSum()) {
            playerWin();
        } else if (dealerHand.getSum() > playerHand.getSum()) {
            dealerWin();

        }
    }
}

void Game::playerWin() {
    std::cout << "You win!" << std::endl;
    if (isBet) {
        betAmount = betAmount * 2;
        playerHand.plusChips(betAmount);
    }

    std::cout << "You won " << betAmount << " chips." << std::endl;
    std::cout << "Your remaining chips: " << playerHand.getChips() << std::endl;

    if (playAgain()) {
        startGame();
    } else {
        gameRunning = false;
    }
}

void Game::dealerWin(){
    std::cout << "Dealer win!" << std::endl;
    if (isBet) {
        betAmount = 0; // Player loses the bet
    }
    std::cout << "You lost " << betAmount << " chips." << std::endl;
    std::cout << "Your remaining chips: " << playerHand.getChips() << std::endl;

    if (playAgain()) {
        startGame();
    } else {
        gameRunning = false;
    }
}

bool Game::playAgain() {
    std::cout << "Do you want to play again? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice) {
        playerHand.clearHand();
        dealerHand.clearHand();
        return true;
    } else {
        return false;
    }
}
