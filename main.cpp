#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "dado.h"
#include "jugador.h"
#include "tablero.h"

using namespace std;

void iniciarJuego() {
    srand(time(0));

    int cantidadJugadores;
    cout << "Ingrese la cantidad de jugadores (2-4): ";
    cin >> cantidadJugadores;
    while (cantidadJugadores < 2 || cantidadJugadores > 4) {
        cout << "Cantidad inválida. Ingrese la cantidad de jugadores (2-4): ";
        cin >> cantidadJugadores;
    }

    tablero t;
    vector<jugador> jugadores;
    for (int i = 1; i <= cantidadJugadores; i++) {
        string nombre;
        cout << "Ingrese el nombre del jugador " << i << ": ";
        cin >> nombre;
        jugadores.emplace_back(nombre);
    }

    dado d1, d2, d3, d4;
    int turno = 0;
    char continuar = 's';

    while (true) {
        jugador& jugadorActual = jugadores[turno];
        cout << "\nEs el turno de " << jugadorActual.obtenerNombre() << endl;

        bool seguirLanzando = true;
        while (seguirLanzando) {
            d1.lanzar();
            d2.lanzar();
            d3.lanzar();
            d4.lanzar();
            d1.mostrar(1);
            d2.mostrar(2);
            d3.mostrar(3);
            d4.mostrar(4);

            int par1, par2, op;
            cout << "¿Qué parejas de dados quieres sumar?" << endl;
            cout << "1. Dado 1 + Dado 2 y Dado 3 + Dado 4" << endl;
            cout << "2. Dado 1 + Dado 3 y Dado 2 + Dado 4" << endl;
            cout << "3. Dado 1 + Dado 4 y Dado 2 + Dado 3" << endl;
            cin >> op;

            switch (op) {
                case 1:
                    par1 = d1.obtenerValor() + d2.obtenerValor();
                    par2 = d3.obtenerValor() + d4.obtenerValor();
                    break;
                case 2:
                    par1 = d1.obtenerValor() + d3.obtenerValor();
                    par2 = d2.obtenerValor() + d4.obtenerValor();
                    break;
                case 3:
                    par1 = d1.obtenerValor() + d4.obtenerValor();
                    par2 = d2.obtenerValor() + d3.obtenerValor();
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    continue;
            }
            cout << "Suma 1: " << par1 << " Suma 2: " << par2 << endl;

            cout << "¿Seguir lanzando (s/n)? ";
            cin >> continuar;
            if (continuar != 's') {
                seguirLanzando = false;
            }
        }

        if (++turno == cantidadJugadores) {
            turno = 0;
        }
    }
}

int main() {
    iniciarJuego();
    return 0;
}
