#ifndef CELDA_H
#define CELDA_H

#include <iostream>
#include <iomanip>

using namespace std;

class celda {
public:
    int valor;
    char ficha;

    celda(int _valor);
    void colocarFicha(char nuevaFicha);
    void limpiarFicha();
    void mostrar();
};

#endif
