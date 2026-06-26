#ifndef LAB09_MINISTERIODETRANSPORTE_HPP
#define LAB09_MINISTERIODETRANSPORTE_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <map>

#include "Infraccion.hpp"
#include "Empresa.hpp"
#include "Vehiculo.hpp"
#include "Multa.hpp"

using namespace std;

class MinisterioDeTransporte {
public:
    // Carga tablaInfracciones y la ordena ascendentemente por codigo
    void cargaDeInfracciones(const char *file_name);

    // Carga listaEmpresas y la ordena ascendentemente por DNI
    void cargaEmpresas(const char *file_name);

    // Lee vehiculos y los asigna a la empresa correspondiente por DNI
    void cargaVehiculos(const char *file_name);

    // Lee multas cometidas, las asigna a la empresa por placa,
    // completa el monto buscando en tablaInfracciones y ordena desc. por fecha
    void cargaInfraccionesCometidas(const char *file_name);

    // Genera reporte completo (todas las multas)
    void reporteDeEmpresasConInfracciones(const char *file_name);

    // Genera reporte solo con infracciones adeudadas (no pagadas)
    void reporteDeEmpresasConInfraccionesDeudas(const char *file_name);

    // Elimina de todas las empresas las infracciones pagadas
    void eliminaInfraccionesPagadas();

private:
    list<Infraccion> tablaInfracciones;
    list<Empresa> listaEmpresas;

    // Auxiliar: imprime linea separadora
    void print_line(ofstream &output, int cant, char caract);
};

#endif
