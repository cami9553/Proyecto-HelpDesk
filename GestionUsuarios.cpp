#include <iostream>
#include "GestionUsuarios.h"
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>

using namespace std;

void AltaUsuario(){

    Usuario reg;
    archivoUsuario arch;
    bool guardado;

    guardado = reg.cargar();

    if(guardado == true){

      Usuario usuarioEncontrado = arch.buscarPorEmail(reg.getEmail());
      if(usuarioEncontrado.getIDUsuario() != -1){
        cout << "Error. Ya existe un usuario activo con ese mail." << endl;
        return;
      }

    if(arch.registrar(reg)){
      cout << "Usuario guardado correctamente" << endl;
 }
    else{
        cout << "Error al guardar el usuario" << endl;
    }
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


  if( id >= 1 && id <= cantidad){

     arch.bajaLogica(id);
     cout << "-------------------------------------------" << endl;
     cout << "Usuario dado de baja correctamente." << endl;
  }

  else {
    cout << "Error. ID no encontrado." << endl;

  }

}



void listarUsuarios(){

    archivoUsuario arch;
    arch.listarTodos();

    system("pause");

}

void VerRespuestasTicket();

void CargarUsuariosPrueba(){


  archivoUsuario arch;
  Usuario usr;

  usr.setNombre("Soporte2");
  usr.setApellido("Test");
  usr.setEmail("soporte2@mail.com");
  usr.setClave("1234");
  usr.setIdRol(2);
  usr.setActivo(true);

  if(arch.registrar(usr)){
    cout << "Usuario soporte2@mail.com cargado. " << endl;
  }

  usr.setNombre("Soporte3");
  usr.setApellido("Test");
  usr.setEmail("soporte3@mail.com");
  usr.setClave("1234");
  usr.setIdRol(2);
  usr.setActivo(true);

  if(arch.registrar(usr)){
    cout << "Usuario soporte3@mail.com cargado." << endl;
  }

  usr.setNombre("Cliente3");
  usr.setApellido("Test");
  usr.setEmail("cliente3@mail.com");
  usr.setClave("1234");
  usr.setIdRol(3);
  usr.setActivo(true);

  if(arch.registrar(usr)){
    cout << "Usuario cliente3@mail.com cargado." << endl;
  }
  cout << "Carga de usuarios de prueba finalizada." << endl;
  system("pause");
}
