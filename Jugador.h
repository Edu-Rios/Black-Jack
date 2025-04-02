#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>
#include "Baraja.h"

class Jugador {
private:
    std::string nombre;
    float dinero;
    int puntos;

public:
    Jugador();
    Jugador(std::string nom, float din);

    void pedirCarta(Baraja &baraja);
    void resetearPuntos();

    int getPuntos() const;
    std::string getNombre() const;
};

#endif // JUGADOR_HPP
