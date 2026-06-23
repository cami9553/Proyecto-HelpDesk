#include <iostream>
#include "Ticket.h"
#include "TicketArchivo.h"
#include <cstring>
#include <ctime>
#include "Fecha.h"
#include "usuarios.h"

using namespace std;


bool Ticket::CreatTicket(Usuario logd){

int _idUsuario;
int _idUsrSoporte;
int _idCategoria;
char _asunto[100];
char _descripcion[200];
int _prioridad;
char _comentario[200];

Fecha f1;

system("cls");

cout<<"--------- Crear Ticket ---------"<<endl;

fechaCreacion.CargarFechaActual();

//cout<<"Ingrese ID Usuario: ";
//cin>>_idUsuario;
//cout<<endl;
idUsuario=logd.getIDUsuario();


cout<<"Ingrese el Asunto: ";
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

cin.ignore();
/// Inicializar comentario vac�o
//comentario[0] = '\0';
cout<<"Ingrese Comentario inicial: " << endl;
cin.getline(_comentario,200);
strcpy(comentario,_comentario);
cout << endl;

cout << "--------- Fecha de Cierre ---------" << endl;
fechaCierre.CargarFecha();
cout << endl;

cin.ignore();
estado=0;


/// id ticket

TickeArchivo archivo;

idTicket =archivo.CantidadTickets()+1;



return true;

 }
int Ticket::getIdUsuario() {return idUsuario;}
int Ticket::getIdUsrSoporte() {return idUsrSoporte;}
int Ticket::getIdAreaSoporte() { return idAreaSoporte; }
int Ticket::getIdCategoria() { return idCategoria; }
int Ticket::getPrioridad() { return prioridad; }
int Ticket::getEstado() { return estado; }
Fecha Ticket::getFechaCreacion() { return fechaCreacion; }
Fecha Ticket::getFechaCierre() { return fechaCierre; }
const char* Ticket::getAsunto() { return asunto; }
const char* Ticket::getDescripcion() { return descripcion; }
const char* Ticket::getComentario() { return comentario; }



 void Ticket::MostrarTicket(){



cout<<"--------- TICKET ---------"<<endl;
cout<<"ID TICKET: "<<idTicket<<endl;
cout<<"Cliente: "<<idUsuario<<endl;
cout<<"Asunto: "<<asunto<<endl;
cout<<"Descripcion: "<<descripcion<<endl;
cout<<"Categoria: "<<idCategoria<<endl;
cout<<"Prioridad: "<<prioridad<<endl;
cout<<"Estado: " <<estado<<endl;
cout<<"Fecha creacion: ";
fechaCreacion.MostrarFecha();
cout<<endl;
cout<<"--------------------------"<<endl;


 }


 int Ticket::getIdTicket(){
    return idTicket;

 }

 void Ticket::AgregarComentario() {
char _comentario[200];
cout << "Ingrese comentario: ";
cin.ignore();
cin.getline(_comentario, 200);
strcpy(comentario, _comentario);
}

// SETTERS

void Ticket::setIdTicket(int id) {
    idTicket = id;
}

void Ticket::setIdUsuario(int id) {
    idUsuario = id;
}
void Ticket::setIdAreaSoporte(int idArea) {
    idAreaSoporte = idArea;
}

void Ticket::setIdCategoria(int idCat) {
    idCategoria = idCat;
}

void Ticket::setPrioridad(int prio) {
    prioridad = prio;
}

void Ticket::setEstado(int est) {
    estado = est;
}

void Ticket::setFechaCreacion(Fecha fCreacion) {
    fechaCreacion = fCreacion;
}

void Ticket::setFechaCierre(Fecha fCierre) {
    fechaCierre = fCierre;
}

void Ticket::setAsunto(std::string _asunto){
     strcpy(asunto,_asunto.c_str());
 }
void Ticket::setDescripcion(std::string _desc){
    strcpy(descripcion,_desc.c_str());
    }
void Ticket::setComentario(std::string _coment){
    strcpy(comentario,_coment.c_str());
}
void Ticket::setIdUsrSoporte(int _idUsrSoporte){
     idUsrSoporte= _idUsrSoporte;
}
