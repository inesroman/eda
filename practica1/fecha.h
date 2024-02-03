//------------------------------------------------------------------------------
// File:   fecha.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   10/11/21
// Coms:   Práctica 1 de EDA
//------------------------------------------------------------------------------
#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

// Interfaz del TAD fecha. Pre-declaraciones:
struct Fecha;
void crear(int dia,int mes, int anyo, Fecha& f);
int dia(const Fecha& f);
int mes (const Fecha& f);
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
