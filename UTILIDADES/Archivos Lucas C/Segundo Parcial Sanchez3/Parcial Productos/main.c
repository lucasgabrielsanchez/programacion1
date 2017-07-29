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
    ArrayList* ProductoAumentado = al_newArrayList();

    Producto_carga(ListProducto);

    //producto_printearTodo(ListProducto); // descomentar para printear el array completo

    ProductoFiltrado = filter(ListProducto,3);

    //producto_printearTodo(ProductoFiltrado); // descomentar para printear el array filtrado

    suma = reduce(ProductoFiltrado);

    printf("La suma de los precios del Arraylist pasado por parametro es de: %.02f",suma); //descomentar para printear el array pasado como parametro

    ProductoAumentado = map(ProductoFiltrado,1.10);

    //producto_printearTodo(ProductoAumentado);
    int i;
    eProducto* algo;
    FILE * nuevo;
    nuevo=fopen("algo.csv","w");
    if(nuevo!=NULL)
    {
        //while(!feof(nuevo))

            for(i=0;i<al_len(ProductoAumentado);i++)
            {
                algo=al_get(ProductoAumentado,i);
                fprintf(nuevo,"%d %d %s %.02f\n",algo->categoria,algo->codigo,algo->descripcion,algo->precio);
            }

        fclose(nuevo);
    }



    return 0;
}
