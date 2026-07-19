#include <iostream>
using namespace std;
#include "MenuClientes.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "ArchivoRespuestas.h"
void MostrarMenuCliente(Usuario &user1){


Ticket t1;
TickeArchivo Archivo;
int opcion;
int Cantidad;

do{

system("cls");
cout<<"         Menu Cliente         "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 1) Crear Ticket              "<<endl;
cout<<" 2) Ver mis tickets           "<<endl;
cout<<" 3) Ver Respuesta de un ticket"<<endl;
cout<<" 4) Mis datos                 "<<endl;
cout<<" 5) Responder ticket          "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 0) Cerrar sesion             "<<endl<<endl;

cout<<"Opcion: ";
cin >> opcion;
cin.ignore();


switch(opcion){

case 1:
    system("cls");
    if(t1.CreatTicket(user1)){
    if(Archivo.GuardarTicket(t1)){
        cout<<"Ticket guardado correctamente"<<endl;
    }else{
    cout<<"Error al guardar ticket"<<endl;
    }
    }
    break;


case 2:
  system("cls");
  Cantidad = Archivo.CantidadTickets();

  for(int i=0; i<Cantidad;i++){
    t1=Archivo.LeerTicket(i);
    if(t1.getIdUsuario()==user1.getIDUsuario()){
    t1.MostrarTicket();
    }
  }

    break;
case 3:
    {
    system("cls");
    archivoRespuesta archr;
    int idTickBuscado;
    int i = 0;
    cout << "En este apartado solamente podra ver respuestas sobre los tickets los cuales usted creo..." << endl;
    cout << "Los tickets creados son:" << endl;
    Cantidad = Archivo.CantidadTickets();
    int *PosTicketsCreado= new int[Cantidad+1]();
    for(i=0;i<Cantidad;i++){
        Ticket tleido = Archivo.LeerTicket(i);
        if(tleido.getIdUsuario() == user1.getIDUsuario()){
            tleido.MostrarTicketPreview();
            PosTicketsCreado[i+1]=1;

            }
        }
        cout << "Ingrese el ticket que usted desea visualizar las respuestas: " << endl;
        cin >> idTickBuscado;
        system("cls");
        if(PosTicketsCreado[idTickBuscado]==1){
            Ticket leidoOk = Archivo.LeerTicket(idTickBuscado-1);
             int idTicketValidado = leidoOk.getIdTicket();
            archr.todasRespuestasxTicket(idTicketValidado);
        }else{
            cout << "Este ticket no lo creo usted." << endl;
        }

     delete[] PosTicketsCreado;
    }

    break;
case 4:
    system("cls");
    user1.mostrar();
    break;
case 5:
    {
                system("cls");
                int idBuscado;
                respuestas resp;
                Fecha fActual;
                archivoRespuesta archResp;
                char mensaje[200];
                bool guardado;

                cout << "Ingrese el ID del ticket: ";
                cin >> idBuscado;

                int pos = Archivo.BuscarTicket(idBuscado);

                if(pos != -1)
                {
                    Ticket tleido =  Archivo.LeerTicket(pos);

                    if(tleido.getIdUsuario() != user1.getIDUsuario()){
                        cout << "Este ticket no esta asignado a usted." << endl;
                    }
                    else if(tleido.getEstado() == 3){
                        cout << "El ticket esta cerrado. No se pueden agregar nuevas respuestas" << endl;
                    }

                    else{
                        tleido.MostrarTicketPreview();

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
case 0:
    system("cls");
    break;
}

if(opcion != 0){
    system ("pause");
    system ("cls");
}


}while(opcion!=0);

}
