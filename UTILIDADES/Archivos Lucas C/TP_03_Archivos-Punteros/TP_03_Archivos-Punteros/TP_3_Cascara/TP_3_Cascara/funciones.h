#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[300];
    int estado;

} ePelicula;

void ListarPeliculas();
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int AgregarPelicula(ePelicula * puntPelicula);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int BorrarPelicula(int id);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(ePelicula lista[], char nombre[]);

void InicializarPelicula(ePelicula pelicula[]);

#endif // FUNCIONES_H_INCLUDED
