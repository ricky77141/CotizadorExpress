#pragma once
#include <string>

using namespace std;

class Vendedor
{
public:
	string nombre;
	string apellido;
	int codigoVendedor;

	Vendedor(string nombre, string apellido, int codigoVendedor) 
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->codigoVendedor = codigoVendedor;
	}
};

