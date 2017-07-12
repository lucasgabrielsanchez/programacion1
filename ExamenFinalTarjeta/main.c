#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
#include "Tarjeta.h"

#define Visa 1
#define Amex 2
#define Master 3


int main()
{

    ArrayList *pTarjetas = al_newArrayList();

    Tarjeta* tarjetita;

    al_clear(pTarjetas);

    char auxID[5];
    char auxNombre[101];
    char auxApellido[101];
    char auxMail[101];
    char auxNumTarjeta[31];

    FILE *f = fopen("data.csv","r");

    int cont = 0;

    if(f != NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxApellido,auxMail,auxNumTarjeta);
            if(cont==0)
            {
                cont=1;
                continue;
            }

            tarjetita = new_tarjeta();

            strcpy(tarjetita->ID,auxID);
            strncpy(tarjetita->nombre,auxNombre,20);
            strcpy(tarjetita->apellido,auxApellido);
            strcpy(tarjetita->mail,auxMail);
            strcpy(tarjetita->NumTarjeta,auxNumTarjeta);

            ///Solo acepto ID numéricos.
            if(esNumerico(auxID))
            {
                ///Solo acepto ID mayores o iguales a 0.
                if(atoi(auxID)>0)
                {
                    if(esSoloLetras(auxNombre))
                    {
                        if(esSoloLetras(auxApellido))
                        {
                            if(esMail(auxMail))
                            {
                                    ///Solo acepto tarjetas iguales a 13, 15 o 16 dígitos.
                                    if(strlen(auxNumTarjeta)==13 || strlen(auxNumTarjeta)==15 || strlen(auxNumTarjeta)==16)
                                    {
                                        if(esVisa(auxNumTarjeta))
                                        {
                                            tarjetita->Tarjeta = Visa;
                                            strcpy(tarjetita->error,"");
                                        }
                                        else
                                        {
                                            if(esAmex(auxNumTarjeta))
                                            {
                                            tarjetita->Tarjeta = Amex;
                                            strcpy(tarjetita->error,"");
                                            }
                                            else
                                            {
                                                if(esMaster(auxNumTarjeta))
                                                {
                                                    tarjetita->Tarjeta = Master;
                                                    strcpy(tarjetita->error,"");
                                                }

                                                else
                                                {
                                                    strcpy(tarjetita->error,"El numero de tarjeta es sintacticamente invalido.");
                                                }
                                            }
                                        }

                                    }
                                    else
                                    {
                                        strcpy(tarjetita->error,"La cantidad de digitos de la tarjeta es invalida");
                                    }
                            }
                            else
                            {
                                strcpy(tarjetita->error,"El mail es incorrecto");
                            }
                        }
                        else
                        {
                            strcpy(tarjetita->error,"El apellido es incorrecto");
                        }
                    }
                    else
                    {
                        strcpy(tarjetita->error,"El nombre es incorrecto");
                    }
                }
                else
                {
                    strcpy(tarjetita->error,"El ID es menor a 1");
                }
            }
            else
            {
                strcpy(tarjetita->error,"El ID no es numerico");
            }

            al_add(pTarjetas,tarjetita);
        }

    }

    fclose(f);

    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        system("cls");
        opcion = menu("MENU:\n1-Listar Clientes Validos\n2-Listar Mastercard Validos\n3-Listar Visa Validos\n4-Listar Amex Validos\n5-Listar Clientes Invalidos\n6-Salir\n","ERROR ingrese opcion valida:\n",1,6);

        switch(opcion)
        {
        case 1:
            printearValidos(pTarjetas);
            system("pause");
            break;
        case 2:
            printearMaster(pTarjetas);
            system("pause");
            break;
        case 3:
            printearVisa(pTarjetas);
            system("pause");
            break;
        case 4:
            printearAmex(pTarjetas);
            system("pause");
            break;
        case 5:
            printearInvalidos(pTarjetas);
            system("pause");
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }
//    int i;
//    for(i=0;i<al_len(pTarjetas);i++)
//    {
//        tarjetita = (Tarjeta*)malloc(sizeof(Tarjeta));
//        tarjetita = al_get(pTarjetas,i);
//        if((strlen(tarjetita->NumTarjeta) == 13 || strlen(tarjetita->NumTarjeta) == 16) && tarjetita->NumTarjeta[0] == '4')
//        {
//           if(validarNumTarjetaSintactico(tarjetita->NumTarjeta))
//           {
//               printf("Somo nosotro Visa  %s\n",tarjetita->ID);
//           }
//           else
//           {
//               printf("No somo nosotro Visa  %s\n",tarjetita->ID);
//           }
//        }
//
//    }

//    int i;
//
//    for(i=0;i<al_len(pTarjetas);i++)
//    {
//        tarjetita = (Tarjeta*)malloc(sizeof(Tarjeta));
//        tarjetita = al_get(pTarjetas,i);
//            if(tarjetita->Tarjeta == Visa)
//            {
//               printf("Somo nosotro Visa  %s\n",tarjetita->ID);
//            }
//            else
//            {
//               printf("No somo nosotro Visa  %s\n",tarjetita->ID);
//            }
//    }



//    printf("\n");
//    int i;
//    for(i=0;i<al_len(pTarjetas);i++)
//    {
//        tarjetita = new_tarjeta();
//        tarjetita = al_get(pTarjetas,i);
//        if(strlen(tarjetita->NumTarjeta)== 15 && tarjetita->NumTarjeta[0] == '3' && (tarjetita->NumTarjeta[1] == '4' || tarjetita->NumTarjeta[1] == '7'))
//        {
//           if(validarNumTarjetaSintactico(tarjetita->NumTarjeta))
//           {
//               printf("Somo nosotro Amex  %s\n",tarjetita->ID);
//           }
//           else
//           {
//               printf("No somo nosotro Amex  %s\n",tarjetita->ID);
//           }
//        }
//
//    }
//
//    printf("\n");
//
//    for(i=0;i<al_len(pTarjetas);i++)
//    {
//        tarjetita = new_tarjeta();
//        tarjetita = al_get(pTarjetas,i);
//        if(strlen(tarjetita->NumTarjeta)== 16)
//        {
//           if(validarNumTarjetaSintactico(tarjetita->NumTarjeta))
//           {
//               printf("Somo nosotro Master  %s\n",tarjetita->ID);
//           }
//           else
//           {
//               printf("No somo nosotro Master  %s\n",tarjetita->ID);
//           }
//        }
//
//    }



///igualando arrays de char con punteros
//    char holita[15];
//    char *holita2 = holita;
//    strcpy(holita2,"3690.729");
//
//    if(esDni(holita2))
//    {
//      printf("groso");
//      printf("%d",strlen(holita2));
//    }
//    else
//    {
//        printf("puto");
//        printf("%d",strlen(holita2));
//    }

///igualando arrays de int con punteros, ojo que al apuntar a la misma dirección, al modificar datos se modifica en ambos.

//    int enteritos[] = {1,2,3,4,5,6};
//    int *enteritos2 = enteritos;
//
//    int i;
//    for(i=0;i<sizeof(enteritos)/sizeof(int);i++)
//    {
//        printf("%d",enteritos2[i]);
//    }
//    enteritos2[2] = 8;
//    printf("\n");
//    for(i=0;i<sizeof(enteritos)/sizeof(int);i++)
//    {
//        printf("%d",enteritos[i]);
//    }

///Recorriendo las tarjetas y mostrándolas
//    int i;
//    for(i=0;i<al_len(pTarjetas);i++)
//    {
//        if(i==20)
//        {
//            system("pause");
//            system("cls");
//        }
//
//        tarjetita = al_get(pTarjetas,i);
//        printf("ID: %d\nNombre: %s\nApellido: %s\nEMail: %s\nNumero de tarjeta: %s\n\n",tarjetita->ID,tarjetita->nombre,tarjetita->apellido,tarjetita->mail,tarjetita->NumTarjeta);
//    }


///pasando de array de char (string) a array de enteros.
//
//    ///array de char original
//    char miString[] = "12345678";
//
//    printf("%s",miString);
//
//    ///creo un array de enteros del tamaño del array de char, la función strlen me devuelve el tamaño real del
//    ///array de char, quitándole el caracter terminador '/0'
//    //int miInt[strlen(miString)];
//    int miInt[strlen(miString)];
//
//
//    //int i;
//
//    printf("\n");
//
//    ArrayCharToArrayInt(miInt,miString);
//
//    for(i=0; i<strlen(miString); i++)
//    {
//        printf("%d",miInt[i]);
//    }

///probando punteros char
//char string[21];
//char *puntero = string;
//gets(puntero);
//printf("%s",puntero);
//gets(puntero);
//printf("%s",puntero);

///invirtiendo un array de enteros sin punteros
//int hola[] = {1,2,3,4};
//
//int hola2[sizeof(hola)/sizeof(int)];
//
//
//int j,k=0;
//for (j=(sizeof(hola)/sizeof(int))-1; j>-1 ; j--)
//{
//    hola2[k] = hola[j];
//    k++;
//}

//for(i=0; i<sizeof(hola)/4; i++)
//{
//    printf("%d",hola[i]);
//}
//
//printf("\n");
//
//for(i=0; i<sizeof(hola)/4; i++)
//{
//    printf("%d",hola2[i]);
//}

///inicializando un array de int con valores conocidos para saber su límite "cargado".
//int miArray[15]={}; //inicializa en 0 las posiciones del array;
//
//miArray[0]=1;
//miArray[1]=2;
//miArray[2]=3;
//miArray[3]=4;
//
//int i;
////el for recorre hasta 15 pero muestra solo 1234 porque son mayores a 0;
//for(i=0; i<sizeof(miArray)/sizeof(int); i++)
//{
//    if(miArray[i]>0)
//    {
//        printf("%d",miArray[i]);
//    }
//}

///invirtiendo array de enteros con punteros
//int miArray[] = {1,2,3,4};
//
//int i;
//
////muestro antes de invertir
//for(i=0; i<sizeof(miArray)/sizeof(int); i++)
//{
//    printf("%d",miArray[i]);
//}
//printf("\n");
//
////hice una función que como parámetro requiere la cantidad de elementos del array porque dentro de la función
////no se puede calcular la cantidad de elementos del array.
//arrayIntInverter(miArray,(sizeof(miArray)/sizeof(int)));
//
//printf("\n");
////muestro después de invertir
//for(i=0; i<sizeof(miArray)/sizeof(int); i++)
//{
//    printf("%d",miArray[i]);
//}

    return 0;
}
