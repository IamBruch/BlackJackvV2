cmake_minimum_required(VERSION 3.31)
project(BlackJackV2)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJackV2
        main.cpp
        Game.cpp
        PlayerHand.cpp
        DealerHand.cpp
        Card.cpp
        Deck.cpp
)
