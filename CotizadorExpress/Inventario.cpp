#include <string>
#include "Inventario.h"


using namespace std;

Inventario::Inventario()
{    
	raiz = NULL;
}

/*Inventario::~Inventario()
{
    borrar(raiz);
}*/

void Inventario::borrar(Nodo* reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        delete reco;
    }
}

void Inventario::insertar(int x, int y, string z)
{
    Nodo* nuevo;
    nuevo = new Nodo();
    nuevo->ident = x;
    nuevo->cantidad = y;
    nuevo->tipo = z;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        Nodo* anterior, * reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (x < reco->ident)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (x < anterior->ident)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

void Inventario::InicializarPuntReco()
{    
    recogeDato=raiz;
}

int Inventario::Cantidad(int cod)
{
    
    if (anterior->ident > cod)
    {
        anterior = anterior->izq;

        return anterior->cantidad;
    }
    else
    {
        anterior = anterior->der;

        return anterior->cantidad;
    }
}

string Inventario::Tipo(int cod)
{
    anterior = recogeDato;
    if (recogeDato->ident > cod)
    {
        recogeDato = recogeDato->izq;

        return recogeDato->tipo;
    }
    else
    {
        recogeDato = recogeDato->der;

        return recogeDato->tipo;
    }
}
