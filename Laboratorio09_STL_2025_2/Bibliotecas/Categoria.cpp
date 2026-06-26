//
// Created by GRINGO on 25/06/2026.
//

#include "Categoria.hpp"

string Categoria::get_codigo() const {
    return codigo;
}

void Categoria::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Categoria::get_nombrea() const {
    return nombrea;
}

void Categoria::set_nombrea(const string &nombrea) {
    this->nombrea = nombrea;
}

string Categoria::get_descripcion() const {
    return descripcion;
}

void Categoria::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

void Categoria::leer(ifstream &input) {
    // UM1000,Just Chatting,Casual conversations; reactions; and hangouts without a main game.
    getline(input, codigo,',');
    if (input.eof()) return;
    getline(input, nombrea,',');
    getline(input, descripcion);
}

void Categoria::imprimir(ofstream &output) const {
    output << codigo  <<  "     " << nombrea << "     "<<descripcion<< endl;
}

bool Categoria::operator<(const Categoria &cat) const {
    return codigo<cat.codigo;
}

void operator>>(ifstream &input, Categoria &cat) {
    cat.leer(input);
}

void operator<<(ofstream &output, const Categoria &cat) {
    cat.imprimir(output);
}
