#include "MinisterioDeTransporte.hpp"

// ---- Carga la tabla de infracciones y la ordena por codigo ascendente ----
void MinisterioDeTransporte::cargaDeInfracciones(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    Infraccion inf;
    while (true) {
        input >> inf;
        if (input.eof()) break;
        tablaInfracciones.push_back(inf);
    }
    tablaInfracciones.sort(); // usa operator< de Infraccion (por codigo)
}

// ---- Carga las empresas y las ordena por DNI ascendente ----
void MinisterioDeTransporte::cargaEmpresas(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    Empresa emp;
    while (true) {
        input >> emp;
        if (input.eof()) break;
        listaEmpresas.push_back(emp);
    }
    listaEmpresas.sort(); // usa operator< de Empresa (por DNI)
}

// ---- Carga vehiculos y los asigna a su empresa por DNI ----
// El archivo puede tener el mismo DNI varias veces
void MinisterioDeTransporte::cargaVehiculos(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    int dni;
    char c;
    Vehiculo v;
    while (true) {
        input >> dni >> c; // lee DNI y consume la coma
        if (input.eof()) break;
        input >> v; // lee placa, marca, modelo
        if (input.eof()) break;

        // Busca la empresa con ese DNI y le agrega el vehiculo
        for (Empresa &emp : listaEmpresas) {
            if (emp.get_dni() == dni) {
                emp.agregarVehiculo(v);
                break;
            }
        }
    }
}

// ---- Carga multas, las asigna por placa, completa montos y ordena ----
// La placa identifica al vehiculo y de ahi se sabe a que empresa pertenece
void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *file_name) {
    ifstream input(file_name, ios::in);
    if (!input.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    Multa m;
    while (true) {
        input >> m;
        if (input.eof()) break;

        // Busca la empresa que tenga el vehiculo con esa placa
        for (Empresa &emp : listaEmpresas) {
            // Se intenta agregar; si la empresa tiene ese vehiculo lo acepta
            // Delegamos la busqueda al metodo de Empresa
            emp.agregarMultaSiCorresponde(m);
        }
    }

    // Completa el monto de cada multa y ordena
    for (Empresa &emp : listaEmpresas) {
        emp.completarMontoMultas(tablaInfracciones);
        emp.ordenarMultas();
    }
}

// ---- Reporte completo con todas las multas ----
void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *file_name) {
    ofstream output(file_name, ios::out);
    if (!output.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    print_line(output, 100, '=');
    output << " RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    print_line(output, 100, '=');

    for (const Empresa &emp : listaEmpresas) {
        print_line(output, 100, '-');
        output << emp;
    }
    print_line(output, 100, '=');
}

// ---- Reporte solo con infracciones adeudadas (no pagadas) ----
void MinisterioDeTransporte::reporteDeEmpresasConInfraccionesDeudas(const char *file_name) {
    ofstream output(file_name, ios::out);
    if (!output.is_open()) { cout << "Error opening file!" << endl; exit(1); }

    print_line(output, 100, '=');
    output << " RELACION DE EMPRESAS CON INFRACCIONES ADEUDADAS" << endl;
    print_line(output, 100, '=');

    for (Empresa &emp : listaEmpresas) {
        print_line(output, 100, '-');
        emp.imprimirSoloDeudas(output);
    }
    print_line(output, 100, '=');
}

// ---- Elimina infracciones pagadas de todas las empresas ----
void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (Empresa &emp : listaEmpresas) {
        emp.eliminarPagadas();
    }
}

// ---- Auxiliar: imprime una linea de caracteres ----
void MinisterioDeTransporte::print_line(ofstream &output, int cant, char caract) {
    for (int i = 0; i < cant; i++) output.put(caract);
    output << endl;
}
