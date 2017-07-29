#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{

    /*
    id,first_name,last_name,is_empty
    1,Eric,Knight,false
    */
    int retorno=-1;
    int firstTime=1;
    Employee *pEmployee;
    char id[256],first_name[256],last_name[256],is_empty[256];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,first_name,last_name,is_empty);
            if(firstTime){firstTime=0;continue;} // Salto la primera
            pEmployee = employee_new();
            employee_setId(pEmployee,atoi(id));
            employee_setName(pEmployee,first_name);
            al_add(pArrayListEmployee,pEmployee);
        }
        //printf("%d" , al_len(pArrayListEmployee));
    }
    return retorno;
}
