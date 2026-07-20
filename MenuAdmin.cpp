#include <iostream>
using namespace std;
#include "Menus.h"
#include "MenuAdmin.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "GestionUsuarios.h"
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include "MenuAdmiConfiguracion.h"
#include "GestionCategorias.h"
#include "ArchivoCategoria.h"
#include "ArchivoAreaSoporte.h"
#include "Roles.h"
#include "ArchivoRoles.h"
#include "GestionEstadisticas.h"
#include "GestionTickets.h"

void MostrarMenuAdmin(Usuario &user1);
void MostrarMenuAdmin(Usuario &user1){

    Ticket t1;
    TickeArchivo Archivo;

    int opcion;
    int cantidad;

    do{
        system("cls");
        cout << "====================================" << endl;
        cout << "|           MENU ADMINISTRADOR     |" << endl;
        cout << "====================================" << endl;
        cout << "| 1) GESTION DE USUARIOS           |" << endl;
        cout << "| 2) GESTION DE TICKETS            |" << endl;
        cout << "| 3) GESTION DE CATEGORIAS         |" << endl;
        cout << "| 4) GESTION DE AREAS DE SOPORTE   |" << endl;
        cout << "| 5) GESTION DE ROLES              |" << endl;
        cout << "| 6) ESTADISTICAS                  |" << endl;
        cout << "| 7) CONFIGURACION                 |" << endl;
        cout << "====================================" << endl;
        cout << "| 0- CERRAR SESION                 |" << endl;
        cout << "====================================" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch(opcion){

            case 1:
           system("cls");
           MenuGestionUsuarios();
           break;

           case 2:
           system("cls");
           MenuGestionTickets();
           break;

           case 3:
           system("cls");
           MenuGestionCategorias();
           break;

           case 4:
           system("cls");
           MenuGestionAreasSoporte();
           break;

           case 5:
           system("cls");
           MenuGestionRoles();
           break;

           case 6:
           system("cls");
           MenuGestionEstadisticas();
           break;

           case 7:
           system("cls");
           MenuAdmiConfiguracion(user1);
           break;


           case 0:
           system("cls");
           cout << "Sesion cerrada." << endl;
           break;

           default:
           cout << "Opcion invalida. " << endl;
           break;
        }

        } while(opcion != 0);

}

void menuModificarAdmin(){
archivoUsuario arch;
bool guardado;
int opcion,usrAModificar,nuevoValorRol;
char nuevoValor[30];
   cout << "preview de usuarios: "<< endl;
   arch.listarTodosPreview();
   system("pause");
   system("cls");
   cout << "=============================================" << endl;
   cout << "|  Ingrese el idUsuario que desea modificar: |"<<endl;
   cout << "=============================================" << endl;
   cin  >> usrAModificar;
   cout << "==========================" << endl;

   int cantidad = arch.contarTotalUsuarios();

    if(usrAModificar < 1 || usrAModificar > cantidad){
        cout << "ID no valido." << endl;
        system("pause");
        return;
    }

    Usuario usrAEditar = arch.leerUsuario(usrAModificar - 1);

    if(usrAEditar.getIDUsuario() != usrAModificar){
        cout << "Usuario no encontrado." << endl;
        system("pause");
        return;
    }

    do{
        system("cls");
        cout << "==========================" << endl;
        cout << "| QUE DESEA MODIFICAR?   |" << endl;
        cout << "==========================" << endl;
        cout << "| 1) Nombre              |" << endl;
        cout << "| 2) Apellido            |" << endl;
        cout << "| 3) Email               |" << endl;
        cout << "| 4) Clave               |" << endl;
        cout << "| 5) Rol                 |" << endl;
        cout << "==========================" << endl;
        cout << "| 0) Salir.              |" << endl;
        cout << "==========================" << endl;
        cin >> opcion;

        switch(opcion){
    case 1:
        system("cls");
        cout << "Ingrese nuevo nombre: "<< endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrAEditar.setNombre(nuevoValor);

        guardado = arch.modificar(usrAEditar);
        if(guardado == true){
            cout <<"Nuevo nombre guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo nombre."<<endl;
            }
        system("pause");
        break;
    case 2:
        system("cls");
        cout << "Ingrese nuevo Apellido: " << endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrAEditar.setApellido(nuevoValor);

        guardado = arch.modificar(usrAEditar);
        if(guardado == true){
            cout <<"Nuevo Apellido guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo Apellido."<<endl;
            }
        system("pause");
        break;
    case 3:
        system("cls");
        cout << "Ingrese el nuevo email: " << endl;
        cin >> nuevoValor;
        usrAEditar.setEmail(nuevoValor);

        guardado = arch.modificar(usrAEditar);
        if(guardado == true){
            cout <<"Nuevo Email guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo email."<<endl;
            }
        system("pause");
        break;
    case 4:
        system("cls");
        cout << "Ingrese la nueva clave: " << endl;
        cin >> nuevoValor;
        usrAEditar.setClave(nuevoValor);

        guardado = arch.modificar(usrAEditar);
        if(guardado == true){
            cout <<"Nueva clave guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar la nueva clave."<<endl;
            }
        system("pause");
        break;
    case 5:
        system("cls");
        cout << "Ingrese el nuevo rol: " << endl;
        cin >> nuevoValorRol;
        usrAEditar.setIdRol(nuevoValorRol);

        guardado = arch.modificar(usrAEditar);
        if(guardado == true){
            cout <<"Nuevo rol guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo rol."<<endl;
            }
        system("pause");
        break;
    case 0:
        system("cls");
        cout << "Saliendo del menu modificar!" << endl;
        break;
        }

        }while(opcion != 0);


    }

void MenuAdmiConfiguracion(Usuario &user1){

    int opcion;

    do{
        cout << "======================================" << endl;
        cout << "| 1) Cambiar Clave                   |" << endl;
        cout << "| 2) Ver Mis Datos                   |" << endl;
        cout << "| 3) Copia de Seguridad              |" << endl;
        cout << "| 4) Restaurar Copia                 |" << endl;
        cout << "| 5) Exportar CSV                    |" << endl;
        cout << "======================================" << endl;
        cout << "| 0) Volver                          |" << endl;
        cout << "======================================" << endl;

        cout << "OPCION: " ;
        cin >> opcion;
        cout << endl;

        if(cin.fail()){
        cout << "Algo salio mal. Debe ingresar un numero." << endl;

        cin.clear();
        cin.ignore();

        continue;

    }

    switch (opcion)
    {
    case 1:
        system("cls");
        cambiarContrasenia(user1);
        break;

    case 2:
        system("cls");
        verMisDatos(user1);
        break;

    case 3:
       system("cls");
       MenuBackup();
        break;

    case 4:
       system("cls");
       MenuRestauracion();
       break;
    case 5:
      system("cls");
      MenuExportacionCSV();
      break;

    case 0:
      system("cls");
      break;

    default:
     system("cls");
     cout << "Opcion invalida." << endl;
        break;
    }
    } while (opcion != 0);
}

    void MenuGestionCategorias(){
        int opcion;

    do{
        system("cls");
        cout << "====================================" << endl;
        cout << "|      GESTION DE CATEGORIAS       |" << endl;
        cout << "====================================" << endl;
        cout << "| 1) Crear Categoria               |" << endl;
        cout << "| 2) Alta/Baja Categoria           |" << endl;
        cout << "| 3) Modificar Categoria           |" << endl;
        cout << "| 4) Listar categorias             |" << endl;
        cout << "====================================" << endl;
        cout << "| 0) Volver                        |" << endl;
        cout << "====================================" << endl;

        cin >> opcion;

        switch(opcion){

            case 1:
            system("cls");
            AltaCategoria();
            break;

            case 2:
    {
            system("cls");
            int opcionEstado, idCat;
            ArchivoCategoria archCat;

            archCat.listarTodas();

            cout << "Desea Activar o Desactivar una categoria?" << endl;
            cout << "1-Activar" << endl;
            cout << "2-Desactivar" << endl;
            cin >> opcionEstado;

            if(opcionEstado == 1){
                cout << "Ingrese el ID de la categoria a activar: ";
                cin >> idCat;
                archCat.altaLogica(idCat);
            }else if(opcionEstado == 2){
                cout << "Ingrese el ID de la categoria a desactivar: ";
                cin >> idCat;
                archCat.bajaLogica(idCat);
            }else{
                cout << "Opcion invalida." << endl;
            }
            system("pause");
            }
            break;

            case 3:
            system("cls");
            ModificarCategoria();
            break;

            case 4:
            system("cls");
            ListarCategorias();
            break;

            case 0:
            system("cls");
            cout << "Volver al menu anterior" << endl;
            break;

            default:
            system("cls");
            cout << "Opcion invalida." << endl;
            break;

        }
    }while(opcion != 0);
}

void MenuGestionAreasSoporte(){
    int opcion;
    char nameAr[30];
    char descAr[30];
    archivoAreaSoporte arch;


    do{

       system("cls");
      cout << "====================================" << endl;
       cout << "|         MENU GESTION AREAS       |" << endl;
       cout << "====================================" << endl;
       cout << "| 1) CREAR AREA SOPORTE            |" << endl;
       cout << "| 2) ALTA AREA SOPORTE             |" << endl;
       cout << "| 3) BAJA AREA SOPORTE             |" << endl;
       cout << "| 4) MODIFICAR AREA SOPORTE        |" << endl;
       cout << "| 5) MOSTRAR AREAS SOPORTE         |" << endl;
       cout << "| 6) MOSTRAR AREA SOPORTE ACTIVAS  |" << endl;
       cout << "====================================" << endl;
       cout << "| 0) SALIR                         |" << endl;
       cout << "====================================" << endl;
       cin  >> opcion;
       cin.ignore();
       areaSoporte AR;
       int idAlta,idBaja;
       switch(opcion){
        case 1:
            system("cls");
            cout << "Ingrese el nombre del area nuevo: "<< endl;
            cin.getline(nameAr,30);
            AR.setNombre(nameAr);
            cout << "Ingrese descripcion del area nuevo: " << endl;
            cin.getline(descAr,30);
            AR.setDescripcion(descAr);
            arch.creaAreaSoporte(AR);
            break;
        case 2:
            system("cls");
            cout << "Ingresar el id que quiere volver a activar: " << endl;
            cin >> idAlta;
            arch.altaLogica(idAlta);
            break;
        case 3:
            system("cls");
            cout << "Ingresar el id que quiere dar de baja: " << endl;
            cin >> idBaja;
            arch.bajaLogica(idBaja);
            break;
        case 4:
            system("cls");
            menuModificarAreaSoporte();
            break;
        case 5:
            system("cls");
            arch.listarTodos();
            system("pause");
            break;
        case 6:
            system("cls");
            arch.listarActivos();
            system("pause");
            break;
       }

    }while(opcion !=0);

}

   void MenuGestionRoles(){
    int opcion;
    rolesArchivo rarch;
     char descr[30];
    do{
    system("cls");
     cout << "===================================" << endl;
    cout << "|        MENU GESTION ROLES       |" << endl;
    cout << "===================================" << endl;
    cout << "| 1) Crear Rol                    |" << endl;
    cout << "| 2) Modificacion Rol             |" << endl;
    cout << "| 3) Mostrar Roles                |" << endl;
    cout << "===================================" << endl;
    cout << "| 0) Salir                        |" << endl;
    cout << "===================================" << endl;
    cin >> opcion;
    cin.ignore();
    roles rol;
    if(opcion == 0){
        break;
    }
    switch(opcion){
case 1:
    system("cls");
    cout << "Ingrese la descripcion del nuevo ROL: "<< endl;
    cin.getline(descr,30);
    rol.setDescripcion(descr);
    rarch.registrar(rol);
    break;
case 2:
    system("cls");
    MenuModificarRoles();
    break;
case 3:
    system("cls");
    rarch.listarTodos();
    system("pause");
    break;
    }

        }while(opcion != 0);
}

void MenuGestionUsuarios(){

    int opcion;
    int OpcionEstado=0;
    int IdUsr;
    archivoUsuario archU;

    do{
        system("cls");
        cout << "================================" << endl;
        cout << "|      GESTION DE USUARIOS     |" << endl;
        cout << "================================" << endl;
        cout << "| 1) Crear                     |" << endl;
        cout << "| 2) Alta/Baja logica          |" << endl;
        cout << "| 3) Modificacion              |" << endl;
        cout << "| 4) Listado                   |" << endl;
        cout << "================================" << endl;
        cout << "| 0) volver                    |" << endl;
        cout << "================================" << endl;

        cin >> opcion;

        switch(opcion){

            case 1:


            system("cls");
            AltaUsuario();
            system("pause");
            break;

            case 2:
               {

            cout << "preview de usuarios: "<< endl;
            archU.listarTodosPreview();
            system("pause");
            system("cls");
<<<<<<< HEAD
=======

            int opcionEstado;
            int idUsr;
            int totalUsuarios = archU.contarTotalUsuarios();

>>>>>>> 983e3c2 (ajustes finales de menus y usuarios)
            cout << "===========================================" << endl;
            cout << "| Desea Activar o Desactivar un usuario?  |"  << endl;
            cout << "===========================================" << endl;
            cout << "| 1) Activar                              |" << endl;
            cout << "| 2) Desactivar                           |" << endl;
            cout << "===========================================" << endl;
            cout << "Opcion: ";
            cin >> OpcionEstado;

            if(OpcionEstado != 1 && opcionEstado != 2){
                cout << "Opcion incorrecta." << endl;
                break;
            }

            cout << endl;
            cout << "Usuarios registrados: " << endl;
            cout << "====================================" << endl;
            archU.listarTodos();

            cout << "Ingrese el ID del usuario: " << endl;
            cin >> idUsr;

            if(idUsr <= 0 || idUsr > totalUsuarios){
                cout << "ID de usuario inexistente." << endl;
                break;
            }

            Usuario usrleido = archU.leerUsuario(idUsr - 1);

               if(OpcionEstado == 1){
                usrleido.setActivo(true);
               }
               else{
                usrleido.setActivo(false);
               }

               bool guardado = archU.modificar(usrleido);

               if(guardado == true){
                cout << "Estado del usuario modificado con exito." << endl;
               }

               else{
                cout << "No se pudo modificar el estado del usuario." << endl;
               }
            }
            break;


            case 3:
            system("cls");
            menuModificarAdmin();
            break;

            case 4:
            system("cls");
            listarUsuarios();
            break;
        }
    } while(opcion != 0);

}
void MenuGestionEstadisticas(){

int opcion;

do {
    system("cls");
    cout << "===============================================" << endl;
    cout << "|       ESTADISTICAS                           |" << endl;
    cout << "==============================================="  << endl;
    cout << "| 1) Resumen General                           |" << endl;
    cout << "| 2) Ticket por estado                         |" << endl;
    cout << "| 3) Usuarios por rol                          |" << endl;
    cout << "| 4) Tickets por Categoria                     |" << endl;
    cout << "| 5) Tickets por prioridad                     |" << endl;
    cout << "| 6) Tickets asignados por soporte (mes/anio)  |" << endl;
    cout << "| 7) Promedio de respuestas por ticket         |" << endl;
    cout << "| 8) Promedio dias por ticket                  |" << endl;
    cout << "==============================================="  << endl;
    cout << "| 0) Volver                                    |" << endl;
    cout << "==============================================="  << endl;
    cout << "Seleccione una opcion: ";

    cin >> opcion;

    if(cin.fail()){
        cout << "Algo salio mal. Debe ingresar un numero." << endl;

        cin.clear();
        cin.ignore(1000, '\n');
        system("pause");
        continue;

    }

    switch (opcion)
    {
    case 1:
        ResumenGeneral();
        break;
    case 2:
        ticketXEstado();
        break;
    case 3:
        usuariosxRol();
        break;
    case 4:
        ticketXCategoria();
        break;
    case 5:
        ticketXPrioridad();
        break;
    case 6:
        ticketXSoporte();
        break;
    case 7:
        promedioRespuestasTicket();
        break;

    case 8:
      promedioDiasTicket();
      break;

    case 0:
      break;

    default:
    cout << "Opcion invalida." << endl;
    system("pause");
        break;
    }
}while(opcion !=0);
}


void menuModificarAreaSoporte(){
  char nuevoValor[30];
    int Estado;
    int opcion;
    int idArea;
    bool guardado;
    archivoAreaSoporte arch;

    do{

        cout << "=====================================" << endl;
        cout << "|        QUE DESEA MODIFICAR?       |" << endl;
        cout << "=====================================" << endl;
        cout << "| 1) Nombre area soporte            |" << endl;
        cout << "| 2) Descripcion area soporte       |"<< endl;
        cout << "| 3) Estado Area soporte            |" << endl;
        cout << "=====================================" << endl;
        cout << "| 0) Salir.                         |" << endl;
        cout << "=====================================" << endl;
        cin >> opcion;
        cin.ignore();
        if(opcion ==  0){
            cout << "Saliendo del menu modificar." << endl;
            break;
        }
        cout << "===========================================" << endl;
        cout << "| Ingrese el IdArea que desea modificar:  |"<< endl;
        cout << "===========================================" << endl;
        cin >> idArea;
        if(idArea<0 || idArea>arch.contarTotalAreaSoporte()){
            cout << "El idArea es incorrecto." << endl;
            system("pause");
            return;
        }
        cin.ignore();
        areaSoporte arModificar = arch.leerAreaSoporte(idArea);

        switch(opcion){
    case 1:
        cout << "Ingrese el nuevo nombre de el area soporte: " << endl;
        cin.getline(nuevoValor,30);
        arModificar.setNombre(nuevoValor);
        guardado = arch.modificar(arModificar);
        if(guardado == true){
            cout << "Nuevo nombre de area guardado con exito." << endl;
            }else {
                cout << "El nuevo nombre de area no se pudo guardar "<< endl;
                }
                break;
    case 2:
        cout << "Ingrese la descripcion nueva de el area soporte: " << endl;
        cin.getline(nuevoValor,30);
        arModificar.setDescripcion(nuevoValor);
        guardado = arch.modificar(arModificar);
        if(guardado == true){
            cout << "Nueva descripcion de area guardado con exito." << endl;
            }else {
                cout << "la nueva descripcion de area no se pudo guardar "<< endl;
                }
                break;
    case 3:
        cout << "ingrese 1 : Activar " << endl;
        cout << "ingrese 2 : Desactivar " << endl;
        cin >> Estado;
        if (Estado == 1 ){
            arModificar.setActivo(true);
            guardado = arch.modificar(arModificar);
            if(guardado == true){
                cout << "Nuevo estado guardado con exito." << endl;
            }else {
                cout << "No se pudo guardar el nuevo estado." << endl;
                }
        }else if(Estado == 2){
            arModificar.setActivo(false);
            guardado = arch.modificar(arModificar);
            if(guardado == true){
                cout << "Nuevo estado guardado con exito." << endl;
            }else {
                cout << "No se pudo guardar el nuevo estado." << endl;
                }
            }
                break;
    case 0:
        cout << "Saliendo del menu modificar." << endl;
        break;
    default:
        cout << "Ingreso una opcion incorrecta!" << endl;
        break;
        }
    }while(opcion != 0);

    }


void MenuModificarRoles(){
    int opcion;
    int Estado;
    bool guardado;
    int idMod;
    char newDesc[30];
    rolesArchivo rArch;
    do{

        cout << "==============================="<< endl;
        cout << "|       QUE DESEA MODIFICAR?  |" << endl;
        cout << "===============================" << endl;
        cout << "| 1) Descripcion Rol          |" << endl;
        cout << "| 2) Estado Rol               |" << endl;
        cout << "===============================" << endl;
        cout << "| 0) Salir.                   |" << endl;
        cout << "===============================" << endl;
        cin >> opcion;
        cin.ignore();
        if(opcion ==  0){
            cout << "Saliendo del menu modificar." << endl;
            break;
        }
        cout << "==============================================" << endl;
        cout << "| Ingrese el id del rol que desea modificar: |"<< endl;
        cout << "==============================================" << endl;
        cin >>idMod;
        if(idMod<0 || idMod>rArch.contarTotalRoles()){
            cout << "Ingreso un id rol incorrecto. " << endl;
            system("pause");
            return;

        }
        cin.ignore();
        roles rol = rArch.leerRol(idMod-1);

        switch(opcion){
    case 1:
        cout << "Ingrese la nueva descripcion: "<<endl;
        cin.getline(newDesc,30);
        rol.setDescripcion(newDesc);
        guardado = rArch.modificar(rol);
        if(guardado == true) {
            cout <<"Nueva descripcion de rol guardado con exito."<< endl;
        }else{
            cout <<"No se pudo guardad la nueva descripcion del rol."<< endl;
        }
        break;
    case 2:
        cout << "ingrese 1 : Activar " << endl;
        cout << "ingrese 2 : Desactivar " << endl;
        cin >> Estado;
        if(Estado== 1){
            rol.setEstado(true);
            guardado = rArch.modificar(rol);
            if(guardado == true){
                cout << "Nuevo estado de rol guardado con exito." << endl;
                }else{
                    cout << "No se pudo guardar el nuevo estado del rol" << endl;
                    }
            }else{
                rol.setEstado(false);
            guardado = rArch.modificar(rol);
            if(guardado == true){
                cout << "Nuevo estado de rol guardado con exito." << endl;
                }else{
                    cout << "No se pudo guardar el nuevo estado del rol" << endl;
                    }
                }
                break;
        }

    }while(opcion !=0);



}

void MenuGestionTickets()
{

    int opcion;

    do{
        cout << "=====================================" << endl;
        cout << "|         GESTION DE TICKETS        |" << endl;
        cout << "=====================================" << endl;
        cout << "| 1) Visualizar todos los tickets   |" << endl;
        cout << "| 2) Reasignar tickets              |" << endl;
        cout << "| 3) Modificar prioridad            |" << endl;
        cout << "| 4) Modificar estado               |" << endl;
        cout << "=====================================" << endl;
        cout << "| 0) volver                         |" << endl;
        cout << "=====================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:
            VisualizarTickets();
            break;

            case 2:
            ReasignarTicket();
            break;

            case 3:
            ModificarPrioridad();
            break;

            case 4:
            ModificarEstado();
            break;

            case 0:
            break;

            default:
            cout << "Opcion invalida." << endl;
            break;

        }
        if(opcion != 0){
            system("pause");
        }

    }while(opcion != 0);

}
