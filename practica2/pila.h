//------------------------------------------------------------------------------
// File:   pila.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   13/12/21
// Coms:   Práctica 2 de EDA
//------------------------------------------------------------------------------
#ifndef PILA_H
#define PILA_H
#include "fecha.h"
#include "programas.h"
#include <iostream>
using namespace std;

// Interfaz del TAD genérico pila. Pre-declaraciones:

/* Es un TAD genérico para representar pilas de tipo T */
template<typename T> struct pila;
/* Crea una pila vacía*/
template<typename T> void crear(pila<T>& p);
/* Añade un elemento T a la pila*/
template<typename T> void apilar(const T& i, pila<T>& p);
/* Si la pila es no vacía, elimina el último elemento T añadido a la pila  y devuelve verdad.
Caso contrario: devuelve falso*/
template<typename T> bool desapilar(pila<T>& p);
/* Devuelve el último elemento T añadido a la pila*/
template<typename T> void cima(T& i, const pila<T>& p);
/* Devuelve verdad si la pila no contiene ningún elemento*/
template<typename T> bool esVacia(const pila<T>& p);
/* Devuelve el número de elementos que contiene la pila*/
template<typename T> int altura(const pila<T>& p);

// Declaración:

template<typename T> struct pila{
    friend void crear<T> (pila<T>& p);
    friend void apilar<T> (const T& i, pila<T>& p);
    friend bool desapilar<T> (pila<T>& p);
    friend void cima<T> (T& i, const pila<T>& p);
    friend bool esVacia<T> (const pila<T>& p);
    friend int altura<T> (const pila<T>& p);
    private: // Declaración interna del tipo:
        struct nodo{
            T dato;
            nodo *sig;
        };
        nodo* cima;
        int total;
};

template<typename T> void crear(pila<T>& p){
    p.total = 0;
    p.cima = nullptr;
}

template<typename T> void apilar(const T& i, pila<T>& p){
    typename pila<T>::nodo *aux;
    aux = p.cima;
    p.cima = new typename pila<T>::nodo;
    p.cima->dato = i;
    p.cima->sig = aux;
    p.total++;
}

template<typename T> bool desapilar(pila<T>& p){
    bool ok = !esVacia(p);
    if(ok){
        typename pila<T>::nodo *aux;
        p.cima = p.cima->sig;
        delete(aux);
        p.total--;
    }
    return ok;
}

template<typename T> void cima(T& i, const pila<T>& p){
    i = p.cima->dato;
}

template<typename T> bool esVacia(const pila<T>& p){
    return p.total == 0; 
}

template<typename T> int altura(const pila<T>& p){
    return p.total;
}

#endif
