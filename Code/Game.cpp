//
// Created by emmas on 29. 6. 2025.
//

#include "Game.h"
#include <iostream>

Game::Game() : gameRunning(false) {
    initializeDeck();
}

void Game::initializeDeck() {
    deck = Deck();
}

void Game::startGame(){
    gameRunning = true;

    playerHand.hit(deck);
    dealerHand.hit(deck);
    playerHand.hit(deck);
    dealerHand.hit(deck);


    std::cout << "Your cards: ";
    playerHand.showHand();
    dealerHand.showFirstCard();

    loop();
}

void Game::bet(int amount) {

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
    if (playAgain()) {
        startGame();
    } else {
        gameRunning = false;
    }
}

void Game::dealerWin(){
    std::cout << "Dealer win!" << std::endl;
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