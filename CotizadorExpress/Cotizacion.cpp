#include "Cotizacion.h"

void Cotizacion::ResetInvent(Tienda* tienda)
{
	tienda->ResetPunt();
}

void Cotizacion::RecorrerInventario(Tienda* tienda, int codigo)
{
	tienda->RecogeDato(codigo);
}

void Cotizacion::CargaPrecio(Tienda* tienda, float precio, int tipo)
{
	tienda->RecogerPrecio(precio, tipo);
}

int Cotizacion::EntregaCantidad(Tienda* tienda, int tipo)
{
	return tienda->DevolverCantidad(tipo);
}