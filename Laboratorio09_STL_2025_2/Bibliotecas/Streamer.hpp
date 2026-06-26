//
// Created by GRINGO on 25/06/2026.
//

#ifndef LABORATORIO09_STL_2025_2_STREAMER_HPP
#define LABORATORIO09_STL_2025_2_STREAMER_HPP


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include <list>
#include <map>

#include "Categoria.hpp"
#include "Etiqueta.hpp"
#include "Comentario.hpp"

using namespace std;


class Streamer {
public:
    string get_canal() const;

    void set_canal(const string &canal);

    int get_fecha() const;

    void set_fecha(int fecha);

    string get_etiqueta_str() const;

    void set_etiqueta_str(const string &etiqueta_str);

    string get_idioma() const;

    void set_idioma(const string &idioma);


    int read_date( ifstream & input);

    void leer(ifstream & input);
    void imprimir(ofstream & output) const;
    bool operator<(const Streamer &com) const;

    string get_CODCAT();

    void SetNombre_DESCRIP(string nomb, string descp);

    void SET_COM( string com);

    void SET_ETIQ(const class  Etiqueta &eti);

private:
    string canal;
    int fecha;
    Categoria categoria;// solo el codigo
    string etiquetaStr;
    vector<class Etiqueta> etiquetasVector; // todo
    string idioma;
    vector<string> comentarios; //todo

};


void operator>>(ifstream &input, Streamer& str);
void operator<<(ofstream &output, const Streamer &str);

#endif //LABORATORIO09_STL_2025_2_STREAMER_HPP