#include <iostream>
using namespace std;
#include "ModificarUsuariosSoporteCliente.h"
#include "ArchivoUsuarios.h"
#include "usuarios.h"

void menuModificarUsrSoporte(Usuario &usrlog){
// Este menu va a servir tanto para CLIENTE como para SOPORTE
archivoUsuario arch;
bool guardado;
int opcion;
char nuevoValor[30];
    do{
        system("cls");
        cout << "==========================" << endl;
        cout << "¿Que desea modificar?     " << endl;
        cout << "1-Nombre                  " << endl;
        cout << "2-Apellido                " << endl;
        cout << "3-Email                   " << endl;
        cout << "4-Clave                   " << endl;
        cout << "0-Salir.                  " << endl;
        cout << "==========================" << endl;
        cin >> opcion;
        system("cls");
        switch(opcion){
    case 1:
        cout << "Ingrese nuevo nombre: "<< endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrlog.setNombre(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo nombre guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo nombre."<<endl;
            }
        system("pause");
        break;
    case 2:
        cout << "Ingrese nuevo Apellido: " << endl;
        cin.ignore();
        cin.getline(nuevoValor,30);
        usrlog.setApellido(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo Apellido guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo Apellido."<<endl;
            }
        system("pause");
        break;
    case 3:
        cout << "Ingrese el nuevo email: " << endl;
        cin >> nuevoValor;
        usrlog.setEmail(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nuevo Email guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar el nuevo email."<<endl;
            }
        system("pause");
        break;
    case 4:
        cout << "Ingrese la nueva clave: " << endl;
        cin >> nuevoValor;
        usrlog.setClave(nuevoValor);

        guardado = arch.modificar(usrlog);
        if(guardado == true){
            cout <<"Nueva clave guardado con exito."<<endl;
        }else{
            cout <<"No se pudo guardar la nueva clave."<<endl;
            }
        system("pause");
        break;
    case 0:
        cout << "Saliendo del menu modificar!" << endl;
        break;
        }

        }while(opcion != 0);


    }
