#include "jugador.h"
#include "tablero.h"

using namespace std;

jugador::jugador(string _nombre) : nombre(_nombre), fichasActivas(0) {
    for (int i = 2; i <= 12; i++) {
        posiciones[i] = -1;
    }
}

string jugador::obtenerNombre() const {
    return nombre;
}

int jugador::obtenerPosicion(int columna) const {
    return posiciones.at(columna);
}

bool jugador::puedeAgregarFicha() const {
    return fichasActivas < 3;
}

void jugador::agregarFicha(int columna) {
    if (posiciones[columna] == -1) {
        fichasActivas++;
    }
}

void jugador::moverFicha(int columna, int avance) {
    posiciones[columna] += avance;
    if (posiciones[columna] == 0) {
        agregarFicha(columna);
    }
}

void jugador::guardarPosiciones(tablero &t) {
    for (auto& pos : posiciones) {
        if (pos.second >= 0) {
            t.colocarFicha(pos.first, pos.second, nombre[0]);
        }
    }
    fichasActivas = 0;
}

bool jugador::puedeMoverFicha(int columna) {
    return posiciones[columna] != -1;
}

void jugador::perderProgreso() {
    for (auto& pos : posiciones) {
        pos.second = -1;
    }
    fichasActivas = 0;
}
