#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float radio;
    float area;

    radio=pideNum();
    area=areaCirc(radio);
    printf("El area del circulo correspondiente al radio ingresado es de: %.2f",area);
    return 0;
}
