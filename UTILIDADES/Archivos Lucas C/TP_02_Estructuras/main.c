#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define Caux 10
#define C 20
#define VACIO -1
#define ALTA 1
#define BAJA 0

int main()
{
    ePersona persona[C];
    asignarEstado (persona,C,VACIO);
    hardcodeo(persona,Caux);
    eMenu opciones;
    strcpy(opciones.menu,"1. Agregar una persona.\n2. Borrar una persona.\n3. Imprimir lista ordenada por nombre.\n4. Imprimir grafico de edades.\n5. Salir.\nINGRESE UNA OPCION: ");
    strcpy(opciones.error,"Ingreso una opcion invalida. Desea continuar? s/n: ");
    opciones.desde=1;
    opciones.hasta=5;
    int opcion;
    char seguir='s';
    int indice=0;
    char dni[20];
    int menor18=0;
    int de18a35=0;
    int mayor35=0;

    do
    {
        system("pause");
        system("cls");
        opcion= validarMenu(opciones);

        switch(opcion)
        {
            case 1:
                system("cls");
                indice=buscarIndiceLibre(persona,C);

                if(indice >= 0)
                {
                    altaPersona(persona,indice,ALTA);
                }
                else
                {
                    printf("Supero el espacio permitido para carga.\n");
                }
                break;
            case 2:
                system("cls");
                printf("Ingrese DNI a eliminar: ");
                fflush(stdin);
                gets(dni);
                indice=buscarPorDni(persona, dni, C);

                if(indice >= 0)
                {
                    bajaPersona (persona,C,indice);
                }
                 else
                {
                    printf("\nEl DNI ingresado no existe.\n");
                }
            break;

            case 3:
                system("cls");
                listarPersonas(persona,C);
            break;

            case 4:
                system("cls");
                contarPorEdad(persona,C,&menor18,&de18a35,&mayor35);
                graficar(menor18,de18a35,mayor35);
            break;

            case 5:
                seguir='n';
            break;
        }

    } while (seguir=='s'||opcion==-1);


    return;
}

