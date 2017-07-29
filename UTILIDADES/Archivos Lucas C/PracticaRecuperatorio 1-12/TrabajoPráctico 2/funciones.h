#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
                char nombre[50];
                int edad;
                int estado;
                long int dni;
              }EPersona;

int menu();
void inicializar(EPersona lista[]);
void altas(EPersona lista[]);
int buscar(EPersona lista[], long int dni);
void imprimir(EPersona lista[]);
void bajas(EPersona lista[]);
int libre(EPersona lista[]);
void grafico(EPersona lista[]);
char salir(EPersona lista[]);
void valtam(char x[], int tam);
char valsn(char rta);

#endif // FUNCIONES_H_INCLUDED

