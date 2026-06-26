#ifndef LAB09_INFRACCION_HPP
#define LAB09_INFRACCION_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Infraccion {
public:
    string get_codigo() const;
    void set_codigo(const string &codigo);

    double get_multa() const;
    void set_multa(double multa);

    string get_gravedad() const;
    void set_gravedad(const string &gravedad);

    string get_descripcion() const;
    void set_descripcion(const string &descripcion);

    // Constructor por defecto, copia, destructor y operador=
    Infraccion();
    Infraccion(const Infraccion &orig);
    ~Infraccion();
    Infraccion& operator=(const Infraccion &orig);

    void leer(ifstream &input);
    void imprimir(ofstream &output) const;

    // Para ordenar list<Infraccion> por código ascendente
    bool operator<(const Infraccion &inf) const;

private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
};

void operator>>(ifstream &input, Infraccion &inf);
void operator<<(ofstream &output, const Infraccion &inf);

#endif
