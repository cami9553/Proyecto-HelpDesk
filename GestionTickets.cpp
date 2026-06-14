#include <iostream>
using namespace std;

#include "GestionTickets.h"
#include "ticket.h"
#include "TicketArchivo.h"

void VisualizarTickets(){

 TickeArchivo arch; // objeto q permite trabajar con el archivo de tickets
 Ticket reg; //ticket individual. Aca guardo cada ticket que leas del archivo.
 int cantidad; // guarda la cantidad de tickets que existen.

 cantidad = arch.CantidadTickets(); 

 for(int i=0; i<cantidad; i++){
   reg = arch.LeerTicket(i); 
   reg.MostrarTicket();

 }
}


void ReasignarTicket(){



}

void ModificarPrioridad(){

}

void ModificarEstado(){

}

//aca esta la logica


