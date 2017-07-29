#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

//char menu[] = "\n1- Ingresar 1er operando (A=x)\n2- Ingresar 2do operando (B=y)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n";
char error[] = "\nLa opcion ingresada no es valida, debe elegir\nuna opcion entre 1 y 9, desea continuar?: s/n \n";


int main()
{
    int num1 = 0,num2 = 0;
    int resul1,resul2,resul3,resul4,resul5;
    //float numdiv1,numdiv2;

    char seguir='s';
    int opcion;
    //no hay que validar que sean letras
    while(seguir=='s')
    {


        system("cls");

        printf("\n1- Ingresar 1er operando (A=%d)\n2- Ingresar 2do operando (B=%d)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n",num1,num2);

        opcion = valOpMen(error,1,9);

        //printf("\n1- Ingresar 1er operando (A=%d)\n2- Ingresar 2do operando (B=d)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n",num1,num2);


        if(opcion==-1)//con esto valido si el usuario no desea continuar con lo que me devuelve mi funcion valOpMen
        {
            return 0;
        }



        //printf("%s",menu);

        //scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                //crear la funcion en la biblioteca de cada case.
                system("cls"); // limpia la pantalla
                printf("\nIngrese el primer operando: ");



                fflush(stdin);//lo utilizo para borrar lo que se encuentra en el "buffer", es decir si no coloco esta linea
                              //se va a guardar el caracter /n que es el Enter, en vez de guardarse el numero que ingresa el usuario.
                scanf("%d",&num1); //escaneo un caracter para poder insertarlo en mi array de char que contiene el menu,y luego mas abajo lo
                                   //transformo a entero para que pueda operar con dicho numero,
                system("cls");
                printf("\n1- Ingresar 1er operando (A=%d)\n2- Ingresar 2do operando (B=%d)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n",num1,num2);
                //system("pause");
                //menu[29] = numm1; //guardo en la posicion 29 de mi array, el numero que el usuario ingresa para que se vea en el menu de mi calculadora.

                //num1 = charAInt(num1,numm1);//convierto el char ingresado a entero para poder operar con el mismo.

                //numdiv1 = atof(num1);

                //num1 = numm - '0'; //para pasar de un char a int le resto - '0' al char porque el 0 en ASCII vale 48 en decimal, y como los numeros
                                   //en ASCII arrancan a partir de la posicion 48, al restarlo, logro igualar el valor numerico del char, al del entero.

                break;
            case 2:
                system("cls");

                printf("\nIngrese el segundo operando: ");

                fflush(stdin);

                scanf("%d",&num2);

                printf("\n1- Ingresar 1er operando (A=%d)\n2- Ingresar 2do operando (B=%d)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n",num1,num2);

                //menu[60] = numm2;

                //num2 = charAInt(num2,numm2);

                //numdiv2 = atof(num2);

                break;
            case 3:
                system("cls");
                resul1 = suma(num1,num2);
                printf("\n El resultado de la suma es: %d \n",resul1);
                system("pause");
                break;
            case 4:
                system("cls");
                resul2 = resta(num1,num2);
                printf("\n El resultado de la resta es: %d \n",resul2);
                system("pause"); //espera hasta que el usuario presiona una tecla.
                break;
            case 5:
                system("cls");

                if(num2==0)
                {
                    printf("No se puede dividir por 0, vuelva a\ningresar un segundo operando que sea distinto a 0 \n");
                    system("pause");
                    break;
                }

                resul3 = division(num1,num2);
                printf("\n El resultado de la division es: %d \n",resul3);
                system("pause");
                break;
            case 6:
                system("cls");
                resul4 = multip(num1,num2);
                printf("\n El resultado de la multiplicacion es: %d \n",resul4);
                system("pause");
                break;
            case 7:
                system("cls");
                if (num1<1)
                {
                    printf("Si desea calcular un factorial, debe ser de un\nnumero mayor que 0 y no debe ser negativo\n");
                    system("pause");
                    break;
                }
                resul5 = factorial(num1);
                printf("\n El resultado del factorial del primer operando es: %d \n",resul5);
                system("pause");
                break;
            case 8:
                system("cls");
                resul1 = suma(num1,num2);
                resul2 = resta(num1,num2);
                resul3 = division(num1,num2);
                resul4 = multip(num1,num2);
                resul5 = factorial(num1);

                printf("El resultado de la suma es: %d",resul1);
                printf("\nEl resultado de la resta es: %d",resul2);
                printf("\nEl resultado de la division es: %d",resul3);
                printf("\nEl resultado de la multiplicacion es: %d",resul4);
                printf("\nEl resultado del factorial es: %d\n",resul5);
                system("pause");

                break;
            case 9:
               seguir = 'n';
                break;

        }
    }
 return 0;

}
