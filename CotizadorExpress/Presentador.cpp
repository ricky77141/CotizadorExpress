#include "Presentador.h"
#include "IVista.h"
#include "Cotizacion.h"
#include "Tienda.h"

Presentador::Presentador(IVista* vista) : mVista(vista), mCotizacion(new Cotizacion())
{

}

void Presentador::RecorrerInventario(Tienda* tienda, int codigo) 
{
	mCotizacion->RecorrerInventario(tienda, codigo);
}

void Presentador::CargaPrecio(Tienda* tienda, float precio, int tipo)
{

}


