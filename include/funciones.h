#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <iostream>
using namespace std;

class Libro {
    string titulo;
    string autor;
    int año;

public:
    void leerDatos() {
        cout << "Titulo: ";
        getline(cin, titulo);
        cout << "Autor: ";
        getline(cin, autor);
        cout << "Anio: ";
        cin >> año;
        cin.ignore();
    }

    void mostrar() {
        cout << titulo << " - " << autor << " (" << año << ")\n";
    }
};

class Biblioteca {
    Libro libros[100];
    int n;

public:
    Biblioteca() : n(0) {}

    void agregarLibro() {
        if (n < 100) {
            libros[n].leerDatos();
            n++;
        } else {
            cout << "No se pueden agregar mas libros.\n";
        }
    }

    void mostrarLibros() {
        cout << "\nLista de libros:\n";
        for (int i = 0; i < n; i++) {
            cout << i+1 << ". ";
            libros[i].mostrar();
        }
    }
};

#endif
