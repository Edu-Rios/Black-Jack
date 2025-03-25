#include "Baraja.h"
#include <cstdlib>

Baraja::Baraja() {
    inicializar();
}

void Baraja::inicializar() {
    for (int palo = 0; palo < 4; palo++) {
        for (int carta = 0; carta < 13; carta++) {
            cartas[palo][carta] = (carta >= 10) ? 10 : carta + 1;
        }
    }
}

int Baraja::repartirCarta() {
    int palo, carta;
    do {
        palo = rand() % 4;
        carta = rand() % 13;
    } while (cartas[palo][carta] == 0);
    int valor = cartas[palo][carta];
    cartas[palo][carta] = 0;
    return valor;
}
