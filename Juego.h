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
    void menuPrincipal();
    void iniciarRonda();
    void turnoJugador(Jugador &jugador);
    void turnoBanca();
    void determinarGanador();
    void agregarJugador();
    void eliminarJugador();
};
#endif // JUEGO_HPP