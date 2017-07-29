#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void hardcodeo(ePersona persona[],int Caux)
{
    char dniAux[10][20]={"50123456","45456789","43789456","40456123","35321654","30951753","25753159","20357951","15159753","10789321"};
    char nombreAux[10][50]={"Juana","Pedro","Marcela","Vanina","Daniel","Diana","Facundo","Laura","Lautaro","Andres"};
    int estadoAux[10]={1,1,1,1,1,1,1,1,1,1};
    int edadAux[10]={10,15,18,25,30,36,40,45,50,55};
    int i=0;

    for(i==0;i<Caux;i++)
    {
        strcpy(persona[i].dni,dniAux[i]);
        strcpy(persona[i].nombre,nombreAux[i]);
        persona[i].estado=estadoAux[i];
        persona[i].edad=edadAux[i];
    }
}


int validarMenu (eMenu opciones)
{
    int opcion;
    char respuesta='s';

    do
    {
        printf(opciones.menu);
        fflush(stdin);
        scanf("%d",&opcion);

        if(opcion>=opciones.desde && opcion<=opciones.hasta)
        {
            break;
        }
        else
        {
            system("cls");
            printf("%s",opciones.error);
            fflush(stdin);
            scanf("%c",&respuesta);
            opcion=-1;
        }
    }
    while(respuesta=='s');

    return opcion;
}

void asignarEstado (ePersona persona[],int C,int estado)
{
    int i;
    for (i=0;i<C;i++)
    {
        persona[i].estado=estado;
    }
}

int buscarIndiceLibre (ePersona persona[],int C)
{
    int i = 0;
    int flag=0;

    for(i=0;i<C;i++)
    {
        if(persona[i].estado==-1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        return i;
    }else
    {
        return -1;
    }
}

void altaPersona(ePersona persona[],int indice,int estado)
{
    eValidar cadena;
    char seguir='s';

    while(seguir=='s')
    {
        cadena.minimo=1;
        cadena.maximo=50;
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(cadena.buffer);

        if(validarRango(cadena)==1)
        {
            strcpy(persona[indice].nombre,cadena.buffer);
            break;
        }
        else
        {
            printf("Nombre invalido. Debe ingresar nombre entre 1 y 50 caracteres.\n¿Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }

    while(seguir=='s')
    {
        printf("Ingrese edad: ");
        fflush(stdin);
        gets(cadena.buffer);
        cadena.minimo=1;
        cadena.maximo=100;

        if(validarRangoEdad(cadena)==1)
        {
            persona[indice].edad = atoi(cadena.buffer);
            break;
        }
        else
        {
            printf("Dato ingresado invalido. Edad permitida entre 1 y 100.¿Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }

    while(seguir=='s')
    {
        cadena.minimo=1000000;
        cadena.maximo=99000000;
        printf("Ingrese DNI: ");
        fflush(stdin);
        gets(cadena.buffer);

        if(verificarDNI(cadena)==1)
        {
            strcpy(persona[indice].dni,cadena.buffer);
            break;
        }
        else
        {
            printf("Debe ingresar DNI valido, sin puntos.\n¿Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }

    if(seguir=='s')
    {
        persona[indice].estado=estado;
    }
}


int validarRangoEdad(eValidar cadena)
{
    int edad;
    edad=atoi(cadena.buffer);
    if(edad>=cadena.minimo && edad<=cadena.maximo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificarDNI(eValidar cadena)
{
    int dni;
    if((strlen(cadena.buffer))==8)
    {
        dni=atoi(cadena.buffer);

        if (dni>=cadena.minimo && dni<=cadena.maximo)
        {
          return 1;
        }
    }
    return 0;
}

int validarRango(eValidar cadena)
{
    if((strlen(cadena.buffer)>= cadena.minimo) && (strlen(cadena.buffer)<=cadena.maximo))
    {
        if(!validarStr(cadena))
        {
            return 0;
        }
    }
    return 1;
}

int validarStr(eValidar cadena)
{
    int i = 0;
    char letra;

    while(cadena.buffer[i] != '\0')
    {
        letra=(char)cadena.buffer[i];
        if(!isalpha(letra))
        {
            return 0;
        }
       i++;
    }
    return 1;
}


int buscarPorDni(ePersona persona[], char dni[], int C)
{
    int i;
    int flag = 0;

    for(i=0;i<C;i++)
    {
        if(strcmp(persona[i].dni,dni)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void bajaPersona (ePersona persona[],int i,int indice)
{
    persona[indice].estado=0;
    printf("Persona eliminada exitosamente.\n\n");
}


void listarPersonas(ePersona persona[],int C)
{
    int i=0;
    int j=0;
    ePersona personaAux;
    printf("DNI\t\tNOMBRE\tEDAD\tESTADO\n");
    for(i=0;i<C-1;i++)
    {
        if(persona[i].estado==1)
        {
            for(j=i+1;j<C;j++)
            {
                if(persona[j].estado==1)
                {
                    if (strcmp(persona[i].nombre,persona[j].nombre)>0)
                    {
                        personaAux=persona[i];
                        persona[i]=persona[j];
                        persona[j]=personaAux;
                    }
                }
            }
        }
    }
    for(i=0;i<C;i++)
    {
        if(persona[i].estado==1)
        {
           printf("%s\t%s\t%d\t%d\n",persona[i].dni,persona[i].nombre,persona[i].edad,persona[i].estado);
        }

    }
}

int contarPorEdad (ePersona persona[],int C,int* menor18,int* de18a35,int* mayor35)
{
    int i;
    for (i=0;i<C;i++)
    {
        if(persona[i].estado==1 && persona[i].edad<18)
        {
            *menor18= *menor18+1;
        }
        else if (persona[i].estado==1 && persona[i].edad>35)
        {
            *mayor35=*mayor35+1;
        }
        else if (persona[i].estado==1 && persona[i].edad>=18 && persona[i].edad<=35)
        {
            *de18a35=*de18a35+1;
        }
    }

    return 0;
}


void graficar (int cantidadMenor18,int cantidadDe18a35, int cantidadMayor35)
{
    int tope=0;
    int i=0;

    if(cantidadMenor18>=cantidadMayor35 && cantidadMenor18>=cantidadDe18a35)
    {
        tope=cantidadMenor18;
    }
    else if(cantidadMayor35>=cantidadMenor18 && cantidadMayor35>=cantidadDe18a35)
    {
        tope=cantidadMayor35;
    }
    else if(cantidadDe18a35>=cantidadMenor18 && cantidadDe18a35>=cantidadMayor35)
    {
        tope=cantidadDe18a35;
    }

    for (i=tope;i>0;i--)
    {
        printf("%d|",i);
        int flag=0;

        if(i<=cantidadMenor18)
        {
            printf("*");
        }
        if (i<=cantidadDe18a35)
        {
            printf("\t*");
            flag=1;
        }
        if (i<=cantidadMayor35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("<18\t18-35\t>35");
    printf("\n");
    printf("%d\t %d \t%d\n",cantidadMenor18,cantidadDe18a35,cantidadMayor35);
    printf("\n");
}


