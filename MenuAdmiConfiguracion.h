#ifndef MENUADMINCONFIGURACION_H_INCLUDED
#define MENUADMINCONFIGURACION_H_INCLUDED

#include "usuarios.h"

void cambiarContrasenia(Usuario &user1);
void verMisDatos(Usuario &user1);
void MenuAdmiConfiguracion(Usuario &user1);
void MenuBackup();

void MenuRestauracion();
void MenuExportacionCSV();
void backupUsuarios();
void backupTickets();
void backupCategorias();
void backupAreas();
void backupCompleto();


#endif 