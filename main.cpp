#include <iostream>
#include "include/funciones.h"
using namespace std;

int main() {
    Libro libros[100];
    int n = 0;
    int opcion;

    do {
        cout << "\n1. Agregar libro\n2. Mostrar libros\n3. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarLibro(libros, n); break;
            case 2: mostrarLibros(libros, n); break;
        }
    } while (opcion != 3);

    return 0;
}
