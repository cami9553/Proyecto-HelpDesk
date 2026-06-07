#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include "fecha.h"

class Ticket {

private:

    int idTicket;
    int idUsuario;
    int idAreaSoporte;
    int idCategoria;
    char asunto[100];
    char descripcion[200];
    int prioridad;
    int estado;
    Fecha fechaCreacion;
    Fecha fechaCierre;

public:

    bool CreatTicket ();
    void MostrarTicket();
    int NumIdTicket ();

    int getIdTicket();


};





#endif // TICKET_H_INCLUDED
