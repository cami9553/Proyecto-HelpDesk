#ifndef AREASOPORTE_H_INCLUDED
#define AREASOPORTE_H_INCLUDED

class areaSoporte{
private:
    int _idAreaSoporte;
    char _nombre[30];
    char _descripcion[30];
    bool _activo;
public:
    areaSoporte();
    areaSoporte(int idAreaSoporte, std::string nombre, std::string descripcion, bool activo);

    int getIdAreaSoporte();
    char* getNombre();
    char* getDescripcion();
    bool getActivo();
    void setIdAreaSoporte(int id);
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setActivo(bool activo);
    void cargar();
    void mostrar();
};

#endif // AREASOPORTE_H_INCLUDED
