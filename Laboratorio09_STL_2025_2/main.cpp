#include "Bibliotecas/SistemaDeGestion.hpp"

using namespace std;

// 20241210
// Richard Franco Tineo Quispe

int main() {
    SistemaDeGestion sistemaDeGestion;
    sistemaDeGestion.cargarCategorias("ArchivosDeDatos/Categorias.csv");
    sistemaDeGestion.cargaComentarios("ArchivosDeDatos/Comentarios.csv");
    sistemaDeGestion.cargaEtiquetas("ArchivosDeDatos/Etiquetas.csv");
    sistemaDeGestion.cargaStreamers("ArchivosDeDatos/Streamers.csv");
    sistemaDeGestion.mostrarReporte("ArchivosDeReportes/reporte_cargados.txt");
    sistemaDeGestion.mostrarReporte1("ArchivosDeReportes/reporte_cargados2.txt");
     sistemaDeGestion.completarStreamers();
    sistemaDeGestion.mostrarReporte1("ArchivosDeReportes/reporte_cargados3.txt");
    sistemaDeGestion.eliminarStreamers("English");
    sistemaDeGestion.mostrarReporte1("ArchivosDeReportes/reporte_eliminados.txt");

    return 0;
}