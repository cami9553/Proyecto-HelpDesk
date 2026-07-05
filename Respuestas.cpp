#include <iostream>
using namespace std;
#include "Respuestas.h"
#include "ArchivoRespuestas.h"
#include <cstring>
respuestas::respuestas() {
    _idMensaje = 0;
    _idTicket = 0;
    _idUsuarioAutor = 0;
    _contenido[0] = '\0';
}

respuestas::respuestas(int idMensaje, int idTicket, int idUsuarioAutor, std::string contenido) {
    _idMensaje = idMensaje;
    _idTicket = idTicket;
    _idUsuarioAutor = idUsuarioAutor;
    strncpy(_contenido,contenido.c_str(), 199);
    _contenido[199] = '\0';
}

// --- SETTERS ---

void respuestas::setIdMensaje(int idMensaje) {
    _idMensaje = idMensaje;
}

void respuestas::setIdTicket(int idTicket) {
    _idTicket = idTicket;
}

void respuestas::setIdUsuarioAutor(int idAutor) {
    _idUsuarioAutor = idAutor;
}

void respuestas::setContenido(std::string contenido) {

    strncpy(_contenido, contenido.c_str(), 199);
    _contenido[199] = '\0';

}

void respuestas::setFechaHora(Fecha fechaHora) {
    _fechaHora = fechaHora;
}

// --- GETTERS ---

int respuestas::getIdMensaje() const {
    return _idMensaje;
}

int respuestas::getIdTicket() const {
    return _idTicket;
}

int respuestas::getIdUsuarioAutor() const {
    return _idUsuarioAutor;
}

const char* respuestas::getContenido() const {
    return _contenido;
}

Fecha respuestas::getFechaHora() const {
    return _fechaHora;
}
