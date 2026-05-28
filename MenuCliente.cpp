#include <iostream>
#include "MenuCliente.h"
#include "Ticket.h"
#include "TiketArchivo.h"
#include "fecha.h"
#include "Usuario.h"
using namespace std;


void MenuCliente::MostrarMenuCliente(){

Usuario user1;
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
cin>>Opcion;



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


}


system ("pause");
system ("cls");






}while(Opcion!=0);















}
