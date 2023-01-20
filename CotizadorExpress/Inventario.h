#pragma once
#include <string>
#include <iostream>
using namespace std;

class Inventario
{
    class Nodo {
    public:
        int ident;
        int cantidad;
        string tipo;
        Nodo* izq;
        Nodo* der;
    };
    Nodo* raiz;
    void borrar(Nodo* reco);
public:
    Inventario();
    ~Inventario();
    void insertar(int x, int y, string z);
};





