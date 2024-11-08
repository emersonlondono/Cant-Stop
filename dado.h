#ifndef DADO_H
#define DADO_H

class dado {
private:
    int valor;

public:
    dado();                    // Constructor
    void lanzar();             // Método para lanzar el dado
    int obtenerValor() const;  // Método para obtener el valor del dado
    void mostrar(int numero) const; // Método para mostrar el valor del dado
};

#endif
