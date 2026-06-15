#include <iostream> 
using namespace std;
#include "MenuAdmiConfiguracion.h" 

void cambiarContrasenia(Usuario &user1){

    string nuevaClave;

    cout << "Ingres una nueva Clave: ";
    cin >> nuevaClave;

     user1.setClave(nuevaClave);
}
void  verMisDatos(Usuario &user1){

    cout << "Ver Mis Datos" << endl;
}