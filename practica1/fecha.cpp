//------------------------------------------------------------------------------
// File:   fecha.cpp
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   10/11/21
// Coms:   Práctica 1 de EDA
//------------------------------------------------------------------------------
#include "fecha.h"

//Implementación de las operaciones del TAD fecha:

void crear(int dia,int mes, int anyo, Fecha& f){
    f.elAnyo = anyo;
    f.elMes = mes;
    f.elDia = dia;
}

int dia(const Fecha& f){
    return f.elDia;
}

int mes (const Fecha& f){
    return f.elMes;
}

int anyo(const Fecha& f){
    return f.elAnyo;
}

bool operator<(const Fecha& f1, const Fecha& f2){
    return (f1.elAnyo < f2.elAnyo) || (f1.elAnyo == f2.elAnyo && f1.elMes < f2.elMes) ||
    (f1.elAnyo == f2.elAnyo && f1.elMes == f2.elMes && f1.elDia < f2.elDia);
}

bool operator ==(const Fecha& f1, const Fecha& f2){
    return (f1.elAnyo == f2.elAnyo && f1.elMes == f2.elMes && f1.elDia == f2.elDia);

}