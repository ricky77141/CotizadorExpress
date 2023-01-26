#include "Presentador.h"
#include "IVista.h"
#include "Cotizacion.h"
#include "Tienda.h"

Presentador::Presentador(IVista* vista) : mVista(vista), mCotizacion(new Cotizacion())
{

}

void Presentador::ResetearInventario(Tienda* tienda)
{
	tienda->ResetPunt();
}

void Presentador::RecorrerInventario(Tienda* tienda, int codigo) 
{
	tienda->RecogeDato(codigo);
}

void Presentador::CargaPrecio(Tienda* tienda, float precio, int tipo)
{
	tienda->RecogerPrecio(precio, tipo);
}

void Presentador::RecogeCantidad(Tienda* tienda, int cant, int tipo)
{
	tienda->RecogeCantidad(cant, tipo);
}

int Presentador::TraerCantidad(Tienda* tienda, int tipo)
{
	return tienda->DevolverCantidad(tipo);
}

void Presentador::ArmaCotiz(Tienda* tienda)
{
	mCotizacion->ArmarCotizacion(tienda);
}

void Presentador::ArmaDatos(Tienda* tienda, int tipo)
{
	tienda->ArmarDatos(tipo);
}

struct DatosCotizacion Presentador::EntregaData()
{
	return mCotizacion->EntregaData();
};

list<DatosCotizacion>* Presentador::RecogeHist()
{
	return mCotizacion->EntregaDataHist();
}




