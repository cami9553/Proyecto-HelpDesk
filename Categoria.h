#ifndef CATEGORIA_h_INCLUDED
#define CATEGORIA_h_INCLUDED

class Categoria{
    private:
    int _idCategoria;
    char _nombre[30];
    bool _activo;


    public:
    Categoria();

   void setIdCategoria(int id);
   void setNombre(const char* nombre);
   void setActivo(bool activo);

  int getIdCategoria();
  const char* getNombre();
  bool getActivo();

  void cargar();
  void mostrar();

};

#endif 