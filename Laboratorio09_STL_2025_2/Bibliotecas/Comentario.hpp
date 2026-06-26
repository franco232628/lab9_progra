//
// Created by GRINGO on 25/06/2026.
//

#ifndef LABORATORIO09_STL_2025_2_COMENTARIO_HPP
#define LABORATORIO09_STL_2025_2_COMENTARIO_HPP


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include <list>
#include <map>

using namespace std;
class Comentario {
public:
    string get_canal() const;

    void set_canal(const string &canal);

    string get_comentario() const;

    void set_comentario(const string &comentario);

    void leer(ifstream & input);
    void imprimir(ofstream & output) const;
    bool operator<(const Comentario &com) const;

private:
    string canal;
    string comentario;

};

void operator>>(ifstream &input, Comentario& com);
void operator<<(ofstream &output, const Comentario &com);

#endif //LABORATORIO09_STL_2025_2_COMENTARIO_HPP