#include <iostream>
using namespace std;

#include "GestionEstadisticas.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "usuarios.h"
#include "ArchivoUsuarios.h"
#include "Fecha.h"
#include "Respuestas.h"
#include "ArchivoRespuestas.h"

void ResumenGeneral(){

    archivoUsuario archUsr; // crea un objeto para trabajar con el archivo de usuarios
    TickeArchivo archTicket;


    int totalUsuarios;
    int totalTickets;


    totalUsuarios = archUsr.contarTotalUsuarios();

    totalTickets = archTicket.CantidadTickets();

    cout << "Usuarios registrados: " << totalUsuarios << endl;
    cout << "Tickets registrados: " << totalTickets << endl;
    system("pause");
    system("cls");
}

void ticketXEstado(){
int i = 0, sA = 0, asig = 0, enPro = 0, cerra = 0;
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

void  ticketXSoporte(){
archivoUsuario archU;
TickeArchivo archT;
int mes=0, anio=0,i=0;
int cantUsuarios =  archU.contarTotalUsuarios();
int cantTickets = archT.CantidadTickets();

cout << "Ingrese mes (1-12): ";
cin >> mes;
cout <<"Ingrese anio :";
cin >> anio;

cout << "================================="<< endl;
cout << "Tickets asignados en: " << mes << "/" << anio << endl;
cout << "================================="<< endl;

for(i=0;i<cantUsuarios;i++){
    Usuario usrleido = archU.leerUsuario(i);
    if(usrleido.getRol()==2 && usrleido.getActivo()){
        int contador = 0;
            for(int j = 0; j < cantTickets; j++){
                Ticket tk = archT.LeerTicket(j);
                if(tk.getIdUsrSoporte() == usrleido.getIDUsuario()
                && tk.getFechaCreacion().GetMes() == mes
                && tk.getFechaCreacion().GetAnio() == anio){
                    contador++;
                }
            }
            cout << usrleido.getNombre() << " " << usrleido.getApellido()
                 << " (ID " << usrleido.getIDUsuario() << "): "
                 << contador << " tickets" << endl;
        }
    }
    system("pause");
    system("cls");
    }

void promedioRespuestasTicket(){
    TickeArchivo archT;
    archivoRespuesta archR;

    int totalTickets = archT.CantidadTickets();
    int totalRespuestas = archR.cantidadRespuestas();

    if(totalTickets == 0){
        cout << "No hay tickets registrados." << endl;
        system("pause");
        system("cls");
        return;
    }
    float promedio = (float)totalRespuestas / totalTickets;

    cout << "Total tickets: " << totalTickets << endl;
    cout << "Total respuestas: " << totalRespuestas << endl;
    cout << "Promedio de respuestas por ticket: " << promedio << endl;

    system("pause");
    system("cls");
}
 
void promedioDiasTicket(){

    TickeArchivo archT;

    int cantidadTickets = archT.CantidadTickets();
    int totalDias = 0;
    int ticketsCerrados = 0;

    if(cantidadTickets == 0){
        cout << "No hay tickets registrados." << endl;
        system("pause");
        system("cls");
        return;
    }

    for(int i = 0; i < cantidadTickets; i++){
        Ticket tk = archT.LeerTicket(i);

        if(tk.getEstado() == 3){
            Fecha fechaInicio = tk.getFechaCreacion();
            Fecha fechaFin = tk.getFechaCierre();

            int diasInicio = fechaInicio.GetAnio() * 365 + fechaInicio.GetMes() * 30 + fechaInicio.GetDia();
            int diasFin = fechaFin.GetAnio() * 365 + fechaFin.GetMes() * 30 + fechaFin.GetDia();

            int diferencia = diasFin - diasInicio;

            if(diferencia >= 0){
                totalDias += diferencia;
                ticketsCerrados++;
            }
        }
    }

    if(ticketsCerrados == 0){
        cout << "No hay tickets cerrados para calcular el promedio." << endl;
    }

    else{
        float promedio = (float)totalDias / ticketsCerrados;

        cout << "Tickets cerrados: " << ticketsCerrados << endl;
        cout << "Total de dias acumulados: " << totalDias << endl;
        cout << "Promedio de dias por ticket cerrado: " << promedio << endl;
    }

    system("pause");
    system("cls");
}