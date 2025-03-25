// ==================== Juego.hpp ====================
#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "Jugador.h"
#include "Baraja.h"

class Juego {
private:
    Jugador jugadores[4];
    Baraja baraja;
    int numJugadores;
    int puntosBanca;

public:
    Juego();
    void iniciar();
    void pedirCarta(Jugador &jugador);
    void turnoBanca();
    void determinarGanador();
};

#endif // JUEGO_HPP