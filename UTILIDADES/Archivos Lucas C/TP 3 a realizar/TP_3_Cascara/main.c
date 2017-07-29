#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    char auxChar[20];
    int opcion=0;
    EMovie auxMovie;

    FILE* miArchivoXD;
    char* nombreArchivo = "Archivito.txt";

    miArchivoXD = fopen(nombreArchivo,"w");

    fprintf(miArchivoXD,"soy Pepito boludo \ny vos?");

    fclose(miArchivoXD);


    while(seguir=='s')
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
                gets(auxChar);
                //agregarPelicula(auxMovie);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error en la opcion elegida, vuelva a elegir la opcion\n");
                system("pause");
                break;
        }
    }

    return 0;
}
