cmake_minimum_required(VERSION 3.20)
project(Poker_card_game)

set(CMAKE_CXX_STANDARD 23)

add_executable(Poker_card_game main.cpp card.h card.cpp deck.h deck.cpp)
