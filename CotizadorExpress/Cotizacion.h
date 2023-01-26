#pragma once
#include <string>
#include <ctime>
#include <list>
#include "Tienda.h"

class Presentador;


using namespace std;

struct DatosCotizacion
{
	int numId;
	string fechaHoraCotiz;
	int codVendedor;
	string prendaCotiz;
	float precioUn;
	int cantCotiz;
	float precioFinal;
};

class Cotizacion
{
	int numCotizacion=0;
	DatosCotizacion dc;		
	list<DatosCotizacion> dcList;	
	string str;
public:
	
	void ArmarCotizacion(Tienda* tienda);
	void CalcularTiempo();
	DatosCotizacion EntregaData();
	list<DatosCotizacion>* EntregaDataHist();
};

