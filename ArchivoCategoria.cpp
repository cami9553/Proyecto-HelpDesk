#include <iostream> 
#include "ArchivoCategoria.h"
#include <cstring>
using namespace std;


ArchivoCategoria::ArchivoCategoria(){
 _archivo = "categorias.dat";

}

ArchivoCategoria::ArchivoCategoria(string archivo){
    _archivo = archivo;
}

int ArchivoCategoria::contarTotalCategorias(){

    FILE *p = fopen(_archivo.c_str(), "rb");

    if(p == NULL){
        return 0;
    }

    fseek(p,0,SEEK_END);

    int bytes = ftell(p);

    fclose(p);

    return bytes / sizeof(Categoria);
}
 
int ArchivoCategoria::obtenerSiguienteID(){

   return contarTotalCategorias() + 1;
}

bool ArchivoCategoria::registrar(Categoria &reg){

 FILE *f = fopen(_archivo.c_str(), "ab");

 if(f == NULL){
    return false;
}
 reg.setIdCategoria(obtenerSiguienteID());
 reg.setActivo(true);

 fwrite(&reg, sizeof(Categoria),1,f);

 fclose(f);

 return true;
}

void ArchivoCategoria::listarTodas(){

    Categoria cat;

    FILE *f = fopen(_archivo.c_str(), "rb");

    if(f == NULL){
        cout << "No existe el archivo de categorias." << endl;
        return;
    }

    int total = contarTotalCategorias();

    for(int i = 0; i < total; i++){

        fread(&cat, sizeof(Categoria), 1, f);

        cat.mostrar();
    }

    fclose(f);
}

void ArchivoCategoria::bajaLogica(int idCategoria){

    Categoria cat;

    FILE *f = fopen(_archivo.c_str(),"rb+");

    if(f == NULL){
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    fseek(f,(idCategoria - 1) * sizeof(Categoria),SEEK_SET);

    fread(&cat,sizeof(Categoria),1,f);

    cat.setActivo(false);

    fseek(f,(idCategoria - 1) * sizeof(Categoria),SEEK_SET);

    fwrite(&cat,sizeof(Categoria),1,f);

    fclose(f);

    cout << "La categoria fue dada de baja correctamente." << endl;
}