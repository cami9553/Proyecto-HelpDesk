#include <iostream>
using namespace std;
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"
void crearAdminAviso(){
archivoUsuario arch;

if(arch.contarTotalUsuarios() > 0){
   return;
}
Usuario admin;

admin.setEmail("admin");
admin.setClave("1234");
admin.setNombre("Admin");
admin.setApellido("Ad");
admin.setIdRol(1);
admin.setActivo(true);

arch.registrar(admin);

cout <<"[Sistema]: Se ha creado el usuario administrador Inicial."<< endl;
cout << "--> Email:admin | Clave :1234" << endl;
    }


int main()
{
    crearAdminAviso();
    ingresoUsuarios();
}
