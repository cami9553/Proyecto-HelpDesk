#include <iostream>
#include <ctime>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(){

    dia=0;
    mes=0;
    anio=0;
    hora=0;
    minuto=0;
    segundo=0;

}

void Fecha::CargarFecha(){

    cout<<"Dia: ";
    cin>>dia;

    cout<<"Mes: ";
    cin>>mes;

    cout<<"Anio: ";
    cin>>anio;

    cout<<"Hora: ";
    cin>>hora;

    cout<<"Minuto: ";
    cin>>minuto;

    cout<<"Segundo: ";
    cin>>segundo;
}

void Fecha::MostrarFecha(){

    cout<<dia<<"/"<<mes<<"/"<<anio;
    cout<<" ";
    cout<<hora<<":"<<minuto<<":"<<segundo;
}

void Fecha::CargarFechaActual(){

    time_t ahora = time(nullptr);

    tm *fecha = localtime(&ahora);

    dia = fecha->tm_mday;
    mes = fecha->tm_mon + 1;
    anio = fecha->tm_year + 1900;

    hora = fecha->tm_hour;
    minuto = fecha->tm_min;
    segundo = fecha->tm_sec;
}


// Getters

int Fecha::GetDia(){ return dia; }
int Fecha::GetMes(){ return mes; }
int Fecha::GetAnio(){ return anio; }
int Fecha::GetHora(){ return hora; }
int Fecha::GetMinuto(){ return minuto; }
int Fecha::GetSegundo(){ return segundo; }


// Setters

void Fecha::SetDia(int d){ dia=d; }
void Fecha::SetMes(int m){ mes=m; }
void Fecha::SetAnio(int a){ anio=a; }
void Fecha::SetHora(int h){ hora=h; }
void Fecha::SetMinuto(int m){ minuto=m; }
void Fecha::SetSegundo(int s){ segundo=s; }
