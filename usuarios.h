#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

class Usuario {
private:
    int _idUsuario;
    char _Email[30];
    char _nombre[30];
    char _apellido[30];
    char  _clave[30];
    int _idrol;
    bool _activo;
public:
    Usuario();

    Usuario(int idUsuario,std::string email, std::string nombre, std::string apellido, std::string clave, int idRol, bool activo);
    void cargar();
    void mostrar();
    //GETTERS
    int getIDUsuario();
    const char* getEmail();
    const char* getNombre();
    const char* getApellido();
    const char* getClave();
    int getRol();
    bool getActivo();
    //SETTERS
    void setIDUsuario(int id);
    void setEmail(std::string email);
    void setNombre(std::string name);
    void setApellido(std::string ape);
    void setClave(std::string clave);
    void setIdRol(int rol);
    void setActivo(bool act);


    };


#endif
