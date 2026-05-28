#include <iostream>
#include "TiketArchivo.h"
#include "Ticket.h"

using namespace std;



///-------GUARDAR TICKET----------------


bool TickeArchivo :: GuardarTicket ( Ticket t1 ){
/// Recibe por paramatro una variable ticket
FILE* arch;


///apertura del archivo
arch = fopen("ticket.dat", "wb");

///validación
if (arch==nullptr){
    cout<<"Error de archivo"<<endl;
    return false;
}
/// Escritura del ticket en memoria (guardado del ticket)
bool escribio = fwrite (&t1, sizeof(Ticket),1,arch);

fclose(arch);

return escribio;
}


int TickeArchivo::CantidadTickets(){

    FILE* arch;


    arch = fopen("ticket.dat","rb");

    if(arch==nullptr){
        return 0;
    }

    fseek(arch,0,SEEK_END);

    int tamanio=ftell(arch);

    fclose(arch);

    return tamanio/sizeof(Ticket);
}



Ticket TickeArchivo:: LeerTicket(int pos){

 Ticket t1;

    FILE* arch=fopen("ticket.dat","rb");

    if(arch==nullptr){
        return t1;
    }

    fseek(arch, pos*sizeof(Ticket), SEEK_SET);

    fread(&t1, sizeof(Ticket), 1, arch);

    fclose(arch);

    return t1;
}





