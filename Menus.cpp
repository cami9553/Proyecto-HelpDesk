#include <iostream>
using namespace std;
#include "ArchivoUsuarios.h"
#include "usuarios.h"
#include <cstring>
#include "Menus.h"
#include "ticket.h"
#include "TicketArchivo.h"

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
            cout << "Bienvenido al menu Soporte"<< endl;
            //menuSoporte();
            break;
        case 3:
            cout << "Bienvenido al menu Cliente"<< endl;
            MostrarMenuCliente(usrLog);
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

void MostrarMenuCliente(Usuario &user1){


Ticket t1;
TickeArchivo Archivo;
int Opcion;
int Cantidad;

do{


cout<<"         Menu Cliente         "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 1) Crear Ticket              "<<endl;
cout<<" 2) Ver mis tickets           "<<endl;
cout<<" 3) Ver Respuesta de un ticket"<<endl;
cout<<" 4) Mis datos                 "<<endl;
cout<<"------------------------------"<<endl;
cout<<" 0) Cerrar sesion             "<<endl<<endl;

cout<<"Opcion: ";
cin>>Opcion;



switch(Opcion){

case 1:

    t1.CreatTicket();
    if(Archivo.GuardarTicket(t1)){
        cout<<"Tiket guardado correctamente"<<endl;
    }else{
    cout<<"Error al guardar ticket"<<endl;
    }


    break;


case 2:

  Cantidad = Archivo.CantidadTickets();

  for(int i=0; i<Cantidad;i++){
    t1=Archivo.LeerTicket(i);
    t1.MostrarTicket();

  }

    break;

case 4:

    user1.mostrar();
    break;


case 0:

    break;





system ("pause");
system ("cls");

}




}while(Opcion!=0);

}
