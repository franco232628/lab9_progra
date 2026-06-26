#include "Bibliotecas/MinisterioDeTransporte.hpp"

using namespace std;

// 20XXXXXX
// Apellido Nombre

int main() {
    MinisterioDeTransporte ministerio;

    // Carga de datos
    ministerio.cargaDeInfracciones("ArchivosDeDatos/TablaDeInfracciones.csv");
    ministerio.cargaEmpresas("ArchivosDeDatos/EmpresasRegistradas.csv");
    ministerio.cargaVehiculos("ArchivosDeDatos/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("ArchivosDeDatos/InfraccionesCometidas.csv");

    // Reporte 1: todas las infracciones
    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReportes/reporte_completo.txt");

    // Reporte 2: solo infracciones adeudadas (sin borrar datos)
    ministerio.reporteDeEmpresasConInfraccionesDeudas("ArchivosDeReportes/reporte_deudas.txt");

    // Elimina las pagadas y genera reporte final solo con deudas
    ministerio.eliminaInfraccionesPagadas();
    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReportes/reporte_sin_pagadas.txt");

    return 0;
}
