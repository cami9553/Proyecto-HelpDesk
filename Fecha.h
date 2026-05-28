#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
class Fecha{

private:

    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;

public:

    // Constructor
    Fecha();

    // Métodos
    void CargarFecha();
    void MostrarFecha();
    void CargarFechaActual();

    // Getters
    int GetDia();
    int GetMes();
    int GetAnio();
    int GetHora();
    int GetMinuto();
    int GetSegundo();

    // Setters
    void SetDia(int d);
    void SetMes(int m);
    void SetAnio(int a);
    void SetHora(int h);
    void SetMinuto(int m);
    void SetSegundo(int s);

};


#endif // FECHA_H_INCLUDED
