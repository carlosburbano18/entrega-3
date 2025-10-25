#include <iostream>
#include "../include/funciones.h"
using namespace std;

void agregarLibro(Libro libros[], int &n) {
    cout << "Titulo: ";
    getline(cin, libros[n].titulo);
    cout << "Autor: ";
    getline(cin, libros[n].autor);
    cout << "Anio: ";
    cin >> libros[n].anio;
    cin.ignore();
    n++;
}

void mostrarLibros(Libro libros[], int n) {
    cout << "\nLista de libros:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << libros[i].titulo << " - "
             << libros[i].autor << " (" << libros[i].anio << ")\n";
    }
}
