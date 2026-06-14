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

admin.setEmail("admin@mail.com");
admin.setClave("1234");
admin.setNombre("Admin");
admin.setApellido("Ad");
admin.setIdRol(1);
admin.setActivo(true);

arch.registrar(admin);

cout <<"[Sistema]: Se ha creado el usuario administrador Inicial."<< endl;
cout << "--> Email:admin@mail.com| Clave :1234" << endl;
    }


int main()
{
    archivoUsuario arc;
    crearAdminAviso();
    //system("cls");
    //arc.listarActivos();
    //arc.bajaLogica(1);
    //arc.altaLogica(1);
    //arc.listarTodos();
    //arc.listarPorRol(2);
    //cout << arc.contarActivos();
    //system("pause");
    ingresoUsuarios();
}
