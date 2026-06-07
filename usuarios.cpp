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
void Usuario::mostrar(){

    cout << "================================="<< endl;
    cout << "            Mis Datos            "<< endl;
    cout << "================================="<< endl;
    cout << " ID Usuario: " << getIDUsuario() << endl;
    cout << " Nombre:     " << getNombre() << endl;
    cout << " Apellido:   " << getApellido() << endl;
    cout << " Email:      " << getEmail() << endl;
    cout << "================================="<< endl;

    system("pause");

    }

    void Usuario::cargar(){
        string email, nombre, apellido, clave;
        int rol;

        cout << "Email: ";
        cin >> email;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Apellido: ";
        cin >> apellido;

        cout << "Clave: ";
        cin >> clave;

        cout << "Rol: ";
        cin >> rol;

        setEmail(email);
        setNombre(nombre);
        setApellido(apellido);
        setClave(clave);
        setIdRol(rol);

    }
