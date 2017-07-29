#include "Materias.h"
#include "ArrayList.h"

#ifndef CONTROLER_H_INCLUDED
#define CONTROLER_H_INCLUDED
#endif // CONTROLER_H_INCLUDED

void controller_mock(ArrayList* pListMaterias);
void controller_printAll(ArrayList* pListMaterias);
void controller_printMateriaId(ArrayList* pListMaterias);
void controller_printOne(Materias* this);
int controller_altaMateria(ArrayList* pListMaterias);
int controller_getNextId(ArrayList* pListMaterias);
int controller_getDataMateria(Materias* this, ArrayList* pListMaterias);
void controller_delete(ArrayList* this);
int controller_modifyMateria(ArrayList* this);
void controller_saveFile(ArrayList* this);
void controller_getFile(ArrayList* this);
int controller_getDataCorrelativa(ArrayList* this, int correlativas[], int* cantCorrelativas);
