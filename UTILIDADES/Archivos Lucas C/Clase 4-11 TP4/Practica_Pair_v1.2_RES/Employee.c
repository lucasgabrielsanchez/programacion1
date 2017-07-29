#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno = 0;
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        if(strcmp(employee_getName(pEmployeeA),employee_getName(pEmployeeB)) > 0)
        {
            retorno = 1;
        }
        else if(strcmp(employee_getName(pEmployeeA),employee_getName(pEmployeeB)) < 0)
        {
            retorno = -1;
        }
    }
    return retorno;
}


void employee_print(Employee* this)
{

}


Employee* employee_new(void)
{
    Employee* returnAux = NULL;
    returnAux = malloc(sizeof(Employee));
    return returnAux;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}

int employee_getId(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;
}

int employee_setName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && strlen(name) > 0)
    {
        retorno = 0;
        strncpy(this->name,name,50);
    }
    return retorno;
}

char* employee_getName(Employee* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}

