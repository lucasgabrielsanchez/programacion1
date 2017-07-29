#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"
#include "ArrayList.h"
#include "string.h"

#define limpieza 1
#define ferreteria 2
#define lacteos 3
#define electro 4
#define bebidas 5

int Producto_carga(ArrayList* this)
{
    int returnAux=0;
    eProducto * auxProducto;
    if(this!=NULL)
    {
        char auxCodigo[10];
        char auxDescripcion[51];
        char auxCategoria[20];
        char auxPrecio[10];
        int CodigoInt;
        int CategoriaInt;
        float PrecioFloat;
        int cont=0;
        FILE *f;
        f=fopen("productos.csv","r");
        if(f!=NULL)
        {
            while(!feof(f))
            {
                fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",auxCodigo,auxDescripcion,auxCategoria,auxPrecio);
                if(!cont)
                {
                    cont=1;
                    continue;
                }
                CodigoInt=atoi(auxCodigo);
                CategoriaInt=atoi(auxCategoria);
                PrecioFloat=atof(auxPrecio);
                auxProducto=producto_nuevo();
                auxProducto->codigo = CodigoInt;
                strcpy(auxProducto->descripcion,auxDescripcion);
                auxProducto->categoria = CategoriaInt;
                auxProducto->precio = PrecioFloat;

                al_add(this,auxProducto);
            }
        }
        fclose(f);
        if(cont)
            returnAux=1;
    }
    return returnAux;
}

/** \brief Crea un espacio en memoria para una estructura del tipo eProducto
*
* \return devuelve la direccion de memoria del nuevo producto
*
*/

eProducto * producto_nuevo()
{
    return (eProducto*)malloc(sizeof(eProducto));
}


/** \brief Printea todo el contenido de un ArrayList pasado como parametro
*
* \param ArrayList* Arraylist pasado como parametro
*
*/

void producto_printearTodo(ArrayList* this)
{
    int i;
    eProducto* aux;
    aux = producto_nuevo();
    if(this!=NULL && aux!=NULL)
    for(i=0;i<this->len(this);i++)
    {
        aux=this->get(this,i);
        producto_printearUno(aux);
    }
}


/** \brief Printea una estructura pasada como parametro
*
* \param eProducto puntero a estructura producto
*
*/

void producto_printearUno(eProducto* this)
{
    if(this!=NULL)
        printf("-Codigo: %d -Descripcion: %s -Categoria: %d -Precio: %0.2f\n",this->codigo,this->descripcion,this->categoria,this->precio);
}


/** \brief devuelve un nuevo Arraylist cargado con los productos pertenecientes a la categoría indicada por parámetro
*
* \param pLista puntero al Arraylist a filtrar
* \param cat entero que indica categoría de filtrado
* \return devuelve un nuevo arraylist cargado con los elementos de la categoría pasada por parámetro
*
*/

ArrayList* filter(ArrayList* pLista, int cat)
{
    int i;
    ArrayList* ProductosFiltrados = al_newArrayList();
    eProducto* aux;
    aux = producto_nuevo();

    if(pLista!=NULL && cat>0 && cat <6)
    for(i=0;i<pLista->len(pLista);i++)
    {
        aux=pLista->get(pLista,i);
        if(aux->categoria == cat)
        {
            al_add(ProductosFiltrados,aux);
            //ProductosFiltrados = ProductosFiltrados->set(ProductosFiltrados,i,aux);
            //ProductosFiltrados->set(aux,i);
            //producto_printearUno(aux);
        }
    }

    if(cat < 1 || cat > 5)
    {
        printf("Categoria fuera de rango\n");
        system("pause");
    }

    return ProductosFiltrados;
}

/** \brief devuelve un float que indica la suma de los precios de todos los productos del puntero a Arraylist
pasado como parámetro.
*
* \param pLista puntero al Arraylist a totalizar
* \return float suma acumulada de los precios de todos los productos del Arraylist
*
*/

float reduce(ArrayList* pLista)
{
    int i;
    float acum;

    eProducto* aux;
    aux = producto_nuevo();

    if(pLista!=NULL)
    for(i=0;i<pLista->len(pLista);i++)
    {
        aux=pLista->get(pLista,i);

        acum = acum + aux->precio;
    }

    return acum;
}

ArrayList* map(ArrayList* pLista, float porcentaje)
{
    int i;
    ArrayList* ProductosAumentados = al_newArrayList();
    eProducto* aux;
    aux = producto_nuevo();

    if(pLista!=NULL)
    for(i=0;i<al_len(pLista);i++)
    {
        //aux=pLista->get(pLista,i);
        aux=al_get(pLista,i);
        aux->precio = aux->precio*porcentaje;
        al_add(ProductosAumentados,aux);
            //ProductosFiltrados = ProductosFiltrados->set(ProductosFiltrados,i,aux);
            //ProductosFiltrados->set(aux,i);
            //producto_printearUno(aux);

    }
    return ProductosAumentados;


}


