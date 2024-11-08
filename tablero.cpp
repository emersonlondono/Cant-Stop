#include "tablero.h"
#include <iostream>
#include <iomanip>  // Para setw

using namespace std;

tablero::tablero() {
    for (int i = 0; i < 11; i++) {
        vector<celda> columna;
        for (int j = 0; j < guia[i]; j++) {
            columna.emplace_back(i + 2);
        }
        columnas.push_back(columna);
    }
}

void tablero::mostrar() {
    cout << "                                 TABLERO" << endl;
    for (int i = 0; i < 11; i++) {
        cout << rotulo[i];
        for (int k = 0; k < ((13 - guia[i]) / 2); k++) {
            cout << "     ";
        }
        cout << "|";
        for (celda& celda : columnas[i]) {
            celda.mostrar();
        }
        cout << endl;
    }
}

void tablero::colocarFicha(int columna, int posicion, char ficha) {
    int indiceColumna = columna - 2;
    if (indiceColumna >= 0 && indiceColumna < 11 && posicion >= 0 && posicion < guia[indiceColumna]) {
        columnas[indiceColumna][posicion].colocarFicha(ficha);
    }
}

void tablero::limpiarFicha(int columna, int posicion) {
    int indiceColumna = columna - 2;
    if (indiceColumna >= 0 && indiceColumna < 11 && posicion >= 0 && posicion < guia[indiceColumna]) {
        columnas[indiceColumna][posicion].limpiarFicha();
    }
}

int tablero::obtenerTamanoColumna(int columna) const {
    return guia[columna - 2];
}
