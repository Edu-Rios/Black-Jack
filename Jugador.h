#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>

class Jugador {
private:
    std::string nombre;
    float dinero;
    int puntos;

public:
    Jugador();
    Jugador(std::string nombre, float dinero);
    void pedirCarta(class Baraja &baraja);
    void recibirCarta(int valor);
    int getPuntos() const;
    std::string getNombre() const;
    void ganarApuesta();
};

#endif // JUGADOR_HPP
