#include "Tienda.h"

using namespace std;

void Tienda::CargarInventario()
{
	Inventario invt;
	invt.insertar(23, 3000, "");
	invt.insertar(14, 1000, "Camisas");
	invt.insertar(5, 500, "Manga Corta");
	invt.insertar(2, 220, "Cuello Mao");
	invt.insertar(1, 100, "Standard");
	invt.insertar(3, 100,"Premium");
	invt.insertar(6, 300, "Cuello comun");
	invt.insertar(4, 150, "Standard");
	invt.insertar(7, 150, "Premium");
	invt.insertar(15, 500, "Manga larga");
	invt.insertar(12, 150, "Cuello Mao");
	invt.insertar(10, 75, "Standard");
	invt.insertar(13, 75, "Premium");
	invt.insertar(16, 350, "Cuello comun");
	invt.insertar(11, 175, "Standard");
	invt.insertar(17, 175, "Premium");
	invt.insertar(24, 2000, "Pantalones");
	invt.insertar(20, 1500, "Chupines");
	invt.insertar(19, 750, "Standard");
	invt.insertar(21, 750, "Premium");
	invt.insertar(25, 500, "Comunes");
	invt.insertar(22, 250, "Standard");
	invt.insertar(26, 250, "Premium");	
}
