#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
};

void agregarLibro(Libro libros[], int &n);
void mostrarLibros(Libro libros[], int n);

#endif
