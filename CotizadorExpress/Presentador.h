#pragma once
#include "Cotizacion.h"
class IVista;
class Cotizacion;
class Tienda;

class Presentador
{
	IVista* mVista = nullptr;
	Cotizacion* mCotizacion = nullptr;
	Tienda* mTienda = nullptr;

public:
	explicit Presentador(IVista* vista);
	void ResetearInventario(Tienda* tienda);
	void RecorrerInventario(Tienda* tienda, int codigo);
	void CargaPrecio(Tienda* tienda, float precio, int tipo);
	int TraerCantidad(Tienda* tienda, int tipo);
	void RecogeCantidad(Tienda* tienda, int cant, int tipo);
	void ArmaDatos(Tienda* tienda, int tipo);
	void ArmaCotiz(Tienda* tienda);
	struct DatosCotizacion EntregaData();
	list<DatosCotizacion>* RecogeHist();
};

