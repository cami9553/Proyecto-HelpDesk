#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED

#include "Categoria.h"
#include <string>

class ArchivoCategoria{
public:
  ArchivoCategoria();
  ArchivoCategoria(std::string archivo);

  bool registrar(Categoria &reg);

  Categoria leerCategoria(int pos);
  void listarTodas();
  
  void bajaLogica(int idCategora);

  int contarTotalCategorias();

  int obtenerSiguienteID();


  private:
  std::string _archivo;
};

#endif 

