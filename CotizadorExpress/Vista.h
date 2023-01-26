#pragma once
#include <string>
#include <iostream>
#include "Tienda.h"
#include "Vendedor.h"
#include "IVista.h"
#include "Cotizacion.h"

using namespace std;
class Presentador;
class Tienda;
class Vendedor;

class Vista : public IVista
{
	Presentador* mPresentador;
	Tienda* mTienda;
	Vendedor* mVendedor;
	DatosCotizacion dcVista;
	list<DatosCotizacion>* listHistorico;
	string nombre;
	string direccion;
	string nombreV;
	string apellidoV;
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
	void EscribeLinea(const string& textoA, int param);
	void EscribeLinea(const string& textoA, float param);
	void EscribeLinea(const string& textoA, const string& textoB, bool param);
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
	void PresentarCotizacion();
};

