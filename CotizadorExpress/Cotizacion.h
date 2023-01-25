#pragma once
#include <string>
#include <ctime>
#include "Tienda.h"

using namespace std;

class Cotizacion
{

	int numCotizacion;
	time_t fechaHoraCotizacion;
	int codigoVendedor;
	int unidades;

public:
	void ResetInvent(Tienda* tienda);
	void RecorrerInventario(Tienda* tienda, int codigo);
	void CargaPrecio(Tienda* tienda, float precio, int tipo);
	int EntregaCantidad(Tienda* tienda, int tipo);
};

