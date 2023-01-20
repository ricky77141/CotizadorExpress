#pragma once
#include <string>
#include "Inventario.h"

using namespace std;



class Tienda
{
	string nombre;
	string direccion;
	string prendas[2];
	Inventario InvObj;

public:
	Tienda(string nombre, string direccion)
	{
		this->nombre;
		this->direccion;
	}
	void CargarInventario();
};

