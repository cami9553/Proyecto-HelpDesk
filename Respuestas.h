#ifndef RESPUESTAS_H_INCLUDED
#define RESPUESTAS_H_INCLUDED
#include "Fecha.h"
#include <string> 

class respuestas{
private:
    int _idMensaje;
    int _idTicket;
    int _idUsuarioAutor;
    char _contenido[200];
    Fecha _fechaHora;

public:
    respuestas();

    respuestas(int idMensaje, int idTicket, int idUsuarioAutor, std::string contenido);

    // SETTERS
    void setIdMensaje(int idMensaje);
    void setIdTicket(int idTicket);
    void setIdUsuarioAutor(int idAutor);
    void setContenido(std::string contenido);
    void setFechaHora(Fecha fechaHora);

    // GETTERS
    int getIdMensaje() const;
    int getIdTicket() const;
    int getIdUsuarioAutor() const;
    const char* getContenido() const;
    Fecha getFechaHora() const;


};

#endif // RESPUESTAS_H_INCLUDED
