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
        cout<<"Tiket guardado correctamente"<<endl;
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
            tleido.MostrarTicket();
            PosTicketsCreado[i+1]=1;
            system("pause");
            }
        }
        cout << "Ingrese el ticket que usted desea modificar: " << endl;
        cin >> idTickBuscado;
        if(PosTicketsCreado[idTickBuscado]==1){
            cout <<"Este ticket lo tiene asignado" << endl;
            cout <<"================================="<< endl;
            Ticket leidoOk = Archivo.LeerTicket(idTickBuscado-1);
             int idTicketValidado = leidoOk.getIdTicket();
            archr.todasRespuestasxTicket(idTicketValidado);
        }else{
            cout << "Este ticket no se encuentra asignado a usted." << endl;
        }

     delete[] PosTicketsCreado;
    }

    break;
case 4:
    system("cls");
    user1.mostrar();
    break;


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
