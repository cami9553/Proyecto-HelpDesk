#ifndef ROLES_H_INCLUDED
#define ROLES_H_INCLUDED
#include "Roles.h"

class roles {
private:
    int _idRol;
    char _descripcion[30];
    bool _estado;
public:
    roles();
    roles(int idRol, std::string descripcion, bool estado);
    //GETTERS
    int getIdRol();
    char* getDescripcion();
    bool getEstado();
    //SETTERS
    void setIdRol(int id);
    void setDescripcion(std::string descripcion);
    void setEstado(bool estado);
};


#endif // ROLES_H_INCLUDED
