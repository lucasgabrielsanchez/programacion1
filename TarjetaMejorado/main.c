#include "Includes.h"

int main()
{
    system("MODE CON: LINES=2000");
    ArrayList *pTarjetas = al_newArrayList();
    int opcion;
    char seguir = 's';

    cargaTarjeta(pTarjetas);

    while(seguir == 's')
    {
        opcion = menu("1- Listar clientes con todos los datos validos\n2- Listar clientes con MasterCard validas\n3- Listar clientes con Visa validas\n4- Listar clientes con America validas\n5- Listar clientes con datos invalidos\n6- Salir\n\n","Opcion ingresada incorrecta\n",1,6);

        switch (opcion)
        {
        case 1:
            printearValidos(pTarjetas);
            system("pause");
            system("cls");
            break;
        case 2:
            printearPorTipo(pTarjetas,MASTER);
            system("pause");
            system("cls");
            break;
        case 3:
            printearPorTipo(pTarjetas,VISA);
            system("pause");
            system("cls");
            break;
        case 4:
            printearPorTipo(pTarjetas,AMERICAN);
            system("pause");
            system("cls");
            break;
        case 5:
            printearPorTipo(pTarjetas,INVALIDA);
            system("pause");
            system("cls");
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }


    return 0;
}
