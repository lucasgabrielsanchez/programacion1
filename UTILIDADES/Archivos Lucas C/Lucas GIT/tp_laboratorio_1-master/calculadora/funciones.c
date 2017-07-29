#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma(int a, int b)
{
    int resultado = a + b;
    return resultado;
}

int resta(int a, int b)
{
    int resultado = a - b;
    return resultado;
}

int multip(int a, int b)
{
    int resultado = a * b;
    return resultado;
}

int division(int a, int b)
{
    int resultado = a / b;
    return resultado;
}

int valOpMen(char error[], int desde, int hasta)
{
    int op;
    char respuesta;

    do
    {
        //system("cls");
        scanf("%d",&op);

        if(op <= hasta && op >= desde)
        {
            respuesta='n';
        }
        else
        {
            //system("cls");
            printf("%s",error);
            fflush(stdin);
            scanf("%c",&respuesta);
            op=-1;
        }

     }
        while(respuesta=='s');

         return op;



}

int factorial(int a) //factorial por metodo de recursividad
{
    int aux;
    if(a==0)
    {
       return 1;
    }

    aux = a * factorial(a-1);
    return (aux);
}



