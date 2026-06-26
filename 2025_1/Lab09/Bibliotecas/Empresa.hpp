#ifndef LAB09_EMPRESA_HPP
#define LAB09_EMPRESA_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>

#include "Vehiculo.hpp"
#include "Multa.hpp"

using namespace std;

class Empresa {
public:
    int get_dni() const;
    void set_dni(int dni);

    string get_nombre() const;
    void set_nombre(const string &nombre);

    string get_distrito() const;
    void set_distrito(const string &distrito);

    Empresa();
    ~Empresa();

    void leer(ifstream &input);
    void imprimir(ofstream &output) const;
    void imprimirSoloDeudas(ofstream &output) const;

    // Agrega un vehiculo al map usando la placa como clave
    void agregarVehiculo(const Vehiculo &v);

    // Agrega una multa al vector si la placa pertenece a esta empresa
    // Usa el map<string,Vehiculo> para buscar la placa en O(log n)
    void agregarMultaSiCorresponde(const Multa &m);

    // Agrega una multa directamente (uso interno)
    void agregarMulta(const Multa &m);

    // Ordena multasRecibidas descendentemente por fecha
    void ordenarMultas();

    // Completa el monto de multa buscando en tablaInfracciones
    void completarMontoMultas(const list<class Infraccion> &tabla);

    // Elimina las multas pagadas del vector
    void eliminarPagadas();

    // Para ordenar list<Empresa> por DNI ascendente
    bool operator<(const Empresa &e) const;

private:
    int dni;
    string nombre;
    string distrito;
    map<string, Vehiculo> vehiculos;        // clave = placa
    vector<Multa> multasRecibidas;

    // Imprime solo la cabecera + vehiculos (reutilizado en ambos reportes)
    void imprimirCabecera(ofstream &output) const;
    void imprimirVehiculos(ofstream &output) const;
};

void operator>>(ifstream &input, Empresa &e);
void operator<<(ofstream &output, const Empresa &e);

#endif
