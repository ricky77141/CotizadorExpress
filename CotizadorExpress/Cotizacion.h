#pragma once
#include <string>
#include <ctime>

using namespace std;

class Cotizacion
{
	int numCotizacion;
	time_t fechaHoraCotizacion;
	int codigoVendedor;
	string prenda;
	int unidades;
	Cotizacion(int numCotizacion, time_t fechaHoraCotizacion, int codigoVendedor, string prenda, int unidades)
	{
		this->numCotizacion = numCotizacion;
		this->fechaHoraCotizacion = fechaHoraCotizacion;
		this->fechaHoraCotizacion = codigoVendedor;
		this->prenda = prenda;
		this->unidades = unidades;
	}
	

};

