//------------------------------------------------------------------------------
// File:   fecha.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   13/12/21
// Coms:   Práctica 2 de EDA
//------------------------------------------------------------------------------
#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

// Pre-declaraciones:
/* Interfaz del TAD fecha. Una fecha está definida por tres enteros: elDia, que representa el día del mes de la fecha;
elMes, que representa el mes del año de la fecha; y elAnyo, que representa el número del año de la fecha*/
struct Fecha;
/*Crea una fecha a partir de los parámetros dia, mes y anyo*/
void crear(int dia,int mes, int anyo, Fecha& f);
/* Devuelve el día del mes de una fecha*/
int dia(const Fecha& f);
/* Devuelve el mes del año de una fecha */
int mes (const Fecha& f);
/*Devuelve el número de año de una fecha */
int anyo(const Fecha& f);
bool operator<(const Fecha& f1, const Fecha& f2);
bool operator ==(const Fecha& f1, const Fecha& f2);

// Declaración:
struct Fecha{
    friend void crear(int dia,int mes, int anyo, Fecha& f);
    friend int dia(const Fecha& f);
    friend int mes (const Fecha& f);
    friend int anyo(const Fecha& f);
    friend bool operator<(const Fecha& f1, const Fecha& f2);
    friend bool operator ==(const Fecha& f1, const Fecha& f2);
    private:
    // Representación de valores del TAD:
        int elDia;
        int elMes;
        int elAnyo;
};
#endif
