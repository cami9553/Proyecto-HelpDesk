#include <iostream>
using namespace std;

#include "GestionTickets.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "ArchivoRespuestas.h"
#include "ArchivoAreaSoporte.h"
#include "AreaSoporte.h"

void VisualizarTickets(){

 TickeArchivo arch; // objeto q permite trabajar con el archivo de tickets
 Ticket reg; //ticket individual. Aca guardo cada ticket que leas del archivo.
 int cantidad; // guarda la cantidad de tickets que existen.

 cantidad = arch.CantidadTickets();


  if (cantidad == 0)
  {
    cout << "No hay tickets cargados." << endl;
    return;
  }

 for(int i=0; i <cantidad; i++){
   reg = arch.LeerTicket(i);
   reg.MostrarTicket();

   cout << "===========================" << endl;

 }
}


void ReasignarTicket(){

   TickeArchivo arch;
   archivoAreaSoporte archAS;
   int idTicket;

   cout << "Ingrese ID del ticket areasignar: ";
   cin >> idTicket;

   int pos = arch.BuscarTicket(idTicket);

   //cout << "Posicion encontrada: "  << pos << endl;

   if(pos == -1){
    cout << "No se encontro el ticket." << endl;
    return;
   }

   Ticket reg;
    reg = arch.LeerTicket(pos);

    cout << "Ticket encontrado: " << endl;
    reg.MostrarTicket();

    int nuevaArea;
    system("cls");
    cout << "Areas Existentes: "<< endl;
    archAS.listarTodosPreview();
    cout << "Ingrese nuevo ID de area de soporte: ";
    cin >> nuevaArea;

    if(nuevaArea<1 || nuevaArea>archAS.contarTotalAreaSoporte()){
        cout << "El id que ingreso es incorrecto." << endl;
        system("pause");
        return;
    }
    areaSoporte area = archAS.leerAreaSoporte(nuevaArea);
    if(area.getActivo()==false){
        cout << "Error, el area que se quiere asignar no esta activo."<< endl;
        system("pause");
        return;
    }

    reg.setIdAreaSoporte(nuevaArea);

    cout << "Nueva area asignada en memoria: " << reg.getIdAreaSoporte() << endl;

    cout << "Ticket luego de reasignar en memoria: " << endl;
    reg.MostrarTicket();


    cout << "Nueva area asignada en memoria: " << reg.getIdAreaSoporte() << endl;

    bool modifico = arch.ModificarTicket(reg,pos);

    if(modifico){
      cout << "Ticket reasignado correctamente." << endl;
    }

    else{
      cout << "Error al asignar el ticket." << endl;
    }

    Ticket prueba;

    prueba = arch.LeerTicket(pos);

    cout << "Area guardada en archivo: " << prueba.getIdAreaSoporte() << endl;
}

void ModificarPrioridad(){

    TickeArchivo arch; // es mi clase qu8e esta en ticketarchivo.h
    int idTicket;  // creo la variable numerica llamada idTicket para guardar el id ticket
  // arch es el nombre del objeto

    cout << "Ingrese ID del ticket: ";
    cin >> idTicket;  // leé lo que escriba el usuario y guardalo dentro de idTicket.

    int pos = arch.BuscarTicket(idTicket); // pos es el nmombre de la variable, Esta variable va a guardar en qué posición del archivo está el ticket.

    if(pos == -1){

      cout << "No se encontro el ticket." << endl;
      return;
    }

    Ticket reg;

    reg = arch.LeerTicket(pos);
    cout << "Ticket encontrado: " << endl;
    reg.MostrarTicket();

    int nuevaPrioridad;
    cout << "Ingrese nueva prioridad: " << endl;
    cout << "1- Alta" << endl;
    cout << "2- Media" << endl;
    cout << "3- Baja" << endl;
    cout << "Opcion: ";
    cin >> nuevaPrioridad;

    if(nuevaPrioridad < 1 || nuevaPrioridad > 3){

      cout << "Prioridad invalida. " << endl;
      return;
    }

    reg.setPrioridad(nuevaPrioridad);

    cout << "Nueva prioridad en memoria: " << reg.getPrioridad() << endl;

    bool modifico = arch.ModificarTicket(reg, pos);

    if(modifico){
      cout << "Prioridad modificada correctamente." << endl;
    } else{
      cout << "Error al modificar la prioridad." << endl;
    }

    Ticket prueba;

    prueba = arch.LeerTicket(pos);
    cout << "Prioridad guardada en archivo: " << prueba.getPrioridad() << endl;

  }
void ModificarEstado(){

  TickeArchivo arch;
   int idTicket;

   cout << "Ingrese el ID del ticket: ";
   cin >> idTicket;

   int pos = arch.BuscarTicket(idTicket);

   if(pos == -1){

    cout << "No se encontro el ticket." << endl;
    return;
   }

   Ticket reg;
   reg = arch.LeerTicket(pos);

   cout << "Ticket encontrado: ";
   reg.MostrarTicket();

   int nuevoEstado;

   cout << "Ingrese nuevo estado: " << endl;
   cout << "0- Sin Asignar "<< endl;
   cout << "1- Asignado" << endl;
   cout << "2- En proceso" << endl;
   cout << "3- Cerrado" << endl;
   cout << "Opcion: ";
   cin >> nuevoEstado;

   if (nuevoEstado < 0 || nuevoEstado > 3)
   {
    cout << "Estado invalido." << endl;
    return;
   }
   reg.setEstado(nuevoEstado);

   if(nuevoEstado == 3){
    Fecha fActual;
    fActual.CargarFechaActual();
    reg.setFechaCierre(fActual);
   }else if(nuevoEstado == 0){
            reg.setIdAreaSoporte(0);
            reg.setIdUsrSoporte(0);
                }

   //cout << "Nuevo estado en  memoria: " << reg.getEstado() << endl;
   bool modifico = arch.ModificarTicket(reg, pos);

   if (modifico)
   {
    cout << "Estado modificado correctamente." << endl;
   }
   else{
    cout << "Error al modificar el estado." << endl;
   }
   Ticket prueba;

   prueba = arch.LeerTicket(pos);

   cout << "Estado guardado en archivo: " << prueba.getEstado() << endl;

}

void VerRespuestasTicket(){

  archivoRespuesta archResp;
  int idTicket;

  cout << "Ingrese ID del ticket: ";
  cin >> idTicket;

  cout << "RESPUESTAS DEL TICKET" << idTicket << endl;

  archResp.todasRespuestasxTicket(idTicket);

  system("pause");

}

//aca esta la logica


