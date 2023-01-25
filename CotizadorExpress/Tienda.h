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
	string nombre;
	string direccion;
	int cantidadInventario;	

	Tienda(string nombre, string direccion)
	{
		this->nombre = nombre;
		this->direccion = direccion;
	}

	void CargarInventario();
	void RecogeDato(int cod);
	void RecogerPrecio(float precio, int tipo);
};

