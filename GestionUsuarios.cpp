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
 archivoUsuario arch;
 int id;
 int cantidad;
 cout << "--------------------------------------------" << endl;
 cout << "Ingrese el ID del usuario a dar de baja: " << endl;
 cin >> id;

 cantidad = arch.contarTotalUsuarios();

 arch.contarTotalUsuarios();

  if( id >= 1 && id <= cantidad){

     arch.bajaLogica(id);
     cout << "-------------------------------------------" << endl;
     cout << "Usuario dado de baja correctamente." << endl;
  }
  
  else {
    cout << "Error. ID no encontrado." << endl;

  }

}


void ModificacionUsuario(){

}

void listarUsuarios(){

}