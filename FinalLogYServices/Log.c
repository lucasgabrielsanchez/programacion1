#include "Includes.h"

int cargaLogs(ArrayList *pLogs)
{
    ///Este retorno servirá para saber si se cargó correctamente el archivo.
    int retorno = 0;
    ///Este contador me ayudará a saber si se leyó al menos una línea del archivo, lo cual indicará que se pudo leer.
    int cont = 0;
    ///auxiliar de la estructura eLog
    eLog *auxLog;
    ///puntero a File que permite manipular archivos.
    FILE *archivo;
    ///variables auxiliares que contendrán cada string leído del archivo que se encuentren separados por ;
    char auxDate[51];
    char auxTime[51];
    char auxServiceId[51];
    char auxGravedad[51];
    char auxMsg[71];

    ///Verifico que el arraylist no sea nulo.
    if(pLogs!=NULL)
    {
        ///Si contiene elementos lo vacío para cargarlo limpio.
        if(al_len(pLogs) != 0)
        {
            al_clear(pLogs);
        }
        ///Acá le digo que archivo abrir y en que modo, r para lectura.
        archivo=fopen("log.txt","r");

        ///verifico que el archivo no sea nulo.
        if(archivo!=NULL)
        {
            ///Mientras NO sea el final del archivo, se leerá el mismo.
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxDate,auxTime,auxServiceId,auxGravedad,auxMsg);

                ///acá pongo el contador en 1 para saber que se leyó al menos una línea.
                if(cont == 0)
                {
                    cont = 1;
                }

                ///le doy espacio en memoria a la estructura auxiliar
                auxLog = new_eLog();

                ///Cargo los datos a la estructura auxiliar
                log_setDate(auxLog,auxDate);
                log_setTime(auxLog,auxTime);
                log_setServideId(auxLog,atoi(auxServiceId));
                log_setGravedad(auxLog,atoi(auxGravedad));
                log_setMsg(auxLog,auxMsg);

                ///cargo la estructura auxiliar en el arraylist.
                al_add(pLogs,auxLog);
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

///Reservo espacio en memoria para una estructura eLog.
eLog* new_eLog()
{
    return (eLog*)malloc(sizeof(eLog));
}

int log_setDate(eLog *auxLog, char *date)
{
    int retorno = 0;

    if(auxLog != NULL && date != NULL)
    {
        strcpy(auxLog->date,date);
        retorno = 1;
    }

    return retorno;
}

char* log_getDate(eLog *auxLog)
{
    char *aux = NULL;

    if(auxLog != NULL)
    {
        aux = auxLog->date;
    }

    return aux;
}

int log_setTime(eLog *auxLog, char *time)
{
    int retorno = 0;

    if(auxLog != NULL && time != NULL)
    {
        strcpy(auxLog->time,time);
        retorno = 1;
    }

    return retorno;
}

char* log_getTime(eLog *auxLog)
{
    char *aux = NULL;

    if(auxLog != NULL)
    {
        aux = auxLog->time;
    }

    return aux;
}

int log_setServideId(eLog *auxLog, int serviceId)
{
    int retorno = 0;

    if(auxLog != NULL && serviceId > -1)
    {
        auxLog->serviceId = serviceId;
        retorno = 1;
    }

    return retorno;
}

int log_getServideId(eLog *auxLog)
{
    int retorno = -1;

    if(auxLog != NULL)
    {
        retorno = auxLog->serviceId;
    }

    return retorno;
}

int log_setGravedad(eLog *auxLog, int gravedad)
{
    int retorno = 0;

    if(auxLog != NULL && gravedad > -1)
    {
        auxLog->gravedad = gravedad;
        retorno = 1;
    }

    return retorno;
}

int log_getGravedad(eLog *auxLog)
{
    int retorno = -1;

    if(auxLog != NULL)
    {
        retorno = auxLog->gravedad;
    }

    return retorno;
}

int log_setMsg(eLog *auxLog, char *msg)
{
    int retorno = 0;

    if(auxLog != NULL && msg != NULL)
    {
        strcpy(auxLog->msg,msg);
        retorno = 1;
    }

    return retorno;
}

char* log_getMsg(eLog *auxLog)
{
    char *aux = NULL;

    if(auxLog != NULL)
    {
        aux = auxLog->msg;
    }

    return aux;
}

///Recorro el arraylist y muestro su contenido.
void log_prinAll(ArrayList *pLog)
{
    int i;
    for (i=0;i<al_len(pLog);i++)
    {
        eLog *auxLog = al_get(pLog,i);

        printf("Date: %s\nTime: %s\nServiceId: %d\nGravedad: %d\nMsg: %.30s\n\n",log_getDate(auxLog),log_getTime(auxLog),
        log_getServideId(auxLog),log_getGravedad(auxLog),log_getMsg(auxLog));
    }
}
