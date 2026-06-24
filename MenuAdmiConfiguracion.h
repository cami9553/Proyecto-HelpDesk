#ifndef MENUADMINCONFIGURACION_H_INCLUDED
#define MENUADMINCONFIGURACION_H_INCLUDED

#include "usuarios.h"

void cambiarContrasenia(Usuario &user1);
void verMisDatos(Usuario &user1);
void MenuAdmiConfiguracion(Usuario &user1);
void MenuBackup();


void MenuExportacionCSV();
void backupUsuarios();
void backupTickets();
void backupCategorias();
void backupAreaSoporte();
void backupCompleto();

void MenuRestauracion();

void restaurarUsuarios();
void restaurarTickets();
void restaurarCategorias();
void restaurarAreaSoporte();
void restaurarCompleto();

void exportarCategoriaCSV();

void exportarUsuariosCSV();
void exportarTicketCSV();
void exportarCategoriasCSV();
void exportarAreaSoporteCSV();


#endif 