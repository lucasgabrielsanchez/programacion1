#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define C 20

//int obtenerEspacioLibre(EPersona lista[])
int menu()
{
    int opcion;

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    scanf("%d",&opcion);

    while(opcion<=0||opcion>6)
    {
        printf("\nIngrese una opcion entre 1 y 5: ");
        scanf("%d",&opcion);
    }
    return opcion;
}/**funcion del menu en el que se ingresa la funcion y valida la opcion ingresada**/

void inicializar(EPersona lista[])
{
    int i;
    for(i=0;i<C;i++)
    {
        strcpy(lista[i].nombre,"\0");
        lista[i].dni=0;
        lista[i].edad=0;
        lista[i].estado=0;
    }
}/**funcion que inicializa todos los datos en 0 para que no haya basura y estropee el programa**/

void altas(EPersona lista[])
{
    int i, indice=-1, flag=0, edad;
    long int dni;
    char aux[75];

    indice=libre(lista);

    if(indice!=-1)
    {
        printf("Ingrese dni: ");
        scanf("%ld",&dni);

        while(dni<1000000||dni>99000000)
        {
            printf("Ingrese un dni correcto: ");
            scanf("%ld",&dni);
        }

        for(i=0;i<C;i++)
        {
            while(dni==lista[i].dni)
            {
                printf("Ingrese dni nuevamente: ");
                scanf("%ld",&dni);

                while(dni<1000000||dni>99000000)
                {
                    printf("Ingrese un dni correcto: ");
                    scanf("%ld",&dni);
                }
            }
        }

        if(flag==0)
        {
            lista[indice].dni=dni;
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(aux);
            valtam(aux,50);
            strcpy(lista[indice].nombre, aux);
            printf("Ingrese su edad: ");
            scanf("%d",&edad);

            while(edad<1 || edad>99)
            {
                printf("Ingrese su edad creible: ");
                scanf("%d",&edad);
            }

            lista[indice].edad=edad;
            lista[indice].estado=1;
        }
    }
    else
        printf("No hay espacio libre");
}/**Funcion en la que se ingresa los datos y se los valida**/

void imprimir(EPersona lista[])
{
    int i, j;
    EPersona aux;
    for(i=0;i<C-1;i++)
    {
        if(lista[i].estado==1)
        {
            for(j=i+1;j<C;j++)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }
        }
    }
    for(i=0;i<C;i++)
    {
        if(lista[i].estado!=0)
            printf("%ld, %s, %d\n",lista[i].dni,lista[i].nombre, lista[i].edad);
    }
}/** Primero ordena alfabeticamente de forma ascendente y luego imprime por consola**/

int buscar(EPersona lista[C], long int dni)
{
    int i, flag=0;

    for(i=0;i<C;i++)
    {
        if(lista[i].dni==dni)
        {
            flag=1;
            break;
        }
    }
    return flag;
}/**busca el dni ingresado en la funcion bajas y retorna un 1 si lo encontro**/

void bajas(EPersona lista[])
{
    int i, flag=0;
    long int dni;
    char rta='n';

    printf("Ingrese dni a borrar: ");
    scanf("%ld",&dni);

    flag=buscar(lista,dni);

    for(i=0;i<C;i++)
    {
        if(dni==lista[i].dni)
        {
            printf("Nombre: %s,DNI: %ld,Edad: %d",lista[i].nombre, lista[i].dni, lista[i].edad);
            printf("\nDesea borrarlo? <s/n>: ");
            rta=tolower(getch());

            rta=valsn(rta);
        }
    }
    if(flag && rta=='s')
    {

        for(i=0;i<C;i++)
        {
            if(dni==lista[i].dni)
            {
               // printf("Los datos son: %s, %ld, %d",lista[i].nombre, lista[i].dni);
                lista[i].edad=0;
                lista[i].dni=0;
                strcpy(lista[i].nombre,"\0");
                lista[i].estado=0;
                break;
            }
        }
    }

    else if(rta=='n')
        printf("\nVolviendo al menu.\n");
    else
        printf("\nEse dni no existe.\n");
}/** Al ingresar el dni lo busca en la funcion buscar, este retorna a flag un 1 si lo encuentra,
     ingresa, pregunta si quiere borrar el usuario, y de responder afirmativamente, lo hace, de
     lo contrario vuelve al menu**/


int libre(EPersona lista[])
{
    int i, indice=-1;

    for(i=0;i<C;i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }

    }
    return indice;
}/**Busca el primer espacio libre y retorna el indice a altas**/

void grafico(EPersona lista[])
{
    int i, c18=0, c19y35=0, cm35=0, mayor=0, flag=0;

    for(i=0;i<C;i++)
    {
        if(lista[i].estado!=0)
        {
            if(lista[i].edad<=18)
                c18++;

            else if(lista[i].edad>18 && lista[i].edad<=35)
                c19y35++;

            else
                cm35++;
        }
    }

    if(c18>=c19y35 && c18>=cm35)
        mayor=c18;

    else if(c19y35>=c18 && c19y35>=cm35)
        mayor=c19y35;

    else
        mayor=cm35;

    for(i=mayor;i>0;i--)
    {
        if(c18>=mayor)
            printf("*");

        if(c19y35>=mayor)
        {
            printf("\t*");
            flag=1;
        }

        if(cm35>=mayor)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag)
                printf("\t*");
        }

        printf("\n");
        mayor--;
    }
    printf("< 18/19<>35/> 35");
}/**Primero crea los contadores de las distintas edades, luego busca el mayor contador y lo usa para
    realizar la cuenta regresiva del for**/



void valtam(char x[], int tam)
{
    while(strlen(x)>tam-1)
    {
        printf("Error, reingrese una cadena que no exeda %d caracteres: ", tam-1);
        fflush(stdin);
        gets(x);
    }
}
/**Recibe el auxiliar del nombre que se encuentra en altas y valida para que no supere 50 caracteres**/

char salir(EPersona lista[])
{
    char rta='n';

    printf("\nDesea salir? <s/n>: ");
    rta=tolower(getch());

    rta=valsn(rta);

    if(rta=='s')
        rta='n';

    else
        rta='s';

    return rta;
}/**pregunta y valida la respuesta para salir del programa o no**/

char valsn(char rta)
{
    while(rta!='s'&&rta!='n')
    {
        printf("\nIngrese solo s o n: ");
        rta=tolower(getch());
    }

    return rta;
}/**Recibe, valida y envia la respuesta a las funciones salir y bajas**/
