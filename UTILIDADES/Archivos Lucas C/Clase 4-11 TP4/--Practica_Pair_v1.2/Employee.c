#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"





void employee_print(Employee* this)
{
    printf("ID:%4d Name: %-15s Last Name: %15s\n",
               this->id,
               this->name,
               this->lastName);
}

void employee_printAll(ArrayList* this)
{
    int i=0;
    Employee* e;
    for (i=0; i<this->len(this); i++)
    {
        e= (Employee*)al_get(this, i);
        employee_print(e);
    }
}


Employee* employee_new(int id, char name[],char lastName[])
{
    Employee* returnAux = NULL;

    returnAux=(Employee*)malloc(sizeof(Employee));
    returnAux->id=id;
    strcpy(returnAux->name,name);
    strcpy(returnAux->lastName,lastName);

    return returnAux;
}

void employee_delete(Employee* this)
{

}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}

Employee* employee_altaEmpleado()
{
    char id[50];
    char name[50];
    char lastName[50];
Employee* e;

    printf("Ingrese el Id: ");
    fflush(stdin);
    gets(id);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(name);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(lastName);

    e=employee_new(atoi(id),name,lastName);
    e->isEmpty=1;

    return e;

}

Employee* buscarPorId (ArrayList*this)
{
    int i= 0,flag=0, id;
    Employee* e;

    printf("Ingrese el Id del empleado que desea eliminar: ");
    scanf("%d",&id);
    for(i=0;i<this->len(this);i++)
    {
        e= (Employee*)this->get(this, i);
        if(e-> id == id)
        {
            flag=1;
            break;
        }
    }

    return e;
}

void Employee_bajaEmpleado(ArrayList*this, Employee *empleado)
{
    int indice;
    Employee *empleadoAux;
    empleadoAux= buscarPorId (this);
    //printf("%d - %s - %s - %d",e->id, e->name,e->lastName,e->isEmpty);

    if(empleadoAux!=NULL)
    {
        indice= al_indexOf(this, empleadoAux);
        empleadoAux=(Employee*)al_pop(this, indice);
        printf("El empleado:\n Id-> %d || Nombre-> %s || Apellido-> %s, \n fue eliminado con exito.",empleadoAux->id,empleadoAux->name,empleadoAux->lastName);
    }

}

void Employee_subList(ArrayList *this)
{
    Employee *empleado;
    int from, to;
    ArrayList* pSubLista;


    printf("Ingrese desde donde listar: ");
    scanf("%d",&from);
    from--;

    printf("Ingrese hasta donde listar: ");
    scanf("%d",&to);
    to--;

    pSubLista = this->subList(this,from,to);
    employee_printAll(pSubLista);

    /*contiene= this->contains(this, (Employee*)empleado);
    if(contiene==1)
    {
        this->subList(this,from,to);
    }
    else
    {
        printf("no contiene empleados");
    }*/

}

void Employee_ordenarPorNombre (ArrayList* this)
{
    int i,j;
    void* empleadoA, *empleadoB;

    for(i=0;i<(this->len(this))-1;i++)
    {
        for(j=i+1;j<this->len(this);j++)
        {
            empleadoA=this->get(this,i);
            empleadoB=this->get(this,j);

            al_sort(this, employee_compare(empleadoA ,empleadoB), 1);
        }
    }
    employee_print(this);
}

int employee_compare(Employee* A, Employee* B)
{
    int retorno=-1;
    if(stricmp(A->name,B->name)>0)
    {
        retorno=1;
    }
     if(stricmp(A->name,B->name)<0)
    {
        retorno=0;
    }
    return retorno;

}



