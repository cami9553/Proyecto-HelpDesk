#include <iostream>
using namespace std;

#include "GestionEstadisticas.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "usuarios.h"
#include "ArchivoUsuarios.h"


void ResumenGeneral(){

    archivoUsuario archUsr; // crea un objeto para trabajar con el archivo de usuarios
    TickeArchivo archTicket;


    int totalUsuarios;
    int totalTickets;


    totalUsuarios = archUsr.contarTotalUsuarios();

    totalTickets = archTicket.CantidadTickets();

    cout << "Usuarios registrados: " << totalUsuarios << endl;
    cout << "Tickets registrados: " << totalTickets << endl;
}

void ticketXEstado(){
int i,sA,asig,enPro,cerra=0;
TickeArchivo tkA;


int cantidadTicket = tkA.CantidadTickets();
for(i=0;i<cantidadTicket;i++){
    Ticket tleido = tkA.LeerTicket(i);
    if(tleido.getEstado()==0){
        sA++;
        }else if(tleido.getEstado()==1){
            asig++;
            }else if(tleido.getEstado()==2){
                enPro++;
                }else if(tleido.getEstado()==3){
                    cerra++;
                    }

    }
cout << "Cantidad de tickets sin asignar: "<< sA << endl;
cout << "Cantidad de tickets asignados: " << asig << endl;
cout << "Cantidad de tickets en Proceso: " << enPro << endl;
cout << "Cantidad de tickets cerrados: "  << cerra << endl;

system("pause");
system("cls");
}
void usuariosxRol(){
int cAdm=0,cCliente=0,cSoporte=0,i=0;
archivoUsuario usrArch;
int cantidad = usrArch.contarTotalUsuarios();

for(i=0;i<cantidad;i++){
    Usuario usrLeido = usrArch.leerUsuario(i);
    if(usrLeido.getRol()==1){
       cAdm++;
    }else if(usrLeido.getRol()==2){
        cSoporte++;
        }else if(usrLeido.getRol()==3){
            cCliente++;
            }
}
cout << "Cantidad de usuarios ADMIN: "<< cAdm << endl;
cout << "Cantidad de usuarios SOPORTE: "<< cSoporte << endl;
cout << "Cantidad de usuarios CLIENTE: "<< cCliente << endl;
system("pause");
system("cls");
}

void ticketXCategoria(){
int i=0,cHard=0,cSoft=0,cOtro=0;
TickeArchivo tkA;

int cantidadTicket = tkA.CantidadTickets();
for(i=0;i<cantidadTicket;i++){
    Ticket tleido = tkA.LeerTicket(i);
     if(tleido.getIdCategoria()==1){
            cHard++;
            }else if(tleido.getIdCategoria()==2){
                cSoft++;
                }else if(tleido.getIdCategoria()==3){
                    cOtro++;
                    }
}
cout << "La cantidad de tickets de la categoria HARDWARE : " << cHard << endl;
cout << "La cantidad de tickets de la categoria SOFTWARE : " << cSoft << endl;
cout << "La cantidad de tickets de la categoria OTROS : " <<cOtro << endl;

system("pause");
system("cls");
}
void ticketXPrioridad(){
int cMax=0,cMedio=0,cBaja=0,i=0;
TickeArchivo tkA;

int cantidadTicket = tkA.CantidadTickets();
for(i=0;i<cantidadTicket;i++){
    Ticket tleido = tkA.LeerTicket(i);
     if(tleido.getPrioridad()==1){
            cMax++;
            }else if(tleido.getPrioridad()==2){
                cMedio++;
                }else if(tleido.getPrioridad()==3){
                    cBaja++;
                    }
}
cout << "La cantidad de tickets de la Prioridad MAXIMA : " << cMax << endl;
cout << "La cantidad de tickets de la Prioridad MEDIA : " << cMedio << endl;
cout << "La cantidad de tickets de la Prioridad BAJA : " <<cBaja << endl;

system("pause");
system("cls");




}
