//------------------------------------------------------------------------------
// File:   coleccionITF.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   10/11/21
// Coms:   Práctica 1 de EDA
//------------------------------------------------------------------------------
#ifndef COLECCION_H
#define COLECCION_H
#include "fecha.h"
#include "programas.h"
#include <iostream>
using namespace std;

// Interfaz del TAD genérico coleccionITF. Pre-declaraciones:

template<typename T> struct coleccionITF;

template<typename T> void crear(coleccionITF<T>& c);
template<typename T> bool anyadir(const T& i, coleccionITF<T>& c);
template<typename T> bool borrar(const string ident, coleccionITF<T>& c);
template<typename T> bool obtenerITF(const string ident, const coleccionITF<T>& c, T& p);
template<typename T> string obsoletos(const Fecha& f, const string separador, const coleccionITF<T>& c);
template<typename T> bool purgar(const Fecha& f, coleccionITF<T>& c);
template<typename T> string delTema(const string t, const string separador, const coleccionITF<T>& c);
template<typename T> bool esVacia(const coleccionITF<T>& c);
template<typename T> int tamanyo(const coleccionITF<T>& c);
template<typename T> void iniciarIterador(coleccionITF<T>& c);
template<typename T> bool existeSiguiente(const coleccionITF<T>& c);
template<typename T> bool siguiente(coleccionITF<T>& c, T& p);

// Declaración: 
template<typename T>
struct coleccionITF{
	friend void crear<T> (coleccionITF<T>& c);
	friend bool anyadir<T> (const T& i, coleccionITF<T>& c);
	friend bool borrar<T> (const string ident, coleccionITF<T>& c);
    friend bool obtenerITF<T> (const string ident, const coleccionITF<T>& c, T& p);
    friend string obsoletos<T> (const Fecha& f, const string separador, const coleccionITF<T>& c);
    friend bool purgar<T> (const Fecha& f, coleccionITF<T>& c);
    friend string delTema<T> (const string t, const string separador, const coleccionITF<T>& c);
    friend bool esVacia<T> (const coleccionITF<T>& c);
    friend int tamanyo<T> (const coleccionITF<T>& c);
    friend void iniciarIterador<T> (coleccionITF<T>& c);
    friend bool existeSiguiente<T> (const coleccionITF<T>& c);
    friend bool siguiente<T> (coleccionITF<T>& c, T& p);
	
	private: // Declaración interna del tipo:
		struct celda{
            T dato;
            celda *sig;
        };
        int total;
        celda *pri;
        celda *iter;
};

// Implementación: 

template<typename T> void crear(coleccionITF<T>& c){
    c.total = 0;
    c.pri = nullptr;
}

template<typename T> bool anyadir(const T& i, coleccionITF<T>& c){
    bool anyadido = false;
    typename coleccionITF<T>::celda *pAux;
    typename coleccionITF<T>::celda *nuevo;
    if(c.pri == nullptr){ // lista vacía
        c.pri = new typename coleccionITF<T>::celda;
        c.pri->dato = i;
        c.pri->sig = nullptr;
        c.total = 1;
        anyadido = true;
    }
    else if(suNombre(i) < suNombre(c.pri->dato)){ // inserción al principio
        pAux = c.pri;
        c.pri = new typename coleccionITF<T>::celda;
        c.pri->dato = i;
        c.pri->sig = pAux;
        c.total++;
        anyadido = true;
    }
    else if(suNombre(i) == suNombre(c.pri->dato)){} //no hacer nada, ya esta
    else{ // suNombre(i) > suNombre(c.pri->dato), buscamos el punto de inserción
        pAux = c.pri;
        while(pAux->sig != nullptr && suNombre(pAux->sig->dato) < suNombre(i)){
            pAux = pAux->sig;
        }
        if((pAux->sig != nullptr) && (suNombre(i) == suNombre(pAux->sig->dato))){} // no hacer nada, ya esta      
        else{ // inserción entre dos registros o al final
            nuevo = new typename coleccionITF<T>::celda;
            nuevo->dato = i;
            nuevo->sig = pAux->sig;
            pAux->sig = nuevo;
            c.total++;
            anyadido = true;
        }
    }
    return anyadido;
}

template<typename T> bool borrar(const string ident, coleccionITF<T>& c){
    bool borrado = false;
    typename coleccionITF<T>::celda *pAux1, *pAux2;
    pAux2 = c.pri;
    if(pAux2 != nullptr){ // caso contrario, no hacer nada
        if(suNombre(pAux2->dato) <= ident){ // caso contrario, no hacer nada
            pAux1 = pAux2->sig;
            if(suNombre(pAux2->dato) == ident){ // borrar el primer elemento
                c.pri = pAux1;
                delete(pAux2);
                c.total--;
                borrado = true;
            }
            while(pAux1 != nullptr && !borrado){ // suNombre(pAux1->dato) < ident, seguir buscando
                if(suNombre(pAux1->dato) == ident){
                    pAux2->sig = pAux1->sig;
                    borrado = true;
                    c.total--;
                    delete(pAux1);
                }
                pAux2 = pAux1;
                pAux1 = pAux1->sig;
            }
        }
    }
    return borrado;
}

template<typename T> bool obtenerITF(const string ident, const coleccionITF<T>& c, T& p){
    bool encontrado = false;
    typename coleccionITF<T>::celda *pAux = c.pri;
    while(pAux != nullptr && !encontrado){ // mientras queden elementos y no lo hayamos encontrado
        if(suNombre(pAux->dato) == ident){
            encontrado = true;
            p = pAux->dato;
        }
        pAux = pAux->sig;
    }
    return encontrado;
}

template<typename T> string obsoletos(const Fecha& f, const string separador, const coleccionITF<T>& c){
    string s = "";
    typename coleccionITF<T>::celda *pAux = c.pri;
    bool primero = true;
    while(pAux != nullptr){ // leemos todos los elementos de la colección
        if(suFecha(pAux->dato) < f){
            if(primero){ // si es el primer elemento que escribimos no hace falta poner el separador antes
                s += suNombre(pAux->dato);
                primero = false;
            }
            else{
                s += separador + suNombre(pAux->dato);
            }
        }
        pAux = pAux->sig;
    }
    return s;
}

template<typename T> bool purgar(const Fecha& f, coleccionITF<T>& c){
    bool purgado = false;
    typename coleccionITF<T>::celda *pAux = c.pri;
    while(pAux != nullptr){ // leemos todos los elementos de la colección
        if(suFecha(pAux->dato) < f){ // borramos solo los que tengan fecha anterior a la dada
            purgado = true;
            borrar(suNombre(pAux->dato), c);
        }
        pAux = pAux->sig;
    }
    return purgado;
}

template<typename T> string delTema(const string t, const string separador, const coleccionITF<T>& c){
    string s = "";
    typename coleccionITF<T>::celda *pAux = c.pri;
    bool primero = true;
    while(pAux != nullptr){ // leemos todos los elementos de la colección
        if(suLenguaje(pAux->dato) == t){
            if(primero){ // si es el primer elemento que escribimos no hace falta poner el separador antes
                s += suNombre(pAux->dato);
                primero = false;
            }
            else{
                s += separador + suNombre(pAux->dato);
            }
        }
        pAux = pAux->sig;
    }
    return s;
}

template<typename T> bool esVacia(const coleccionITF<T>& c){
    return c.total == 0;
}

template<typename T> int tamanyo(const coleccionITF<T>& c){
    return c.total;
}

template<typename T> void iniciarIterador(coleccionITF<T>& c){
    c.iter = c.pri;
}

template<typename T> bool existeSiguiente(const coleccionITF<T>& c){
    return c.iter != nullptr;
}

template<typename T> bool siguiente(coleccionITF<T>& c, T& p){
    bool ok = existeSiguiente(c);
    if(ok){
        p = c.iter->dato;
        c.iter = c.iter->sig;
    }
    return ok;
}

#endif