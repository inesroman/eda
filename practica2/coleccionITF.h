//------------------------------------------------------------------------------
// File:   coleccionITF.h
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   13/12/21
// Coms:   Práctica 2 de EDA
//------------------------------------------------------------------------------
#ifndef COLECCIONITF_H
#define COLECCIONITF_H
#include "fecha.h"
#include "pila.h"
#include <iostream>
using namespace std;

// Interfaz del TAD genérico coleccionITF. Pre-declaraciones:

/* Es un TAD genérico para representar colecciones de ítems temáticos fechados (ITF) en la que
no puede haber dos ITFs con el mismo identificador. A un ITF se le requiere tener definidas: una operación
identificador, que devuelve una cadena que identifica a ese ítem; una operación tema, que devuelve una 
cadena igual al tema del ítem; y otra operación fecha, que devuelve la fecha asociada al ítem */
template<typename ITF> struct coleccionITF;

/* Crea una colección de ITF vacía, sin ítems */
template<typename ITF> void crear(coleccionITF<ITF>& c);

/* Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a la
resultante de añadir el ítem i a la colección c en la posición que le corresponda siguiendo un orden 
lexicógrafico según su identificador. En caso contrario, devuelve una colección igual a c.*/
template<typename ITF> bool anyadir(const ITF& i, coleccionITF<ITF>& c);

/* {Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección igual a c.*/
template<typename ITF> bool borrar(string ident, coleccionITF<ITF>& c);

/* Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem y el booleano error
es igual a falso. En caso contrario, devuelve error igual a true y devuelve el ítem p. */
template<typename ITF> bool obtenerITF(string ident, const coleccionITF<ITF>& c, ITF& i);

/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
con fecha estrictamente anterior a f, en cualquier orden y separados entre sí por la cadena separador */
template<typename ITF> string obsoletos(const Fecha& f, string separador, const coleccionITF<ITF>& c);

/* Devuelve una colección igual a la resultante de eliminar de c todos los ítems con fecha
estrictamente anterior a f*/
template<typename ITF> bool purgar(const Fecha& f, coleccionITF<ITF>& c);

/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
con tema igual a t, en cualquier orden y separados entre sí por la cadena separador.*/
template<typename ITF> string delTema(string t, string separador, const coleccionITF<ITF>& c);

/* Devuelve verdad si y sólo si c no contiene ningún ítem.*/
template<typename ITF> bool esVacia(const coleccionITF<ITF>& c);

/* Devuelve el número de ítems que hay en la colección c. */
template<typename ITF> int tamanyo(const coleccionITF<ITF>& c);


// Las siguientes operaciones constituyen un iterador:

/* Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem a visitar 
sea el que tiene el (lexicográficamente) menor identificador (situación de no haber visitado ningún ítem). */
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c);

/* Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
 falso si ya se ha visitado el último ítem. */
template<typename ITF> bool existeSiguiente(const coleccionITF<ITF>& c);

/* Si quedan ítems por visitar, devuelve el siguiente ítem a visitar con el iterador de la colección c, prepara el 
iterador de la colección c para que se pueda visitar el siguiente ítem y la función devuelve true. En caso contrario, devuelve
la colección c y la función devuelve false. */
template<typename ITF> bool siguiente(coleccionITF<ITF>& c, ITF& i);


// Las siguientes funciones son auxiliares de tipo interno:

/* Este procedimiento es auxiliar para el de anyadir */
template<typename ITF> bool anyadirRec(const ITF& i, typename coleccionITF<ITF>::nodo*& aux);

/* Este procedimiento es auxiliar para borrar */
template<typename ITF> bool borrarRec(string ident, typename coleccionITF<ITF>::nodo*& aux);

/* Este procedimiento es auxiliar para borrarRec. Precondición, el TAD al que apunta aux es no vacío */
template<typename ITF> void borrarMax(ITF& i, typename coleccionITF<ITF>::nodo*& aux);

/* Este procedimiento es auxiliar para el de obtenerITF */
template<typename ITF> bool obtenerRec(ITF& i,string ident, typename coleccionITF<ITF>::nodo* aux);

/* Este procedimiento es auxiliar para el de obsoletos */
template<typename ITF> string obsoletosRec(bool& primero, const Fecha& f, string separador, typename coleccionITF<ITF>::nodo* aux);

/* Este procedimiento es auxiliar para el de delTema */
template<typename ITF> string delTemaRec(bool& primero, string t, string separador, typename coleccionITF<ITF>::nodo* aux);

/* Este procedimiento es auxiliar para purgar */
template<typename ITF> void purgarRec(const Fecha& f, typename coleccionITF<ITF>::nodo*& aux, int& purgados);


// Declaración: 
template<typename ITF> struct coleccionITF{
	friend void crear<ITF> (coleccionITF<ITF>& c);
	friend bool anyadir<ITF> (const ITF& i, coleccionITF<ITF>& c);
	friend bool borrar<ITF> (string ident, coleccionITF<ITF>& c);
    friend bool obtenerITF<ITF> (string ident, const coleccionITF<ITF>& c, ITF& i);
    friend string obsoletos<ITF> (const Fecha& f, string separador, const coleccionITF<ITF>& c);
    friend bool purgar<ITF> (const Fecha& f, coleccionITF<ITF>& c);
    friend string delTema<ITF> (string t, string separador, const coleccionITF<ITF>& c);
    friend bool esVacia<ITF> (const coleccionITF<ITF>& c);
    friend int tamanyo<ITF> (const coleccionITF<ITF>& c);
    friend void iniciarIterador<ITF> (coleccionITF<ITF>& c);
    friend bool existeSiguiente<ITF> (const coleccionITF<ITF>& c);
    friend bool siguiente<ITF> (coleccionITF<ITF>& c, ITF& i);
	private: // Declaración interna del tipo:
		struct nodo{
            ITF dato;
            nodo *der;
            nodo *izq;
        };
        nodo *raiz;
        pila<nodo*> iter;
        int total;
        friend bool anyadirRec<ITF> (const ITF& i, typename coleccionITF<ITF>::nodo*& aux);
        friend bool borrarRec<ITF> (string ident, typename coleccionITF<ITF>::nodo*& aux);
        friend void borrarMax<ITF> (ITF& i, typename coleccionITF<ITF>::nodo*& aux);
        friend bool obtenerRec<ITF> (ITF& i,string ident, typename coleccionITF<ITF>::nodo* aux);
        friend string obsoletosRec<ITF> (bool& primero, const Fecha& f, string separador, typename coleccionITF<ITF>::nodo* aux);
        friend string delTemaRec<ITF> (bool& primero, string t, string separador, typename coleccionITF<ITF>::nodo* aux);
        friend void purgarRec<ITF> (const Fecha& f, typename coleccionITF<ITF>::nodo*& aux, int& purgados);
};

// Implementación: 

template<typename ITF> void crear(coleccionITF<ITF>& c){
    c.total = 0;
    c.raiz = nullptr;
}

template<typename ITF> bool anyadir(const ITF& i, coleccionITF<ITF>& c){
    bool anyadido = false;
    if(anyadirRec(i, c.raiz)){
        c.total++;
        anyadido = true;
    }
    return anyadido;
}

template<typename ITF> bool anyadirRec(const ITF& i, typename coleccionITF<ITF>::nodo*& aux){
    bool anyadido;
    if(aux == nullptr){
        aux = new typename coleccionITF<ITF>::nodo;
        aux->izq = nullptr;
        aux->der = nullptr;
        aux->dato = i;
        anyadido = true;
    }
    else{
        if(identificador(i) < identificador(aux->dato)){
            anyadido = anyadirRec(i, aux->izq);
        }
        else if(identificador(i) > identificador(aux->dato)){
            anyadido = anyadirRec(i, aux->der);
        }
        else{ // identificador(i) == identificador(aux->dato)
            anyadido = false;
        }
    }
    return anyadido;
}

template<typename ITF> bool borrar(string ident, coleccionITF<ITF>& c){
    bool borrado = borrarRec<ITF>(ident, c.raiz);
    if(borrado){
        c.total--;
    }
    return borrado;
}

template<typename ITF> bool borrarRec(string ident, typename coleccionITF<ITF>::nodo*& aux){
    bool borrado;
    typename coleccionITF<ITF>::nodo* aux2;
    
    if(aux == nullptr){
        borrado = false;
    }
    else{
        if(ident < identificador(aux->dato)){
            borrado = borrarRec<ITF>(ident, aux->izq);
        }
        else if(ident > identificador(aux->dato)){
            borrado = borrarRec<ITF>(ident, aux->der);
        }
        else{ // ident == identificador(aux->dato)
            if(aux->izq == nullptr){
                aux2 = aux;
                aux = aux->der;
                delete(aux2);
            }
            else{
                borrarMax(aux->dato, aux->izq);
            }
            borrado = true;
        }
    }
    return borrado;
}

template<typename ITF> void borrarMax(ITF& i, typename coleccionITF<ITF>::nodo*& aux){
    typename coleccionITF<ITF>::nodo* aux2;
    if(aux->der == nullptr){
        i = aux->dato;
        aux2 = aux;
        aux = aux->izq;
        delete(aux2);
    }
    else{
        borrarMax(i, aux->der);
    }
}

template<typename ITF> bool obtenerITF(string ident,const coleccionITF<ITF>& c, ITF& i){
    return obtenerRec(i, ident, c.raiz);
}

template<typename ITF> bool obtenerRec(ITF& i,string ident, typename coleccionITF<ITF>::nodo* aux){
    bool encontrado;
    if(aux == nullptr){
        encontrado = false;
    }
    else{
        if(ident < identificador(aux->dato)){
            encontrado = obtenerRec(i, ident, aux->izq);
        }
        else if(ident > identificador(aux->dato)){
            encontrado = obtenerRec(i, ident, aux->der);
        }
        else{ // ident == identificador(aux->dato)
            i = aux->dato;
            encontrado = true;
        }
    }
    return encontrado;
}
template<typename ITF> string obsoletosRec(bool& primero, const Fecha& f, string separador, typename coleccionITF<ITF>::nodo* aux){
    string s = "";
    if(aux != nullptr){
        s += obsoletosRec<ITF>(primero, f, separador, aux->izq);
        s += obsoletosRec<ITF>(primero, f, separador, aux->der);
        if(fecha(aux->dato) < f){
            if(primero){ // si es el primer elemento que escribimos no hace falta poner el separador antes
                s += identificador(aux->dato);
                primero = false;
            }
            else{
                s += separador + identificador(aux->dato);
            }
        }
    }
    return s;
}
template<typename ITF> string obsoletos(const Fecha& f, string separador,const coleccionITF<ITF>& c){
    string s = "";
    bool primero = true;
    s = obsoletosRec<ITF>(primero, f, separador, c.raiz);
    return s;
}

template<typename ITF> void purgarRec(const Fecha& f, typename coleccionITF<ITF>::nodo*& aux, int& purgados){
    if(aux != nullptr){
        purgarRec<ITF>(f, aux->izq, purgados);
        purgarRec<ITF>(f, aux->der, purgados);
        if(fecha(aux->dato) < f){
            if(borrarRec<ITF>(identificador(aux->dato), aux)){
                purgados++;
            }
        }
    }
}

template<typename ITF> bool purgar(const Fecha& f, coleccionITF<ITF>& c){
    int purgados = 0;
    purgarRec<ITF>(f, c.raiz, purgados);
    c.total = c.total - purgados;
    return purgados > 0;
}

template<typename ITF> string delTemaRec(bool& primero, string t, string separador, typename coleccionITF<ITF>::nodo* aux){
    string s = "";
        if(aux != nullptr){
            if(tema(aux->dato) == t){
                if(primero){ // si es el primer elemento que escribimos no hace falta poner el separador antes
                    s += identificador(aux->dato);
                    primero = false;
                }
                else{
                    s += separador + identificador(aux->dato);
                }
            }
            s += delTemaRec<ITF>(primero, t, separador, aux->izq);
            s += delTemaRec<ITF>(primero, t, separador, aux->der);
        }
    return s;
}

template<typename ITF> string delTema(string t, string separador,const coleccionITF<ITF>& c){
    string s = "";
    bool primero = true;
    s = delTemaRec<ITF>(primero, t, separador, c.raiz);
    return s;
}

template<typename ITF> bool esVacia(const coleccionITF<ITF>& c){
    return c.total == 0;
}

template<typename ITF> int tamanyo(const coleccionITF<ITF>& c){
    return c.total;
}

template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c){
    crear(c.iter);
    typename coleccionITF<ITF>::nodo *aux = c.raiz;
    while(aux != nullptr){
        apilar(aux, c.iter);
        aux = aux->izq;
    }
}

template<typename ITF> bool existeSiguiente(const coleccionITF<ITF>& c){
    return !esVacia(c.iter);
}

template<typename ITF> bool siguiente(coleccionITF<ITF>& c, ITF& i){
    bool ok;
    if(existeSiguiente(c)){
        ok = true;
        typename coleccionITF<ITF>::nodo *aux, *aux2;
        cima(aux, c.iter);
        desapilar(c.iter);
        i = aux->dato;
        aux = aux->der;
        while(aux != nullptr){
            aux2 = aux;
            apilar(aux2, c.iter);
            aux = aux->izq;
        }
    }
    else{
        ok = false;
    }
    return ok;
}

#endif
