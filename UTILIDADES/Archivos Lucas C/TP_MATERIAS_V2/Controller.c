#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Materias.h"
#include "ArrayList.h"
#include "Controller.h"
#include "utn.h"


void controller_mock(ArrayList* pListMaterias)
{
    int correlativas01[] = {0};
    int cantCorrelativas;
    cantCorrelativas = sizeof(correlativas01)/sizeof(int);
    printf("CANTIDAD ELEMENTOS: %d\n", cantCorrelativas);
    printf("hadcordeo01: %d\n", correlativas01[0]);
    Materias* m0=NULL;
    m0 = materias_new();
    materias_append (m0, "Programacion I","TP", 116, 28, 1, correlativas01, cantCorrelativas);
    Materias* m1=NULL;
    m1 = materias_new();
    materias_append (m1, "Laboratorio I","TP", 116, 28, 1, correlativas01, cantCorrelativas);
    //Materias* m2=NULL;
    //m2 = materias_new();
    //materias_append (m2, "Matematica I","TP", 87, 28, 1, &correlativas01);
    //Materias* m3=NULL;
    //m3 = materias_new();
    //materias_append (m3, "Ingles I","TP", 28, 14, 1, &correlativas01);
    //Materias* m4=NULL;
    //m4 = materias_new();
    //materias_append (m4, "SPD","TP", 46, 14, 1, &correlativas01);

    int correlativas02[] = {3,2};
    cantCorrelativas = sizeof(correlativas02)/sizeof(int);
    printf("CANTIDAD ELEMENTOS: %d\n", cantCorrelativas);
    printf("hadcordeo02: %d | %d\n", correlativas02[0],correlativas02[1]);
    Materias* m5=NULL;
    m5 = materias_new();
    materias_append (m5, "Estadistica","TP", 87, 28, 2, &correlativas02,cantCorrelativas);
    int correlativas03[] = {5};
    cantCorrelativas = sizeof(correlativas03)/sizeof(int);
    printf("CANTIDAD ELEMENTOS: %d\n", cantCorrelativas);
    printf("hadcordeo03: %d\n", correlativas03[0]);
    Materias* m6=NULL;
    m6 = materias_new();
    materias_append (m6, "Metodologia","TP", 28, 14, 2, &correlativas03,cantCorrelativas);
    //int correlativas06[] = {1,2};
    //Materias* m7=NULL;
    //m7 = materias_new();
    //materias_append (m7, "Laboratorio II","TP", 116, 28, 2, &correlativas06,len);
    //Materias* m8=NULL;
    //m8 = materias_new();
    //materias_append (m8, "Arquitectura","TP", 116, 28, 2, &correlativas03);
    //int correlativas07[] = {4};
    //printf("hadcordeo07: %d | %d\n", correlativas07[0],&correlativas07);
    //printf("\n");
    //Materias* m9=NULL;
    //m9 = materias_new();
    //materias_append (m9, "Ingles II","TP", 28, 14, 2, &correlativas07);
    //Materias* m10=NULL;
    //m10 = materias_new();
    //materias_append (m10, "Programacion II","TP", 116, 28, 2, &correlativas06);

    //Materias* m11=NULL;
    //m11 = materias_new();
    //materias_append (m11, "Investigacion","TP", 87, 28, 3, &correlativas01);
    //Materias* m12=NULL;
    //m12 = materias_new();
    //materias_append (m12, "Org Contable","TP", 28, 14, 3, &correlativas01);
    //Materias* m13=NULL;
    //m13 = materias_new();
    //materias_append (m13, "Laboratorio III","TP", 116, 28, 3, &correlativas01);
    //Materias* m14=NULL;
    //m14 = materias_new();
    //materias_append (m14, "Org Empresarial","TP", 116, 28, 3, &correlativas01);
    //Materias* m15=NULL;
    //m15 = materias_new();
    //materias_append (m15, "Programacion III","TP", 116, 28, 3, &correlativas01);

    m0->id = materias_getStaticId();
    m1->id = materias_getStaticId();
    //m2->id = materias_getStaticId();
    //m3->id = materias_getStaticId();
    //m4->id = materias_getStaticId();
    m5->id = materias_getStaticId();
    m6->id = materias_getStaticId();
    //m7->id = materias_getStaticId();
    //m8->id = materias_getStaticId();
    //m9->id = materias_getStaticId();
    //m10->id = materias_getStaticId();
    //m11->id = materias_getStaticId();
    // m12->id = materias_getStaticId();
    // m13->id = materias_getStaticId();
    // m14->id = materias_getStaticId();
    // m15->id = materias_getStaticId();

    pListMaterias->add(pListMaterias, m0);
    pListMaterias->add(pListMaterias, m1);
    //pListMaterias->add(pListMaterias, m2);
    //pListMaterias->add(pListMaterias, m3);
    //pListMaterias->add(pListMaterias, m4);
    pListMaterias->add(pListMaterias, m5);
    pListMaterias->add(pListMaterias, m6);
    //pListMaterias->add(pListMaterias, m7);
    //pListMaterias->add(pListMaterias, m8);
    //pListMaterias->add(pListMaterias, m9);
    //pListMaterias->add(pListMaterias, m10);
    //pListMaterias->add(pListMaterias, m11);
    //pListMaterias->add(pListMaterias, m12);
    //pListMaterias->add(pListMaterias, m13);
    //pListMaterias->add(pListMaterias, m14);
    //pListMaterias->add(pListMaterias, m15);
}


int controller_getNextId(ArrayList* pListMaterias)
{
    int i;
    int indiceMaximo = 0;
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    if(auxMateria != NULL)
    {
        for (i=0; i<pListMaterias->len(pListMaterias); i++)
        {
            auxMateria = pListMaterias->get(pListMaterias, i);
            if (auxMateria->id > indiceMaximo);
            indiceMaximo = auxMateria->id;
        }
    }
    return indiceMaximo+1;
}

int controller_altaMateria(ArrayList* this)
{
    int retorno = -1, id;
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    retorno = controller_getDataMateria(auxMateria, this);
    if(retorno == 0)
    {
        id = controller_getNextId(this);
        materias_setId(auxMateria, id);
        this->add(this, auxMateria);
    }
    return retorno;
}

int controller_getDataMateria(Materias* this, ArrayList* pListMaterias)
{
    int retorno = -1, classes = 0, hours = 0, cuatrimestre, len, cantCorrelativas=0;
    //char* name=NULL, *career=NULL;
    //name = (char*)malloc(sizeof(char)*4000);
    //career = (char*)malloc(sizeof(char)*4000);
    char name [100];
    char career [100];
    int correlativas[10];
    retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 50", name,50,3);
    if(retorno == 0)
    {
        //len = strlen(name)+1;
        //name = (char*)realloc(name, sizeof(char)*len);
        retorno = getValidString("\nCarrera: ","\nNo es una carrera valida","\nLongitud maxima 50", career,50,3);
        if(retorno == 0)
        {
            //len = strlen(career)+1;
            //career = (char*)realloc(career, sizeof(char)*len);
            retorno = getValidInt("\nHoras: ","\nRango valido 10 - 40", &hours,10,40,3);
            if(retorno == 0)
            {
                retorno = getValidInt("\nCantidad de clases: ","\nRango valido 10 - 40", &classes,10,40,3);
                if(retorno == 0)
                {
                    retorno = getValidInt("\nCuatrimestre: ","\nRango valido 1 - 6", &cuatrimestre,1,6,3);
                    if(retorno == 0)
                    {
                        controller_getDataCorrelativa(pListMaterias, &correlativas, &cantCorrelativas);

                        if(retorno == 0)
                        {
                            retorno = materias_append (this, name, career, hours, classes, cuatrimestre, correlativas, cantCorrelativas);
                            if(retorno != 0)
                            {
                                printf("No se pudo cargar la materia\n");
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int controller_getDataCorrelativa(ArrayList* this, int correlativas[], int* cantCorrelativas)
{
    controller_printMateriaId(this);
    int auxCorrelativa;
    int retorno = 0;
    char seguir = 's';
    do
    {
        retorno = getValidInt("\nId Materia Correlativa: ","\nRango valido 0 - 10", &auxCorrelativa,0,10,3);
        if (retorno == 0)
        {
            correlativas[*cantCorrelativas] = auxCorrelativa;
            *cantCorrelativas = *cantCorrelativas+1;
            seguir = getChar("Desea ingresar otra correlativa? s/n: ");
        }
        else { seguir = 'n'; }
    }
    while (seguir == 's');
    return retorno;
}




int controller_modifyMateria(ArrayList* this)
{
    int retorno = -1, id, index;
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    if (this != NULL && auxMateria !=NULL)
    {
        retorno = getValidInt("\nId materia: ","\nRango valido 1 - 9999", &id,0,9999,3);
        if(retorno==0)
        {
            index = id-1;
            if(this->contains(this, this->get(this, index))==1)
            {
                retorno = controller_getDataMateria(auxMateria, this);
                if(retorno == 0)
                {
                    auxMateria->id = id;
                    this->set(this, index, auxMateria);
                    printf("Materia modificada con exito.\n");
                    retorno = 0;
                }
            }
            else
            {
                printf("\nEl id ingresado no existe.\n");
            }
        }
    }
    else
    {
        printf("No hay espacio suficiente en memoria.");
    }
    return retorno;
}

void controller_printAll(ArrayList* this)
{
    Materias* auxMateria = NULL;
    int i = 0, j = 0;
    for(i=0; i<this->len(this); i++)
    {
        auxMateria =(Materias*) this->get(this, i);
        printf("\n\nId: %-3d| Nombre: %-15s| Carrera: %-4s| \nClases: %-3d| Horas: %-3d| Nro cuatrimestre: %-3d \n", auxMateria->id, auxMateria->name, auxMateria->career, auxMateria->classes, auxMateria->hours, auxMateria->cuatrimestre);
        printf("Correlativas: ");
        for(j=0; j<auxMateria->cantCorrelativas; j++)
        {
            printf(" %-1d -", auxMateria->correlativas[j]);
        }
        printf("\n");
    }
}

void controller_printMateriaId(ArrayList* this)
{
    Materias* auxMateria = NULL;
    int i = 0;
    for(i=0; i<this->len(this); i++)
    {
        auxMateria =(Materias*) this->get(this, i);
        printf("\nId: %-3d| Nombre: %-15s\n", auxMateria->id, auxMateria->name);
    }
}

void controller_delete(ArrayList* this)
{
    if (this!= NULL)
    {
        Materias* auxMateria = NULL;
        int id, index, retorno;
        retorno = getValidInt("\nId materia: ","\nRango valido 1 - 9999",&id,1,9999,3);
        if (retorno == 0)
        {
            index = id-1;
            if(this->contains(this, this->get(this, index))==1)
            {
                system("cls");
                auxMateria = al_pop(this, index);
                printf("La siguiente materia fue eliminada de la lista:\n");
                controller_printOne(auxMateria);
            }
        }
    }
    else
    {
        printf("No es posible eliminar materia.");
    }
}

void controller_printOne(Materias* this)
{
    printf("\nId: %-3d| Nombre: %-15s| Carrera: %-4s| \nClases: %-3d| Horas: %-3d| Correlativas: %-3d| Nro cuatrimestre: %-3d \n", this->id, this->name, this->career, this->classes, this->hours,  this->correlativas, this->cuatrimestre);
}

void controller_saveFile(ArrayList* this)
{
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    FILE *f;
    int i = 0, cantidad;
    f = fopen("Materias.dat", "wb");
    if(f != NULL)
    {
        if (auxMateria != NULL)
        {
            cantidad = this->len(this);
            for(i=0; i<cantidad; i++)
            {
                auxMateria = this->get(this, i);
                fwrite((Materias*)this->get(this, i), sizeof(Materias),1,f);

            }
            fclose(f);
            printf("Archivo guardado con exito\n\n");
        }
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}


void controller_getFile(ArrayList* this)
{
    FILE* f;
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    f = fopen("Materias.dat", "rb");
    int cantidad = 0, cantTotal=0;
    if(f != NULL)
    {
        while(!feof(f))
        {
            auxMateria = materias_new();
            if(auxMateria != NULL)
            {
                cantidad = fread(auxMateria, sizeof(Materias), 1, f);
                if(cantidad == 1)
                {
                    controller_printOne(auxMateria);
                    this->add(this, auxMateria);
                    cantTotal++;
                }
                else
                {
                    if(feof(f))
                        break;
                    else
                    {
                        printf("No leyo el ultimo registro.\n");
                        break;
                    }
                }
            }//printf("%d\n", auxMateria->id);
        }
        fclose(f);
        printf("Archivo levantado con exito. Se obtuvieron %d registros\n\n", cantTotal);
        //controller_printAll(this);
    }
    else
    {
        printf("No existe archivo.\n");
    }
}

Materias* controller_findId(ArrayList* pListMaterias, int idMateria)
{
    Materias* auxMateria = NULL;
    //auxMateria = materias_new();
    int exist = -1, i = 0;
    if(pListMaterias != NULL)
    {
        for(i=0; i<pListMaterias->len(pListMaterias); i++)
        {
            auxMateria = pListMaterias->get(pListMaterias, i);
            if(materias_getId(auxMateria) == idMateria)
            {
                exist = 0;
                break;
            }
        }
        if(exist!=0)
        {
            auxMateria = NULL;
        }
    }
    return auxMateria;
}
