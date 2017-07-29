#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    FILE *pArchivo;
    int opcion=0;
    EMovie Peli;
    char seguir='s';

    pArchivo=fopen("archivo.dat", "rb+");
    if(pArchivo==NULL)
    {
        pArchivo=fopen("archivo.dat", "wb+");
        if(pArchivo==NULL)
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
                altas(Peli, pArchivo);
                break;
            case 2:
                modificar(Peli, pArchivo);
                break;
            case 3:
                eliminar(Peli, pArchivo);
                break;
            case 4:
                generarPagina(pArchivo,Peli);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    fclose(pArchivo);
    return 0;
}
