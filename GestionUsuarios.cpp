#include <iostream>
#include "GestionUsuarios.h"
#include "ArchivoUsuarios.h"
#include "usuarios.h"


using namespace std;

void AltaUsuario(){

    Usuario reg;
    archivoUsuario arch;

    reg.cargar();

    if(arch.registrar(reg)){
      cout << "Usuario guardado correctamente" << endl;
 }

    else{
        cout << "Error al guardar el usuario" << endl;
    }

}
void BajaUsuario(){

}

void ModificacionUsuario(){

}

void listarUsuarios(){

}