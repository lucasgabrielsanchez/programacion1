#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define C 20
int main()
{
    EPersona lista[C];
    char seguir='s';
    int opcion=0, flag=0;

    inicializar(lista);

    while(seguir=='s')
    {
        system("cls");
        opcion=menu();

        switch(opcion)
        {
            case 1:
                altas(lista);
                flag=1;
                system("pause");
                break;
            case 2:
                if(flag==1)
                {
                    bajas(lista);
                }
                system("pause");
                break;
            case 3:
                if(flag==1)
                {
                    imprimir(lista);
                }
                system("pause");
                break;
            case 4:
                if(flag==1)
                {
                    grafico(lista);
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                seguir = salir(lista);
                break;
        }
    }

    return 0;
}
