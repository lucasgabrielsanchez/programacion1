#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

#define ALQUILADO 1
#define FINALIZADO 0

int opcionMenu()
{
    int opcion;

    system("cls");
        printf("1- Alta Cliente\n");
        printf("2- Modificar Cliente\n");
        printf("3- Baja Cliente\n");
        printf("4- Nuevo Alquiler\n");
        printf("5- Finalizar Alquiler\n");
        printf("6- Informar cliente con mas alquileres\n");
        printf("7- Informar equipo/s mas alquilado/s\n");
        printf("8- Informar tiempo promedio de alquiler de los equipos\n\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        return opcion;
}

void inicializarArrayCliente(ECliente cliente[],int cantidad_de_elementos,int valor)
{
    int m;
    for(m=0;m < cantidad_de_elementos; m++)
    {
        cliente[m].estado_cliente = valor;
    }
}

void inicializarArrayAlquiler(EAlquiler alquiler[],int cantidad_de_elementos,int valor)
{
    int m;
    for(m=0;m < cantidad_de_elementos; m++)
    {
        alquiler[m].estado_alquiler = valor;
    }
}

void altaCliente(ECliente cliente[],int indice,int estado)
{
    eValidar cadena;
    char seguir='s';

    while(seguir=='s')
    {
        cadena.minimo=1;
        cadena.maximo=50;
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(cadena.buffer);

        if(validarRango(cadena)==1)
        {
            strcpy(cliente[indice].nombre,cadena.buffer);
            break;
        }
        else
        {
            printf("Nombre invalido. Debe ingresar nombre entre 1 y 50 caracteres.\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }

     while(seguir=='s')
    {
        cadena.minimo=1;
        cadena.maximo=50;
        printf("ingrese apellido: ");
        fflush(stdin);
        gets(cadena.buffer);

        if(validarRango(cadena)==1)
        {
            strcpy(cliente[indice].apellido,cadena.buffer);
            break;
        }
        else
        {
            printf("Apellido invalido. Debe ingresar nombre entre 1 y 50 caracteres.\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }


    while(seguir=='s')
    {
        cadena.minimo=1000000;
        cadena.maximo=99000000;
        printf("Ingrese DNI: ");
        fflush(stdin);
        gets(cadena.buffer);

        if(verificarDNI(cadena)==1)
        {
            strcpy(cliente[indice].dni,cadena.buffer);
            break;
        }
        else
        {
            printf("Debe ingresar DNI valido y sin puntos.\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }

    if(seguir=='s')
    {
        cliente[indice].estado_cliente=estado;
        cliente[indice].idCliente=indice;
        printf("La persona --%s-- fue agregada con exito\n", cliente[indice].nombre);
    }

}

int validarRango(eValidar cadena)
{
    if((strlen(cadena.buffer)>= cadena.minimo) && (strlen(cadena.buffer)<=cadena.maximo))
    {
        if(!validarStr(cadena))
        {
            return 0;
        }
    }
    return 1;
}

int validarRangoEdad(eValidar cadena)
{
    int edad;
    edad=atoi(cadena.buffer);
    if(edad>=cadena.minimo && edad<=cadena.maximo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificarDNI(eValidar cadena)
{
    int dni;
    if((strlen(cadena.buffer))==8)
    {
        dni=atoi(cadena.buffer);

        if (dni>=cadena.minimo && dni<=cadena.maximo)
        {
          return 1;
        }
    }
    return 0;
}

int validarStr(eValidar cadena)
{
    int i = 0;
    char letra;

    while(cadena.buffer[i] != '\0')
    {
        letra=(char)cadena.buffer[i];
        if(!isalpha(letra))
        {
            return 0;
        }
       i++;
    }
    return 1;
}

int buscarPosicionCliente(ECliente cliente[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(cliente[i].estado_cliente == valor)
        {
            return i;
        }
    }
    return -2;
}

int buscarPosicionAlquiler(EAlquiler alquiler[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(alquiler[i].estado_alquiler == valor)
        {
            return i;
        }
    }
    return -2;
}

void bajaCliente(ECliente cliente[],int cant_elementos, int estado)
{
    int j = 0;
    int h = 0;
    int idIngresado;

    printf("Por favor introduzca el id del cliente que desea eliminar de la lista: \n");

            for(j=0; j<cant_elementos; j++)
            {
                if(cliente[j].estado_cliente==1)
                {
                    printf("nombre-->%s apellido-->%s DNI:-->%s ID:-->%d\n",cliente[j].nombre,cliente[j].apellido,cliente[j].dni,cliente[j].idCliente);

                }
            }

            //fflush(stdin);
            scanf("%d",&idIngresado);



            for(h=0; h<cant_elementos; h++)
            {
                if (idIngresado == cliente[h].idCliente)
                {
                    printf("La persona --%s-- fue borrada con exito\n",cliente[h].nombre);
                    cliente[h].estado_cliente = estado;
                    break;
                }

                if (idIngresado != cliente[h].idCliente)
                {
                    printf("No existe el ID ingresado\n");
                    break;
                }
            }
}

void modificarCliente(ECliente cliente[],int cant_elementos)
{
    int j = 0;
    int h = 0;
    int idIngresado = 0;

    printf("Por favor introduzca el id del cliente que desea modificar de la lista: \n");

            for(j=0; j<cant_elementos; j++)
            {
                if(cliente[j].estado_cliente==1)
                {
                    printf("nombre-->%s apellido-->%s DNI:-->%s ID:-->%d\n",cliente[j].nombre,cliente[j].apellido,cliente[j].dni,cliente[j].idCliente);

                }
            }

    scanf("%d",&idIngresado);

    for(h=0; h<cant_elementos; h++)
            {
                if (idIngresado == cliente[h].idCliente)
                {
                    eValidar cadena;
                    char seguir='s';

                    while(seguir=='s')
                    {
                        cadena.minimo=1;
                        cadena.maximo=50;
                        printf("ingrese nombre: ");
                        fflush(stdin);
                        gets(cadena.buffer);

                        if(validarRango(cadena)==1)
                        {
                            strcpy(cliente[idIngresado].nombre,cadena.buffer);
                            break;
                        }
                        else
                        {
                            printf("Nombre invalido. Debe ingresar nombre entre 1 y 50 caracteres.\nDesea continuar? s/n: ");
                            fflush(stdin);
                            scanf("%c",&seguir);
                        }
                    }

                     while(seguir=='s')
                    {
                        cadena.minimo=1;
                        cadena.maximo=50;
                        printf("ingrese apellido: ");
                        fflush(stdin);
                        gets(cadena.buffer);

                        if(validarRango(cadena)==1)
                        {
                            strcpy(cliente[idIngresado].apellido,cadena.buffer);
                            break;
                        }
                        else
                        {
                            printf("Apellido invalido. Debe ingresar nombre entre 1 y 50 caracteres.\nDesea continuar? s/n: ");
                            fflush(stdin);
                            scanf("%c",&seguir);
                        }
                    }


                    while(seguir=='s')
                    {
                        cadena.minimo=1000000;
                        cadena.maximo=99000000;
                        printf("Ingrese DNI: ");
                        fflush(stdin);
                        gets(cadena.buffer);

                        if(verificarDNI(cadena)==1)
                        {
                            strcpy(cliente[idIngresado].dni,cadena.buffer);
                            break;
                        }
                        else
                        {
                            printf("Debe ingresar DNI valido y sin puntos.\nDesea continuar? s/n: ");
                            fflush(stdin);
                            scanf("%c",&seguir);
                        }

                    }

                    printf("La persona --%s-- fue modificada con exito\n",cliente[h].nombre);
                    system("pause");
                    break;

    }


                if (idIngresado != cliente[h].idCliente)
                {
                    printf("No existe el ID ingresado\n");
                    system("pause");
                    break;
                }
            }
}

void altaAlquiler(EAlquiler alquiler[],ECliente cliente[],int cant_elemClientes,int indice,int estado)
{
    int j = 0;
    int h = 0;
    int idIngresado,maquina,tiempo;
    int flag = 0;

    printf("Por favor seleccione el ID del cliente que realiza el alquiler\n");

    for(j=0; j<cant_elemClientes; j++)
            {
                if(cliente[j].estado_cliente==1)
                {
                    printf("nombre-->%s apellido-->%s DNI:-->%s ID:-->%d\n",cliente[j].nombre,cliente[j].apellido,cliente[j].dni,cliente[j].idCliente);

                }
            }

    scanf("%d",&idIngresado);

    for(h=0; h<cant_elemClientes; h++)
    {
        if (idIngresado == cliente[h].idCliente)
        {
            alquiler[indice].idCliente = idIngresado;

            printf("seleccione el equipo a alquilar:\n1--AMOLADORA\n2--MEZCLADORA\n3--TALADRO\n");

            scanf("%d",&maquina);
            while(maquina<1 || maquina>3)
            {
                printf("Opcion invalida, puede elegir 1, 2 o 3\n");
                scanf("%d",&maquina);
            }

            alquiler[indice].equipo = maquina;

            printf ("Ingrese el tiempo en horas de lo que durara el alquiler, maximo 72 hs\n");

            scanf("%d",&tiempo);

            while(tiempo<1 || tiempo>72)
            {
                printf("Opcion invalida, puede elegir entre 1 a 72hs\n");
                scanf("%d",&tiempo);
            }

            alquiler[indice].tiempo = tiempo;

            alquiler[indice].idAlquiler = indice;
            alquiler[indice].estado_alquiler = ALQUILADO;
            system("pause");
            flag = 1;
            break;
        }

    }
        if(flag == 0)
        {
            printf("El ID ingresado no existe\n");
            system("pause");
        }
    return flag;
}

void finAlquiler(EAlquiler alquiler[],int cantElemAlquiler,int estado)
{
    int j = 0;
    int h = 0;
    int idIngresado;

    printf("Por favor introduzca el id del alquiler que desea eliminar de la lista: \n");

            for(j=0; j<cantElemAlquiler; j++)
            {
                if(alquiler[j].estado_alquiler==1)
                {
                    printf("ID Alquiler-->%d\n",alquiler[j].idAlquiler);

                }
            }

            //fflush(stdin);
            scanf("%d",&idIngresado);

            for(h=0; h<cantElemAlquiler; h++)
            {
                if (idIngresado == alquiler[h].idAlquiler)
                {
                    printf("EL alquiler --%d-- fue borrado con exito\n",alquiler[h].idAlquiler);
                    alquiler[h].estado_alquiler = FINALIZADO;
                    system("pause");
                    break;
                }

                if (idIngresado != alquiler[h].idAlquiler)
                {
                    printf("No existe el ID ingresado\n");
                    system("pause");
                    break;
                }
            }
}
