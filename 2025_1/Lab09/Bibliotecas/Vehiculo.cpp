#include "Vehiculo.hpp"
#include <iomanip>

Vehiculo::Vehiculo() {}

Vehiculo::Vehiculo(const Vehiculo &orig) {
    *this = orig;
}

Vehiculo::~Vehiculo() {}

Vehiculo& Vehiculo::operator=(const Vehiculo &orig) {
    if (this == &orig) return *this;
    set_placa(orig.get_placa());
    set_marca(orig.get_marca());
    set_modelo(orig.get_modelo());
    return *this;
}

string Vehiculo::get_placa() const { return placa; }
void Vehiculo::set_placa(const string &placa) { this->placa = placa; }

string Vehiculo::get_marca() const { return marca; }
void Vehiculo::set_marca(const string &marca) { this->marca = marca; }

string Vehiculo::get_modelo() const { return modelo; }
void Vehiculo::set_modelo(const string &modelo) { this->modelo = modelo; }

// Lectura desde archivo: 80310768,G752-478, TOYOTA,Hilux
// Este metodo solo lee placa, marca y modelo (el DNI lo lee la Empresa)
void Vehiculo::leer(ifstream &input) {
    getline(input, placa, ',');
    if (input.eof()) return;
    getline(input, marca, ',');
    getline(input, modelo);
}

void Vehiculo::imprimir(ofstream &output) const {
    output << left << setw(12) << placa
           << setw(15) << marca
           << modelo << endl;
}

void operator>>(ifstream &input, Vehiculo &v) { v.leer(input); }
void operator<<(ofstream &output, const Vehiculo &v) { v.imprimir(output); }
