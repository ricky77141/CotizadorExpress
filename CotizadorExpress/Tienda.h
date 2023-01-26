#pragma once
#include <string>
#include "Inventario.h"
#include "Prenda.h"

using namespace std;

class Tienda
{
	Inventario invt;
	camisa cm;
	pantalon pm;
public:
	string nombre="";
	string direccion="";
	int cantidadInventario=0;
	string descPrenda="";
	float precioUn=0;
	int cantidad=0;
	float precioFinal=0;

	Tienda(string nombre, string direccion)
	{
		this->nombre = nombre;
		this->direccion = direccion;
	}
	~Tienda()
	{
		invt.InicializarDest();		
	}

	void ResetPunt();
	void CargarInventario();
	void RecogeDato(int cod);
	void RecogerPrecio(float precio, int tipo);
	void RecogeCantidad(int cant, int tipo);
	int DevolverCantidad(int tipo);
	void ArmarDatos(int tipo);
};

