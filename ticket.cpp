#include <iostream>
#include "Ticket.h"
#include "TicketArchivo.h"
#include <cstring>
#include <ctime>
#include "fecha.h"

using namespace std;


bool Ticket::CreatTicket(){

int _idUsuario;
int _idSoporte;
int _idCategoria;
char _asunto[100];
char _descripcion[200];
int _prioridad;
Fecha f1;

system("cls");

cout<<"--------- Crear Ticket ---------"<<endl;

fechaCreacion.CargarFechaActual();

cout<<"Ingrese ID Usuario: ";
cin>>_idUsuario;
cout<<endl;
idUsuario=_idUsuario;

cout<<"Ingrese el Asunto: ";
cin.ignore();
cin.getline(_asunto,100);
strcpy(asunto,_asunto);
cout<<endl;

cout<<"Descripcion: ";
cin.getline(_descripcion,200 );
strcpy(descripcion,_descripcion);
cout<<endl;

cout<<"Ingrese Id Catergoria: ";
/// funcion que muestre las categorias cargadas
cin>>_idCategoria;
idCategoria=_idCategoria;
cout<<endl;

cout<<"Indique Prioridad: ";
cin>>_prioridad;
prioridad=_prioridad;
cout<<endl;

/// Inicializar comentario vacío
comentario[0] = '\0';



/// id ticket

TickeArchivo archivo;

idTicket =archivo.CantidadTickets()+1;



return true;

 }




 void Ticket::MostrarTicket(){



cout<<"--------- TICKET ---------"<<endl;
cout<<"ID TICKET: "<<idTicket<<endl;
cout<<"Cliente: "<<idUsuario<<endl;
cout<<"Asunto: "<<asunto<<endl;
cout<<"Descripcion: "<<descripcion<<endl;
cout<<"Categoria: "<<idCategoria<<endl;
cout<<"Prioridad: "<<prioridad<<endl;
cout<<"Fecha creacion: ";
fechaCreacion.MostrarFecha();
cout<<endl;
cout<<"--------------------------"<<endl;


 }


 void Ticket::AgregarComentario() {
    char _comentario[200];
    cout << "Ingrese comentario: ";
    cin.ignore();
    cin.getline(_comentario, 200);
    strcpy(comentario, _comentario);
}
