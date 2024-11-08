#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dado.h"

using namespace std;

dado::dado() {
    srand(time(0));  // Inicializar el generador de números aleatorios
    lanzar();
}

void dado::lanzar() {
    valor = rand() % 6 + 1;
}

int dado::obtenerValor() const {
    return valor;
}

void dado::mostrar(int numero) const {
    cout << "Dado " << numero << ": " << valor << endl;
}


