#include <iostream>
using namespace std;
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"

void muereXLogin(int cont){
    if(cont >=3){
       cout << "Ingreso mal el login 3 veces, el proceso se cerrara."<<endl;
       exit(1);
        }
}

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
    cout << "\n---Iniciar sesion---"<< endl;
    cout << "Ingrese 0 en email para finalizar programa." << endl;
    cout << "Ingrese email:"<< endl;

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
        rolLogueado = usrLog.getRol();
        switch(rolLogueado){
        case 1:
            cout << "Bienvenido al menu Admin"<< endl;
            //menuAdmin();
            break;
        case 2:
            cout << "Bienvenido al menu Admin"<< endl;
            //menuSoporte();
            break;
        case 3:
            cout << "Bienvenido al menu Admin"<< endl;
            //menuCliente();
            break;
        }
        //break; para que no me muestre nuevamente el iniciar sesion.
    }else{
        cout<< "Contrasena incorrecta."<< endl;
        cont++;
        cout<<"contador: " <<cont<<endl;
        muereXLogin(cont); //Si ingresa 3 veces mal usuario contra se cierra el programa.
        }
   }while(true);

}
