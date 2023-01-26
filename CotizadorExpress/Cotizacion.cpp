
#include "Cotizacion.h"

void Cotizacion::ArmarCotizacion(Tienda* tienda)
{
    CalcularTiempo();
    numCotizacion = numCotizacion++;
    dc.numId = numCotizacion;
    dc.fechaHoraCotiz = str;
    dc.prendaCotiz = tienda->descPrenda;
    dc.precioUn = tienda->precioUn;
    dc.cantCotiz = tienda->cantidad;
    dc.precioFinal = tienda->precioFinal;
    dcList.push_back(dc);
}

void Cotizacion::CalcularTiempo()
{
    struct tm newtime;
    time_t now = time(0);

    localtime_s(&newtime, &now);
    int year = 1900 + newtime.tm_year;
    int month = 1 + newtime.tm_mon;
    int day = newtime.tm_mday;
    int hour = newtime.tm_hour;
    int min = 1 + newtime.tm_min;
    int sec = 1 + newtime.tm_sec;

    str = to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);

}

struct DatosCotizacion Cotizacion::EntregaData()
{
    return dc;
};

list<DatosCotizacion>* Cotizacion::EntregaDataHist()
{
    return &dcList;
}

