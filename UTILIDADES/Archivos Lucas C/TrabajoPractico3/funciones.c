#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void altas(EMovie movie, FILE *parch)
{
    char aux[100];
    float auxn;

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(aux);
    valtam(aux,20);
    valtitulo(aux,movie,parch);
    strcpy(movie.titulo,aux);

    printf("Ingrese el genero: ");
    fflush(stdin);
    gets(aux);
    valtam(aux,20);
    strcpy(movie.genero,aux);

    printf("Ingrese la duracion en minutos: ");
    scanf("%f",&auxn);
    auxn=(int)valnum(auxn,0,180);
    movie.duracion=auxn;

    printf("Ingrese la descripcion: ");
    fflush(stdin);
    gets(aux);
    valtam(aux,50);
    strcpy(movie.descripcion,aux);

    printf("Ingrese el puntaje (1/10): ");
    scanf("%f",&auxn);
    auxn=valnum(auxn,0,10);
    movie.puntaje=auxn;

    printf("Ingrese el link de la imagen: ");
    fflush(stdin);
    gets(aux);
    valtam(aux,1000);
    strcpy(movie.link,aux);

    movie.estado=1;

    fseek(parch,0L,SEEK_END);
    fwrite(&movie,sizeof(EMovie),1,parch);

    return;
}

void modificar(EMovie movie, FILE *parch)
{
    char dato[20];
    char aux[100];
    float auxn;

    printf("Ingrese pelicula a modificar: ");
    fflush(stdin);
    gets(dato);

    rewind(parch);
    while(!feof(parch))
    {
        fread(&movie,sizeof(EMovie),1,parch);
        if(strcmp(dato, movie.titulo)==0)
        {
            printf("Ingrese el titulo de la pelicula: ");
            fflush(stdin);
            gets(aux);
            valtam(aux,20);
            valtitulo(aux,movie,parch);
            strcpy(movie.titulo,aux);

            printf("Ingrese el genero: ");
            fflush(stdin);
            gets(aux);
            valtam(aux,20);
            strcpy(movie.genero,aux);

            printf("Ingrese la duracion en minutos: ");
            scanf("%f",&auxn);
            auxn=(int)valnum(auxn,0,180);
            movie.duracion=auxn;

            printf("Ingrese la descripcion: ");
            fflush(stdin);
            gets(aux);
            valtam(aux,50);
            strcpy(movie.descripcion,aux);

            printf("Ingrese el puntaje (1/10): ");
            scanf("%f",&auxn);
            auxn=valnum(auxn,0,10);
            movie.puntaje=auxn;

            printf("Ingrese el link de la imagen: ");
            fflush(stdin);
            gets(aux);
            valtam(aux,1000);
            strcpy(movie.link,aux);

            movie.estado=1;

            fseek(parch,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,parch);
            break;
        }
    }
    return;
}

void eliminar(EMovie movie, FILE *parch)
{
    char dato[20];

    printf("Ingrese pelicula a eliminar: ");
    fflush(stdin);
    gets(dato);

    rewind(parch);
    while(!feof(parch))
    {
        fread(&movie,sizeof(EMovie),1,parch);
        if(stricmp(dato, movie.titulo)==0)
        {
            strcpy(movie.titulo,"\0");
            movie.estado=0;

            fseek(parch,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&movie,sizeof(EMovie),1,parch);
            break;
        }
    }
    return;
}

void valtam(char x[], int tam)
{
    while(strlen(x)>tam-1)
    {
        printf("Error, reingrese una cadena que no exeda %d caracteres: ", tam-1);
        fflush(stdin);
        gets(x);
    }
}

float valnum(float cant, int min, int max)
{
    while(cant<=min||cant>max)
    {
        printf("Ingrese una cantidad entre %d y %d: ",min,max);
        scanf("%f",&cant);
    }
    return cant;
}

void valtitulo(char x[], EMovie movie, FILE *parch)
{
    rewind(parch);
    while(!feof(parch))
    {
        fread(&movie,sizeof(EMovie),1,parch);
        while(stricmp(x, movie.titulo)==0)
        {
            printf("Esta pelicula ya fue ingresada, ingresela nuevamente: ");
            fflush(stdin);
            gets(x);
            valtam(x,20);
        }
    }
}

void generarPagina(FILE *parch, EMovie movie)
{

    FILE *parchHtml;

    char bloque1[]="<!DOCTYPE html><html><head><title>Tp3</title></head><body><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char bloque2[]="alt=''></a><h3><a href='#'>";
    char bloque3[]="</h3><ul><li>Género:";
    char bloque4[]="</li><li>Puntaje:";
    char bloque5[]="</li><li>Duración:";
    char bloque6[]="</li></ul><p>";
    char bloque7[]="</p></article></html></body>";

    parchHtml = fopen("archivo.html", "w");

    fprintf(parchHtml, "%s\n", bloque1);

    rewind(parch);
    while(!feof(parch))
    {
        fread(&movie,sizeof(EMovie),1,parch);
        if(movie.estado==1)
            fprintf(parchHtml, "%s%s%s%s%s%s%.02f%s%d%s%s%s\n", movie.link, bloque2, movie.titulo, bloque3, movie.genero, bloque4, movie.puntaje,bloque5,movie.duracion,bloque6,movie.descripcion,bloque7);
    }

    fprintf(parchHtml, "%s", bloque7);

    fclose(parch);

}
