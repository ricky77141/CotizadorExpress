#include <Windows.h>
#include "Vista.h"
#include "Presentador.h"
#include "Tienda.h"

using namespace std;

Vista::Vista()
{	
	mTienda = new Tienda("La esquina de la ropa", "Clle. 32B #64B-54");
	mTienda->CargarInventario();	
	SetConsoleTitleW(L"Cotizador express");
	setlocale(LC_ALL, "es_Es");
	mPresentador = new Presentador(this);
	MostrarMenuPrincipal();
}


void Vista::EscribeLinea(const string& texto)
{
	cout << texto << endl;	
}

void Vista::EscribeLinea(const string& textoA, const string& textoB)
{
	cout << textoA << " | " << textoB << endl;
}

void Vista::MostrarMenuPrincipal()
{	
	bool salida = false;
	string opcion;
	nombre = mTienda->nombre;
	direccion = mTienda->direccion;
	do {
		system("cls");
		EscribeLinea("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea(nombre, direccion);
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea("Nombre");
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea("");
		EscribeLinea("Seleccione opción:");
		EscribeLinea("");
		EscribeLinea("1. Historial de cotizaciones");
		EscribeLinea("2. Realizar cotización");
		EscribeLinea("3. Salir");
		cin >> opcion;
		system("cls");
		EjecutarOpcion(opcion.c_str(), salida);
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	} while (!salida);

}

void Vista::MostrarHistorial()
{
	bool regresar = false;

	do {
		system("cls");
		EscribeLinea("COTIZADOR EXPRESS - HISTORIAL");
		EscribeLinea("----------------------------------------------------------");
	
	} while (!regresar);
}

void Vista::MostrarCotizacion()
{	
	string opcion;
	bool regresar = false;


	do {
		Encabezado();
		EscribeLinea("PASO 1: Seleccione prenda a cotizar:");
		EscribeLinea("1. Camisa");
		EscribeLinea("2. Pantalon");
		cin >> opcion;
		system("cls");

		if (opcion == "1")
		{
			mPresentador->RecorrerInventario(mTienda,10);
			//Cargar struct tipo prenda.	
			regresar = true;
			MostrarCamisaPasoA();
		}
		else if (opcion == "2")
		{
			mPresentador->RecorrerInventario(mTienda, 31);
			//Cargar struct tipo prenda.		
			regresar = true;
			MostrarPantalonPasoA();
		}
		else if (opcion == "3")
		{
			regresar = true;
			MostrarMenuPrincipal();
		}
		else
		{
			EscribeLinea("Opcion erronea");
			cin.get();
			regresar = false;
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	} while (!regresar);

	
}

void Vista::MostrarCamisaPasoA()
{

	bool regresar = false;
	string opcion;
	
	do {
		Encabezado();
		EscribeLinea("PASO 2.a: ¿La Camisa a cotizar es manga corta?:");
		EscribeLinea("1. Si");
		EscribeLinea("2. No");
		cin >> opcion;
		system("cls");
		if (opcion == "1")
		{
			mPresentador->RecorrerInventario(mTienda, 6);
			opcionCamisa = true;
			//Cargar struct tipo camisa.
			MostrarCamisaPasoB();
		}
		else if (opcion == "2")
		{
			mPresentador->RecorrerInventario(mTienda, 14);
			opcionCamisa = false;
			//Cargar struct tipo camisa.
			MostrarCamisaPasoB();
		}
		else if (opcion == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			EscribeLinea("Opcion erronea");
			cin.get();
			regresar = false;
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	}while(!regresar);

	
}

void Vista::MostrarCamisaPasoB()
{

	bool regresar = false;
	camisa = true;
	string opcion;

	do {
		Encabezado();
		EscribeLinea("PASO 2.b: ¿La Camisa a cotizar es cuello Mao?:");
		EscribeLinea("1. Si");
		EscribeLinea("2. No");
		cin >> opcion;
		system("cls");
		if (opcion == "1")
		{
			if (opcionCamisa)
			{
				mPresentador->RecorrerInventario(mTienda, 2);
			}
			else
			{
				mPresentador->RecorrerInventario(mTienda, 12);
			}
			opcionCuello = true;
			MostrarPasoC();
		}
		else if (opcion == "2")
		{
			if (opcionCamisa)
			{
				mPresentador->RecorrerInventario(mTienda, 8);
			}
			else
			{
				mPresentador->RecorrerInventario(mTienda, 16);
			}
			opcionCuello = false;
			MostrarPasoC();
		}
		else if (opcion == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			EscribeLinea("Opcion erronea");
			cin.get();
			regresar = false;
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	}while(!regresar);


}

void Vista::MostrarPasoC()
{
	bool regresar = false;
	string opcion;
	
	do {
		Encabezado();
		EscribeLinea("PASO 3: Seleccione la calidad de la prenda");
		EscribeLinea("1. Standard");
		EscribeLinea("2. Premium");
		cin >> opcion;
		system("cls");

		if (opcion == "1")
		{
			if (camisa) {
				if (opcionCamisa && opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 1);
				}
				else if (opcionCamisa && !opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 7);
				}
				else if (!opcionCamisa && opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 11);
				}
				else if (!opcionCamisa && !opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 15);
				}
			}
			else 
			{
				if (opcionPantalon) 
				{
					mPresentador->RecorrerInventario(mTienda, 28);
				}
				else
				{
					mPresentador->RecorrerInventario(mTienda, 30);
				}
			}
			//Cargar struct calidad.
			MostrarPrecio();
		}
		else if (opcion == "2")
		{
			if (camisa)
			{
				if (opcionCamisa && opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 3);
				}
				else if (opcionCamisa && !opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 9);
				}
				else if (!opcionCamisa && opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 13);
				}
				else if (!opcionCamisa && !opcionCuello)
				{
					mPresentador->RecorrerInventario(mTienda, 17);
				}
			}
			else
			{
				if (opcionPantalon)
				{
					mPresentador->RecorrerInventario(mTienda, 30);
				}
				else
				{
					mPresentador->RecorrerInventario(mTienda, 34);
				}
			}
			//Cargar struct calidad.
			MostrarPrecio();
		}
		else if (opcion == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			EscribeLinea("Opcion erronea");
			cin.get();
			regresar = false;
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	}while(!regresar);

	
}

void Vista::MostrarPantalonPasoA()
{
	bool regresar = false;
	camisa = false;
	string opcion;

	do {
		Encabezado();
		EscribeLinea("PASO 2: El pantalon a cotizar, ¿es chupín?");
		EscribeLinea("1. Si");
		EscribeLinea("2. No");
		cin >> opcion;
		system("cls");

		if (opcion == "1")
		{
			mPresentador->RecorrerInventario(mTienda, 29);
			opcionPantalon = true;
			//Cargar struct calidad.
			MostrarPasoC();
		}
		else if (opcion == "2")
		{
			mPresentador->RecorrerInventario(mTienda, 33);
			opcionPantalon = false;
			//Cargar struct calidad.
			MostrarPasoC();
		}
		else if (opcion == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			EscribeLinea("Opcion erronea");
			cin.get();
			regresar = false;
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	} while (!regresar);

	
}

void Vista::MostrarPrecio()
{
	bool regresar = false;
	string precio;
	float precioUn;
	
	do {
		Encabezado();
		EscribeLinea("PASO 4: Ingrese precio unitario de la prenda a cotizar.");
		cin >> precio;
		system("cls");

		if (precio == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			ValidarTipoPrecio(precio);

			precioUn = stof(precio);

			if (camisa)
			{
				mPresentador->CargaPrecio(mTienda, precioUn, 0);
			}
			else 
			{
				mPresentador->CargaPrecio(mTienda, precioUn, 1);
			}
			MostrarCantidad();
		}
	} while (!regresar);
}

void Vista::MostrarCantidad()
{
	bool regresar = false;
	string cantidad;

	do {
		Encabezado();
		EscribeLinea("INFORMACION:");
		EscribeLinea("Existe x cantidad de unidades en stock de la prenda seleccionada.");
		EscribeLinea("PASO 5: Ingrese la cantidad de unidades a cotizar.");
		cin >> cantidad;
		system("cls");

		if (cantidad == "3")
		{
			MostrarMenuPrincipal();
		}
		else
		{
			MostrarCotizacion();
		}
	} while (!regresar);
}

void Vista::MostrarCotizacionRealizada()
{

}

void Vista::Encabezado()
{
	system("cls");
	EscribeLinea("COTIZADOR EXPRESS - COTIZAR");
	EscribeLinea("----------------------------------------------------------");
	EscribeLinea("Presione 3 para volver al menú principal");
	EscribeLinea("----------------------------------------------------------");
}

void Vista::EjecutarOpcion(const char* opcion, bool& salida)
{
	auto strOpcion = string(opcion);

	if (strOpcion == "1")
	{
		MostrarHistorial();
	}
	else if (strOpcion == "2")
	{
		MostrarCotizacion();
	}
	else if (strOpcion == "3")
	{
		cout.flush();
		exit(EXIT_SUCCESS);
	}
	else 
	{
		EscribeLinea("Opcion erronea");
		cin.get();
		salida = false;
	}
}

int Vista::ValidarTipoPrecio(string precio)
{
	int x = 0;
	string digito;

	for (int i = 0; i < precio.size(); i++) {  
		digito = precio[i];
		//int val = digito.compare(",");

		if (precio[i] == ',')
			x++;

		if (!isdigit(precio[i]) && precio[i] != ',' && precio[i] != '\0')
			return 3;   /* Not a valid number. */
	}

	if (x == 0)
		return 1;   /* Integer number. */

	if (x == 1)
		return 2;   /* Float number. */

	if (x > 1)
		return 3;   /* Not a valid number. */
}
