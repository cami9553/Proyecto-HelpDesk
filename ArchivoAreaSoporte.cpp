#include <iostream>
using namespace std;
#include <cstring>
#include "ArchivoAreaSoporte.h"


archivoAreaSoporte::archivoAreaSoporte(){
    _archivoArea = "areaSoporte.dat";
}
archivoAreaSoporte::archivoAreaSoporte(std::string archivoArea){
    _archivoArea = archivoArea;
}

int archivoAreaSoporte::obtenerSiguienteID(){
    int siguienteID;
    FILE *f = fopen(_archivoArea.c_str(),"rb");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    fseek(f,0,SEEK_END);
    int bytes = ftell(f);
    fclose(f);
    siguienteID = (bytes /sizeof(areaSoporte))+1;

    return siguienteID;
    }


bool archivoAreaSoporte::registrar(areaSoporte &area){
    bool registro;
    FILE *f = fopen(_archivoArea.c_str(),"ab");
    if(f == NULL){
        cout << "error de archivo en contar usuarios." << endl;
        exit(1);
    }
    int siguienteID = obtenerSiguienteID();
    area.setIdAreaSoporte(siguienteID);
    area.setActivo(true);

    registro = fwrite(&area,sizeof(areaSoporte),1,f);
    fclose(f);
    return registro;
}
void archivoAreaSoporte::bajaLogica(int idArea){
    areaSoporte are;
    FILE *f = fopen(_archivoArea.c_str(),"rb+");
    if(f == NULL){
        cout << "error de archivo en contar usuarios." << endl;
        exit(1);
    }
    fseek(f,(idArea - 1)* sizeof(areaSoporte),SEEK_SET);
    fread(&are,sizeof(areaSoporte),1,f);
    are.setActivo(false);
    fseek(f,(idArea - 1)* sizeof(areaSoporte),SEEK_SET);
    fwrite(&are,sizeof(areaSoporte),1,f);
    fclose(f);
    cout << "El area en la posicion "<< idArea << "Se dio de baja exitosamente. ";
}
void archivoAreaSoporte::altaLogica(int idArea){
    areaSoporte are;
    FILE *f = fopen(_archivoArea.c_str(),"rb+");
    if(f == NULL){
        cout << "error de archivo en contar usuarios." << endl;
        exit(1);
    }
    fseek(f,(idArea - 1)* sizeof(areaSoporte),SEEK_SET);
    fread(&are,sizeof(areaSoporte),1,f);
    are.setActivo(true);
    fseek(f,(idArea - 1)* sizeof(areaSoporte),SEEK_SET);
    fwrite(&are,sizeof(areaSoporte),1,f);
    fclose(f);
    cout << "El area en la posicion "<< idArea << "Se dio de Alta exitosamente. ";
}

bool archivoAreaSoporte::creaAreaSoporte(areaSoporte &AR){
    FILE *f = fopen(_archivoArea.c_str(),"ab");
    if(f == NULL){
        cout << "error al abrir el archivo area soporte" << endl;
        exit(1);
    }
    int siguienteID = obtenerSiguienteID();
    AR.setIdAreaSoporte(siguienteID);
    AR.setActivo(true);

    fwrite(&AR,sizeof(areaSoporte),1,f);
    fclose(f);

    return true;
}

areaSoporte archivoAreaSoporte::leerAreaSoporte(int idArea){
    areaSoporte ar;
    FILE *f = fopen(_archivoArea.c_str(),"rb+");
    if(f == NULL){
        cout << "error de archivo en contar usuarios." << endl;
        exit(1);
    }
    fseek(f,(idArea - 1)* sizeof(areaSoporte),0);
    fread(&ar,sizeof(areaSoporte),1,f);
    fclose(f);
    return ar;
}

bool archivoAreaSoporte::modificar(areaSoporte &ar){

    int pos = ar.getIdAreaSoporte() - 1;



    FILE *f = fopen(_archivoArea.c_str(),"rb+");

    if(f == NULL){

        cout << "Error al abrir el archivo area soporte."<< endl;

        exit(1);

    }

    fseek(f,pos * sizeof(areaSoporte),SEEK_SET);

    bool guardado = (fwrite(&ar,sizeof(areaSoporte),1,f)==1);

    fclose(f);

    return guardado;

}


int archivoAreaSoporte::contarTotalAreaSoporte(){
 int cant_registros;
 FILE *p = fopen(_archivoArea.c_str(),"rb");
 if(p == NULL){
        cout << "error de archivo en contar usuarios." << endl;
    exit(1);
 }
 fseek(p,0,SEEK_END);
 int bytes = ftell(p);
 fclose(p);

 cant_registros = bytes / sizeof(areaSoporte);
 return cant_registros;
}
void archivoAreaSoporte::listarActivos(){
    areaSoporte ar;
    int totalArea =contarTotalAreaSoporte();
    FILE *f = fopen(_archivoArea.c_str(),"rb");
    if (f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
    }
    for(int i=0;i<totalArea;i++){
        fread(&ar,sizeof(areaSoporte),1,f);
        if(ar.getActivo() == true){
            cout << "Id: " << ar.getIdAreaSoporte() <<endl;
            cout <<"Nombre: "<<ar.getNombre()<<endl;
            cout << "Descripcion: "<<ar.getDescripcion() <<endl;
        }
    }
    fclose(f);
}

void archivoAreaSoporte::listarTodos(){
    areaSoporte ar;
    int totalArea = contarTotalAreaSoporte();
    FILE *f = fopen(_archivoArea.c_str(),"rb");
    if(f == NULL){
        cout << "Error al abrir el archivo, el sistema se cerrara" << endl;
        exit(1);
    }
    for(int i=0;i<totalArea;i++){
        fread(&ar,sizeof(areaSoporte),1,f);

            cout << "Id: " << ar.getIdAreaSoporte()<<endl;
            cout << "Nombre: "<<ar.getNombre()<<endl;
            cout << "Descripcion: "<<ar.getDescripcion() <<endl;
            cout << "Estado: " << ar.getActivo()<<endl;

    }
    fclose(f);

}
