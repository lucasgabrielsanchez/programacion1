#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
typedef struct
{
    int id;
    //char* name;
    //char* career;
    char name [100];
    char career [100];
    int hours;
    int classes;
    int cuatrimestre;
    int correlativas[10];
    int cantCorrelativas;

}  Materias;

typedef struct
{
    int correlativas[10];
    int cantCorrelativas;
    int capacidad;
    int idMateria;

}  Correlativas;

#endif //MATERIAS_H_INCLUDED


Materias* materias_new();
int materias_getStaticId();
int materias_append (Materias* this, char* name, char* career, int hours, int classes, int cuatrimestre, int correlativas[], int cantCorrelativas);

int materias_setId(Materias* this, int id);
int materias_setName(Materias* this, char* name);
int materias_setCareer(Materias* this, char* career);
int materias_setHours(Materias* this, int hours);
int materias_setClasses(Materias* this, int classes);
int materias_setCorrelativas(Materias* this, int correlativas[], int cantCorrelativas);
int materias_setCuatrimestre(Materias* this, int cuatrimestre);
int materias_getId(Materias* this);
char* materias_getName(Materias* this);
char* materias_getCareer(Materias* this);
int materias_getClasses(Materias* this);
int materias_getCuatrimestre(Materias* this);
int* materias_getCorrelativas(Materias* this);
