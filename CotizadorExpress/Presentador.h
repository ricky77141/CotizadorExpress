#pragma once
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
	void RecorrerInventario(Tienda* tienda, int codigo);
	void CargaPrecio(Tienda* tienda, float precio, int tipo);
};

