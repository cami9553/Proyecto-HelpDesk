#ifndef ARCHIVORESPUESTAS_H_INCLUDED
#define ARCHIVORESPUESTAS_H_INCLUDED
#include "Respuestas.h"
class archivoRespuesta{
public:
    bool cargarArchivo(respuestas &resp); //Desarrollada
    respuestas leerRespuesta(int idRespuesta); //Desarrollada
    void todasRespuestasxTicket(int idTicket); //Desarrollada
    archivoRespuesta(); //Desarrollada
    archivoRespuesta(std::string archivo); //Desarrollada
    int obtenerSiguienteID(); //Desarrollada
    int cantidadRespuestas(); //Desarrollada
private:
    std::string _archivo;
};

#endif // ARCHIVORESPUESTAS_H_INCLUDED
