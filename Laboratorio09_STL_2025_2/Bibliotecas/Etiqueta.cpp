//
// Created by GRINGO on 25/06/2026.
//

#include "Etiqueta.hpp"

string Etiqueta::get_codigo() const {
    return codigo;
}

void Etiqueta::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const {
    return nombre;
}

void Etiqueta::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

void Etiqueta::leer(ifstream &input) {
//AAM100,dropsenabled
    getline(input, codigo,',');
    if (input.eof()) return;
    getline(input, nombre);
}

void Etiqueta::imprimir(ofstream &output) const {
    output << codigo  <<  "     " << nombre<< endl;
}

bool Etiqueta::operator<(const Etiqueta &objeto) const {
    return codigo < objeto.codigo;
}

void operator>>(ifstream &input, Etiqueta &etiq) {
    etiq.leer(input);
}

void operator<<(ofstream &output, const Etiqueta &etiq) {
    etiq.imprimir(output);
}
