cmake_minimum_required(VERSION 3.31)
project(BlackJackV2)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJackV2
        Code/main.cpp
        Code/Game.cpp
        Code/DataManager.cpp
        Code/PlayerHand.cpp
        Code/DealerHand.cpp
        Code/Card.cpp
        Code/Deck.cpp
)
