#include "Cotizacion.h"

void Cotizacion::RecorrerInventario(Tienda* tienda, int codigo)
{
	tienda->RecogeDato(codigo);
}

void Cotizacion::CargaPrecio(Tienda* tienda, float precio, int tipo)
{
	tienda->RecogerPrecio(precio, tipo);
}