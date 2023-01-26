#include <Windows.h>
#include <iomanip>
#include <list>
#include "Vista.h"
#include "Presentador.h"
#include "Tienda.h"

using namespace std;

Vista::Vista()
{	
	mTienda = new Tienda("La esquina de la ropa", "Clle. 32B #64B-54");
	mTienda->CargarInventario();
	mVendedor = new Vendedor("Benito", "Camelo", 1);
	SetConsoleTitleW(L"Cotizador express");
	setlocale(LC_ALL, "es_Es");
	mPresentador = new Presentador(this);
	MostrarMenuPrincipal();
}


void Vista::EscribeLinea(const string& texto)
{
	cout << texto << endl;	
}

void Vista::EscribeLinea(const string& textoA, const string& textoB, bool param)
{
	if (param)
	{
		cout << textoA << " | " << textoB << endl;
	} else
	{
		cout << textoA << " " << textoB << endl;
	}
}

void Vista::EscribeLinea(const string& textoA, const string& textoB, int param)
{
	cout << textoA << " " << param << " " << textoB << endl;
}

void Vista::EscribeLinea(const string& textoA, int param)
{
	cout << textoA << " " << param  << endl;
}

void Vista::EscribeLinea(const string& textoA, float param)
{
	cout << textoA << " " << fixed << setprecision(2) << param << endl;
}



void Vista::MostrarMenuPrincipal()
{	
	bool salida = false;
	string opcion;
	nombre = mTienda->nombre;
	direccion = mTienda->direccion;
	nombreV = mVendedor->nombre;
	apellidoV = mVendedor->apellido;
	ReseteaInventario();
	do {
		system("cls");
		EscribeLinea("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea("Tienda: " + nombre, "Dirección: " + direccion, true);
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea("Nombre: " + nombreV, "Apellido: " + apellidoV, true);
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
	string opcion;

	listHistorico = mPresentador->RecogeHist();

	do {
		system("cls");
		EscribeLinea("COTIZADOR EXPRESS - HISTORIAL");
		EscribeLinea("----------------------------------------------------------");
		EscribeLinea("Escriba M para regresar al menú principal.");
		EscribeLinea("----------------------------------------------------------");
		for (auto it = begin(*listHistorico); it != end(*listHistorico); ++it)
		{
			EscribeLinea("Número de identificación: ", it->numId);
			EscribeLinea("Fecha y hora de la cotización: ", it->fechaHoraCotiz, false);
			EscribeLinea("Código del vendedor: ", it->codVendedor);
			EscribeLinea("Prenda cotizada: ", it->prendaCotiz, false);
			EscribeLinea("Precio unitario: $", it->precioUn);
			EscribeLinea("Cantidad de unidades cotizadas: ", it->cantCotiz);
			EscribeLinea("Precio final: $", it->precioFinal);
			cout << "\n";
		}
		cin >> opcion;

		if (opcion == "M" || opcion == "m")
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
		else if (opcion == "M" || opcion == "m")
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
			regresar = true;
			MostrarCamisaPasoB();
		}
		else if (opcion == "2")
		{
			mPresentador->RecorrerInventario(mTienda, 14);
			opcionCamisa = false;
			regresar = true;
			MostrarCamisaPasoB();
		}
		else if (opcion == "M" || opcion == "m")
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
			regresar = true;
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
			regresar = true;
			MostrarPasoC();
		}
		else if (opcion == "M" || opcion == "m")
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
			regresar = true;
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
			regresar = true;
			MostrarPrecio();
		}
		else if (opcion == "M" || opcion == "m")
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
			regresar = true;
			MostrarPasoC();
		}
		else if (opcion == "2")
		{
			mPresentador->RecorrerInventario(mTienda, 33);
			opcionPantalon = false;
			regresar = true;
			MostrarPasoC();
		}
		else if (opcion == "M" || opcion == "m")
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

void Vista::MostrarPrecio()
{
	bool regresar = false;
	string precio;
	float precioUn;
	int validacion;
	
	do {
		Encabezado();
		EscribeLinea("PASO 4: Ingrese precio unitario de la prenda a cotizar.");
		cin >> precio;
		system("cls");

		validacion = ValidarValor(precio);

		if (precio == "M" || precio == "m")
		{
			regresar = true;
			MostrarMenuPrincipal();
		}
		else if (validacion == 1)
		{
			EscribeLinea("Debe ingresar número con decimales separados por ,");
			cin.get();
			regresar = false;
		}
		else if (validacion == 3)
		{
			EscribeLinea("Solo deben ingresarse números decimales separados por ,");
			cin.get();
			regresar = false;
		}
		else if (validacion == 2)
		{
			precioUn = stof(precio);

			if (camisa)
			{
				mPresentador->CargaPrecio(mTienda, precioUn, 0);
			}
			else
			{
				mPresentador->CargaPrecio(mTienda, precioUn, 1);
			}
			regresar = true;
			MostrarCantidad();
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	} while (!regresar);
}

void Vista::MostrarCantidad()
{
	bool regresar = false;
	int cantidad;
	string cantidadCotiz;
	int cantidadFinal;
	int validacion;

	do {
		if (camisa)
		{
			cantidad = mPresentador->TraerCantidad(mTienda, 0);
		}
		else
		{
			cantidad = mPresentador->TraerCantidad(mTienda, 1);
		}
		Encabezado();
		EscribeLinea("INFORMACION:");
		EscribeLinea("Existe", "cantidad de unidades en stock de la prenda seleccionada.", cantidad);
		EscribeLinea("PASO 5: Ingrese la cantidad de unidades a cotizar.");
		cin >> cantidadCotiz;
		system("cls");

		validacion = ValidarValor(cantidadCotiz);

		if (cantidadCotiz == "M" || cantidadCotiz == "m")
		{
			regresar = true;
			MostrarMenuPrincipal();
		}
		else if (validacion == 2)
		{
			EscribeLinea("Solo debe ingresar enteros.");
			cin.get();
			regresar = false;
		}
		else if (validacion == 3)
		{
			EscribeLinea("Solo puede ingresar números enteros.");
			cin.get();
			regresar = false;
		} 		
		else if (validacion == 1)
		{
			cantidadFinal = stoi(cantidadCotiz);
			if (cantidadFinal > cantidad)
			{
				EscribeLinea("No hay suficiente stock en el inventario.");
				cin.get();
				regresar = false;
			}
			else
			{
				regresar = true;
				if (camisa)
				{
					mPresentador->RecogeCantidad(mTienda,cantidadFinal,0);
					mPresentador->ArmaDatos(mTienda, 0);
				}
				else
				{
					mPresentador->RecogeCantidad(mTienda, cantidadFinal, 1);
					mPresentador->ArmaDatos(mTienda, 1);
				}
				PresentarCotizacion();
				//Se muestra la cotizacion en pantalla.
			}
		}
		EscribeLinea("");
		EscribeLinea("Presione cualquier tecla para continuar.");
		cin.get();
	} while (!regresar);
}

void Vista::PresentarCotizacion()
{
	bool regresar = false;
	int codVendedor = mVendedor->codigoVendedor;
	string opcion;

	mPresentador->ArmaCotiz(mTienda);
	dcVista = mPresentador->EntregaData();	

	do {
		Encabezado();
		EscribeLinea("Número de identificación: ", dcVista.numId);
		EscribeLinea("Fecha y hora de la cotización: ", dcVista.fechaHoraCotiz, false);
		EscribeLinea("Código del vendedor: ", codVendedor);
		EscribeLinea("Prenda cotizada: ", dcVista.prendaCotiz, false);
		EscribeLinea("Precio unitario: $", dcVista.precioUn);
		EscribeLinea("Cantidad de unidades cotizadas: ", dcVista.cantCotiz);
		EscribeLinea("Precio final: $", dcVista.precioFinal);
		cin >> opcion;
		if (opcion == "M" || opcion == "m")
		{
			regresar = true;
			MostrarMenuPrincipal();
		}

	} while (!regresar);
}

void Vista::Encabezado()
{
	system("cls");
	EscribeLinea("COTIZADOR EXPRESS - COTIZAR");
	EscribeLinea("----------------------------------------------------------");
	EscribeLinea("Presione M para volver al menú principal");
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
		delete mPresentador;
		delete mTienda;
		delete mVendedor;
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

void Vista::ReseteaInventario()
{
	mPresentador->ResetearInventario(mTienda);
}

int Vista::ValidarValor(string precio)
{
	int x = 0;
	string digito;

	for (int i = 0; i < precio.size(); i++) {  
		digito = precio[i];

		if (precio[i] == ',')
			x++;

		if (!isdigit(precio[i]) && precio[i] != ',' && precio[i] != '\0')
			return 3;   
	}

	if (x == 0)
		return 1;   

	if (x == 1)
		return 2;   

	if (x > 1)
		return 3;   
}
