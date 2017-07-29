#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
                char titulo[20];
                char genero[20];
                int duracion;
                char descripcion[50];
                float puntaje;
                char link[1000];
                int estado;
              }EMovie;


void altas(EMovie movie, FILE *parch);
void modificar(EMovie movie, FILE *parch);
void eliminar(EMovie movie, FILE *parch);
void valtam(char x[], int tam);
float valnum(float, int, int);
void valtitulo(char x[], EMovie movie, FILE *parch);
void imprimir(EMovie movie, FILE *parch);
int cantidadPeliculas(FILE *parch);
void generarPagina(FILE *parch, EMovie movie);

#endif // FUNCIONES_H_INCLUDED

