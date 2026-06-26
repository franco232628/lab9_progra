#include "Multa.hpp"

Multa::Multa() : fecha(0), multa(0.0), pagada(false), fechaDePago(0) {}

Multa::Multa(const Multa &orig) {
    *this = orig;
}

Multa::~Multa() {}

Multa& Multa::operator=(const Multa &orig) {
    if (this == &orig) return *this;
    set_fecha(orig.get_fecha());
    set_placa(orig.get_placa());
    set_codMulta(orig.get_codMulta());
    set_multa(orig.get_multa());
    set_pagada(orig.get_pagada());
    set_fechaDePago(orig.get_fechaDePago());
    return *this;
}

// ---- Selectores ----
int Multa::get_fecha() const { return fecha; }
void Multa::set_fecha(int fecha) { this->fecha = fecha; }

string Multa::get_placa() const { return placa; }
void Multa::set_placa(const string &placa) { this->placa = placa; }

string Multa::get_codMulta() const { return codMulta; }
void Multa::set_codMulta(const string &codMulta) { this->codMulta = codMulta; }

double Multa::get_multa() const { return multa; }
void Multa::set_multa(double multa) { this->multa = multa; }

bool Multa::get_pagada() const { return pagada; }
void Multa::set_pagada(bool pagada) { this->pagada = pagada; }

int Multa::get_fechaDePago() const { return fechaDePago; }
void Multa::set_fechaDePago(int fechaDePago) { this->fechaDePago = fechaDePago; }

// ---- Lee fecha en formato dd/mm/yyyy con delimitador al final ----
int Multa::leerFecha(ifstream &input, char delim) {
    int dd, mm, yyyy;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    input.get(); // consume el delimitador (coma o newline)
    return yyyy * 10000 + mm * 100 + dd;
}

// ---- Lectura desde archivo CSV ----
// Formato: 3/2/2022,M832-314,M1008,N
//          5/10/2024,M907-605,M1002,P,24/10/2024
void Multa::leer(ifstream &input) {
    fecha = leerFecha(input, ',');
    if (input.eof()) return;

    getline(input, placa, ',');
    getline(input, codMulta, ',');

    char estado;
    input >> estado;
    pagada = (estado == 'P');
    input.get(); // consume coma o newline

    if (pagada) {
        fechaDePago = leerFecha(input, '\n');
    } else {
        fechaDePago = 0;
    }
}

// ---- Impresion con formato de tabla ----
void Multa::imprimir(ofstream &output) const {
    // Descomponemos fecha yyyymmdd para mostrar dd/mm/yyyy
    int dd = fecha % 100;
    int mm = (fecha / 100) % 100;
    int yyyy = fecha / 10000;

    output << left
           << setw(17) << placa
           << setw(2) << dd << "/" << setw(2) << mm << "/" << yyyy << "             "
           << setw(16) << codMulta
           << setw(10) << fixed << setprecision(2) << multa
           << setw(5)  << (pagada ? "SI" : "NO");

    if (pagada) {
        int dp_dd = fechaDePago % 100;
        int dp_mm = (fechaDePago / 100) % 100;
        int dp_yyyy = fechaDePago / 10000;
        output << "   " << dp_dd << "/" << dp_mm << "/" << dp_yyyy;
    }
    output << endl;
}

// ---- Orden DESCENDENTE por fecha (el mas reciente primero) ----
bool Multa::operator<(const Multa &m) const {
    return fecha > m.fecha; // > para descendente
}

void operator>>(ifstream &input, Multa &m) { m.leer(input); }
void operator<<(ofstream &output, const Multa &m) { m.imprimir(output); }
