#include <iostream>
using namespace std;
#include "MenuAdmiConfiguracion.h"
#include "AreaSoporte.h"
#include <fstream>
#include "Categoria.h"
#include "ticket.h"
#include "AreaSoporte.h"
#include "ArchivoUsuarios.h"
#include <direct.h>

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
        system("cls");
        cout << "========================================" << endl;
        cout << "|           RESTAURAR COPIA            |" << endl;
        cout << "========================================" << endl;
        cout << "| 1- Usuarios                          |" << endl;
        cout << "| 2) Tickets                           |" << endl;
        cout << "| 3) Categorias                        |" << endl;
        cout << "| 4) Area de Soporte                   |" << endl;
        cout << "| 5) Todos los archivos                |" << endl;
        cout << "========================================" << endl;
        cout << "| 0) Volver                            |" << endl;
        cout << "========================================" << endl;

         cout << "Opcion: ";
         cin >> opcion;

         switch (opcion)
         {
         case 1:
            system("cls");
            restaurarUsuarios();
            system("pause");
            break;
        case 2:
           system("cls");
           restaurarTickets();
           system("pause");
           break;

        case 3:
           system("cls");
           restaurarCategorias();
           system("pause");
           break;

        case 4:
          system("cls");
          restaurarAreaSoporte();
          system("pause");
          break;

        case 5:
         system("cls");
         restaurarCompleto();
         system("pause");
         break;

        case 0:
         break;

          default:
          system("cls");
          cout << "Opcion invalida." << endl;
          system("pause");
            break;
         }
        }while(opcion != 0);
}

void MenuExportacionCSV(){

    int opcion;

    do{
        system("cls");
        cout << "========================================" << endl;
        cout << "|               EXPORTAR CSV           |" << endl;
        cout << "========================================" << endl;
        cout << "| 1) Usuarios                          |" << endl;
        cout << "| 2) Tickets                           |" << endl;
        cout << "| 3) Categorias                        |" << endl;
        cout << "| 4) Areas de Soporte                  |" << endl;
        cout << "========================================" << endl;
        cout << "| 0) Volver                            |" << endl;
        cout << "========================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion){

        case 1:
            system("cls");
            exportarUsuariosCSV();
            system("pause");
            break;

        case 2:
          system("cls");
          exportarTicketCSV();
          system("pause");
           break;

        case 3:
         system("cls");
         exportarCategoriasCSV();
         system("pause");
          break;

        case 4:
           system("cls");
           exportarAreaSoporteCSV();
            system("pause");
            break;

        case 0:
         break;


          default:
          system("cls");
          cout << "Opcion invalida." << endl;
          system("pause");
            break;
        }

    }while(opcion != 0);
}


void MenuBackup(){
    _mkdir("backups");
    int opcion;

    do{
        system("cls");
        cout << "========================================" << endl;
        cout << "|             COPIA DE SEGURIDAD       |" << endl;
        cout << "========================================" << endl;
        cout << "| 1) Usuarios                          |" << endl;
        cout << "| 2) Tickets                           |" << endl;
        cout << "| 3) Categorias                        |" << endl;
        cout << "| 4) Areas de Soporte                  |" << endl;
        cout << "| 5) Todos los archivos                |" << endl;
        cout << "========================================" << endl;
        cout << "| 0) Volver                            |" << endl;
        cout << "========================================" << endl;

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
            system("cls");
            backupUsuarios();
            system("pause");
            break;


        case 2:
            system("cls");
            backupTickets();
            system("pause");
            break;

        case 3:
            system("cls");
            backupCategorias();
            system("pause");
            break;

        case 4:
            system("cls");
            backupAreaSoporte();
            system("pause");
            break;

        case 5:
            system("cls");
            backupCompleto();
            system("pause");
            break;

        case 0:
            break;


        default:
            system("cls");
            cout << "Opcion invalida." << endl;
            system("pause");
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
    cout << "Backup realizado correctamente." << endl;
    cout << "--------------------------------" << endl;


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

    cout << "Backup realizado correctamente." << endl;

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
    }
    if (!destino) {
        cout << "No se pudo restaurar areaSoporte.dat" << endl;
        return;
    }

    destino << origen.rdbuf();
    cout << "Area restaurado correctamente" << endl;

    origen.close();
    destino.close();


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
        archivoCSV << reg.getIDUsuario()<<",";
        archivoCSV << reg.getEmail()<< ",";
        archivoCSV << reg.getNombre() << ",";
        archivoCSV << reg.getApellido() << ",";
        archivoCSV << reg.getRol() << endl;
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

    archivoCSV << "ID,ASUNTO,ESTADO,PRIORIDAD" << endl;

       while(archivoDat.read((char*)&reg, sizeof(Ticket))){
        archivoCSV << reg.getIdTicket() << ",";
        archivoCSV << reg.getAsunto() << ",";
        archivoCSV << reg.getEstado() << ",";
        archivoCSV << reg.getPrioridad() << endl;
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
