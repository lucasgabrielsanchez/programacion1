#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Controller.h"
#include "utn.h"

int main()
{
    ArrayList* pListMaterias = NULL;
    pListMaterias = al_newArrayList();
    controller_getFile(pListMaterias);
    controller_mock(pListMaterias);
    if(pListMaterias != NULL)
    {
        char seguir='s';
        int option = 0, lowLimit = 1, hiLimit = 6, attempt = 2;
        char errorMessage[]="Opcion invalida. Debe ingresar una opcion entre 1 y 6.";

        char menu[]=
            "\n1- Agregar materia.\
                \n2- Modificar materia.\
                \n3- Eliminar materia.\
                \n4- Listar todas las materias.\
                \n5- Listar por cuatrimestre.\
                \n6- Guardar y Salir.\
                \nINGRESE UNA OPCION: ";
        do
        {
            system("pause");
            system("cls");
            if(!getValidInt(menu,errorMessage, &option,lowLimit, hiLimit, attempt ))
            {
                switch (option)
                {
                case 1://ALTA MATERIA
                    controller_altaMateria(pListMaterias);
                    break;

                case 2://MODIFICAR MATERIA
                    system("cls");
                    controller_printMateriaId(pListMaterias);
                    controller_modifyMateria(pListMaterias);
                    break;

                case 3://BAJA MATERIA
                    system("cls");
                    controller_printMateriaId(pListMaterias);
                    controller_delete(pListMaterias);
                    break;

                case 4:
                    system("cls");
                    controller_printAll(pListMaterias);
                    break;

                case 5:
                    system("cls");
                    //materias_listByCuatrimestre(pListMaterias);
                    break;

                case 6:
                    controller_saveFile(pListMaterias);
                    // pListMaterias->clear(pListMaterias);
                    // pListMaterias->deleteArrayList(pListMaterias);
                    seguir='n';
                    break;

                }
            }
            else
            {
                seguir='n';
            }
        }
        while(seguir=='s');
    }
    else
    {
        printf("No hay suficiente espacio en memoria.");
    }
    return 0;
}

