#include <iostream>
using namespace std;

#include "GestionCategorias.h"
#include "ArchivoCategoria.h"
#include "Categoria.h" 

void AltaCategoria(){

    Categoria reg;
    ArchivoCategoria arch;

    cout << "Alta categoria" << endl;

    reg.cargar();

    if(arch.registrar(reg)){
        cout << "Categoria guardada correctamente." << endl;
    }
    else{
        cout << "Error al guardar la categoria." << endl;
    }
        system("pause");

}

void BajaCategoria(){
    
    ArchivoCategoria arch;
    int id;
    arch.listarTodas();
    cout << "Ingrese el ID de la categoria a dar de baja: ";
    cin >> id;
    int cantidad = arch.contarTotalCategorias();
    if(id >= 1 && id <= cantidad){
        arch.bajaLogica(id);
    }else{
        cout << "ID no valido." << endl;
    }
    system("pause");

}

void ModificarCategoria(){
 ArchivoCategoria arch;
 Categoria reg;

 int id;
 int cantidad;
 int pos = -1;

 cout << "Ingrese ID de categoria a modificar: ";
 cin >> id;

 cantidad = arch.contarTotalCategorias();

 for(int i = 0; i < cantidad; i++){
    reg = arch.leerCategoria(i);

    if(reg.getIdCategoria() == id){
        pos = i;
        break;
    }
 }

 if(pos == -1){
    cout << "No se encontro la categoria." << endl;
    system("pause");
    return;
 }

 reg = arch.leerCategoria(pos);

    cout << "Categoria encontrada:" << endl;
    reg.mostrar();

    char nuevoNombre[30];

    cout << "Ingrese nuevo nombre: ";
    cin.ignore();
    cin.getline(nuevoNombre, 30);

    reg.setNombre(nuevoNombre);

    if(arch.modificarCategoria(reg, pos)){
        cout << "Categoria modificada correctamente." << endl;
    }
    else{
        cout << "Error al modificar la categoria." << endl;
    }

    system("pause");
}


void ListarCategorias(){

    ArchivoCategoria arch;

     cout << "LISTADO DE CATEGORIAS" << endl;

     arch.listarTodas();
     system("pause");

}