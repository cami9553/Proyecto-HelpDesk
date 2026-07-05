#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include "fecha.h"
#include "usuarios.h"
class Ticket {

private:

    int idTicket;
    int idUsuario;
    int idUsrSoporte;
    int idAreaSoporte;
    int idCategoria;
    char asunto[100];
    char descripcion[200];
    char comentario[200];
    int prioridad;
    int estado;
    Fecha fechaCreacion;
    Fecha fechaCierre;

public:

    bool CreatTicket (Usuario logd);
    void MostrarTicket();
    void MostrarTicketPreview();
    int NumIdTicket ();
    void AgregarComentario();

    int getIdTicket();
    int getIdUsuario();
    const char* getAsunto();
    const char* getDescripcion();
    const char* getComentario();
    int getIdAreaSoporte();
    int getIdUsrSoporte();
    int getIdCategoria();
    int getPrioridad();
    int getEstado();
    Fecha getFechaCreacion();
    Fecha getFechaCierre();
    void setIdTicket(int id);
    void setIdUsuario(int id);
    void setIdUsrSoporte(int _idUsrSoporte);
    void setAsunto(std::string _asunto);
    void setDescripcion(std::string _desc);
    void setComentario(std::string _coment);
    void setIdAreaSoporte(int idArea);
    void setIdCategoria(int idCat);
    void setPrioridad(int prio);
    void setEstado(int est);
    void setFechaCreacion(Fecha fCreacion);
    void setFechaCierre(Fecha fCierre);

};





#endif // TICKET_H_INCLUDED
