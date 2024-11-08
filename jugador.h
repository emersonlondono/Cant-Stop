#ifndef JUGADOR_H
#define JUGADOR_H

#include <map>
#include <string>
#include "tablero.h"

class jugador {
private:
    std::string nombre;
    std::map<int, int> posiciones;
    int fichasActivas;

public:
    jugador(std::string _nombre);
    std::string obtenerNombre() const;
    int obtenerPosicion(int columna) const;
    bool puedeAgregarFicha() const;
    void agregarFicha(int columna);
    void moverFicha(int columna, int avance);
    void guardarPosiciones(tablero &t);
    bool puedeMoverFicha(int columna);
    void perderProgreso();
};

#endif
