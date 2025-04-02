#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador() : nombre(""), dinero(0), puntos(0) {}

Jugador::Jugador(string nom, float din) : nombre(nom), dinero(din), puntos(0) {}

void Jugador::pedirCarta(Baraja &baraja) {
    int carta = baraja.repartirCarta();
    puntos += carta;
    cout << nombre << " recibio una carta de " << baraja.getPalo() << " con valor " << carta << ". Total: " << puntos << endl;
}

void Jugador::resetearPuntos() {
    puntos = 0;
}

int Jugador::getPuntos() const {
    return puntos;
}

string Jugador::getNombre() const {
    return nombre;
}
