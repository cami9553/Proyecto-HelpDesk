#ifndef TIKETARCHIVO_H_INCLUDED
#define TIKETARCHIVO_H_INCLUDED
#include "Ticket.h"

class TickeArchivo {


public:

bool  GuardarTicket (Ticket t1);

void ListarTickets();

int CantidadTickets();

Ticket LeerTicket(int pos);
};


#endif // TIKETARCHIVO_H_INCLUDED
