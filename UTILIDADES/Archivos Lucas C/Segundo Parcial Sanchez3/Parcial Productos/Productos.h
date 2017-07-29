#include "ArrayList.h"

typedef struct
{
int codigo;
char descripcion[20];
int categoria;
float precio;
}eProducto;

int Producto_carga(ArrayList* this);

eProducto * producto_nuevo();

void producto_printearTodo(ArrayList* this);

void producto_printearUno(eProducto* this);

ArrayList* filter(ArrayList* pLista, int cat);

float reduce(ArrayList* pLista);

ArrayList* map(ArrayList* pLista, float porcentaje);
