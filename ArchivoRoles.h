#ifndef ARCHIVOROLES_H_INCLUDED
#define ARCHIVOROLES_H_INCLUDED
#include "Roles.h"

class rolesArchivo{
private:
    std::string _archivo;
public:
    rolesArchivo(); //Desarrollada
    rolesArchivo(std::string archivo); //Desarrollada
    int obtenerSiguienteID(); //Desarrollada
    bool registrar(roles &reg);  //Desarrollada
    void bajaLogica(int idRol);  //Desarrollada
    void altaLogica(int idRol);  //Desarrollada
    bool modificar(roles &reg);   //Desarrollada
    roles leerRol(int idRol); //Desarrollada
    void listarTodos(); //Desarrollada
    int contarTotalRoles(); //Desarrollada
};

#endif // ARCHIVOROLES_H_INCLUDED
