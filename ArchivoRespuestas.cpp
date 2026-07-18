#include <iostream>
using namespace std;
#include "ArchivoRespuestas.h"
#include "usuarios.h"
#include "ArchivoUsuarios.h"

archivoRespuesta::archivoRespuesta(){
    _archivo = "respuestas.dat";
}
archivoRespuesta::archivoRespuesta(std::string archivo){
    _archivo = archivo;
}

 int archivoRespuesta::obtenerSiguienteID(){
     int siguienteID;
    FILE *f = fopen(_archivo.c_str(),"rb");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
    fseek(f,0,SEEK_END);
    int bytes = ftell(f);
    fclose(f);
    siguienteID = (bytes /sizeof(respuestas))+1;

    return siguienteID;
}
respuestas archivoRespuesta::leerRespuesta(int idRespuesta){
    respuestas resp;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
        fseek(f,idRespuesta * sizeof(respuestas),0);
        fread(&resp,sizeof(respuestas),1,f);
        fclose(f);
        return resp;
}
int archivoRespuesta::cantidadRespuestas(){
    int cantTickets;
    FILE *f = fopen(_archivo.c_str(),"rb+");
    if(f==NULL){
        cout << "error al abrir archivo, el sistema se cerrara."<<endl;
        exit(1); //Exit me va a terminar el programa directamente.
        }
        fseek(f,0,SEEK_END);
        int bytes = ftell(f);
        fclose(f);
        cantTickets = bytes / sizeof(respuestas);
        return cantTickets;
}

void archivoRespuesta::todasRespuestasxTicket(int idTicket){
    respuestas resp;
    Usuario usr;
    archivoUsuario archU;
    int contadorRespuestas=0;

    int i=0;
    int CantTickets = cantidadRespuestas();
    for(i=0;i<CantTickets;i++){
        resp = leerRespuesta(i);
        if(resp.getIdTicket()== idTicket){
            usr = archU.leerUsuario(resp.getIdUsuarioAutor()-1);
            cout << "Id Ticket: " << resp.getIdTicket() << endl;
            cout << "Autor: " << usr.getNombre()<<endl;
            cout << "Fecha: " ;
            resp.getFechaHora().MostrarFecha();
            cout << endl;
            cout << "Contenido: " << resp.getContenido() << endl;
            contadorRespuestas++;
        }
    }
    if(contadorRespuestas==0){
        cout << "El ticket todavia no tuvo respuestas." << endl;
    }
}

bool archivoRespuesta::cargarArchivo(respuestas &resp) {
    FILE *f = fopen(_archivo.c_str(), "ab");
    if (f == NULL) {
        return false;
    }
    int  siguienteID = obtenerSiguienteID();
    resp.setIdMensaje(siguienteID);
    bool escribio = fwrite(&resp, sizeof(respuestas), 1, f);
    fclose(f);
    return escribio;
}
