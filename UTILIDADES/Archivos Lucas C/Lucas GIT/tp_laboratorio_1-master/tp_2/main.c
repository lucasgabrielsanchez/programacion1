#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"
#define cant 3
#define VACIO -1
#define OCUPADO 1
#define BAJA 0


int main()
{

    //int j,h,cmp;
    int valorLugar=0;
    //char dniStr[10];
    EPersona persona[cant];


    char seguir='s';
    int opcion;

    //int opcionMenu();

    inicializarArrayInt(persona,cant,VACIO);
    system("cls");

    //hardcodear(persona,3);

    while(seguir=='s')

    {
        opcion = opcionMenu();


        switch(opcion)
        {
        case 1:


            valorLugar = buscarValorPosicion(persona,cant,VACIO);

            if (valorLugar == -2)
            {
                printf("Se agotaron los lugares disponibles\n");
                system("pause");
                break;
            }

            altaPersona(persona, valorLugar,OCUPADO);

            system("pause");

            break;
        case 2:

        bajaPersona(persona,cant,BAJA);
            break;
        case 3:

            OrdenarNombres(persona,cant);
            system("pause");
            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\nLa opcion ingresada es incorrecta, vuelva a ingresar una opcion:\n");
            system("pause");

        }
    }

    return 0;
}
