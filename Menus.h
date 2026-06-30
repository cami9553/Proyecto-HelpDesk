#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "usuarios.h"

void muereXLogin(int cont);
void ingresoUsuarios();

void MostrarMenuAdmin(Usuario &user1);
void MostrarMenuCliente(Usuario &user1);







void ingresoUsuarios();
void menuAdmin();
void menuSoporte();
void MostrarMenuCliente(Usuario &user1);
bool validarIdElegido(int idAsig, Usuario &user1);
#endif // MENUS_H_INCLUDED

