//
// Created by GRINGO on 25/06/2026.
//

#include "Comentario.hpp"


string Comentario::get_canal() const {
    return canal;
}

void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_comentario() const {
    return comentario;
}

void Comentario::set_comentario(const string &comentario) {
    this->comentario = comentario;
}

void Comentario::leer(ifstream &input) {
    //LosPollosTV,reds
    getline(input, canal,',');
    if (input.eof()) return;
    getline(input, comentario);
}

void Comentario::imprimir(ofstream &output) const {
    output << canal  <<  "     " << comentario << endl;
}

bool Comentario::operator<(const Comentario &com) const {
    return canal < com.canal;
}

void operator>>(ifstream &input, Comentario &com) {
    com.leer(input);
}

void operator<<(ofstream &output, const Comentario &com) {
    com.imprimir(output);
}
