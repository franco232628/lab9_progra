//
// Created by GRINGO on 25/06/2026.
//

#include "SistemaDeGestion.hpp"

void SistemaDeGestion::cargarCategorias(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    Categoria cat;
    while (true) {
        input>>cat;
        if (input.eof()) break;
        categorias.push_back(cat);
    }
    categorias.sort();
}

void SistemaDeGestion::cargaComentarios(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    Comentario com;
    while (true) {
        input>>com;
        if (input.eof()) break;
        comentarios.push_back(com);
    }
    comentarios.sort();
}

void SistemaDeGestion::cargaEtiquetas(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    Etiqueta eti;
    while (true) {
        input>>eti;
        if (input.eof()) break;
        etiquetas[eti.get_codigo()] = eti;
    }

}

void SistemaDeGestion::cargaStreamers(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    Streamer str;
    while (true) {
        input>>str;
        if (input.eof()) break;
        Streamers.push_back(str);
    }

}


void SistemaDeGestion::mostrarReporte(const char *file_name) {
    ofstream output(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    print_line(output, 120, '=');
    output << "Categoria:" << endl;
    print_line(output, 120, '=');

    for (Categoria cat : categorias) {
        output<< cat;
    }
    output << endl;

    print_line(output, 120, '=');
    output << "Comentarios:" << endl;
    print_line(output, 120, '=');

    for (Comentario com : comentarios) {
        output<< com;
    }
    output << endl;



    print_line(output, 120, '=');
    output << "Etiquetas:" << endl;
    print_line(output, 120, '=');

    for (auto eti : etiquetas) {
        print_line(output, 120, '-');
        output<< eti.second;
    }
    output << endl;


}

void SistemaDeGestion::completarStreamers() {
    string cod_cat, canal_com, sgEtiquetas, eti;
    for (Streamer &s : Streamers) {
        // Completa nombre y descripcion de la categoria
        cod_cat = s.get_CODCAT();
        for (Categoria c : categorias) {
            if (c.get_codigo() == cod_cat) {
                s.SetNombre_DESCRIP(c.get_nombrea(), c.get_descripcion());
                break;
            }
        }
        // Corta el string de etiquetas de 7 en 7 (6 de codigo + 1 de guion)
        // y busca cada codigo en el map con find() en O(log n)
        sgEtiquetas = s.get_etiqueta_str();
        for (int i=0; i < sgEtiquetas.length(); i+=7) {//HTR108-UPK123-SWT139-LWC105
            eti = sgEtiquetas.substr(i, 6);

            map<string, Etiqueta> ::iterator it;
            it = etiquetas.find(eti);
            if (it != etiquetas.end()) {
                s.SET_ETIQ(it->second);
            }

        }
        // Asigna todos los comentarios que correspondan al canal
        canal_com = s.get_canal();
        for (Comentario com : comentarios) {
            if (com.get_canal() == canal_com) {
                s.SET_COM(com.get_comentario());
            }
        }
    }
}


void SistemaDeGestion::print_line(ofstream &output, int cant, char caract) {
    for (int i = 0; i < cant; i++) output.put(caract);
    output<<endl;
}

void SistemaDeGestion::mostrarReporte1(const char *file_name) {
    ofstream output(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    print_line(output, 130, '-');
    output <<right<< setw(((130 + 21)/2))<<"RELACION DE STREAMERS" << endl;
    print_line(output, 130, '-');

    for (Streamer s : Streamers) {
        output<<s;
    }
    print_line(output, 130, '-');
}
void SistemaDeGestion::eliminarStreamers(const string &idioma) {
    list<Streamer>::iterator it = Streamers.begin();
    while (it != Streamers.end()) {
        if (it->get_idioma() == idioma)
            it = Streamers.erase(it); // erase retorna el siguiente iterador valido
        else
            ++it;
    }
}