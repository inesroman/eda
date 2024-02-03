//------------------------------------------------------------------------------
// File:   programas.cpp
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   10/11/21
// Coms:   Práctica 1 de EDA
//------------------------------------------------------------------------------
#include "programas.h"

//Implementación de las operaciones del TAD programas:

void crear(string nom, Fecha cre, string leng, string desc, programa& p){
    p.nombre = nom;
    p.fecha = cre;
    p.lenguaje = leng;
    p.descripcion = desc;
}

string suNombre(const programa& p){
    return p.nombre;
}

Fecha suFecha(const programa& p){
    return p.fecha;
}

string suLenguaje(const programa& p){
    return p.lenguaje;
}
string suDescripcion(const programa& p){
    return p.descripcion;
}