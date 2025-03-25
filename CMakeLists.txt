cmake_minimum_required(VERSION 3.30)
project(blackjack)

set(CMAKE_CXX_STANDARD 20)

add_executable(blackjack main.cpp
        Juego.cpp
        Juego.h
        Jugador.cpp
        Jugador.h
        Baraja.cpp
        Baraja.h)
