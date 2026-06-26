//
// Created by GRINGO on 25/06/2026.
//

#ifndef LABORATORIO09_STL_2025_2_ETIQUETA_HPP
#define LABORATORIO09_STL_2025_2_ETIQUETA_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include <list>
#include <map>

using namespace std;

class Etiqueta {
public:
    string get_codigo() const;

    void set_codigo(const string &codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    // Etiqueta();
    // Etiqueta(const Etiqueta &e);

    void leer(ifstream & input);
    void imprimir(ofstream & output) const;
    bool operator<(const Etiqueta &objeto) const;
private:
    string codigo;
    string nombre;

};

void operator>>(ifstream &input, Etiqueta& etiq);
void operator<<(ofstream &output, const Etiqueta &etiq);
#endif //LABORATORIO09_STL_2025_2_ETIQUETA_HPP