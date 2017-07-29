#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"

void getString(char mensaje[],char destino[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", destino);
}

void inicializarArrayInt(EPersona persona[],int cantidad_de_elementos,int valor)
{
    int m;
    for(m=0;m < cantidad_de_elementos; m++)
    {
        persona[m].estado = valor;
    }
}

int buscarValorPosicion(EPersona persona[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(persona[i].estado == valor)
        {
            return i;
        }
    }
    return -2;
}

int opcionMenu()
{
    int opcion;

    system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        return opcion;
}

void hardcodear(EPersona persona[],int cantAux)
{
    char dniAux[10][20]={"50123456","45456789","43789456","40456123","35321654","30951753","25753159","20357951","15159753","10789321"};
    char nombreAux[10][50]={"Juana","Pedro","Marcela","Vanina","Daniel","Diana","Facundo","Laura","Lautaro","Andres"};
    int estadoAux[10]={1,1,1,1,1,1,1,1,1,1};
    int edadAux[10]={10,15,18,25,30,36,40,45,50,55};
    int i;

    for(i=0;i<cantAux;i++)
    {
        strcpy(persona[i].dni,dniAux[i]);
        strcpy(persona[i].nombre,nombreAux[i]);
        persona[i].estado=estadoAux[i];
        persona[i].edad=edadAux[i];
    }
}

void OrdenarNombres(EPersona persona[],int C)
{
    int i=0;
    int j=0;
    EPersona personaAux;
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
           printf("nombre-->%s DNI:-->%s Edad:-->%d Estado:-->%d\n",persona[i].nombre,persona[i].dni,persona[i].edad,persona[i].estado);
        }

    }
}

void altaPersona(EPersona persona[],int indice,int estado)
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
            printf("Nombre invalido. Debe ingresar nombre entre 1 y 50 caracteres.\nDesea continuar? s/n: ");
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
            printf("Dato ingresado invalido. Edad permitida entre 1 y 100.\nDesea continuar? s/n: ");
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
            printf("Debe ingresar DNI valido y sin puntos.\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }

    if(seguir=='s')
    {
        persona[indice].estado=estado;
        printf("La persona --%s-- fue agregada con exito\n", persona[indice].nombre);
    }

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

void bajaPersona(EPersona persona[],int cant, int estado)
{
    int j = 0;
    int h = 0;
    int cmp;
    char dniStr[10];

    printf("Por favor introduzca el DNI de la persona que desea eliminar de la lista: \n");

            for(j=0; j<cant; j++)
            {
                if(persona[j].estado==1)
                {
                    printf("nombre-->%s DNI:-->%s Edad:-->%d Estado:-->%d\n",persona[j].nombre,persona[j].dni,persona[j].edad,persona[j].estado);

                }
            }

            fflush(stdin);
            gets(dniStr);



            for(h=0; h<cant; h++)
            {
                cmp = strcmp(persona[h].dni,dniStr);
                if (cmp == 0)
                {
                    printf("La persona --%s-- fue borrada con exito\n",persona[h].nombre);
                    persona[h].estado = estado;
                    system("pause");
                    break;
                }
                if (h == cant - 1)
                {
                printf("No existe el DNI ingresado\n");
                system("pause");
                }
            }
}

void OrdenarEdades(EPersona persona[],int C)
{
    int i=0;
    int j=0;
    EPersona personaAux;
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
           printf("nombre-->%s DNI:-->%s Edad:-->%d Estado:-->%d\n",persona[i].nombre,persona[i].dni,persona[i].edad,persona[i].estado);
        }

    }
}

