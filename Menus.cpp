#include <iostream>
using namespace std;
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "GestionUsuarios.h"
#include "GestionTickets.h"

void muereXLogin(int cont){
    if(cont >=3){
       cout << "Ingreso mal el login 3 veces, el proceso se cerrara."<<endl;
       exit(1);
        }
}

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
           MenuGestionAreas();
           break;

           case 5:
           MenuGestionRoles();
           break;

           case 6:
           MenuEstadisticas();
           break;

           case 7:
           MenuConfiguracion();
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

    void MenuGestionCategorias(){
    cout << "Menu Gestion Categorias" << endl;
}

   void MenuGestionAreas(){
    cout << "Menu Gestion Areas" << endl;
}

   void MenuGestionRoles(){
    cout << "Menu Gestion Roles" << endl;
}

  void MenuEstadisticas(){
    cout << "Menu Estadisticas" << endl;
}

  void MenuConfiguracion(){
    cout << "Menu Configuracion" << endl;
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
            //AltaUsuario();
            break;

            case 2:
            //BajaUsuario();
            break;

            case 3:
            //ModificacionUsuario();
            break;

            case 4:
            //listarUsuarios();
            break;
        }
    } while(opcion != 0);

}

void MostrarMenuCliente(Usuario &user1){


Ticket t1;
TickeArchivo Archivo;
int Opcion;
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
cin >> Opcion;



switch(Opcion){

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




}while(Opcion!=0);

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
int Opcion;
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
        cin>>Opcion;
        if (Opcion < 0 || Opcion > 4) {
        cout << endl<<endl;
        cout << "!!!Opcion invalida, intente de nuevo.!!!" << endl;
        cout << endl<<endl;
        system ("pause");
        system("cls");
        } else {
        system("cls");

    }


        switch(Opcion)
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




}while(Opcion!=0);

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