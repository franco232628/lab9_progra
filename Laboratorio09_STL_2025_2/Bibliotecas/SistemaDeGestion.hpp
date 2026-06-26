//
// Created by GRINGO on 25/06/2026.
//

#ifndef LABORATORIO09_STL_2025_2_SISTEMADEGESTION_HPP
#define LABORATORIO09_STL_2025_2_SISTEMADEGESTION_HPP

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
#include "Streamer.hpp"
using namespace std;

class SistemaDeGestion {

    public:
    // SistemaDeGestion();
    void cargarCategorias(const char*file_name);
    void cargaComentarios(const char*file_name);
    void cargaEtiquetas(const char*file_name);
    void cargaStreamers(const char*file_name);
    void completarStreamers();
    void mostrarReporte(const char*file_name);
    void print_line(ofstream& output, int cant, char caract);
    void mostrarReporte1(const char*file_name);
    void eliminarStreamers(const string &idioma);
private:
    list<class Categoria> categorias;
    list<class Comentario> comentarios;
    map<string, class Etiqueta> etiquetas;// clave = codigo de etiqueta, busqueda O(log n)
    list<class Streamer> Streamers;
};



#endif //LABORATORIO09_STL_2025_2_SISTEMADEGESTION_HPP