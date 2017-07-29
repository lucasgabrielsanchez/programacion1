#include <stdio.h>
#include <stdlib.h>

void *intercambia (int *x, int *z  );

int main()
{
    //printf ("%x\n",&intercambia);

    int a = 7,b = 8;

    printf("a = %d - b = %d\n",a,b);

    intercambia(&a,&b);

    printf("a = %d - b = %d\n",a,b);

    return 0;
}

void *intercambia (int *x, int *z)
{
    int aux;

    aux = *x;
    *x = *z;
    *z = aux;
}
