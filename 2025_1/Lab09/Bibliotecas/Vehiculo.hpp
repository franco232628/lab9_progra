#ifndef LAB09_VEHICULO_HPP
#define LAB09_VEHICULO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Vehiculo {
public:
    string get_placa() const;
    void set_placa(const string &placa);

    string get_marca() const;
    void set_marca(const string &marca);

    string get_modelo() const;
    void set_modelo(const string &modelo);

    Vehiculo();
    Vehiculo(const Vehiculo &orig);
    ~Vehiculo();
    Vehiculo& operator=(const Vehiculo &orig);

    void leer(ifstream &input);
    void imprimir(ofstream &output) const;

private:
    string placa;
    string marca;
    string modelo;
};

void operator>>(ifstream &input, Vehiculo &v);
void operator<<(ofstream &output, const Vehiculo &v);

#endif
