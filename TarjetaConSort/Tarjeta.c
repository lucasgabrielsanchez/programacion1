#include <stdio.h>
#include <stdlib.h>
#include "Tarjeta.h"
#include "ArrayList.h"
#include "string.h"
#include "funciones.h"

#define Visa 1
#define Amex 2
#define Master 3

Tarjeta* new_tarjeta()
{
    return (Tarjeta*)malloc(sizeof(Tarjeta));
}


int validarNumTarjetaSintactico(char arrayCharIn[])
{
    int auxArrayInt[strlen(arrayCharIn)];
    int acumInt = 0;
    int retorno=1;

    arrayCharIn = strrev(arrayCharIn);

    int i;

    arrayCharToArrayInt(arrayCharIn,auxArrayInt);

    for(i=0; i<strlen(arrayCharIn); i++)
    {
        ///i+1 porque necesito evaluar las posiciones pares de los elementos contenidos
        ///en el array y NO de los índices del mismo.
        if((i+1)%2 == 0)
        {
            auxArrayInt[i] *= 2;

            if (auxArrayInt[i]>9)
            {
                auxArrayInt[i] -= 9;
            }
        }

        acumInt += auxArrayInt[i];
    }
    if(acumInt%10 != 0)
    {
        retorno = 0;
    }

    return retorno;
}

int esVisa(char numTarjeta[])
{
    int retorno = 0;

    if((strlen(numTarjeta) == 13 || strlen(numTarjeta) == 16) && numTarjeta[0] == '4')
    {
       if(validarNumTarjetaSintactico(numTarjeta))
       {
           retorno = 1;
       }
    }
    return retorno;
}

int esAmex(char numTarjeta[])
{
    int retorno = 0;

    if(strlen(numTarjeta)== 15 && numTarjeta[0] == '3' && (numTarjeta[1] == '4' || numTarjeta[1] == '7'))
    {
       if(validarNumTarjetaSintactico(numTarjeta))
       {
           retorno = 1;
       }
    }
    return retorno;
}

int esMaster(char numTarjeta[])
{
    int retorno = 0;

    if(strlen(numTarjeta) == 16 && numTarjeta[0] == '5' && (numTarjeta[1] > '0' && numTarjeta[1] < '6'))
    {
       if(validarNumTarjetaSintactico(numTarjeta))
       {
           retorno = 1;
       }
    }
    return retorno;
}

void printearValidos(ArrayList *pTarjetas)
{
    int i;
    for(i=0; i<al_len(pTarjetas); i++)
    {
        Tarjeta *tarjetita = new_tarjeta();
        tarjetita = al_get(pTarjetas,i);
        if(strlen(tarjetita->error)==0)
        {
            switch(tarjetita->Tarjeta)
            {
            case Visa:
                printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\nTARJETA VISA\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
                break;
            case Amex:
                printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\nTARJETA AMEX\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
                break;
            default:
                printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\nTARJETA MASTER\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
                break;
            }
        }
    }
}

void printearMaster(ArrayList *pTarjetas)
{
    int i;
    for(i=0; i<al_len(pTarjetas); i++)
    {
        Tarjeta *tarjetita = new_tarjeta();
        tarjetita = al_get(pTarjetas,i);
        if(tarjetita->Tarjeta == Master)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
        }

    }
}

void printearVisa(ArrayList *pTarjetas)
{
    int i;
    for(i=0; i<al_len(pTarjetas); i++)
    {
        Tarjeta *tarjetita = new_tarjeta();
        tarjetita = al_get(pTarjetas,i);
        if(tarjetita->Tarjeta == Visa)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
        }

    }
}

void printearAmex(ArrayList *pTarjetas)
{
    int i;
    for(i=0; i<al_len(pTarjetas); i++)
    {
        Tarjeta *tarjetita = new_tarjeta();
        tarjetita = al_get(pTarjetas,i);
        if(tarjetita->Tarjeta == Amex)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
        }

    }
}

void printearInvalidos(ArrayList *pTarjetas)
{
    int i;
    for(i=0; i<al_len(pTarjetas); i++)
    {
        Tarjeta *tarjetita = new_tarjeta();
        tarjetita = al_get(pTarjetas,i);
        if(strlen(tarjetita->error)>1)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\nError: %s\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta,tarjetita->error);
        }

    }
}

///probando ordenamiento
int getTarjeta(Tarjeta* tarjetita)
{
    int retorno = -1;
    if(tarjetita != NULL)
    {
        retorno = tarjetita->Tarjeta;
    }
    return retorno;
}

///probando ordenamiento
int compararTarjetas(void* inputA, void* inputB)
{
    int returnAux = 0;
    if(inputA != NULL && inputB != NULL)
    {
        int tipoTarjetaA = getTarjeta(inputA);
        int tipoTarjetaB = getTarjeta(inputB);

        if(tipoTarjetaA>tipoTarjetaB)
        {
            returnAux=1;
        }
        else if(tipoTarjetaA<tipoTarjetaB)
        {
            returnAux=-1;
        }
    }
    return returnAux;
}

