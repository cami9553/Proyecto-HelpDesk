#include <iostream>
using namespace std;
#include "MenuSoporte.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "ArchivoRespuestas.h"
#include "Respuestas.h"
#include "Fecha.h"


bool validarIdElegido(int idAsig, Usuario &user1){
    TickeArchivo Archivo;
    int Cantidad = Archivo.CantidadTickets();
    for(int i=0; i<Cantidad; i++){
        Ticket tleido = Archivo.LeerTicket(i);
        if(tleido.getIdUsrSoporte() == user1.getIDUsuario() && tleido.getIdTicket() == idAsig){
            return true;
        }
    }
    return false;
}
void MostrarMenuSoporte(Usuario &user1){

Ticket t1;
TickeArchivo Archivo;
archivoRespuesta archResp;
int opcion,OpcAsig,contin,idAsig,nuevoEstado;
int i,Cantidad=0;
char mensaje[200];
bool guardado;
    do
    {

        system("cls");
        cout << "=======================================" << endl;
        cout << "|          MENU SOPORTE               |" << endl;
        cout << "=======================================" << endl;
        cout << "| 1) VER MIS TICKETS ASIGNADOS        |" << endl;
        cout << "| 2) VER TICKETS ABIERTOS             |" << endl;
        cout << "| 3) CAMBIAR ESTADO DE TICKET         |" << endl;
        cout << "| 4) RESPONDER TICKET                 |" << endl;
        cout << "| 5) VER RESPUESTAS DE TICKETS        |" << endl;
        cout << "=======================================" << endl;
        cout << "| 0) CERRAR SESION                    |" << endl;
        cout << "=======================================" << endl;
        cout<<"Opcion: ";
        cin>> opcion;
        if (opcion < 0 || opcion > 5) {
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
        {
            system("cls");

            bool tieneAsignados =  false;

            Cantidad = Archivo.CantidadTickets();

            for(i=0; i < Cantidad; i++){
                Ticket tleido = Archivo.LeerTicket(i);

                if(tleido.getIdUsrSoporte() == user1.getIDUsuario()){
                    tleido.MostrarTicket();
                    tieneAsignados = true;
                }
            }

            if(tieneAsignados == false){
                cout << "Aun no tenes tickets asignados." << endl;
            }
        }
            break;

        case 2:
{
         system("cls");

         int idTicketAsignar = 0;
         bool hayAbiertos = false;

        Cantidad = Archivo.CantidadTickets();

        if(Cantidad == 0){
        cout << "No hay tickets registrados." << endl;
        }
        else{
        cout << "Tickets abiertos disponibles:" << endl;
        cout << "========================================" << endl;

        for(i = 0; i < Cantidad; i++){
            Ticket tleido = Archivo.LeerTicket(i);

            if(tleido.getEstado() == 0){
                tleido.MostrarTicketPreview();
                hayAbiertos = true;
            }
        }

        if(hayAbiertos == false){
            cout << "No hay tickets abiertos disponibles para asignarse." << endl;
        }
        else{
            cout << "Ingrese el ID del ticket que desea asignarse: ";
            cin >> idTicketAsignar;

            int pos = Archivo.BuscarTicket(idTicketAsignar);

            if(pos != -1){
                Ticket tAsignar = Archivo.LeerTicket(pos);

                if(tAsignar.getEstado() == 0){
                    tAsignar.setEstado(1);
                    tAsignar.setIdUsrSoporte(user1.getIDUsuario());

                    guardado = Archivo.ModificarTicket(tAsignar, pos);

                    if(guardado == true){
                        cout << "Ticket asignado con exito." << endl;
                    }
                    else{
                        cout << "No fue posible asignarse el ticket." << endl;
                    }
                }
                else{
                    cout << "El ticket elegido no se encuentra abierto para asignarse." << endl;
                }
            }
            else{
                cout << "No se encontro un ticket con ese ID." << endl;
            }
        }
    }
}
break;

        case 3:
            {
            system("cls");
            cout << "En este apartado solamente podra modificar el estado de los tickets los cuales usted tiene asignado..." << endl;
            cout << "Los tickets asignados son:" << endl;
            Cantidad = Archivo.CantidadTickets();
            for(i = 0; i < Cantidad; i++){
                Ticket tleido = Archivo.LeerTicket(i);

                if(tleido.getIdUsrSoporte() == user1.getIDUsuario()){
                    tleido.MostrarTicket();
                }
            }
            cout << "Ingrese el id de el ticket a modificar: " << endl;
            cin >> idAsig;

            bool esValido = validarIdElegido(idAsig, user1);

            if(esValido == false){
                cout << "El id ingresado no corresponde a ningun ticket asignado a usted." << endl;
            }
            else{
            int pos = Archivo.BuscarTicket(idAsig);

            if(pos != -1){
              Ticket tleido = Archivo.LeerTicket(pos);

            cout << "=======================================" << endl;
            cout << "|     Que estado desea asignar?       |" << endl;
            cout << "=======================================" << endl;
            cout << "| 0-Abierto                           |" << endl;
            cout << "| 1-Asignado                          |" <<endl;
            cout << "| 2-Resuelto                          | " << endl;
            cout << "| 3-Cerrado                           |" << endl;
            cout << "=======================================" << endl;
            cin >> nuevoEstado;

            if(nuevoEstado >= 0 && nuevoEstado <= 3){
                tleido.setEstado(nuevoEstado);

                if(nuevoEstado == 3){
                    Fecha fActual;
                    fActual.CargarFechaActual();
                    tleido.setFechaCierre(fActual);
            }else if(nuevoEstado == 0){
                tleido.setIdAreaSoporte(0);
                tleido.setIdUsrSoporte(0);
                }
             guardado = Archivo.ModificarTicket(tleido, pos);

             if(guardado == true){
                cout << "Estado cambiado con exito." << endl;
             }
             else{
                cout << "No se pudo cambiar el estado del ticket." << endl;
             }
        }

        else{
            cout << "Estado invalido." << endl;
        }

    }
            else{
                 cout << "El estado ingresado no es valido." << endl;
             }
         }
    }
            break;

        case 4:
            {
                system("cls");
                int idBuscado;
                respuestas resp;
                Fecha fActual;
                cout << "Ingrese el ID del ticket: ";
                cin >> idBuscado;

                int pos = Archivo.BuscarTicket(idBuscado);

                if(pos != -1)
                {
                    Ticket tleido =  Archivo.LeerTicket(pos);

                    if(tleido.getIdUsrSoporte() != user1.getIDUsuario()){
                        cout << "Este ticket no esta asignado a usted." << endl;
                    }
                    else if(tleido.getEstado() == 3){
                        cout << "El ticket esta cerrado. No se pueden agregar nuevas respuestas" << endl;
                    }

                    else{
                        tleido.MostrarTicket();

                        cin.ignore();

                        resp.setIdTicket(idBuscado);

                        cout << "Ingrese el mensaje:  " << endl;
                        cin.getline(mensaje,200);

                        resp.setContenido(mensaje);
                        fActual.CargarFechaActual();
                        resp.setFechaHora(fActual);
                        resp.setIdUsuarioAutor(user1.getIDUsuario());
                        guardado = archResp.cargarArchivo(resp);
                        if(guardado == true){
                            cout << "Respuesta guardada con exito." << endl;
                        }else{
                            cout << "No se pudo guardar la respuesta." << endl;
                        }

                    }
                }
                else
                {
                    cout << "No se encontro el ticket." << endl;
                }

            break;
            }
        case 5:
            {
            system("cls");
            archivoRespuesta resp;
            cout << "En este apartado solamente podra ver respuesta de los tickets los cuales usted tiene asignado..." << endl;
            cout << "============================" << endl;
            cout << "Preview de tickets: " << endl;
            Archivo.ListarTicketsPreview();
            system("pause");
            system("cls");
            int IdTicketRespuestaBuscar=0;
            Cantidad = Archivo.CantidadTickets();
            int *PosTicketRespuesta = new int[Cantidad + 1]();
            if(Cantidad==0){
                cout <<"No hay tickets registrados."<< endl;
            }
            for(i=0;i<Cantidad;i++){
                Ticket tleido = Archivo.LeerTicket(i);
                if(tleido.getIdUsrSoporte() == user1.getIDUsuario()){
                   tleido.MostrarTicketPreview();
                   PosTicketRespuesta[i+1] = 1;
                   //cout << PosTicketAsignable[i+1]<< endl;
                }
            }
            cout << "QUE TICKET DESEA VER LAS RESPUESTAS?" << endl;
            cin >> IdTicketRespuestaBuscar ;
            if(PosTicketRespuesta[IdTicketRespuestaBuscar]==1){
                resp.todasRespuestasxTicket(IdTicketRespuestaBuscar);
            }else{
                cout << "EL TICKET ELEGIDO NO ESTA ASIGNADO A USTED." << endl;
                }
            delete[] PosTicketRespuesta;
            }
            break;
        case 0:
            system("cls");
            break;
        }




if(opcion != 0){
    system("pause");
}
    }while(opcion != 0);
}
