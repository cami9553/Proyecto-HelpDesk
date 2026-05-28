#include <iostream>
using namespace std;
#include "usuarios.h"
#include <cstring>

Usuario::Usuario(){

}

Usuario::Usuario(int idUsuario,std::string email, std::string nombre, std::string apellido, std::string clave, int idRol, bool activo){
    _idUsuario = idUsuario;
    strcpy(_Email,email.c_str());
    strcpy(_nombre,nombre.c_str());
    strcpy(_apellido,apellido.c_str());
    strcpy(_clave,clave.c_str());
    _idrol = idRol;
    _activo = activo;
}
// GETTERS
int Usuario::getIDUsuario(){
    return _idUsuario;
    }
const char* Usuario::getEmail(){
    return _Email;
}
const char* Usuario::getNombre(){
    return _nombre;
}
const char* Usuario::getApellido(){
    return _apellido;
}
const char* Usuario::getClave(){
    return _clave;
}
int Usuario::getRol(){
    return _idrol;
    }
bool Usuario::getActivo(){
    return _activo;
    }
//SETTERS:
void Usuario::setIDUsuario(int id){
    _idUsuario = id ;
}
void Usuario::setEmail(std::string email){
    strcpy(_Email,email.c_str());
    }
void Usuario::setNombre(std::string name){
    strcpy(_nombre,name.c_str());
    }
void Usuario::setApellido(std::string ape){
    strcpy(_apellido,ape.c_str());
    }
void Usuario::setClave(std::string clave){
    strcpy(_clave,clave.c_str());
    }
void Usuario::setIdRol(int rol){
    _idrol = rol;
    }
void Usuario::setActivo(bool act){
    _activo = act;
}

