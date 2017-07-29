#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int i;
    FILE *pFile;
    ArrayList *pArrayEmployee;
    Employee *pEmployee;
    pArrayEmployee = al_newArrayList();

    pFile = fopen("data.csv","r");
    parserEmployee(pFile ,pArrayEmployee );
    for(i=0;i<al_len(pArrayEmployee);i++)
    {
        pEmployee = al_get(pArrayEmployee,i);
        //printf("%d-%s\n",employee_getId(pEmployee),employee_getName(pEmployee));
    }

    al_sort(pArrayEmployee,employee_compare,0);


    for(i=al_len(pArrayEmployee)-20; i > 0 ; i--)
    {
        employee_delete(al_pop(pArrayEmployee,0));
       // printf("%d\n",al_len(pArrayEmployee));
    }



    for(i=0;i<al_len(pArrayEmployee);i++)
    {
        pEmployee = al_get(pArrayEmployee,i);
        printf("%d-%s\n",employee_getId(pEmployee),employee_getName(pEmployee));
    }

    fclose(pFile);








    return 0;
}
