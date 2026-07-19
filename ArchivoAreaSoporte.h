#ifndef ARCHIVOAREASOPORTE_H_INCLUDED
#define ARCHIVOAREASOPORTE_H_INCLUDED
#include "AreaSoporte.h"
#include <cstring>

class archivoAreaSoporte{
public:
    bool registrar(areaSoporte &area); //DESARROLLADA
    void bajaLogica(int idArea); //DESARROLLADA
    void altaLogica(int idArea); //DESARROLLADA
    bool modificar (areaSoporte &area); //DESARROLLADA
    bool creaAreaSoporte (areaSoporte &area); //DESARROLLADA
    areaSoporte leerAreaSoporte (int idArea); //DESARROLLADA
    int contarTotalAreaSoporte(); //DESARROLLADA
    void listarActivos(); //DESARROLLADA
    void listarTodos();  //DESARROLLADA
    void listarTodosPreview();
    archivoAreaSoporte();
    archivoAreaSoporte(std::string archivoArea);
    int obtenerSiguienteID(); //DESARROLLADA
private:
    std::string _archivoArea;

};


#endif // ARCHIVOAREASOPORTE_H_INCLUDED
