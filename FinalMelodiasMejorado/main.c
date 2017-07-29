#include "Includes.h"

int main()
{
    system("MODE CON: LINES=500");
    ArrayList *pNotas = al_newArrayList();
    ArrayList *pNotasAux = al_newArrayList();
    int opcion;
    char seguir = 's';
    int flag1 = 0;

    while(seguir == 's')
    {
        opcion = menu("1- Leer archivo\n2- Reproducir\n3- Ecualizar\n4- Correcion\n5- Salir\n\n", "opcion ingresada incorrecta",1,5);

        switch (opcion)
        {
        case 1:
            if(crearNotas(pNotas))
            {
                printf("Archivos leidos correctamente\n\n");
                flag1 = 1;
                system("pause");
                system("cls");
            }
            else
            {
                printf("Error al leer archivos\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            if(flag1)
            {
                printearNotas(pNotas);
                system("pause");
                 system("cls");
            }
            else
            {
                printf("Para acceder a esta opcion primero debe acceder a la opcion 1\n\n");
                system("pause");
                system("cls");
            }

            break;
        case 3:
            if(flag1)
            {
                pNotasAux=al_clone(pNotas);
                ecualizar(pNotasAux);
                printearNotas(pNotasAux);
                system("pause");
                system("cls");
            }
            else
            {
                printf("Para acceder a esta opcion primero debe acceder a la opcion 1\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if(flag1)
            {
                corregir(pNotas);
                printf("Corregido\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Para acceder a esta opcion primero debe acceder a la opcion 1\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
