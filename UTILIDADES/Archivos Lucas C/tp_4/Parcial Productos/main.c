#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Productos.h"
#include "string.h"



int main()
{
    float suma = 0;

    ArrayList* ListProducto = al_newArrayList();
    ArrayList* ProductoFiltrado = al_newArrayList();

    Producto_carga(ListProducto);

    //producto_printearTodo(ListProducto); // descomentar para printear el array completo

    ProductoFiltrado = filter(ListProducto,4);

    //producto_printearTodo(ProductoFiltrado); // descomentar para printear el array filtrado

    suma = reduce(ProductoFiltrado);

    //printf("La suma de los precios del Arraylist pasado por parametro es de: %f",suma); descomentar para printear el array pasado como parametro

    return 0;
}
