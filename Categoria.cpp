#include <iostream> 
#include <cstring>
using namespace std;

#include "Categoria.h"

Categoria::Categoria(){
    _idCategoria = 0;
    strcpy(_nombre, "");
    _activo = true;
}

void Categoria::setIdCategoria(int id){
    _idCategoria = id;
}

void Categoria::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Categoria::setActivo(bool activo){
    _activo = activo;
}

int Categoria::getIdCategoria(){
    return _idCategoria;
}

const char* Categoria::getNombre(){
    return _nombre;
}

bool Categoria::getActivo(){
    return _activo;
}

void Categoria::cargar(){
    cout << "ID categoria: ";
    cin >> _idCategoria;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(_nombre,30);
    _activo = true;
}

void Categoria::mostrar(){
    cout << "ID: " << _idCategoria << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Estado: ";

    if(_activo){
        cout << "Activa" << endl;
    }else {
        cout << "Inactiva" << endl;

    }

    cout << "-----------------------------" << endl;
}


