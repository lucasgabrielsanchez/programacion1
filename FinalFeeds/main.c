#include "includes.h"

int main()
{
    system("MODE CON: LINES=2000");
    ArrayList *pUsuarios = al_newArrayList();
    ArrayList *pMensajes = al_newArrayList();
    ArrayList *pFeeds = al_newArrayList();
    int flag1 = 0, flag2 = 0, flag3 = 0;
    char seguir = 's';
    while(seguir == 's')
    {
        system("cls");

        printf("Usuarios Cargados: %d\n",al_len(pUsuarios));
        printf("Mensajess Cargados: %d\n",al_len(pMensajes));
        printf("Feeds Cargados: %d\n\n",al_len(pFeeds));


        int opcion = 0;
        opcion = menu("1-Cargar y mostrar usuarios\n2-cargar y mostrar mensajes\n3-Crear y mostrar feeds\n4-Guardar archivo FEED.CSV\n5-Salir\n","La opcion ingresada no es valida",1,5);
        switch(opcion)
        {
        case 1:
            cargaUsuarios(pUsuarios);
            usuario_printAll(pUsuarios);
            system("pause");
            flag1 = 1;
        break;
        case 2:
            cargaMensajes(pMensajes);
            mensaje_printAll(pMensajes);
            system("pause");
            flag2 = 1;
        break;
        case 3:
            if(flag1 && flag2)
            {
                crearFeed(pUsuarios,pMensajes,pFeeds);
                printf("Feeds sin ordenar:\n\n");
                feed_printAll(pFeeds);
                system("pause");
                system("cls");
                printf("Feeds Ordenado:\n\n");
                al_sort(pFeeds,compararFeeds,0);
                feed_printAll(pFeeds);
                system("pause");
                flag3 = 1;
            }
            else
            {
                printf("Para acceder a esta opcion, primero debera acceder a la opcion 1 y 2\n");
                system("pause");
                system("cls");
            }
        break;

        case 4:
            if(flag3)
            {
                if(guardarFeed(pFeeds))
                {
                    printf("Archivo Feeds guardado con exito\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al guardar archivo Feeds\n\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Para acceder a esta opcion, primero debera acceder a la opcion 3\n");
                system("pause");
                system("cls");
            }
        break;

        case 5:
            seguir = 'n';
        break;
        }
    }



    return 0;
}
