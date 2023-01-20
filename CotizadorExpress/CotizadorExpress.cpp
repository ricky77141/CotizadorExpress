#include <iostream>
#include <ctime>
#include "Tienda.h"

using namespace std;


/*int main()
{
    time_t now = time(0);
    
    char str[26];
    ctime_s(str, sizeof str, &now);

    //char* date_time = ctime(&now);
    cout << str;
    return 0;
}*/

int main()
{
    Tienda LaTienda("Casa","Por ahí");
    LaTienda.CargarInventario();
    return 0;
}

