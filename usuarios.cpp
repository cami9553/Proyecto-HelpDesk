#include <iostream>
using namespace std;
#include "usuarios.h"
#include <cstring>
#include "Roles.h"
#include "ArchivoRoles.h"
#include "ArchivoUsuarios.h"
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

    bool Usuario::cargar(){
        char email[30], nombre[30], apellido[30], clave[30];
        int rol;
        int i=0;
        archivoUsuario archU;
        rolesArchivo rArchivo;
        roles rolLeido;
        Usuario usr;
        bool validar1 = false;
        bool validar2;
        cout << "Email: ";
        cin >> email;
        cin.ignore();
        for(i=0;i<archU.contarTotalUsuarios();i++){
            usr = archU.leerUsuario(i);
            if(strcmp(usr.getEmail(),email)==0){
                validar1 = true;
                cout << "EL email ya se encuentra registrado." << endl;
                return false;
            }else{
                validar1 = false;
            }
        }

        cout << "Nombre: ";
        cin.getline(nombre,30);

        cout << "Apellido: ";
        cin.getline(apellido,30);

        cout << "Clave: ";
        cin >> clave;

        cout << "Los roles existentes son: " << endl;
        rArchivo.listarTodos();
        cin >> rol;

        int cantrol = rArchivo.contarTotalRoles();
        if(rol>0 and rol <=cantrol){
            rolLeido = rArchivo.leerRol(rol-1);
            if(rolLeido.getEstado()==1){
                setEmail(email);
                setNombre(nombre);
                setApellido(apellido);
                setClave(clave);
                setIdRol(rol);
                validar2 = true;
            }else{
                cout << "El rol que eligio no se encuentra activo." << endl;
                return false;
                }
        }else{
            cout << "Rol Inexistente"<<endl;
            validar2 = false;
            }
        if(validar1==false and validar2==true){
            return true;
        }else{
            return false;
        }
    }
