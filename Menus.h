#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "usuarios.h"

void muereXLogin(int cont);
void ingresoUsuarios();

void MostrarMenuAdmin(Usuario &user1);
void MostrarMenuCliente(Usuario &user1);
void MostrarMenuSoporte(Usuario &user1);


void MenuGestionUsuarios();
void MenuGestionTickets();
void MenuGestionCategorias();
void MenuGestionAreasSoporte();
void menuModificarAreaSoporte();
void MenuGestionRoles();
void MenuGestionEstadisticas();
void MenuAdmiConfiguracion(Usuario &user1);


void ingresoUsuarios();
void menuAdmin();
void menuSoporte();
void MostrarMenuCliente(Usuario &user1);

#endif // MENUS_H_INCLUDED
