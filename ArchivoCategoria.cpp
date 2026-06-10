#include <iostream> 
#include "ArchivoCategoria.h"
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

