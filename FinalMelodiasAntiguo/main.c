#include "Includes.h"

int main()
{
    system("MODE CON: LINES=2000");
    int opcion;
    char seguir = 's';
    ArrayList *pNotas = al_newArrayList();

    while(seguir == 's')
    {
        opcion = menu("1- Leer archivo\n2- Reproducir\n3- Ecualizar\n4- Correccion\n5- Salir\n\n","Opcion ingresada invalida\n",1,5);
        switch (opcion)
        {
        case 1:
            cargaNotas(pNotas);
            break;
        case 2:
            printearNotas(pNotas);
            system("pause");
            break;
        case 3:
            Ecualizar(pNotas);
            printearNotas(pNotas);
            system("pause");
            al_sort(pNotas, compararNotas,1);
            printearNotas(pNotas);
            system("pause");
            break;
        case 4:
            Corregir(pNotas);
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }

    return 0;
}
