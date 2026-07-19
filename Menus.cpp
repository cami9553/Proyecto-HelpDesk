#include <iostream>
using namespace std;
#include <string>
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"
#include "ticket.h"
#include "TicketArchivo.h"
#include "GestionUsuarios.h"
#include "GestionTickets.h"
#include "GestionCategorias.h"
#include "Categoria.h"
#include "GestionEstadisticas.h"
#include "Menus.h"
#include "ArchivoAreaSoporte.h"
#include "AreaSoporte.h"
#include "MenuAdmiConfiguracion.h"
#include "Roles.h"
#include "ArchivoRoles.h"
#include "Categoria.h"
#include "Respuestas.h"
#include "ArchivoCategoria.h"
#include "ArchivoRespuestas.h"



void muereXLogin(int cont){
    if(cont >=3){
       cout << "Ingreso mal el login 3 veces, el proceso se cerrara."<<endl;
       exit(1);
        }
}

void MostrarMenuSoporte(Usuario &user1);
void MostrarMenuCliente(Usuario &user1);

void MostrarMenuAdmin(Usuario &user1);

void MenuGestionUsuarios();
void MenuGestionTickets();
void MenuGestionCategorias();
void MenuGestionAreasSoporte();
void MenuGestionRoles();
void MenuGestionEstadisticas();
void MenuAdmiConfiguracion(Usuario &user1);

void menuModificarAreaSoporte();
void MenuModificarRoles();
void menuModificarAdmin();

void ingresoUsuarios(){
    int cont=0;
    int rolLogueado =0;
    archivoUsuario arch;
    Usuario usrLog;
    bool loginExitoso;
    char email[30];
    char contra[30];



    //cin.ignore();
   do{
    system("cls");
    cout << "===============================================" <<endl;
    cout << "|             INICIAR SESION                  |"<< endl;
    cout << "===============================================" <<endl;
    cout << "| Ingrese 0 en email para finalizar programa. |" << endl;
    cout << "| Ingrese email:                              |"<< endl;
    cout << "===============================================" <<endl;

    cin.getline(email,30);

    if(strcmp(email,"0")== 0){
        cout << "Programa finalizado" << endl;
        break;
    }
    cout << "Ingrese contrasena:"<< endl;
    cin.getline(contra,30);
    loginExitoso = arch.validarLogin(email,contra,usrLog);
    //cout << loginExitoso;
    if(loginExitoso == true){
            system("cls");
        rolLogueado = usrLog.getRol();

        switch(rolLogueado){
        case 1:
            cout << "Bienvenido al menu Admin"<< endl;
            MostrarMenuAdmin(usrLog);
            cin.ignore();
            break;
        case 2:
            cout << "Bienvenido al menu Soporte"<< endl;
            MostrarMenuSoporte(usrLog);
            cin.ignore();
            break;
        case 3:
            cout << "Bienvenido al menu Cliente"<< endl;
            MostrarMenuCliente(usrLog);
            cin.ignore();
            break;
        }
        //break; para que no me muestre nuevamente el iniciar sesion.
    }else{

        cout<< "Contrasena incorrecta."<< endl;
        cont++;
        //cout<<"contador: " <<cont<<endl;
        cin.ignore();
        muereXLogin(cont); //Si ingresa 3 veces mal usuario contra se cierra el programa.
        }
   }while(true);

}
