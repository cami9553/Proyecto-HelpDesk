#ifndef ARCHIVOUSUARIOS_H_INCLUDED
#define ARCHIVOUSUARIOS_H_INCLUDED
#include "usuarios.h"

class archivoUsuario {
public:
    void registrar(Usuario &reg);
    void bajaLogica(int idUsuario);
    void modificar(Usuario &reg);
    Usuario buscarPorId(int idUsuario);
    Usuario buscarPorUsuario(const char* usuario);
    bool validarLogin(const char* usuario, const char* clave,Usuario &reg);

    void listarPorRol(int idRol);
    void listarActivos();
    int contarActivos();
    int contarTotalUsuarios();
    archivoUsuario();
    archivoUsuario(std::string archivo);
    int obtenerSiguienteID();
private:
    std::string _archivo;
    };


#endif // ARCHIVOUSUARIOS_H_INCLUDED
