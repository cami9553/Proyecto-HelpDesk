#include <iostream>
using namespace std;
#include "MenuAdmiConfiguracion.h"
#include "AreaSoporte.h"
#include <fstream>
#include "Categoria.h"
#include "ticket.h"
#include "AreaSoporte.h"
#include "ArchivoUsuarios.h"

void cambiarContrasenia(Usuario &user1){
    archivoUsuario archU;
    string nuevaClave;

    cout << "Ingres una nueva Clave: ";
    cin >> nuevaClave;

     user1.setClave(nuevaClave);
     bool guardado = archU.modificar(user1);
     if(guardado== true){
           cout << "contrasenia modificada correctamente: "<< endl;
     }else{
        cout << "No se pudo cambiar contrasenia" << endl;
        }
}
void verMisDatos(Usuario &user1){

    cout << "ID: " << user1.getIDUsuario() << endl;
    cout << "Email: " << user1.getEmail() << endl;
    cout << "Nombre: " << user1.getNombre() << endl;
    cout << "Apellido: " << user1.getApellido() << endl;
    cout << "Rol: " << user1.getRol() << endl;
}

void MenuRestauracion(){

     int opcion;

     do{

        cout << "RESTAURAR COPIA" << endl;
        cout << "1- Usuarios" << endl;
        cout << "2- Tickets" << endl;
        cout << "3- Categorias" << endl;
        cout << "4- Area de Soporte" << endl;
        cout << "5- Todos los archivos" << endl;
        cout << "0- Volver" << endl;

         cout << "Opcion: ";
         cin >> opcion;

         switch (opcion)
         {
         case 1:
            restaurarUsuarios();
            break;
        case 2:
           restaurarTickets();
           break;

        case 3:
           restaurarCategorias();
           break;

        case 4:
          restaurarAreaSoporte();
          break;

        case 5:
         restaurarCompleto();
         break;

        case 0:
         break;

          default:
          cout << "Opcion invalida." << endl;
            break;
         }
        }while(opcion != 0);
}

void MenuExportacionCSV(){

    int opcion;

    do{

        cout << "EXPORTAR CSV" << endl;
        cout << "1- Usuarios" << endl;
        cout << "2- Tickets" << endl;
        cout << "3- Categorias" << endl;
        cout << "4- Areas de Soporte" << endl;
        cout << "0- Volver" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion){

        case 1:
            exportarUsuariosCSV();
            break;

        case 2:
          exportarTicketCSV();
           break;

        case 3:
         exportarCategoriasCSV();
          break;

        case 4:
           exportarAreaSoporteCSV();
            break;

        case 0:
         break;


          default:
          cout << "Opcion invalida." << endl;
            break;
        }

    }while(opcion != 0);
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
            backupAreaSoporte();
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

    cout << "ENTRE A BACKUP DE USUARIOS" << endl;

    ifstream origen("usuarios.dat", ios::binary);
    ofstream destino("backups/usuarios.dat", ios::binary);

    if(!origen){
        cout << "No se pudo abrir usuarios.dat" << endl;
        return;
    }

    if(!destino){
        cout << "No se pudo crear el backup" << endl;
        return;
    }

    destino << origen.rdbuf();

    cout << "--------------------------------" << endl;
    cout << "Backup realiziado correctamente." << endl;
    cout << "--------------------------------" << endl;

    cout << "Copiando usuarios.dat..." << endl;
    origen.close();
    destino.close();
}

void backupTickets(){
     ifstream origen("ticket.dat", ios::binary);
     ofstream destino("backups/ticket.dat", ios::binary);  // revisar bien esto

    if(!origen){
        cout << "No se pudo abrir ticket.dat" << endl;
        return;
    }

    if(!destino){
        cout << "No se pudo crear el backup" << endl;
        return;
    }

    destino << origen.rdbuf();

    cout << "Backup realiziado correctamente." << endl;

    origen.close();
    destino.close();
}

void backupCategorias(){

     ifstream origen("categorias.dat", ios::binary);
     ofstream destino("backups/categorias.dat", ios::binary);

    if(!origen){
        cout << "No se pudo abrir categorias.dat" << endl;
        return;
    }

    if(!destino){
        cout << "No se pudo crear el backup" << endl;
        return;
    }

    destino << origen.rdbuf();

    cout << "Backup realiziado correctamente." << endl;

    origen.close();
    destino.close();
}

void backupAreaSoporte(){
     ifstream origen("areaSoporte.dat", ios::binary);
     ofstream destino("backups/areaSoporte.dat", ios::binary);

    if(!origen){
        cout << "No se pudo abrir areaSoporte.dat" << endl;
        return;
    }

    if(!destino){
        cout << "No se pudo crear el backup" << endl;
        return;
    }

    destino << origen.rdbuf();

    cout << "Backup realiziado correctamente." << endl;

    origen.close();
    destino.close();
}

void backupCompleto(){
     backupUsuarios();
     backupTickets();
     backupCategorias();
     backupAreaSoporte();

     cout << "Backup completo realizado." << endl;
}

void restaurarUsuarios(){
    ifstream origen("backups/usuarios.dat", ios::binary);
    ofstream destino("usuarios.dat", ios::binary);

    if (!origen){
        cout << "No existe el backup de usuarios." << endl;
        return;
    }

    if(!destino){
        cout << "no se pudo restaurar usuarios.dat" << endl;
        return;

    }

    destino << origen.rdbuf();

    cout << "Usuarios restaurados correctamente." << endl;

    origen.close();
    destino.close();

}

void restaurarTickets(){
    ifstream origen("backups/ticket.dat", ios::binary);
    ofstream destino("ticket.dat", ios::binary);

    if (!origen){
        cout << "No existe el backup de ticket." << endl;
        return;
    }

    if (!destino){
        cout << "no se pudo restaurar ticket.dat" << endl;
        return;
    }

    destino << origen.rdbuf();
     cout << "Tickets restaurados correctamente." << endl;

     origen.close();
     destino.close();
}

void restaurarCategorias(){
    ifstream origen("backups/categorias.dat", ios::binary);
    ofstream destino("categorias.dat", ios::binary);

    if (!origen){
        cout << "No existe el backup categorias" << endl;
        return;
    }

    if (!destino){
        cout << "No se pudo restaurar categorias.dat" << endl;
        return;
    }
    destino << origen.rdbuf();
    cout <<  "Categorias restaurado correctamente" << endl;

    origen.close();
    destino.close();

}

void restaurarAreaSoporte(){
    ifstream origen("backups/areaSoporte.dat", ios::binary);
    ofstream destino("areaSoporte.dat", ios::binary);

    if (!origen){
      cout << "No existe el backup areaSoporte.dat." << endl;
      return;


    if (!destino) {
        cout << "No se pudo restaurar areaSoporte.dat" << endl;
        return;
    }

    destino << origen.rdbuf();
    cout << "Area restaurado correctamente" << endl;

    origen.close();
    destino.close();

}
}

void restaurarCompleto(){

    restaurarUsuarios();
    restaurarTickets();
    restaurarCategorias();
    restaurarAreaSoporte();

    cout << "Restauracion completa realizada" << endl;

}

void exportarCategoriasCSV(){

    ifstream archivoDat("categorias.dat", ios::binary);
    ofstream archivoCSV("categorias.csv");

    if (!archivoDat)
    {
        cout << "No se pudo abrir categorias.dat" << endl;
        return;
    }

    if (!archivoCSV)
    {
        cout << "No se pudo crear categorias.csv" << endl;
        return;
    }
    Categoria reg;

    archivoCSV << "ID, Nombre, Activo" << endl;


    while(archivoDat.read((char*)&reg, sizeof(Categoria))){
        archivoCSV << reg.getIdCategoria() << ",";
        archivoCSV << reg.getNombre() << ",";
        archivoCSV << reg.getActivo() << endl;
    }

    archivoDat.close();
    archivoCSV.close();

    cout << "Categorias exportadas correctamente a categoria.csv" << endl;

}

void exportarUsuariosCSV(){

    ifstream archivoDat("usuarios.dat", ios::binary);
    ofstream archivoCSV("usuarios.csv");

    if (!archivoDat)
    {
        cout << "No se pudo abrir usuarios.dat" << endl;
        return;
    }

    if (!archivoCSV)
    {
        cout << "No se pudo crear usuarios.dat" << endl;
        return;
    }

    Usuario reg;

    archivoCSV <<"ID, Email, Nombre, Apellido, Rol" << endl;

    while(archivoDat.read((char*)&reg, sizeof(Usuario))){
        archivoCSV << reg.getIDUsuario() << ",";
        archivoCSV << reg.getEmail()<< ",";
        archivoCSV << reg.getNombre() << ",";
        archivoCSV << reg.getApellido() << ",";
        archivoCSV << reg.getRol() << ",";
    }
    archivoDat.close();
    archivoCSV.close();

    cout << "Usuarios exportados correctamente a usuarios.csv" << endl;
}

void exportarTicketCSV(){

    ifstream archivoDat("ticket.dat", ios::binary);
    ofstream archivoCSV("ticket.csv");

    if (!archivoDat)
    {
        cout << "No se pudo abrir ticket.dat" << endl;
        return;
    }

    if (!archivoCSV)
    {
        cout << "No se pudo crear ticket.dat" << endl;
        return;
    }
    Ticket reg;

    archivoCSV << "ID" << endl;

       while(archivoDat.read((char*)&reg, sizeof(Ticket))){
        archivoCSV << reg.getIdTicket() << endl;
    }

    archivoDat.close();
    archivoCSV.close();

    cout << "Tickets exportados correctamente a tickets." << endl;



}

void exportarAreaSoporteCSV(){


    ifstream archivoDat("areaSoporte.dat", ios::binary);
    ofstream archivoCSV("areaSoporte.csv");

    if (!archivoDat)
    {
        cout << "No se pudo abrir areaSoporte.dat" << endl;
        return;
    }

    if (!archivoCSV)
    {
        cout << "No se pudo crear areaSoporte.csv" << endl;
        return;
    }

    areaSoporte reg;

    archivoCSV << "ID,Nombre,Descripcion,Activo" << endl;

    while(archivoDat.read((char*)&reg, sizeof(areaSoporte))){
        archivoCSV << reg.getIdAreaSoporte() << ",";
        archivoCSV << reg.getNombre() << ",";
        archivoCSV << reg.getDescripcion() << ",";
        archivoCSV << reg.getActivo() << endl;
    }

    archivoDat.close();
    archivoCSV.close();

    cout << "Areas de soporte exportadas correctamente a areaSoporte.csv." << endl;
}
