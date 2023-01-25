#pragma once
#include <string>
#include <iostream>
#include "Tienda.h"
#include "IVista.h"

using namespace std;
class Presentador;
class Tienda;

class Vista : public IVista
{
	Presentador* mPresentador;
	Tienda* mTienda;
	string nombre;
	string direccion;
	int codigo;
	bool opcionCamisa;
	bool opcionCuello;
	bool opcionPantalon;
	bool camisa;
	void MostrarMenuPrincipal();
	void EjecutarOpcion(const char* opcion, bool& salida);
public:
	Vista();
	void EscribeLinea(const string& texto);
	void EscribeLinea(const string& textoA, const string& textoB);
	void EscribeLinea(const string& textoA, const string& textoB, int param);
	void ReseteaInventario();
	void MostrarHistorial();
	void MostrarCotizacion();
	void Encabezado();
	void MostrarCamisaPasoA();
	void MostrarCamisaPasoB();
	void MostrarPasoC();
	void MostrarPantalonPasoA();	
	void MostrarPrecio();
	void MostrarCantidad();
	void MostrarCotizacionRealizada();
	int ValidarValor(string precio);
};

