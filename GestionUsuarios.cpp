#include <iostream>
#include "GestionUsuarios.h"
#include "ArchivoUsuarios.h"
#include "usuarios.h"


using namespace std;

void AltaUsuario(){

    Usuario reg;
    archivoUsuario arch;

    reg.Cargar();

    if(arch.Guardar(reg)){
        cout << "Guadado correctamente" << endl;
    }

    else{
        cout << "Error al guardar el usuario" << endl;
    }

}