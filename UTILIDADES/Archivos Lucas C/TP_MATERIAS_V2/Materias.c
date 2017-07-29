#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Materias.h"
#include "ArrayList.h"
#include "Controller.h"

static int id = 0;

int materias_append (Materias* this, char* name, char* career, int hours, int classes, int cuatrimestre, int correlativas[], int cantCorrelativas)
{
    int retorno = -1;

    if(this != NULL)
    {
        materias_setName(this, name);
        materias_setCareer(this, career);
        materias_setHours(this, hours);
        materias_setClasses(this, classes);
        materias_setCorrelativas(this, correlativas, cantCorrelativas);
        materias_setCuatrimestre(this, cuatrimestre);

        retorno = 0;
    }
    return retorno;
}

int materias_getStaticId()
{
    id++;
    return id;
}

Materias* materias_new()
{
    Materias* returnAux = NULL;
    returnAux = (Materias*)malloc(sizeof(Materias));
    return returnAux;
}

int materias_setId(Materias* this, int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int materias_setHours(Materias* this, int hours)
{
    int retorno = -1;
    if(this != NULL && hours > 0)
    {
        this->hours = hours;
        retorno = 0;
    }
    return retorno;
}

int materias_setClasses(Materias* this, int classes)
{
    int retorno = -1;
    if(this != NULL && classes > 0)
    {
        this->classes = classes;
        retorno = 0;
    }
    return retorno;
}

int materias_setCorrelativas(Materias* this, int correlativas[], int cantCorrelativas)
{
    int retorno = -1, i = 0;
    //printf("CANTIDAD ELEMENTOS: %d \n", cantidad);
    if(this != NULL)
    {
        for (i= 0; i<cantCorrelativas; i++)
        {
            this->correlativas[i] = correlativas[i];
            printf("SET: %d \n", correlativas[i]);
        }
        this->cantCorrelativas = cantCorrelativas;
        retorno = 0;
    }
    return retorno;
}

int materias_setCuatrimestre(Materias* this, int cuatrimestre)
{
    int retorno = -1;
    if(this != NULL && cuatrimestre > 0)
    {
        this->cuatrimestre = cuatrimestre;
        retorno = 0;
    }
    return retorno;
}

int materias_setName(Materias* this, char* name)
{
    int retorno = -1;
    if(this != NULL && strlen(name) > 0)
    {
        strcpy(this->name, name);
        //this->name = name;
        retorno = 0;
    }
    return retorno;
}

int materias_setCareer(Materias* this, char* career)
{
    int retorno = -1;
    if(this != NULL && strlen(career) > 0)
    {
        strcpy(this->career, career);
        retorno = 0;
    }
    return retorno;
}

int materias_getId(Materias* this)
{
    if(this!= NULL)
        return this->id;
}

char* materias_getName(Materias* this)
{
    if(this != NULL)
        return this->name;
}

char* materias_getCareer(Materias* this)
{
    if(this != NULL)
        return this->career;
}

int materias_getClasses(Materias* this)
{
    if(this!= NULL)
        return this->classes;
}

int materias_getCuatrimestre(Materias* this)
{
    if(this!= NULL)
        return this->cuatrimestre;
}

int* materias_getCorrelativas(Materias* this)
{
    if(this!= NULL)
        return this->correlativas[0];
}
