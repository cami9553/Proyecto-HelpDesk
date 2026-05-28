#include <iostream>
using namespace std;
#include "Usuario.h"
#include <cstring>


Usuario::Usuario(){

    _idUsuario = 0;

    strcpy(_Email,"");
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_clave,"");

    _idrol = 0;

    _activo = false;
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


void Usuario::mostrar(){

cout<<"------------------------"<<endl;

    cout<<"ID Usuario: "<<_idUsuario<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"Email: "<<_Email<<endl;
    cout<<"ID rol: "<<_idrol<<endl;

    if(_activo){
        cout<<"Estado: ACTIVO"<<endl;
    }
    else{
        cout<<"Estado: INACTIVO"<<endl;
    }

    cout<<"------------------------"<<endl;
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
