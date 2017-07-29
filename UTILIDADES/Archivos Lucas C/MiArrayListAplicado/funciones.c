#include "funciones.h"

int opcionMenu()
{
    int opcion;

    system("cls");
        printf("1- Alta Cliente\n");
        printf("2- Modificar Cliente\n");
        printf("3- Baja Cliente\n");
        printf("4- Nuevo Alquiler\n");
        printf("5- Finalizar Alquiler\n");
        printf("6- Informar cliente con mas alquileres\n");
        printf("7- Informar equipo/s mas alquilado/s\n");
        printf("8- Informar tiempo promedio de alquiler de los equipos\n\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        return opcion;
}
