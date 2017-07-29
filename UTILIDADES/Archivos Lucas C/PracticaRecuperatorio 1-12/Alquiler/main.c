#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
#include <ctype.h>
#define cant_clientes 10
#define cant_alquileres 20

#define VACIO -1
#define OCUPADO 1
#define BAJA 0

#define ALQUILADO 1
#define FINALIZADO 0

#define AMOLADORA 0
#define MEZCLADORA 1
#define TALADRO 2

int main()
{
    char seguir='s';
    int opcion;
    int valorLugar=0;
    int cont = 0;
    int i = 0;
    int acum = 0;
    int tiempoPromedio;

    ECliente cliente[cant_clientes];
    EAlquiler alquiler[cant_alquileres];

    inicializarArrayCliente(cliente,cant_clientes,VACIO);
    inicializarArrayAlquiler(alquiler,cant_alquileres,VACIO);

    while(seguir=='s')

    {
        opcion = opcionMenu();


        switch(opcion)
        {
        case 1:

            valorLugar = buscarPosicionCliente(cliente,cant_clientes,VACIO);

            if (valorLugar == -2)
            {
                printf("Se agotaron los lugares disponibles\n");
                system("pause");
                break;
            }

            altaCliente(cliente, valorLugar,OCUPADO);

            system("pause");

            break;
        case 2:

            modificarCliente(cliente,cant_clientes);
            break;
        case 3:

            bajaCliente(cliente,cant_clientes,BAJA);
            system("pause");
            break;
        case 4:
            valorLugar = buscarPosicionAlquiler(alquiler,cant_alquileres,VACIO);

            if (valorLugar == -2)
            {
                printf("Se agotaron los lugares disponibles\n");
                system("pause");
                break;
            }

            altaAlquiler(alquiler,cliente,cant_clientes,valorLugar,ALQUILADO);
            break;
        case 5:
            finAlquiler(alquiler,cant_alquileres,FINALIZADO);
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            for (i=0;i<cant_alquileres;i++)
            {
                if (alquiler[i].tiempo>1 && alquiler[i].tiempo<72)
                {
                    acum = acum + (alquiler[i].tiempo);
                    cont++;
                }
            }

            tiempoPromedio = acum/cont;
            printf("El tiempo promedio de alquiler es %d\n",tiempoPromedio);
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("\nLa opcion ingresada es incorrecta, vuelva a ingresar una opcion:\n");
            system("pause");

        }
    }

    return 0;
}
