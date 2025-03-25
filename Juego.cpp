#include "Juego.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

Juego::Juego() : puntosBanca(0) {
    cout << "¿Cuantos jugadores? (1-4): ";
    cin >> numJugadores;
    for (int i = 0; i < numJugadores; i++) {
        string nombre;
        float dinero = 10000;
        cout << "Nombre del jugador " << i+1 << ": ";
        cin >> nombre;
        /*
        cout << "Dinero inicial: ";
        cin >> dinero;
        */
        jugadores[i] = Jugador(nombre, dinero);
    }
    baraja.inicializar();
}

void Juego::iniciar() {
    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].pedirCarta(baraja);
        jugadores[i].pedirCarta(baraja);
    }
    turnoBanca();
    determinarGanador();
}

void Juego::pedirCarta(Jugador &jugador) {
    int carta = baraja.repartirCarta();
    jugador.recibirCarta(carta);
}

void Juego::turnoBanca() {
    while (puntosBanca < 17) {
        puntosBanca += baraja.repartirCarta();
    }
    cout << "La banca tiene " << puntosBanca << " puntos"<<endl;
}

void Juego::determinarGanador() {
    for (int i = 0; i < numJugadores; i++) {
        int puntos = jugadores[i].getPuntos();
        if (puntos > 21) {
            cout << jugadores[i].getNombre() << " perdio"<<endl;
        } else if (puntosBanca > 21 || puntos > puntosBanca) {
            cout << jugadores[i].getNombre() << " gano"<<endl;
            jugadores[i].ganarApuesta();
        } else {
            cout << jugadores[i].getNombre() << " perdio contra la banca"<<endl;
        }
    }
}
