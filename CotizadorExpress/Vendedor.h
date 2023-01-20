#pragma once
#include <string>

using namespace std;

class Vendedor
{
	string nombre;
	string apellido;
	int codigoVendedor;

public:
	Vendedor(string nombre, string apellido, int codigoVendedor) 
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->codigoVendedor = codigoVendedor;
	}

	void RealizarCotizacion()
	{

	}
};

