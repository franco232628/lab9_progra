//
// Created by GRINGO on 25/06/2026.
//

#ifndef LABORATORIO09_STL_2025_2_CATEGORIA_HPP
#define LABORATORIO09_STL_2025_2_CATEGORIA_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include <list>
#include <map>

using namespace std;

class Categoria {
public:
    string get_codigo() const;

    void set_codigo(const string &codigo);

    string get_nombrea() const;

    void set_nombrea(const string &nombrea);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    void leer(ifstream & input);
    void imprimir(ofstream & output) const;
    bool operator<(const Categoria &cat) const;
private:
    string codigo;
    string nombrea;
    string descripcion;


};

void operator>>(ifstream &input, Categoria& cat);
void operator<<(ofstream &output, const Categoria &cat);

#endif //LABORATORIO09_STL_2025_2_CATEGORIA_HPP