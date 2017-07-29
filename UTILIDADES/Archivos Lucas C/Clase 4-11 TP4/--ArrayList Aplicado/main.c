#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

int main()
{

    void* auxEmployee;
    Employee* empleado;
    ArrayList* ArrayListEmpleados;

    auxEmployee = employee_altaEmpleado();

    employee_print(auxEmployee);

    ArrayListEmpleados = al_newArrayList();

    printf("%d\n",al_len(ArrayListEmpleados));

    system("pause");

    al_add(ArrayListEmpleados,auxEmployee);

    printf("%d\n",al_len(ArrayListEmpleados));

    system("pause");


    return 0;
}
