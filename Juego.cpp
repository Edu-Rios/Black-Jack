#include "Juego.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Juego::Juego() : puntosBanca(0), numJugadores(0) {
    srand(time(NULL)); // Semilla random
}

void Juego::menuPrincipal() {
    char opcion;
    do {
        cout << "===== MENU PRINCIPAL =====" << endl;
        cout << "1. Agregar jugador" << endl;
        cout << "2. Eliminar jugador" << endl;
        cout << "3. Jugar ronda" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                agregarJugador();
                break;
            case '2':
                eliminarJugador();
                break;
            case '3':
                if (numJugadores > 0) {
                    iniciarRonda();
                } else {
                    cout << "No hay jugadores. Agrega al menos uno." << endl;
                }
                break;
            case '4':
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }

    } while (opcion != '4');
}

void Juego::agregarJugador() {
    if (numJugadores >= 4) {
        cout << "Maximo 4 jugadores." << endl;
        return;
    }
    string nombre;
    float dinero;
    cout << "Nombre del jugador: ";
    cin >> nombre;
    cout << "Dinero inicial: ";
    cin >> dinero;
    jugadores[numJugadores] = Jugador(nombre, dinero);
    numJugadores++;
}

void Juego::eliminarJugador() {
    if (numJugadores == 0) {
        cout << "No hay jugadores." << endl;
        return;
    }
    int pos;
    cout << "Que jugador deseas eliminar? (1-" << numJugadores << "): ";
    cin >> pos;
    if (pos < 1 || pos > numJugadores) {
        cout << "Numero invalido." << endl;
        return;
    }
    for (int i = pos - 1; i < numJugadores - 1; i++) {
        jugadores[i] = jugadores[i + 1];
    }
    numJugadores--;
    cout << "Jugador eliminado.";
}

void Juego::iniciarRonda() {
    puntosBanca = 0;
    baraja.inicializar();

    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].resetearPuntos();
        jugadores[i].pedirCarta(baraja);
        jugadores[i].pedirCarta(baraja);
        turnoJugador(jugadores[i]);
    }
    turnoBanca();
    determinarGanador();
}

void Juego::turnoJugador(Jugador &jugador) {
    char opcion;
    do {
        cout << jugador.getNombre() << " tienes " << jugador.getPuntos() << " puntos" << endl;
        cout << "Quieres otra carta? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            jugador.pedirCarta(baraja);
        } else if (opcion != 'n' && opcion != 'N') {
            cout << "Opcion invalida" << endl;
        }
    } while (opcion == 's' || opcion == 'S');
}

void Juego::turnoBanca() {
    cout << "Turno de la banca..." << endl;
    while (puntosBanca < 17) {
        int carta = baraja.repartirCarta();
        puntosBanca += carta;
        cout << "La banca recibe " << carta << " puntos. Total: " << puntosBanca << endl;
    }
    cout << "Banca termina con " << puntosBanca << " puntos"<<endl;
}

void Juego::determinarGanador() {
    for (int i = 0; i < numJugadores; i++) {
        int puntos = jugadores[i].getPuntos();
        if (puntos > 21) {
            cout << jugadores[i].getNombre() << " perdio por pasarse de 21."<<endl;
        } else if (puntosBanca > 21 || puntos > puntosBanca) {
            cout << jugadores[i].getNombre() << " gano!"<<endl;
        } else if (puntos == puntosBanca) {
            cout << jugadores[i].getNombre() << " empato con la banca"<<endl;
        } else {
            cout << jugadores[i].getNombre() << " perdio contra la banca"<<endl;
        }
    }
}