#include <iostream>
using namespace std;
#include "ArchivoUsuarios.h"
#include <cstring>
archivoUsuario::archivoUsuario(){
    _archivo = "usuarios.dat";
}
archivoUsuario::archivoUsuario(std::string archivo){
    _archivo = archivo;
}


archivoUsuario::contarTotalUsuarios(){
 int cant_registros;
 FILE *p = fopen(_archivo.c_str(),"rb");
 if(p == NULL){
        cout << "error de archivo en contar usuarios." << endl;
    exit(1);
 }
 fseek(p,0,SEEK_END);
 int bytes = ftell(p);
 fclose(p);

 cant_registros = bytes / sizeof(Usuario);
 return cant_registros;
}
archivoUsuario::obtenerSiguienteID(){
    int siguienteID;
    FILE *f = fopen(_archivo.c_str(),"rb");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    fseek(f,0,SEEK_END);
    int bytes = ftell(f);
    fclose(f);
    siguienteID = (bytes /sizeof(Usuario))+1;

    return siguienteID;
    }

void archivoUsuario::registrar(Usuario &reg){
    FILE *f = fopen(_archivo.c_str(),"ab");
    if(f == NULL){
        cout << "error al insertar usuario, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    int siguienteID = obtenerSiguienteID();
    reg.setIDUsuario(siguienteID);
    reg.setActivo(true);

    fwrite(&reg,sizeof(Usuario),1,f);
    fclose(f);
    }

bool archivoUsuario::validarLogin(const char *usuario, const char *clave, Usuario &reg){
    Usuario usr;
    int totalUsuario=contarTotalUsuarios();
    FILE *f = fopen(_archivo.c_str(),"rb");
    if (f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
    }
    for(int i=0;i<totalUsuario;i++){
        fread(&usr,sizeof(Usuario),1,f);//Para leer el registro en la posicion I
        if(strcmp(usr.getEmail(),usuario)== 0 && strcmp(usr.getClave(),clave)== 0 && usr.getActivo()== true){
            reg = usr;
            fclose(f);
            return true;
        }

    }

    fclose(f);
    return false;
}
void archivoUsuario::listarActivos(){
    Usuario usr;
    int totalUsuario=contarTotalUsuarios();
    FILE *f = fopen(_archivo.c_str(),"rb");
    if (f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
    }
    for(int i=0;i<totalUsuario;i++){
        fread(&usr,sizeof(Usuario),1,f);
        cout <<"Email:"<<usr.getEmail();
        cout << "Clave:"<<usr.getClave();

    }
}

