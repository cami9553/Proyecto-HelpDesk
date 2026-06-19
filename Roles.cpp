#include <iostream>
using namespace std;
#include "Roles.h"
#include <cstring>

roles::roles(){

}

roles::roles(int idRol,std::string descripcion, bool estado){
    _idRol = idRol;
    strcpy(_descripcion,descripcion.c_str());
    _estado = estado;
}

int roles::getIdRol(){
    return _idRol;
}

char* roles::getDescripcion(){
    return _descripcion;
}

bool roles::getEstado(){
    return _estado;
}

void roles::setIdRol(int id){
    _idRol = id;
}
void roles::setDescripcion(std::string descripcion){
    strcpy(_descripcion,descripcion.c_str());
}
void roles::setEstado(bool estado){
    _estado = estado;
}
