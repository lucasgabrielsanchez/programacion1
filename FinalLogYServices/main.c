#include "Includes.h"

int main()
{
    ///Creo los arraylists que contendrán los punteros a las estructuras Log y Services.
    ArrayList *pLogs = al_newArrayList();
    ArrayList *pServices = al_newArrayList();

    char seguir = 's';
    int opcion = 0;

    ///Con estos flags puedo saber que opciones del menú se seleccionaron.
    int flag1 = 0,flag2 = 0;

    while(seguir == 's')
    {
        ///Llamo a la función menu que va a mostrar y validar el menu en pantalla.
        opcion = menu("1-Leer Log\n2-Procesar Informacion\n3-Mostrar Estadisticas\n4-Salir\n","Opcion incorrecta",1,4);
        switch (opcion)
        {
        case 1:
            system("MODE CON: LINES=2000");///permite setear el buffer de líneas que el cmd puede mostrar.
            ///Cargo los logs y los printeo.
            cargaLogs(pLogs);
            log_prinAll(pLogs);
            system("pause");
            system("cls");
            ///Cargo los services y los printeo.
            cargaServices(pServices);
            service_prinAll(pServices);
            system("pause");
            system("cls");
            flag1 = 1;
            break;
        case 2:
            if(flag1)
            {
                ///Evalúo el valor de la gravedad para saber que hacer en cada caso.
                evaluarGravedad(pLogs,pServices);
                system("pause");
                system("cls");
                flag2 = 1;
            }
            else
            {
                printf("Para acceder a esta opcion, primero debera acceder a la primera.\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if(flag2)
            {
                ///Muestro las estadísticas derivadas del recorrido de ambos arrayList.
                mostrarEstadisticas();
                system("pause");
                system("cls");
            }
            else
            {
                printf("Para acceder a esta opcion, primero debera acceder a la segunda.\n");
                system("pause");
                system("cls");
            }
            break;
        default:
            ///salgo del programa.
            seguir = 'n';
            break;
        }
    }

    return 0;
}
