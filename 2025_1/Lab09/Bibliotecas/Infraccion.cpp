#include "Infraccion.hpp"

// ---- Constructor por defecto ----
Infraccion::Infraccion() : multa(0.0) {}

// ---- Constructor copia ----
Infraccion::Infraccion(const Infraccion &orig) {
    *this = orig;
}

// ---- Destructor ----
Infraccion::~Infraccion() {}

// ---- Operador de asignacion ----
Infraccion& Infraccion::operator=(const Infraccion &orig) {
    if (this == &orig) return *this;
    set_codigo(orig.get_codigo());
    set_multa(orig.get_multa());
    set_gravedad(orig.get_gravedad());
    set_descripcion(orig.get_descripcion());
    return *this;
}

// ---- Selectores ----
string Infraccion::get_codigo() const { return codigo; }
void Infraccion::set_codigo(const string &codigo) { this->codigo = codigo; }

double Infraccion::get_multa() const { return multa; }
void Infraccion::set_multa(double multa) { this->multa = multa; }

string Infraccion::get_gravedad() const { return gravedad; }
void Infraccion::set_gravedad(const string &gravedad) { this->gravedad = gravedad; }

string Infraccion::get_descripcion() const { return descripcion; }
void Infraccion::set_descripcion(const string &descripcion) { this->descripcion = descripcion; }

// ---- Lectura desde archivo CSV: M1046,658.70, Muy grave,Obstruir la ciclovia ----
void Infraccion::leer(ifstream &input) {
    getline(input, codigo, ',');
    if (input.eof()) return;
    input >> multa;
    input.get(); // consume la coma
    getline(input, gravedad, ',');
    getline(input, descripcion);
}

// ---- Impresion hacia archivo ----
void Infraccion::imprimir(ofstream &output) const {
    output << "CODIGO: " << codigo
           << "   MULTA: " << fixed << setprecision(2) << multa
           << "   GRAVEDAD: " << gravedad
           << "   DESCRIPCION: " << descripcion << endl;
}

// ---- Comparacion por codigo para list.sort() ----
bool Infraccion::operator<(const Infraccion &inf) const {
    return codigo < inf.codigo;
}

void operator>>(ifstream &input, Infraccion &inf) { inf.leer(input); }
void operator<<(ofstream &output, const Infraccion &inf) { inf.imprimir(output); }
