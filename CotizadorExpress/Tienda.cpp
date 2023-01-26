#include <iostream>
#include <iomanip>
#include "Tienda.h"

using namespace std;

void Tienda::CargarInventario()
{
	invt.insertar(25, 3000, "");
	invt.insertar(10, 1000, "Camisas");
	invt.insertar(6, 500, "Manga Corta");
	invt.insertar(2, 220, "Cuello Mao");
	invt.insertar(1, 100, "Standard");
	invt.insertar(3, 100,"Premium");
	invt.insertar(8, 300, "Cuello comun");
	invt.insertar(7, 150, "Standard");
	invt.insertar(9, 150, "Premium");
	invt.insertar(14, 500, "Manga larga");
	invt.insertar(12, 150, "Cuello Mao");
	invt.insertar(11, 75, "Standard");
	invt.insertar(13, 75, "Premium");
	invt.insertar(16, 350, "Cuello comun");
	invt.insertar(15, 175, "Standard");
	invt.insertar(17, 175, "Premium");
	invt.insertar(31, 2000, "Pantalones");
	invt.insertar(29, 1500, "Chupines");
	invt.insertar(28, 750, "Standard");
	invt.insertar(30, 750, "Premium");
	invt.insertar(33, 500, "Comunes");
	invt.insertar(32, 250, "Standard");
	invt.insertar(34, 250, "Premium");
}

void Tienda::ResetPunt()
{
	invt.InicializarPuntReco();
}

void Tienda::RecogeDato(int cod)
{
	if (cod == 10)
	{
		cm.tipo = invt.Tipo(cod);
	}
	else if (cod == 6 || cod == 14)
	{
		cm.tipoManga = invt.Tipo(cod);
	}
	else if (cod == 2 || cod == 8 || cod == 12 || cod == 16)
	{
		cm.tipoCuello = invt.Tipo(cod);
	}
	else if (cod==1||cod==3||cod==7||cod==9||cod==11||cod==13||cod==15||cod==17)
	{
		cm.calidad = invt.Tipo(cod);
		cm.cantidadInventario = invt.Cantidad(cod);
	}
	else if (cod == 31)
	{
		pm.tipo = invt.Tipo(cod);
	}
	else if (cod == 29 || cod == 33)
	{
		pm.tipoPantalon = invt.Tipo(cod);
	}
	else if (cod == 28 || cod == 30 || cod == 32 || cod == 34)
	{
		pm.calidad = invt.Tipo(cod);
		pm.cantidadInventario = invt.Cantidad(cod);
	}
	
}

void Tienda::RecogerPrecio(float precio, int tipoPrenda)
{
	if (tipoPrenda == 0)
	{
		cm.precio = precio;
	}
	else
	{
		pm.precio = precio;
	}
}

void Tienda::RecogeCantidad(int cant, int tipoPrenda)
{
	if (tipoPrenda == 0)
	{
		cm.cantidadCotizacion = cant;
	}
	else
	{
		pm.cantidadCotizacion = cant;
	}
	ResetPunt();
	invt.DescargarInventario(cant);
}


int Tienda::DevolverCantidad(int tipoPrenda)
{
	if (tipoPrenda == 0)
	{
		return cm.cantidadInventario;
	}
	else
	{
		return pm.cantidadInventario;
	}	
}

void Tienda::ArmarDatos(int tipo)
{
	if (tipo == 0)
	{
		cantidadInventario = cm.cantidadInventario;
		descPrenda = cm.tipo + " - " + cm.tipoManga + " - " + cm.tipoCuello + " - " + cm.calidad;
		precioUn = cm.precio;
		if (cm.tipoManga == "Manga Corta")
		{
			precioUn = precioUn - (precioUn * 0.1);
		}
		if (cm.tipoCuello == "Cuello Mao")
		{
			precioUn = precioUn + (precioUn * 0.03);
		}
		if (cm.calidad == "Premium")
		{
			precioUn = precioUn + (precioUn * 0.3);
		}
		cantidad = cm.cantidadCotizacion;
		precioFinal = precioUn * cantidad;
	}
	else
	{
		cantidadInventario = pm.cantidadInventario;
		descPrenda = pm.tipo + " - " + pm.tipoPantalon + " - " + pm.calidad;
		precioUn = pm.precio;
		if (pm.tipoPantalon == "Chupines")
		{
			precioUn = precioUn - (precioUn * 0.12);
		}
		if (cm.calidad == "Premium")
		{
			precioUn = precioUn + (precioUn * 0.3);
		}
		cantidad = pm.cantidadCotizacion;
		precioFinal = precioUn * cantidad;
	}
}
