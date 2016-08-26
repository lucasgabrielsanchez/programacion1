#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    int acumulador;
    int minimo;
    int maximo;
    contador = 0;
    acumulador = 0;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numero);
    minimo=numero;
    maximo=numero;
    acumulador=acumulador+numero;

    while(contador<4)
        {
        contador++;
        printf("Ingrese el siguiente numero: ");
        scanf("%d",&numero);
        acumulador=acumulador+numero;

        if(numero<minimo)
            {
            minimo=numero;
            }

        if(numero>maximo)
            {
            maximo=numero;
            }

        }

    printf("El maximo es: %i\n",maximo); //El simbolo \n sirve para saltar al siguiente renglon en el print.
    printf("El minimo es: %i\n",minimo);
    printf("El promedio es: %f\n", ((float)acumulador) / 5); //El float sirve para que el numero tambien muestre los que siguen luego de la coma.
                                                             //Si no me interesa que eso suceda y que muestre solo el entero, la linea seria printf("El promedio es: %i\n",acumulador / 5);


    return 0;
}
