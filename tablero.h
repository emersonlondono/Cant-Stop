#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "celda.h"

class tablero {
private:
    int guia[11] = {3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};
    std::string rotulo[11] = {"2 : ", "3 : ", "4 : ", "5 : ", "6 : ", "7 : ", "8 : ", "9 : ", "10: ", "11: ", "12: "};
    std::vector<std::vector<celda>> columnas;

public:
    tablero();
    void mostrar();
    void colocarFicha(int columna, int posicion, char ficha);
    void limpiarFicha(int columna, int posicion);
    int obtenerTamanoColumna(int columna) const;
};

#endif
