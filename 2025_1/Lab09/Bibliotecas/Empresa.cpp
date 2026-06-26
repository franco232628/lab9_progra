#include "Empresa.hpp"
#include "Infraccion.hpp"
#include <algorithm>

Empresa::Empresa() : dni(0) {}
Empresa::~Empresa() {}

// ---- Selectores ----
int Empresa::get_dni() const { return dni; }
void Empresa::set_dni(int dni) { this->dni = dni; }

string Empresa::get_nombre() const { return nombre; }
void Empresa::set_nombre(const string &nombre) { this->nombre = nombre; }

string Empresa::get_distrito() const { return distrito; }
void Empresa::set_distrito(const string &distrito) { this->distrito = distrito; }

// ---- Lectura desde archivo: 48528209,ZAVALETA CORONADO FELICITA ELOISA,Villa Maria del Triunfo ----
void Empresa::leer(ifstream &input) {
    input >> dni;
    input.get(); // consume la coma
    if (input.eof()) return;
    getline(input, nombre, ',');
    getline(input, distrito);
}

// ---- Agrega vehiculo al map usando la placa como clave ----
// El map<string,Vehiculo> permite busqueda O(log n) por placa
void Empresa::agregarVehiculo(const Vehiculo &v) {
    vehiculos[v.get_placa()] = v;
}

// ---- Agrega multa directamente ----
void Empresa::agregarMulta(const Multa &m) {
    multasRecibidas.push_back(m);
}

// ---- Agrega multa solo si la placa existe en el map de vehiculos ----
// Aqui es donde el map<string,Vehiculo> brilla: find() es O(log n) vs O(n) de un vector
void Empresa::agregarMultaSiCorresponde(const Multa &m) {
    map<string, Vehiculo>::iterator it = vehiculos.find(m.get_placa());
    if (it != vehiculos.end()) {
        multasRecibidas.push_back(m);
    }
}

// ---- Ordena multas descendentemente (operator< ya esta definido con > en Multa) ----
void Empresa::ordenarMultas() {
    sort(multasRecibidas.begin(), multasRecibidas.end());
}

// ---- Busca en tablaInfracciones el codigo y completa el monto de cada multa ----
void Empresa::completarMontoMultas(const list<Infraccion> &tabla) {
    for (Multa &m : multasRecibidas) {
        for (const Infraccion &inf : tabla) {
            if (inf.get_codigo() == m.get_codMulta()) {
                m.set_multa(inf.get_multa());
                break;
            }
        }
    }
}

// ---- Elimina del vector las multas ya pagadas ----
void Empresa::eliminarPagadas() {
    vector<Multa> pendientes;
    for (const Multa &m : multasRecibidas) {
        if (!m.get_pagada()) pendientes.push_back(m);
    }
    multasRecibidas = pendientes;
}

// ---- Comparacion por DNI para list.sort() ----
bool Empresa::operator<(const Empresa &e) const {
    return dni < e.dni;
}

// ---- Imprime cabecera DNI / NOMBRE / DISTRITO ----
void Empresa::imprimirCabecera(ofstream &output) const {
    output << "DNI: " << dni
           << "   NOMBRE: " << nombre
           << "   DISTRITO: " << distrito << endl;
}

// ---- Imprime tabla de vehiculos del map (se imprimen en orden de placa por ser map) ----
void Empresa::imprimirVehiculos(ofstream &output) const {
    output << "VEHICULOS DE LA EMPRESA:" << endl;
    output << left << setw(12) << "PLACA" << setw(15) << "MARCA" << "MODELO" << endl;
    for (const auto &par : vehiculos) {
        output << par.second; // usa operator<< de Vehiculo
    }
}

// ---- Impresion completa (todas las multas) ----
void Empresa::imprimir(ofstream &output) const {
    imprimirCabecera(output);
    imprimirVehiculos(output);
    output << "MULTAS IMPUESTAS" << endl;
    output << left
           << setw(12) << "PLACA"
           << setw(22) << "FECHA DE INFRACCION"
           << setw(22) << "CODIGO DE INFRACCION"
           << setw(10) << "MULTA"
           << setw(8)  << "PAGADA"
           << "FECHA DE PAGO" << endl;
    for (const Multa &m : multasRecibidas) {
        output << m;
    }
}

// ---- Impresion solo con deudas (multas no pagadas) ----
void Empresa::imprimirSoloDeudas(ofstream &output) const {
    imprimirCabecera(output);
    imprimirVehiculos(output);
    output << "MULTAS ADEUDADAS" << endl;
    output << left
           << setw(12) << "PLACA"
           << setw(22) << "FECHA DE INFRACCION"
           << setw(22) << "CODIGO DE INFRACCION"
           << setw(10) << "MULTA" << endl;
    for (const Multa &m : multasRecibidas) {
        if (!m.get_pagada()) output << m;
    }
}

void operator>>(ifstream &input, Empresa &e) { e.leer(input); }
void operator<<(ofstream &output, const Empresa &e) { e.imprimir(output); }
