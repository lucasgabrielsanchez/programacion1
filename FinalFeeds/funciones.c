#include "includes.h"

int esNumerico(char stringIn[])
{
    int i;
    int retorno = 1;

    //Si el string está vacío, devuelvo un "falso".
    if(strlen(stringIn) == 0)
    {
        retorno=0;
    }
    else
    {
        for(i=0; i<strlen(stringIn); i++)
        {
            if(stringIn[i] < '0' || stringIn[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int esNumericoFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

int esEdad(char edad[])
{
    int auxEdad;

    auxEdad = atoi(edad);

    if(auxEdad < 1 || auxEdad > 99)
    {
        return 0;
    }

    return 1;
}

int esDni(char auxDni[])
{
    int x;

    x = strlen(auxDni);

    if(x!=8)
    {
        return 0;
    }
    else
    {
        if(!esNumerico(auxDni))
        {
            return 0;
        }
    }

    return 1;
}

int esSoloLetras(char stringIn[])
{
    int i;
    int retorno=1;

    if(strlen(stringIn) == 0)
    {
        retorno = 0;
    }
    else
    {
        for(i=0; i<strlen(stringIn); i++)
        {
            if((stringIn[i]<'a' || stringIn[i]>'z') && (stringIn[i]<'A' || stringIn[i]>'Z'))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

int esMail(char stringIn[])
{
    int i,contPuntos=0,contArrobas=0;
    int retorno=1;


    if(strlen(stringIn) == 0)
    {
        retorno=0;
    }
    else
    {
        for(i=0; i<strlen(stringIn); i++)
        {
            if(stringIn[i] == '@')
                contArrobas++;

            if(stringIn[i] == '.')
                contPuntos++;

            if(stringIn[i]!='@' && stringIn[i]!='.' && (stringIn[i]<'a' || stringIn[i]>'z') && (stringIn[i]<'A' || stringIn[i]>'Z'))
            {
                retorno = 0;
            }
        }
    }

    if(contArrobas>1 || contPuntos>1)
    {
        retorno = 0;
    }

    return retorno;
}

void arrayIntInverter(int arrayInt[], int cantElemArray)
{
    int k=0,i;
    int auxArrayInt[cantElemArray];

    //primero invierto los numeros en un array auxiliar
    for(i=cantElemArray-1; i>-1; i--)
    {
        auxArrayInt[k] = arrayInt[i];
        k++;
    }

    //luego igualo los elementos del array auxiliar en el original
    for(i=0; i<cantElemArray; i++)
    {
       arrayInt[i] = auxArrayInt[i];
    }
}

int arrayCharToArrayInt(char arrayStringIn[], int arrayIntOut[])
{
    int i;

    if(esNumerico(arrayStringIn))
    {
        for(i=0; i<strlen(arrayStringIn); i++)
        {
            arrayIntOut[i] = arrayStringIn[i] - '0';
        }
        return 1;
    }

    return 0;
}

int menu (char menuTexto[],char errorTexto[],int desde,int hasta)
{
    int op,aux;
    printf("%s",menuTexto);
    aux=scanf("%d",&op);
    fflush(stdin);
    while(aux==0 ||(op<desde||op>hasta))
    {
        printf("%s",errorTexto);
        fflush(stdin);
        aux=scanf("%d",&op);
    }
    return op;
}


