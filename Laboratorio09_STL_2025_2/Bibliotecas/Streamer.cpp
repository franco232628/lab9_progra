//
// Created by GRINGO on 25/06/2026.
//

#include "Streamer.hpp"

string Streamer::get_canal() const {
    return canal;
}

void Streamer::set_canal(const string &canal) {
    this->canal = canal;
}

int Streamer::get_fecha() const {
    return fecha;
}

void Streamer::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Streamer::get_etiqueta_str() const {
    return etiquetaStr;
}

void Streamer::set_etiqueta_str(const string &etiqueta_str) {
    etiquetaStr = etiqueta_str;
}

string Streamer::get_idioma() const {
    return idioma;
}

void Streamer::set_idioma(const string &idioma) {
    this->idioma = idioma;
}

int Streamer::read_date(ifstream &input) {
    int dd, mm, yyyy;
    char c;
    input >> dd>>c>>mm>>c>>yyyy;
    input.get();
    return yyyy*10000 + mm*100 + dd;
}
void Streamer::leer(ifstream &input) {
    // summit1g,12/11/2021,MK1092,HTR108-UPK123-SWT139-LWC105,English
    getline(input, canal, ',');
    if (input.eof()) return;
    fecha = read_date(input);
    string cod_categoria;
    getline(input, cod_categoria, ',');
    categoria.set_codigo(cod_categoria);
    getline(input, etiquetaStr, ',');
    getline(input, idioma);
}

void Streamer::imprimir(ofstream &output) const {
    output<< left<< setw(10)<< "CANAL: " << canal << endl;
    output<< setw(10) << "FECHA: " << fecha << endl;
    output<< setw(10) << "LENGUAJE: " << idioma << endl;
    output<< "CATEGORIA" << endl;
    output<<"   CODIGO: " <<categoria.get_codigo() <<endl;
    output<<"   NOMBRE: " <<categoria.get_nombrea() <<endl;
    output<<"   DESCRIPCION: " <<categoria.get_descripcion() <<endl;
    output<<"ETIQUETAS STR: " <<etiquetaStr <<endl;
    output<<"ETIQUETAS: " <<endl;

    int i=0;
    for (class Etiqueta e: etiquetasVector) {
        output<<right<< setw(4) <<++i<< ") CODIGO: " << e.get_codigo()
            << "  NOMBRE: " << e.get_nombre() << endl;
    }
    i = 0;
    output<<"COMENTARIOS: " <<endl;
    for (string com: comentarios) {
        output<<right<< setw(4) <<++i<< ") " << com << endl;
    }
}
string Streamer::get_CODCAT() {
    return categoria.get_codigo();
}
void Streamer::SetNombre_DESCRIP(string nomb, string descp) {
    categoria.set_nombrea(nomb);
    categoria.set_descripcion(descp);
}

void Streamer::SET_COM(string com) {
    comentarios.push_back(com);
}

void Streamer::SET_ETIQ(const class  Etiqueta &eti) {
    etiquetasVector.push_back(eti);
}

void operator>>(ifstream &input, Streamer &str) {
    str.leer(input);
}

void operator<<(ofstream &output, const Streamer &str) {
    str.imprimir(output);
}
