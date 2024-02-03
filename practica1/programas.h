//------------------------------------------------------------------------------
// File:   programas.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   10/11/21
// Coms:   Práctica 1 de EDA
//------------------------------------------------------------------------------
#ifndef PROGRAMAS_H
#define PROGRAMAS_H
#include <iostream>
#include "fecha.h"
using namespace std;

// Interfaz del TAD programas. Pre-declaraciones:
struct programa;
void crear(string nom, Fecha cre, string leng, string desc, programa& p);
string suNombre(const programa& p);
Fecha suFecha(const programa& p);
string suLenguaje(const programa& p);
string suDescripcion(const programa& p);

// Declaración:
struct programa{
    friend void crear(string nom, Fecha cre, string leng, string desc, programa& p);
    friend string suNombre(const programa& p);
    friend Fecha suFecha(const programa& p);
    friend string suLenguaje(const programa& p);
    friend string suDescripcion(const programa& p);
    private:
    // Representación de valores del TAD:
        string nombre;
        Fecha fecha;
        string lenguaje;
        string descripcion;
};
#endif