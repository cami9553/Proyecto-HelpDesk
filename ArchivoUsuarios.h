#ifndef ARCHIVOUSUARIOS_H_INCLUDED
#define ARCHIVOUSUARIOS_H_INCLUDED
#include "usuarios.h"

class archivoUsuario {
public:
    void registrar(Usuario &reg); //Desarrollada ok
    void bajaLogica(int idUsuario); //Desarrollada ok
    void altaLogica(int idUsuario); //Desarrollada ok
    void modificar(Usuario &reg); //
    Usuario buscarPorId(int idUsuario);
    Usuario buscarPorEmail(const char* usuario);
    bool validarLogin(const char* usuario, const char* clave,Usuario &reg); // Desarrollada OK
    Usuario leerUsuario(int idUsuario); //Desarrollada ok
    void listarPorRol(int idRol); //Desarrollada ok
    void listarActivos(); //Desarrollada ok
    void listarTodos(); //Corregida OK
    int contarActivos(); //Desarrollada Ok
    int contarTotalUsuarios(); //Desarrollada ok
    archivoUsuario(); //Desarrollada ok
    archivoUsuario(std::string archivo); //Desarrollada ok
    int obtenerSiguienteID(); //Desarrollada ok
private:
    std::string _archivo;
    };


#endif // ARCHIVOUSUARIOS_H_INCLUDED
