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


int archivoUsuario::contarTotalUsuarios(){
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
int archivoUsuario::obtenerSiguienteID(){
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

bool archivoUsuario::registrar(Usuario &reg){
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

    return true;
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
        if(usr.getActivo()==true){
            cout <<"Email:"<<usr.getEmail()<<endl;
            cout << "Clave:"<<usr.getClave()<<endl;
        }
    }
    fclose(f);
}

void archivoUsuario::bajaLogica(int idUsuario){
    Usuario usr;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "Error al abrir el archivo, el sistema se cerrara."<<endl;
        exit(1);
    }
    fseek(f,(idUsuario - 1)* sizeof(Usuario),SEEK_SET); // SEEK_SET --> Comienzo del archivo
    fread(&usr,sizeof(Usuario),1,f); //Para leer el registro en la posicion que nos colocamos
    usr.setActivo(false);
    fseek(f,(idUsuario - 1) * sizeof(Usuario),SEEK_SET); //el fread nos movio el puntero hacia adelante por eso estos pasos devuelta.
    fwrite(&usr,sizeof(Usuario),1,f);
    fclose(f);
    cout << "El usuario en la posicion:"<< idUsuario << " Se dio de baja exitosamente." << endl;
}

Usuario archivoUsuario::leerUsuario(int idUsr){
    Usuario usr;
    FILE *f;
    f=fopen(_archivo.c_str(),"rb+");
    if(f==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN LEER CLIENTE"<<endl;
        exit(1);
    }
    fseek(f, idUsr * sizeof(Usuario),0);
    fread(&usr, sizeof(Usuario), 1,f);
    fclose(f);
    return usr;
    }

void archivoUsuario::listarTodos(){
    Usuario usr;
    int i=0;
    int totalUsuarios = contarTotalUsuarios();
    for(i=0;i<totalUsuarios;i++){
         usr = leerUsuario(i);
        cout <<"IdUsuario:"<<usr.getIDUsuario()<<endl;
        cout <<"Email:"<<usr.getEmail()<<endl;
        cout <<"Nombre:"<<usr.getNombre()<<endl;
        cout <<"Apellido:"<<usr.getApellido()<<endl;
        cout <<"Rol:"<<usr.getRol()<<endl;
        cout <<"Activo:"<<usr.getActivo()<<endl;
    }

}
void archivoUsuario::altaLogica(int idUsuario){
    Usuario usr;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "Error al abrir el archivo, el sistema se cerrara."<<endl;
        exit(1);
    }
    fseek(f,(idUsuario - 1)* sizeof(Usuario),SEEK_SET); // SEEK_SET --> Comienzo del archivo
    fread(&usr,sizeof(Usuario),1,f); //Para leer el registro en la posicion que nos colocamos
    usr.setActivo(true);
    fseek(f,(idUsuario - 1) * sizeof(Usuario),SEEK_SET); //el fread nos movio el puntero hacia adelante por eso estos pasos devuelta.
    fwrite(&usr,sizeof(Usuario),1,f);
    fclose(f);
    cout << "El usuario en la posicion:"<< idUsuario << " Se dio de alta exitosamente." << endl;
}
void archivoUsuario::listarPorRol(int idRol){
    int i=0;
    Usuario usr;
    int totalUsuarios = contarTotalUsuarios();
    for(i=0;i<totalUsuarios;i++){
         usr = leerUsuario(i);
        if(usr.getRol()==idRol){
            cout <<"IdUsuario:"<<usr.getIDUsuario()<<endl;
            cout <<"Email:"<<usr.getEmail()<<endl;
            cout <<"Nombre:"<<usr.getNombre()<<endl;
            cout <<"Apellido:"<<usr.getApellido()<<endl;
            cout <<"Rol:"<<usr.getRol()<<endl;
            cout <<"Activo:"<<usr.getActivo()<<endl;
        }
    }
}
int archivoUsuario::contarActivos(){
 Usuario usr;
    int i,cont=0;
    int totalUsuarios = contarTotalUsuarios();
    for(i=0;i<totalUsuarios;i++){
        Usuario usr = leerUsuario(i);
        if(usr.getActivo()==true){
            cont++;
        }
    }
    return cont;
}
Usuario archivoUsuario::buscarPorEmail(const char *usuario){
    int i=0;
    Usuario usr;
    int totalUsuarios = contarTotalUsuarios();
    for(i=0;i<totalUsuarios;i++){
        Usuario usrAct = leerUsuario(i);
        if(strcmp(usrAct.getEmail(),usuario)==0 && usrAct.getActivo()==1){
            cout <<"IdUsuario:"<<usrAct.getIDUsuario()<<endl;
            cout <<"Email:"<<usrAct.getEmail()<<endl;
            cout <<"Nombre:"<<usrAct.getNombre()<<endl;
            cout <<"Apellido:"<<usrAct.getApellido()<<endl;
            cout <<"Rol:"<<usrAct.getRol()<<endl;
            cout <<"Activo:"<<usrAct.getActivo()<<endl;

            return usrAct;
                }
            }
    Usuario usrVacio;
    usrVacio.setIDUsuario(-1);
    return usrVacio;
}
bool archivoUsuario::modificar(Usuario &reg){
    int pos = reg.getIDUsuario() - 1;

    FILE *f ;
    f=fopen(_archivo.c_str(),"rb+");
    if(f==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN LEER CLIENTE"<<endl;
        exit(1);
    }

    fseek(f, pos * sizeof(Usuario),SEEK_SET);

    bool guardado = (fwrite(&reg,sizeof(Usuario),1,f)== 1);

    fclose(f);
    return guardado;
}
