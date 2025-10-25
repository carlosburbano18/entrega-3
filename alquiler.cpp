#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool alquilado;

public:
    Vehiculo(string m, string mo, string p) : marca(m), modelo(mo), placa(p), alquilado(false) {}
    virtual void mostrarInformacion() {
        cout << "Marca: " << marca
             << ", Modelo: " << modelo
             << ", Placa: " << placa
             << ", Estado: " << (alquilado ? "Alquilado" : "Disponible") 
             << endl;
    }
    string getPlaca() { return placa; }
    bool estaAlquilado() { return alquilado; }
    void alquilar() { alquilado = true; }
    void devolver() { alquilado = false; }
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
    int capacidadPasajeros;

public:
    Auto(string m, string mo, string p, int cap) : Vehiculo(m, mo, p), capacidadPasajeros(cap) {}
    void mostrarInformacion() override {
        Vehiculo::mostrarInformacion();
        cout << "Capacidad de pasajeros: " << capacidadPasajeros << endl;
    }
};

class Bicicleta : public Vehiculo {
    string tipo;

public:
    Bicicleta(string m, string mo, string p, string t) : Vehiculo(m, mo, p), tipo(t) {}
    void mostrarInformacion() override {
        Vehiculo::mostrarInformacion();
        cout << "Tipo: " << tipo << endl;
    }
};

class SistemaAlquiler {
    vector<Vehiculo*> vehiculos;

public:
    void registrarVehiculo(Vehiculo* v) {
        vehiculos.push_back(v);
        cout << "Vehículo " << v->getPlaca() << " registrado correctamente." << endl;
    }
    void mostrarDisponibles() {
        cout << "Vehículos disponibles:" << endl;
        for (auto v : vehiculos) {
            if (!v->estaAlquilado())
                v->mostrarInformacion();
        }
    }
    void alquilarVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (!v->estaAlquilado()) {
                    v->alquilar();
                    cout << "Vehículo " << placa << " alquilado con éxito." << endl;
                    return;
                } else {
                    cout << "Vehículo " << placa << " ya está alquilado." << endl;
                    return;
                }
            }
        }
        cout << "No se encontró el vehículo con placa " << placa << "." << endl;
    }
    void devolverVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaAlquilado()) {
                    v->devolver();
                    cout << "Vehículo " << placa << " devuelto correctamente." << endl;
                    return;
                } else {
                    cout << "Vehículo " << placa << " no estaba alquilado." << endl;
                    return;
                }
            }
        }
        cout << "No se encontró el vehículo con placa " << placa << "." << endl;
    }
    ~SistemaAlquiler() {
        for (auto v : vehiculos)
            delete v;
    }
};

int main() {
    SistemaAlquiler sistema;

    Auto* auto1 = new Auto("Toyota", "Corolla", "ABC123", 5);
    Bicicleta* bici1 = new Bicicleta("Trek", "Marlin 7", "XYZ789", "Montaña");

    sistema.registrarVehiculo(auto1);
    sistema.registrarVehiculo(bici1);

    sistema.mostrarDisponibles();

    sistema.alquilarVehiculo("ABC123");
    sistema.mostrarDisponibles();

    sistema.devolverVehiculo("ABC123");
    sistema.mostrarDisponibles();

    return 0;
}
