#include "Baraja.h"
#include <cstdlib>
#include <ctime>

Baraja::Baraja() {
    inicializar();
    srand(time(nullptr));
}

void Baraja::inicializar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baraja[i][j] = (j + 1);
            if (baraja[i][j] > 10)
                baraja[i][j] = 10; // Figuras valen 10
        }
    }
}

int Baraja::repartirCarta() {
    int palo, carta;
    do {
        palo = rand() % 4;
        carta = rand() % 13;
    } while (baraja[palo][carta] == 0);

    int valor = baraja[palo][carta];
    baraja[palo][carta] = 0;

    switch (palo) {
        case 0: ultimoPalo = "Corazones "; break;
        case 1: ultimoPalo = "Diamantes "; break;
        case 2: ultimoPalo = "Picas "; break;
        case 3: ultimoPalo = "Treboles "; break;
        default: ultimoPalo = "";
    }

    return valor;
}

std::string Baraja::getPalo() const {
    return ultimoPalo;
}
