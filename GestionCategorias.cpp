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
        cout << "Error al guardad la categoria." << endl;
    }
        system("pause");

}

void BajaCategoria(){

}

void ModificarCategoria(){

}

void ListarCategorias(){

    ArchivoCategoria arch;

     cout << "LISTADO DE CATEGORIAS" << endl;

     arch.listarTodas();
     system("pause");

}