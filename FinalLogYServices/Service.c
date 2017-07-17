#include "Includes.h"

///Estos contadores almacenarán los valores para el punto 3.
int menorA3 = 0,igualA3 = 0, entre4Y7 = 0, mayorA7 = 0, servMasFallos = 0, contFallos = 0;
///Esta variable char almacenará el nombre del servicio con más fallos.
char *nombreServicioMasFallos = NULL;

int cargaServices(ArrayList *pServices)
{
    ///Este retorno servirá para saber si se cargó correctamente el archivo.
    int retorno = 0;
    ///Este contador me ayudará a saber si se leyó al menos una línea del archivo, lo cual indicará que se pudo leer.
    int cont = 0;
    ///auxiliar de la estructura eService
    eService *auxService;
    ///puntero a File que permite manipular archivos.
    FILE *archivo;
    ///variables auxiliares que contendrán cada string leído del archivo que se encuentren separados por ;
    char auxId[11];
    char auxName[51];
    char auxEmail[71];

    ///Verifico que el arraylist no sea nulo.
    if(pServices!=NULL)
    {
        ///Si contiene elementos lo vacío para cargarlo limpio.
        if(al_len(pServices) != 0)
        {
            al_clear(pServices);
        }
        ///Acá le digo que archivo abrir y en que modo, r para lectura.
        archivo=fopen("services.txt","r");

        ///verifico que el archivo no sea nulo.
        if(archivo!=NULL)
        {
            ///Mientras NO sea el final del archivo, se leerá el mismo.
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^;];%[^;];%[^\n]\n",auxId,auxName,auxEmail);

                ///acá pongo el contador en 1 para saber que se leyó al menos una línea.
                if(cont == 0)
                {
                    cont = 1;
                }

                ///le doy espacio en memoria a la estructura auxiliar
                auxService = new_service();

                ///Cargo los datos a la estructura auxiliar
                service_setId(auxService,atoi(auxId));
                service_setName(auxService,auxName);
                service_setEmail(auxService,auxEmail);

                ///cargo la estructura auxiliar en el arraylist.
                al_add(pServices,auxService);
            }
        }

        ///cierro el archivo
        fclose(archivo);

        ///retorno 1 si el contador está en 1.
        if(cont)
        {
            retorno=1;
        }
    }
    return retorno;
}

///Reservo espacio en memoria para una estructura eService.
eService* new_service()
{
    return (eService*)malloc(sizeof(eService));
}

int service_setId(eService *auxService, int id)
{
    int retorno = 0;

    if(auxService != NULL && id > -1)
    {
        auxService->id = id;
        retorno = 1;
    }

    return retorno;
}

int service_getId(eService *auxService)
{
    int retorno = -1;

    if(auxService != NULL)
    {
        retorno = auxService->id;
    }

    return retorno;
}

int service_setName(eService *auxService, char *name)
{
    int retorno = 0;

    if(auxService != NULL && name != NULL)
    {
        strcpy(auxService->name,name);
        retorno = 1;
    }

    return retorno;
}

char* service_getName(eService *auxService)
{
    char *aux = NULL;

    if(auxService != NULL)
    {
        aux = auxService->name;
    }

    return aux;
}

int service_setEmail(eService *auxService, char *email)
{
    int retorno = 0;

    if(auxService != NULL && email != NULL)
    {
        strcpy(auxService->email,email);
        retorno = 1;
    }

    return retorno;
}

char* service_getEmail(eService *auxService)
{
    char *aux = NULL;

    if(auxService != NULL)
    {
        aux = auxService->email;
    }

    return aux;
}

///Recorro el arraylist y muestro su contenido.
void service_prinAll(ArrayList *pService)
{
    int i;
    for (i=0;i<al_len(pService);i++)
    {
        eService *auxService = al_get(pService,i);

        printf("ID: %d\nName: %s\nEmail: %s\n\n",service_getId(auxService),service_getName(auxService),service_getEmail(auxService));
    }
}

///recibo los 2 ArrayLists para compararlos
void evaluarGravedad(ArrayList *pLogs, ArrayList *pServices)
{
    ///contadores para los for.
    int i,j;
    ///Puntero a file con el que escribiré los archivos.
    FILE *f;
    ///extructuras auxiliares donde guardaré los elementos leidos de los ArrayList.
    eLog *auxLog = new_eLog();
    eService *auxService = new_service();;

    ///en el for mas grande recorro los servicios
    for (i=0;i<al_len(pServices);i++)
    {
        ///traigo los datos del primer servicio leído
        auxService = al_get(pServices,i);

        ///Este contador lo uso para ver que servicio tiene mas fallos.
        contFallos = 0;

        ///en el for mas chico recorro los logs, por cada dato leido del Service, se leeran todos los del log, para compararse
        ///entre si y encontrar igualdad entre ServiceId de los Services y el ID de los logs.
        for(j=0;j<al_len(pLogs);j++)
        {
            auxLog = al_get(pLogs,j);

            ///si los ID de ambas estructuras son iguales, procedo a evaluar los valores de gravedad de los errores.
            if(auxService->id == auxLog->serviceId)
            {
                contFallos++;

                if(auxLog->gravedad < 3)
                {
                    menorA3++;
                }
                else if(auxLog->gravedad == 3)
                {
                    ///creo el archivo y lo pongo en modo a para que agregue los datos que va leyendo, sino, se pisarían los datos.
                    f = fopen("warnings.txt","a");
                    if(f!=NULL)
                    {
                        fprintf(f,"%s,%s,%s,%s,%s\n",log_getDate(auxLog),log_getTime(auxLog),service_getName(auxService),
                                log_getMsg(auxLog),service_getEmail(auxService));
                    }
                    fclose(f);

                    igualA3++;
                }
                else if(auxLog->gravedad > 3 && auxLog->gravedad < 8)
                {
                    printf("Fecha %s\nHora: %s\nNombre de Servicio: %s\nMensaje: %s\nGravedad: %d\n\n",log_getDate(auxLog),
                           log_getTime(auxLog),service_getName(auxService),log_getMsg(auxLog),log_getGravedad(auxLog));

                    entre4Y7++;
                }
                else if(auxLog->gravedad > 7)
                {
                    f = fopen("errors.txt","a");
                    if(f!=NULL)
                    {
                        ///creo el archivo y lo pongo en modo a para que agregue los datos que va leyendo, sino, se pisarían los datos.
                        fprintf(f,"%s,%s,%s,%s,%s\n",log_getDate(auxLog),log_getTime(auxLog),service_getName(auxService),
                                log_getMsg(auxLog),service_getEmail(auxService));
                    }
                    fclose(f);

                    mayorA7++;
                }
            }
        }
        ///a partir de acá, evalúo el servicio con más fallos, si i==0 (osea la primer vuelta del for mas grande),
        ///les doy un valor inicial al contador y al nombre para que tengan un valor inicial por el cual
        ///el resto de los elementos puedan compararse.
        if(i==0)
        {
            servMasFallos = contFallos;
            nombreServicioMasFallos = auxService->name;
        }
        ///Luego, si el contador de fallos es mas grande que el servicio con mas fallos guardado anterioremente, este nuevo
        ///contador indicará que este nuevo servicio tiene mas fallos que el anterior y lo pisará.
        else if(contFallos>servMasFallos)
        {
            servMasFallos = contFallos;
            nombreServicioMasFallos = auxService->name;
        }
    }
}

///Muestro las estadísticas que pude capturar del punto 2.
void mostrarEstadisticas()
{
    printf("El servicio que mas fallos tiene es el %s, con un total de %d fallos.\n",
           nombreServicioMasFallos,servMasFallos);

    printf("Fallos por gravedad:\nGravedad menor a 3: %d\nGravedad igual a 3: %d\nGravedad entre 4 y 7: %d\nGravedad mayor a 7: %d\n",
           menorA3,igualA3,entre4Y7,mayorA7);
}
