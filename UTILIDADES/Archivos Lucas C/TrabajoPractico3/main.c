#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    FILE *parch;
    EMovie movie;

    parch=fopen("datos.dat", "rb+");
    if(parch==NULL)
    {
        parch=fopen("datos.dat", "wb+");
        if(parch==NULL)
        {
            printf("No se puede iniciar el archivo.");
            exit(1);
        }
    }

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altas(movie, parch);
                break;
            case 2:
                modificar(movie, parch);
                break;
            case 3:
                eliminar(movie, parch);
                break;
            case 4:
                generarPagina(parch,movie);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    fclose(parch);
    return 0;
}
