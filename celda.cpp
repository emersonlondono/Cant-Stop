#include "celda.h"

celda::celda(int _valor) : valor(_valor), ficha(' ') {}

void celda::colocarFicha(char nuevaFicha) {
    ficha = nuevaFicha;
}

void celda::limpiarFicha() {
    ficha = ' ';
}

void celda::mostrar() {
    if (ficha != ' ') {
        cout << setw(3) << ficha << "|";
    } else {
        cout << setw(3) << valor << "|";
    }
}
