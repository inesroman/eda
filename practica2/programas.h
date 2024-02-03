//------------------------------------------------------------------------------
// File:   programas.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   13/12/21
// Coms:   Práctica 2 de EDA
//------------------------------------------------------------------------------
#ifndef PROGRAMAS_H
#define PROGRAMAS_H
#include <iostream>
#include "fecha.h"
using namespace std;

// Pre-declaraciones:
/* Interfaz del TAD programas. Un programa está definido por cuatro parámetros: una cadena nombre,
que identifica a cada programa y es único para cada programa; la fecha fecha, que indica el momento de la
creación del programa; la cadena lenguaje, que indica en qué lenguaje de progrmación está escrito dicho programa;
y la cadena su descripción, en la que se indican algunos detalles acerca del programa */
struct programa;
/* Crea un progarma a partir de un nombre, una fecha, un lenguaje y una descripción */
void crear(string nom, Fecha cre, string leng, string desc, programa& p);
/* Devuelve la cadena nombre de un programa */
string suNombre(const programa& p);
/* Devuelve la fecha de creación de un programa */
Fecha suFecha(const programa& p);
/* Devuelve la cadena lenguaje de un programa */
string suLenguaje(const programa& p);
/* Devuelve la cadena descripción de un programa */
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
