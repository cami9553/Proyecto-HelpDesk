#include <iostream>
using namespace std;
#include "ArchivoRoles.h"
#include <cstring>


rolesArchivo::rolesArchivo(){
    _archivo = "Roles.dat";
}

rolesArchivo::rolesArchivo(std::string archivo){
    _archivo = archivo;
    }

int rolesArchivo::obtenerSiguienteID(){
    int siguienteID;
    FILE *f = fopen(_archivo.c_str(),"rb");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    fseek(f,0,SEEK_END);
    int bytes = ftell(f);
    fclose(f);
    siguienteID = (bytes /sizeof(roles))+1;

    return siguienteID;
    }

bool rolesArchivo::registrar(roles &reg){
    FILE *f = fopen(_archivo.c_str(),"ab");
    if(f == NULL){
        cout << "error al insertar usuario, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    int siguienteID = obtenerSiguienteID();
    reg.setIdRol(siguienteID);
    reg.setEstado(true);

    fwrite(&reg,sizeof(roles),1,f);
    fclose(f);

    return true;
}
void rolesArchivo::bajaLogica(int idRol){
     roles rol;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "Error al abrir el archivo, el sistema se cerrara."<<endl;
        exit(1);
    }
    fseek(f,(idRol - 1)* sizeof(roles),SEEK_SET); // SEEK_SET --> Comienzo del archivo
    fread(&rol,sizeof(roles),1,f); //Para leer el registro en la posicion que nos colocamos
    rol.setEstado(false);
    fseek(f,(idRol - 1) * sizeof(roles),SEEK_SET); //el fread nos movio el puntero hacia adelante por eso estos pasos devuelta.
    fwrite(&rol,sizeof(roles),1,f);
    fclose(f);
    cout << "El rol en la posicion:"<< idRol << " Se dio de baja exitosamente." << endl;

}

void rolesArchivo::altaLogica(int idRol){
     roles rol;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "Error al abrir el archivo, el sistema se cerrara."<<endl;
        exit(1);
    }
    fseek(f,(idRol - 1)* sizeof(roles),SEEK_SET); // SEEK_SET --> Comienzo del archivo
    fread(&rol,sizeof(roles),1,f); //Para leer el registro en la posicion que nos colocamos
    rol.setEstado(true);
    fseek(f,(idRol - 1) * sizeof(roles),SEEK_SET); //el fread nos movio el puntero hacia adelante por eso estos pasos devuelta.
    fwrite(&rol,sizeof(roles),1,f);
    fclose(f);
    cout << "El rol en la posicion:"<< idRol << " Se dio de baja exitosamente." << endl;

}

bool rolesArchivo::modificar(roles &reg){
    int pos =  reg.getIdRol() - 1;

    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL)
    {
        cout << "Error al abrir el archivo, el sistema se cerrara."<<endl;
        exit(1);
    }

    fseek(f,pos * sizeof(roles),SEEK_SET);
    bool guardado = (fwrite(&reg,sizeof(roles),1,f) == 1);

    fclose(f);

    return guardado;


}

roles rolesArchivo::leerRol(int idRol){
    roles rol;
    FILE *f;
    f=fopen(_archivo.c_str(),"rb+");
    if(f==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN LEER CLIENTE"<<endl;
        exit(1);
    }
    fseek(f, idRol * sizeof(roles),0);
    fread(&rol, sizeof(roles), 1,f);
    fclose(f);
    return rol;

}
int rolesArchivo::contarTotalRoles(){
 int cant_registros;
 FILE *p = fopen(_archivo.c_str(),"rb");
 if(p == NULL){
        cout << "error de archivo en contar usuarios." << endl;
    exit(1);
 }
 fseek(p,0,SEEK_END);
 int bytes = ftell(p);
 fclose(p);

 cant_registros = bytes / sizeof(roles);
 return cant_registros;
}


void rolesArchivo::listarTodos(){
    roles rol;
    int i=0;
    int totalUsuarios = contarTotalRoles();
    for(i=0;i<totalUsuarios;i++){
         rol = leerRol(i);
        cout << "==========================" << endl;
        cout <<"idrol:"<<rol.getIdRol()<<endl;
        cout <<"descripcion:"<<rol.getDescripcion()<<endl;
        cout <<"estado:"<<rol.getEstado()<<endl;
        cout << "==========================" << endl;
    }

}
