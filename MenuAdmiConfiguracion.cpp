#include <iostream> 
using namespace std;
#include "MenuAdmiConfiguracion.h" 

void cambiarContrasenia(Usuario &user1){

    string nuevaClave;

    cout << "Ingres una nueva Clave: ";
    cin >> nuevaClave;

     user1.setClave(nuevaClave);
}
void verMisDatos(Usuario &user1){

    cout << "ID: " << user1.getIDUsuario() << endl;
    cout << "Email: " << user1.getEmail() << endl;
    cout << "Nombre: " << user1.getNombre() << endl;
    cout << "Apellido: " << user1.getApellido() << endl;
    cout << "Rol: " << user1.getRol() << endl;
}
void MenuRestauracion(){
    cout << "Menu Restauracion" << endl;
}

void MenuExportacionCSV(){
    cout << "Menu Exportacion CSV" << endl;
}


void MenuBackup(){

    int opcion;

    do{

        cout << "COPIA DE SEGURIDAD" << endl;
        cout << "1- Usuarios" << endl;
        cout << "2- Tickets" << endl;
        cout << "3- Categorias" << endl;
        cout << "4- Areas de Soporte" << endl;
        cout << "5- Todos los archivos" << endl; 
        cout << "0- Volver" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        if(cin.fail()){
            cout << "Debe ingresar un numero." << endl; 

            cin.clear();
            cin.ignore(1000, '\n');
            
            continue;
        }

        switch (opcion)
        {
        case 1:
            backupUsuarios();
            break;
        

        case 2:
            backupTickets();
            break;

        case 3: 
            backupCategorias();
            break;

        case 4:
            backupAreas();
            break;

        case 5:
            backupCompleto();
            break;

        case 0:
            break;


        default:
            cout << "Opcion invalida." << endl;
            break;
        }


    }while(opcion != 0);

}

void backupUsuarios(){
    cout << "Backup Usuarios" << endl;
}

void backupTickets(){
    cout << "Backup Tickets" << endl;
}

void backupCategorias(){
    cout << "Backup Categorias" << endl;
}

void backupAreas(){
    cout << "Backup Areas de Soporte" << endl;
}

void backupCompleto(){
    cout << "Backup Completo" << endl;
}