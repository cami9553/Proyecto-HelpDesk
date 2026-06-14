#include <iostream>
using namespace std;
#include "AreaSoporte.h"
#include <cstring>

areaSoporte::areaSoporte(){
}

areaSoporte::areaSoporte(int idAreaSoporte, std::string nombre, std::string descripcion, bool activo){
    _idAreaSoporte = idAreaSoporte;
    strcpy(_nombre,nombre.c_str());
    strcpy(_descripcion,descripcion.c_str());
    _activo = activo;
}

int areaSoporte::getIdAreaSoporte(){
    return _idAreaSoporte;
}
char* areaSoporte::getNombre(){
    return _nombre;
}

char* areaSoporte::getDescripcion(){
    return _descripcion;
    }
bool areaSoporte::getActivo(){
    return _activo;
    }
 //SETTERS
void areaSoporte::setIdAreaSoporte(int id){
    _idAreaSoporte = id;
    }
void areaSoporte::setNombre(std::string nombre){
    strcpy(_nombre,nombre.c_str());
    }
void areaSoporte::setDescripcion(std::string descripcion){
    strcpy(_descripcion,descripcion.c_str());
    }
void areaSoporte::setActivo(bool activo){
    _activo = activo;
    }
