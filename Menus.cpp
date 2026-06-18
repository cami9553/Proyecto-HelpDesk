#include <iostream>
using namespace std;
#include <string>
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "GestionUsuarios.h"
#include "GestionTickets.h"
#include "GestionCategorias.h"
#include "GestionEstadisticas.h"
#include "Menus.h"
#include "ArchivoAreaSoporte.h"
#include "AreaSoporte.h"
#include "MenuAdmiConfiguracion.h"



void muereXLogin(int cont){
    if(cont >=3){
       cout << "Ingreso mal el login 3 veces, el proceso se cerrara."<<endl;
       exit(1);
        }
}
void MostrarMenuAdmin(Usuario &user1);
void MostrarMenuSoporte(Usuario &user1);
void MostrarMenuCliente(Usuario &user1);

void ingresoUsuarios(){
    int cont=0;
    int rolLogueado =0;
    archivoUsuario arch;
    Usuario usrLog;
    bool loginExitoso;
    char email[30];
    char contra[30];



    //cin.ignore();
   do{
    cout << "\n---Iniciar sesion---"<< endl;
    cout << "Ingrese 0 en email para finalizar programa." << endl;
    cout << "Ingrese email:"<< endl;

    cin.getline(email,30);

    if(strcmp(email,"0")== 0){
        cout << "Programa finalizado" << endl;
        break;
    }
    cout << "Ingrese contrasena:"<< endl;
    cin.getline(contra,30);
    loginExitoso = arch.validarLogin(email,contra,usrLog);
    //cout << loginExitoso;
    if(loginExitoso == true){
        rolLogueado = usrLog.getRol();

        switch(rolLogueado){
        case 1:
            cout << "Bienvenido al menu Admin"<< endl;
            MostrarMenuAdmin(usrLog);
            break;
        case 2:
            cout << "Bienvenido al menu Soporte"<< endl;
            MostrarMenuSoporte(usrLog);
            break;
        case 3:
            cout << "Bienvenido al menu Cliente"<< endl;
            MostrarMenuCliente(usrLog);
            break;
        }
        //break; para que no me muestre nuevamente el iniciar sesion.
    }else{
        cout<< "Contrasena incorrecta."<< endl;
        cont++;
        cout<<"contador: " <<cont<<endl;
        muereXLogin(cont); //Si ingresa 3 veces mal usuario contra se cierra el programa.
        }
   }while(true);

}
void MostrarMenuSoporte(Usuario &user1){
    cout << "Menu Soporte" << endl;
}

void MostrarMenuAdmin(Usuario &user1){

    Ticket t1;
    TickeArchivo Archivo;

    int opcion;
    int cantidad;

    do{
        cout << "      MENU ADMINISTRADOR      " << endl;
        cout << "------------------------------" << endl;
        cout << " 1- GESTION DE USUARIOS" << endl;
        cout << " 2- GESTION DE TICKETS" << endl;
        cout << " 3- GESTION DE CATEGORIAS" << endl;
        cout << " 4- GESTION DE AREAS DE SOPORTE" << endl;
        cout << " 5- GESTION DE ROLES" << endl;
        cout << " 6- ESTADISTICAS" << endl;
        cout << " 7- CONFIGURACION " << endl;
        cout << "------------------------------" << endl;
        cout << "0- CERRAR SESION" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch(opcion){

            case 1:
           MenuGestionUsuarios();
           break;

           case 2:
           MenuGestionTickets();
           break;

           case 3:
           MenuGestionCategorias();
           break;

           case 4:
           MenuGestionAreasSoporte();
           break;

           case 5:
           MenuGestionRoles();
           break;

           case 6:
           MenuGestionEstadisticas();
           break;

           case 7:
           MenuAdmiConfiguracion(user1);
           break;

           case 0:
           cout << "Sesion cerrada." << endl;
           break;

           default:
           cout << "Opcion invalida. " << endl;
           break;
        }

        } while(opcion != 0);

}
void MenuAdmiConfiguracion(Usuario &user1){
   
    int opcion;

    do{
        cout << "1- Cambiar Clave" << endl;
        cout << "2- Ver Mis Datos" << endl;
        cout << "3- Copia de Seguridad" << endl;
        cout << "4- Restaurar Copia" << endl;
        cout << "5- Exportar CSV" << endl;
        cout << "0- Volver" << endl;
        cin >> opcion;

        if(cin.fail()){
        cout << "Algo salio mal. Debe ingresar un numero." << endl;

        cin.clear();
        cin.ignore();

        continue;

    }

    switch (opcion)
    {
    case 1:
        cambiarContrasenia(user1);
        break;

    case 2:
        verMisDatos(user1);
        break;

    case 3:
       MenuBackup();
        break;

    case 4: 
       MenuRestauracion();
       break;
    case 5:
      MenuExportacionCSV();
      break;

    case 0:
      break;
    
    default:
     cout << "Opcion invalida." << endl;
        break;
    }
    } while (opcion != 0);
}
    void MenuGestionCategorias(){
        int opcion;

    do{
        cout << "\n ====== GESTION DE CATEGORIAS ======" << endl;
        cout << "1 - Alta Categoria" << endl;
        cout << "2 - Baja Categoria" << endl;
        cout << "3 - Modificar Categoria" << endl;
        cout << "4 - Listar categorias" << endl;
        cout << "0 - Volver" << endl;

        cin >> opcion;

        switch(opcion){

            case 1:
            cout << "Alta Categoria" << endl;
            break;

            case 2:
            cout << "Baja Categoria" << endl;
            break;

            case 3:
            cout << "Modificar Categoria" << endl;
            break;

            case 4:
            cout << "Listar Categorias" << endl;
            break;

            case 0:
            cout << "Volver al menu anterior" << endl;
            break;

            default:
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
       cout << "Menu Gestion Areas" << endl;
       cout << "============================" << endl;
       cout << "1-CREAR AREA SOPORTE" << endl;
       cout << "2-ALTA AREA SOPORTE" << endl;
       cout << "3-BAJA AREA SOPORTE" << endl;
       cout << "4-MODIFICAR AREA SOPORTE" << endl;
       cout << "5-MOSTRAR AREAS SOPORTE" << endl;
       cout << "6-MOSTRAR AREA SOPORTE ACTIVAS" << endl;
       cout << "0-SALIR                 " << endl;
       cout << "============================" << endl;
       cin  >> opcion;
       cin.ignore();
       areaSoporte AR;
       int idAlta,idBaja;
       switch(opcion){
        case 1:
            cout << "Ingrese el nombre del area nuevo: "<< endl;
            cin.getline(nameAr,30);
            AR.setNombre(nameAr);
            cout << "Ingrese descripcion del area nuevo: " << endl;
            cin.getline(descAr,30);
            AR.setDescripcion(descAr);
            arch.creaAreaSoporte(AR);
            break;
        case 2:
            cout << "Ingresar el id que quiere volver a activar: " << endl;
            cin >> idAlta;
            arch.altaLogica(idAlta);
            break;
        case 3:
            cout << "Ingresar el id que quiere dar de baja: " << endl;
            cin >> idBaja;
            arch.bajaLogica(idBaja);
            break;
        case 4:
            menuModificarAreaSoporte();
            break;
        case 5:
            arch.listarTodos();
            break;
        case 6:
            arch.listarActivos();
            break;
       }

    }while(opcion !=0);

}

   void MenuGestionRoles(){
    cout << "Menu Gestion Roles" << endl;
}

void MenuGestionUsuarios(){

    int opcion;

    do{
        cout << "GESTION DE USUARIOS" << endl;
        cout << " 1- Alta" << endl;
        cout << " 2- Baja" << endl;
        cout << " 3- Modificacion" << endl;
        cout << " 4- Listado" << endl;
        cout << " 0- volver" << endl;

        cin >> opcion;

        switch(opcion){

            case 1:
            AltaUsuario();
            break;

            case 2:
            BajaUsuario();
            break;

            case 3:
            ModificacionUsuario();
            break;

            case 4:
            listarUsuarios();
            break;
        }
    } while(opcion != 0);

}
void MenuGestionEstadisticas(){

int opcion;

do {
    cout << "-------------------" << endl;
    cout << "ESTADISTICAS" << endl;
    cout << "-------------------" << endl;
    cout << "1- Resumen General " << endl;
    cout << "0- Volver" << endl;
    cin >> opcion;
    
    if(cin.fail()){
        cout << "Algo salio mal. Debe ingresar un numero." << endl;

        cin.clear();
        cin.ignore();

        continue;

    }

    switch (opcion)
    {
    case 1:
        ResumenGeneral();
        break;

    case 0:
      break;

    default:
    cout << "Opcion invalida." << endl;
        break;
    }
}while(opcion !=0);
}




void MostrarMenuCliente(Usuario &user1){


Ticket t1;
TickeArchivo Archivo;
int opcion;
int Cantidad;

do{


cout<<"         Menu Cliente         "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 1) Crear Ticket              "<<endl;
cout<<" 2) Ver mis tickets           "<<endl;
cout<<" 3) Ver Respuesta de un ticket"<<endl;
cout<<" 4) Mis datos                 "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 0) Cerrar sesion             "<<endl<<endl;

cout<<"Opcion: ";
cin >> opcion;



switch(opcion){

case 1:

    t1.CreatTicket();
    if(Archivo.GuardarTicket(t1)){
        cout<<"Tiket guardado correctamente"<<endl;
    }else{
    cout<<"Error al guardar ticket"<<endl;
    }


    break;


case 2:

  Cantidad = Archivo.CantidadTickets();

  for(int i=0; i<Cantidad;i++){
    t1=Archivo.LeerTicket(i);
    t1.MostrarTicket();

  }

    break;

case 4:

    user1.mostrar();
    break;


case 0:

    break;





system ("pause");
system ("cls");

}




}while(opcion!=0);

}

void MenuGestionTickets()
{

    int opcion;

    do{
        cout << " GESTION DE TICKETS" << endl;
        cout << "------------------------------" << endl;
        cout << " 1- Visualizar todos los tickets" << endl;
        cout << " 2- Reasignar tickets" << endl;
        cout << " 3- Modificar prioridad" << endl;
        cout << " 4- Modificar estado" << endl;
        cout << " 0- volver" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:
            //VisualizarTickets();
            break;

            case 2:
            //ReasignarTicket();
            break;

            case 3:
            //ModificarPrioridad();
            break;

            case 4:
            //ModificarEstado();
            break;

            case 0:
            break;

            default:
            cout << "Opcion invalida." << endl;
            break;

        }
        system ("pause");
        system ("cls");

    }while(opcion != 0);

}

void menuSoporte(){


Ticket t1;
TickeArchivo Archivo;
int opcion;
int Cantidad;
    do
    {


        cout << "MENU SOPORTE" << endl<<endl;
        cout << "------------------------------------" << endl;
        cout << "1) VER MIS TICKETS ASIGNADOS" << endl;
        cout << "2) VER TICKETS ABIERTOS" << endl;
        cout << "3) CAMBIAR ESTADO DE TICKET" << endl;
        cout << "4) RESPONDER TIKECT" << endl;
        cout << "------------------------------------" << endl<<endl;
        cout << "0) CERRAR SESION" << endl<<endl;
        cout<<"Opcion: ";

        cin >> opcion;

        if (opcion < 0 || opcion > 4) {
        cout << endl<<endl;
        cout << "!!!Opcion invalida, intente de nuevo.!!!" << endl;
        cout << endl<<endl;
        system ("pause");
        system("cls");
        } else {
        system("cls");

    }


        switch(opcion)
        {



        case 1:

        /// ver mis tickets asignados
            break;

        case 2:
        /// ver tickets abiertos

            break;
        case 3:
            /// modificar estado del tickect
            break;

        case 4:
            {
                int idBuscado;

                cout << "Ingrese el ID del ticket: ";
                cin >> idBuscado;

                int pos = Archivo.BuscarTicket(idBuscado);

                if(pos != -1)
                {
                    Ticket reg = Archivo.LeerTicket(pos);

                    reg.AgregarComentario();

                    if(Archivo.ModificarTicket(reg, pos))
                    {
                        cout << "Comentario agregado correctamente." << endl;
                    }
                    else
                    {
                        cout << "Error al guardar el comentario." << endl;
                    }
                }
                else
                {
                    cout << "No se encontro el ticket." << endl;
                }

                system("pause");
                system("cls");
            }
            break;


        case 0:

            break;





system ("pause");
system ("cls");

}




}while(opcion!=0);

}

void menuModificarUsrSoporte(Usuario &usrlog){
// Este menu va a servir tanto para CLIENTE como para SOPORTE
archivoUsuario arch;
bool guardado;
int opcion;
char nuevoValor[30];
    do{
        cout << "==========================" << endl;
        cout << "¿Que desea modificar?     " << endl;
        cout << "1-Nombre                  " << endl;
        cout << "2-Apellido                " << endl;
        cout << "3-Email                   " << endl;
        cout << "4-Clave                   " << endl;
        cout << "0-Salir.                  " << endl;
        cout << "==========================" << endl;
        cin >> opcion;
        switch(opcion){
    case 1:
        cout << "Ingrese nuevo nombre: "<< endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrlog.setNombre(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo nombre guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo nombre."<<endl;
            }
        system("pause");
        break;
    case 2:
        cout << "Ingrese nuevo Apellido: " << endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrlog.setApellido(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo Apellido guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo Apellido."<<endl;
            }
        system("pause");
        break;
    case 3:
        cout << "Ingrese el nuevo email: " << endl;
        cin >> nuevoValor;
        usrlog.setEmail(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo Email guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo email."<<endl;
            }
        system("pause");
        break;
    case 4:
        cout << "Ingrese la nueva clave: " << endl;
        cin >> nuevoValor;
        usrlog.setClave(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nueva clave guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar la nueva clave."<<endl;
            }
        system("pause");
        break;
    case 0:
        cout << "Saliendo del menu modificar!" << endl;
        break;
        }

        }while(opcion != 0);


    }



void menuModificarAdmin(Usuario &usrlog){
archivoUsuario arch;
bool guardado;
int opcion,usrAModificar,nuevoValorRol;
char nuevoValor[30];
   cout << "==========================" << endl;
   cout << "Ingrese el idUsuario que desea modificar: "<<endl;
   cin  >> usrAModificar;
   cout << "==========================" << endl;

    do{
        cout << "==========================" << endl;
        cout << "¿Que desea modificar?     " << endl;
        cout << "1-Nombre                  " << endl;
        cout << "2-Apellido                " << endl;
        cout << "3-Email                   " << endl;
        cout << "4-Clave                   " << endl;
        cout << "5-Rol                     " << endl;
        cout << "0-Salir.                  " << endl;
        cout << "==========================" << endl;
        cin >> opcion;

        Usuario usrAEditar = arch.leerUsuario(usrAModificar);
        switch(opcion){
    case 1:
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
        cout << "Saliendo del menu modificar!" << endl;
        break;
        }

        }while(opcion != 0);


    }
void menuModificarAreaSoporte(){
  char nuevoValor[30];
    int Estado;
    int opcion;
    int idArea;
    bool guardado;
    archivoAreaSoporte arch;

    do{

        cout << "==========================" << endl;
        cout << "¿Que desea Modificar?" << endl;
        cout << "1-Nombre area soporte" << endl;
        cout << "2-Descripcion area soporte"<< endl;
        cout << "3-Estado Area soporte " << endl;
        cout << "0-Salir." << endl;
        cin >> opcion;
        cin.ignore();
        if(opcion ==  0){
            cout << "Saliendo del menu modificar." << endl;
            break;
        }
        cout << "==========================" << endl;
        cout << "Ingrese el IdArea que desea modificar: "<< endl;
        cin >> idArea;
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


