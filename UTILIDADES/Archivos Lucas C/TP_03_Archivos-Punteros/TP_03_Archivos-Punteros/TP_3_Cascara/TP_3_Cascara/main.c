#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    ePelicula peliculas[20];
    ePelicula pelicula;
    ePelicula * pEncontrada;
    char buffer[4000];
    int idAux=0;
    int pos=0;
    char continuar = 's';
    char seguir='s';
    int opcion=0;

   InicializarPelicula(peliculas);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Modificar Pelicula\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            while(continuar=='s')
            {
                AgregarPelicula(&pelicula);
                savePelicula(&pelicula);
                printf("Pelicula guardada con exito.\n");
                printf("Ingresar uno nuevo? s/n: ");
                continuar = getchar();
            }

            break;

        case 2:
            if(getInt("Ingrese un id: ",buffer,1,10))
                idAux= atoi(buffer);

            BorrarPelicula(idAux);
            system("pause");
            system("cls");

            break;
        case 3:

            crearArrayPelicula (peliculas);
            if(ListarPeliculasHtml(peliculas))
                printf("La pagina web se ha creado con exito!");

            break;
        case 4:
            ListarPeliculasBasic();
            if(getInt("Ingrese un id: ",buffer,1,10))
                idAux= atoi(buffer);
            modificarPelicula (idAux);
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
