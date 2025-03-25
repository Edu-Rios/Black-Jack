#include "Jugador.h"
#include "Baraja.h"
#include <iostream>
using namespace std;

Jugador::Jugador() : nombre(""), dinero(0), puntos(0) {}

Jugador::Jugador(string nombre, float dinero) : nombre(nombre), dinero(dinero), puntos(0) {}

void Jugador::pedirCarta(Baraja &baraja) {
    recibirCarta(baraja.repartirCarta());
}

void Jugador::recibirCarta(int valor) {
    puntos += valor;
    cout << nombre << " recibe una carta de " << valor << ". Total: " << puntos << " puntos.\n";
}

int Jugador::getPuntos() const {
    return puntos;
}

string Jugador::getNombre() const {
    return nombre;
}

void Jugador::ganarApuesta() {
    dinero += 10; // Ajuste según apuestas
}
