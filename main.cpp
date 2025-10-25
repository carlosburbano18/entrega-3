#include <iostream>
#include "include/funciones.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    int opcion;

    do {
        cout << "\n1. Agregar libro\n2. Mostrar libros\n3. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: biblioteca.agregarLibro(); break;
            case 2: biblioteca.mostrarLibros(); break;
        }
    } while(opcion != 3);

    return 0;
}
