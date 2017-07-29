#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void mostrarMenu (char opciones[][100])
{
    int i = 0;
    char opcion[100];
    while (opciones[i][0] != '\0')
    {
        strcpy(opcion, opciones[i]);
        i++;
        printf("%d)- %s\n", i, opcion);
    }
}

int menu(char input[])
{
    int retorno=1;
    char opciones[7][100] = {{"LISTAR USUARIOS"},{"LISTAR TEMAS"},{"ESCUCHAR TEMA"},{"GUARDAR ESTADISTICA"},{"INFORMAR"},{"Salir"}, {'\0'}};
    char aux[256];
    char rta[10];
    mostrarMenu(opciones);
    gets(aux);
    while((esNumeroNatural(aux,1))||(!validarRangoDeEntero(atoi(aux),1,6)))
    {
        system("cls");
        strcpy(rta,reingresarDatos("Error debe ingresar un numero entre 1 y 6.","Desea reingresar opcion del menu?\nPresione 'si' para reingresar.Otra tecla para salir del programa"));
        if(!strcmp(rta,"si"))
        {
            system("cls");
            mostrarMenu(opciones);
            getString("Ingrese una opcion del menu por favor",aux);
        }
        else
        {
            system("cls");
            retorno=0;
            break;
        }
    }
    if((!esNumeroNatural(aux,1))||(validarRangoDeEntero(atoi(aux),1,8)))
    strcpy(input,aux);
    return retorno;
}

int esNumeroNatural(char numeros[],int limite)
{
    int i=0;
    int verdad=0;
    int cantidad=strlen(numeros);
    if(limite>=1)
    {
        while(numeros[i] != '\0'|| !cantidad)
        {
            if((cantidad>limite)||(numeros[i] < '0' || numeros[i] > '9'))
            {
                verdad=-1;
                break;
            }
            i++;
        }
    }
    return verdad;
}

void limpiar (char *cadena)
{
  char *p= strchr (cadena, '\n');
  if (p)
    *p = '\0';
}

int validarRangoDeEntero(int x,int desde,int hasta)
{
    int verdad=1;
    if(x<desde||x>hasta)
    {
        verdad=0;
    }
    return verdad;
}

char* reingresarDatos(char eMensaje[],char pregunta[])
{
    puts(eMensaje);
    puts(pregunta);
    fflush(stdin);
    char *aux=malloc(sizeof(char)*5);
    char *retorno=NULL;
    if(aux!=NULL)
    {
        retorno=aux;
        fgets(retorno,4,stdin);
        limpiar(retorno);
        strlwr(retorno);
    }
    else
    {
        pausa("No se pudo generar memoria para registrar su respuesta. Libere espacio en su memoria por favor.");
    }
    return retorno;
}

void pausa(char mensaje[])
{
    system("cls");
    puts(mensaje);
    system("pause");
    system("cls");
}

void getString (char message[],char entrada[])
{
    puts(message);
    fflush(stdin);
    fgets(entrada,55,stdin);
    limpiar(entrada);
}


