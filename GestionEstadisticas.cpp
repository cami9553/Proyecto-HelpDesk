#include <iostream>
using namespace std; 

#include "GestionEstadisticas.h"
#include "TicketArchivo.h"
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