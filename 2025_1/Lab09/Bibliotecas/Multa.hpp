#ifndef LAB09_MULTA_HPP
#define LAB09_MULTA_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Multa {
public:
    int get_fecha() const;
    void set_fecha(int fecha);

    string get_placa() const;
    void set_placa(const string &placa);

    string get_codMulta() const;
    void set_codMulta(const string &codMulta);

    double get_multa() const;
    void set_multa(double multa);

    bool get_pagada() const;
    void set_pagada(bool pagada);

    int get_fechaDePago() const;
    void set_fechaDePago(int fechaDePago);

    Multa();
    Multa(const Multa &orig);
    ~Multa();
    Multa& operator=(const Multa &orig);

    void leer(ifstream &input);
    void imprimir(ofstream &output) const;

    // Para ordenar descendentemente por fecha de infraccion
    bool operator<(const Multa &m) const;

private:
    int fecha;          // fecha en que cometio la infraccion (yyyymmdd)
    string placa;
    string codMulta;
    double multa;       // monto de la multa (completado desde tablaInfracciones)
    bool pagada;
    int fechaDePago;    // 0 si no pago

    // Lee una fecha dd/mm/yyyy y la convierte a yyyymmdd
    int leerFecha(ifstream &input, char delim);
};

void operator>>(ifstream &input, Multa &m);
void operator<<(ofstream &output, const Multa &m);

#endif
