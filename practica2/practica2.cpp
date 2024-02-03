//------------------------------------------------------------------------------
// File:   practica2.cpp
// Equipo 49: Inés Román Gracia NIP:820731
// Date:   13/12/21
// Coms:   Práctica 2 de EDA
//         Compilar mediante:
//           g++ -std=c++11 -o practica2 practica2.cpp programas.cpp fecha.cpp
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include "programas.h"
#include "fecha.h"
#include "coleccionITF.h"
#include "pila.h"
using namespace std;

string identificador(const programa& p){
    return suNombre(p);
}

Fecha fecha(const programa& p){
    return suFecha(p);
}

string tema(const programa& p){
    return suLenguaje(p);
}

string formatoFecha(int num){
    string formato ="";
    if(num < 10){
        formato = "0" + to_string(num);
    }
    else{
        formato = to_string(num);
    }
    return formato;
}

int main(){
    // Datos usados para los ficheros de entrada y de salida:
    programa p;
    coleccionITF<programa> c;
    crear(c);
    string nombre, lenguaje, descripcion;
    Fecha f;
    int day, month, year;
    char raya;
    string separador = ":::";
    ifstream fentrada;
    string instruccion;
    string salto;
    // Abrimos el fichero de entrada:
    fentrada.open("entrada.txt");
    if(fentrada.is_open()) { //comprueba que el fichero de entrada se ha abierto correctamente
        ofstream fsalida;
        // Abrimos el fichero de salida:
        fsalida.open("salida.txt", ios::out);
        if(fsalida.is_open()) { //comprueba que el fichero de salida se ha abierto correctamente
            while(fentrada >> instruccion) { //mientras queden datos en el fichero leemos la siguiente instruccion
                getline(fentrada, salto);
                if(instruccion == "A"){
                    getline(fentrada, nombre);
                    fentrada >> year;
                    fentrada >> raya;
                    fentrada >> month;
                    fentrada >> raya;
                    fentrada >> day;
                    getline(fentrada, salto);
                    getline(fentrada, lenguaje);
                    getline(fentrada, descripcion);
                    crear(day, month, year, f);
                    crear(nombre, f, lenguaje, descripcion, p);
                    if(anyadir(p, c)){
                        fsalida << "INTRODUCIDO: " << nombre << separador << year << "-" << formatoFecha(month) << "-" << formatoFecha(day) << separador << lenguaje << separador << descripcion << endl;
                    }           
                    else{
                        fsalida << "NO INTRODUCIDO: " << nombre << separador << year << "-" << formatoFecha(month) << "-" << formatoFecha(day) << separador << lenguaje << separador << descripcion << endl;
                    }
                }
                else if(instruccion == "O"){
                    getline(fentrada, nombre);
                    if(obtenerITF(nombre, c, p)){
                        fsalida << "LOCALIZADO: " << nombre << separador << anyo(suFecha(p)) << "-" << formatoFecha(mes(suFecha(p))) << "-" << formatoFecha(dia(suFecha(p))) << separador << suLenguaje(p) << separador << suDescripcion(p) << endl;
                    }
                    else{
                        fsalida << "NO LOCALIZADO: " << nombre << endl;
                    }
                }
                else if(instruccion == "B"){
                    getline(fentrada, nombre);
                    if(borrar(nombre, c)){
                        fsalida << "BORRADO: " << nombre << endl;
                    }
                    else{
                        fsalida << "NO BORRADO: " << nombre << endl;
                    }
                }
                else if(instruccion == "P"){
                    fentrada >> year;
                    fentrada >> raya;
                    fentrada >> month;
                    fentrada >> raya;
                    fentrada >> day;
                    crear(day, month, year, f);
                    if(purgar(f, c)){
                        fsalida << "PURGADOS: " << year << "-" << formatoFecha(month) << "-" << formatoFecha(day) << endl;
                    }
                    else{
                        fsalida << "NO PURGADOS: " << year << "-" << formatoFecha(month) << "-" << formatoFecha(day) << endl;
                    }
                }
                else if(instruccion == "NO"){
                    fentrada >> year;
                    fentrada >> raya;
                    fentrada >> month;
                    fentrada >> raya;
                    fentrada >> day;
                    crear(day, month, year, f);
                    fsalida << "ANTERIORES A: " << year << "-" << formatoFecha(month) << "-" << formatoFecha(day) << separador << obsoletos(f, separador, c) << endl;
                }
                else if(instruccion == "NL"){
                    getline(fentrada, lenguaje);
                    fsalida << "LENGUAJE: " << lenguaje << separador << delTema(lenguaje, separador, c) <<endl;;
                }
                else if(instruccion == "L"){
                    fsalida << "-----LISTADO: " << tamanyo(c) << endl;
                    iniciarIterador(c);
                    while(existeSiguiente(c)){
                        siguiente(c, p);
                        fsalida << suNombre(p) << separador << anyo(suFecha(p)) << "-" << formatoFecha(mes(suFecha(p))) << "-" << formatoFecha(dia(suFecha(p))) << separador << suLenguaje(p) << separador << suDescripcion(p) << endl;
                    }
                    fsalida << "-----" << endl;
                }
            }
            fsalida.close();
        }
        else {
            cerr << "El fichero salida.txt no se ha podido abrir/crear" << endl;
        }
        fentrada.close();
    }
    else {
        cerr << "El fichero entrada.txt no se ha podido abrir" << endl;
    }
    return 0;
}
