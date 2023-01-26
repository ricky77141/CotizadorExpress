#pragma once
#include <string>
#include <list>

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
    Nodo* recogeDato;
    Nodo* anterior;
    list<int> camino;
    void borrar(Nodo* reco);
public:
    Inventario();   
    void InicializarDest();
    void insertar(int x, int y, string z);
    void InicializarPuntReco();
    int Cantidad(int cod);
    string Tipo(int cod);
    void DescargarInventario(int cantidad);
};





