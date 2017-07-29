#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b);

int main()
{
    int(*p)(int , int);
    p=suma;
    int i;
//    for(i=0;i<5;++i)
//    {
//        printf("%d\n",i);
//    }
    int *k;
    k=malloc(sizeof(int)*5);
    for(i=0;i<5;i++)
    {
        *(k+i)=i*2;
    }
    for(i=0;i<5;i++)
    {
//        printf("%d\n",k[i]);
        printf("%d\n",k+=3);

    }
    *(k++)=6;

    printf("%d",p(5,5));
    return 0;
}
int suma (int a, int b)
{
    int retorno=a+b;
    return retorno;
}
