#include "Includes.h"

int cargaTarjeta(ArrayList *pTarjetas)
{
    int retorno = 0;
    ///contador que utilizaré para saltear la primer línea del archivo.
    int cont = 0;
    eTarjeta *auxTarjeta;
    FILE *archivo;
    char auxId[21];
    char auxNombre[51];
    char auxApellido[51];
    char auxMail[51];
    char auxNumTarjeta[51];

    ///Verifico que el arraylist no sea nulo.
    if(pTarjetas!=NULL)
    {
        ///Si contiene elementos lo vacío para cargarlo limpio.
        if(al_len(pTarjetas) != 0)
        {
            al_clear(pTarjetas);
        }

        archivo=fopen("data.csv","r");
        ///verifico que el archivo no sea nulo.
        if(archivo!=NULL)
        {
            ///Mientras NO sea el final del archivo, se leerá el mismo.
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxMail,auxNumTarjeta);

                ///esto provoca que la primer línea no sea leída, cuando un archivo tiene datos que no nos sirven en dicha línea.
                if(!cont)
                {
                    cont=1;
                    continue;
                }

                auxTarjeta = new_tarjeta();

                if(esNumerico(auxId))
                {
                    if (esSoloLetras(auxNombre))
                    {
                        if (esSoloLetras(auxApellido))
                        {
                            if (esMail(auxMail))
                            {
                                if (strlen(auxNumTarjeta) == 13 || strlen(auxNumTarjeta) == 15 || strlen(auxNumTarjeta) == 16)
                                {
                                    switch (validarTarjeta(auxNumTarjeta))
                                    {
                                    case MASTER:
                                        auxTarjeta->tipoTarjeta = MASTER;
                                        break;
                                    case VISA:
                                        auxTarjeta->tipoTarjeta = VISA;
                                        break;
                                    case AMERICAN:
                                        auxTarjeta->tipoTarjeta = AMERICAN;
                                        break;
                                    default:
                                        auxTarjeta->tipoTarjeta = INVALIDA;
                                        strcpy(auxTarjeta->errorMsg,"Numero de Tarjeta Sintacticamente Invalido");
                                        break;
                                    }
                                }
                                else
                                {
                                    strcpy(auxTarjeta->errorMsg,"Longitud de numero de tarjeta invalida");
                                    auxTarjeta->tipoTarjeta = INVALIDA;
                                }

                            }
                            else
                            {
                                strcpy(auxTarjeta->errorMsg,"Mail Invalido");
                                auxTarjeta->tipoTarjeta = INVALIDA;
                            }

                        }
                        else
                        {
                            strcpy(auxTarjeta->errorMsg,"Apellido Invalido");
                            auxTarjeta->tipoTarjeta = INVALIDA;
                        }
                    }
                    else
                    {
                        strcpy(auxTarjeta->errorMsg,"Nombre Invalido");
                        auxTarjeta->tipoTarjeta = INVALIDA;
                    }
                }
                else
                {
                    strcpy(auxTarjeta->errorMsg,"ID Invalido");
                    auxTarjeta->tipoTarjeta = INVALIDA;
                }
                tarjeta_setId(auxTarjeta,auxId);
                tarjeta_setNombre(auxTarjeta,auxNombre);
                tarjeta_setApellido(auxTarjeta,auxApellido);
                tarjeta_setMail(auxTarjeta,auxMail);
                tarjeta_setNumTarjeta(auxTarjeta,auxNumTarjeta);

                al_add(pTarjetas,auxTarjeta);
            }
        }
        fclose(archivo);

        ///si el cont es 1, significa que se leyó aunque sea una línea.
        if(cont)
        {
            retorno=1;
        }
    }
    return retorno;
}

eTarjeta* new_tarjeta()
{
    return (eTarjeta*)malloc(sizeof(eTarjeta));
}

int tarjeta_setId(eTarjeta *auxTarjeta, char *id)
{
    int retorno = 0;

    if(auxTarjeta != NULL && id != NULL)
    {
        strcpy(auxTarjeta->id,id);
        retorno = 1;
    }

    return retorno;
}

int tarjeta_setNombre(eTarjeta *auxTarjeta, char *nombre)
{
    int retorno = 0;

    if(auxTarjeta != NULL && nombre != NULL)
    {
        strcpy(auxTarjeta->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

int tarjeta_setApellido(eTarjeta *auxTarjeta, char *apellido)
{
    int retorno = 0;

    if(auxTarjeta != NULL && apellido != NULL)
    {
        strcpy(auxTarjeta->apellido,apellido);
        retorno = 1;
    }

    return retorno;
}

int tarjeta_setMail(eTarjeta *auxTarjeta, char *mail)
{
    int retorno = 0;

    if(auxTarjeta != NULL && mail != NULL)
    {
        strcpy(auxTarjeta->mail,mail);
        retorno = 1;
    }

    return retorno;
}

int tarjeta_setNumTarjeta(eTarjeta *auxTarjeta, char *numTarjeta)
{
    int retorno = 0;

    if(auxTarjeta != NULL && numTarjeta != NULL)
    {
        strcpy(auxTarjeta->numTarjeta,numTarjeta);
        retorno = 1;
    }

    return retorno;
}

int validarTarjeta(char *numTarjeta)
{
    int retorno = -1;

    if(numTarjeta != NULL)
    {
        if(strlen(numTarjeta) == 13 || strlen(numTarjeta) == 16)
        {
            if(numTarjeta[0] == '4')
            {
                if(validarSintaxis(numTarjeta))
                {
                    retorno = VISA;
                }
            }
            else if(numTarjeta[0] == '5' && (numTarjeta[1] > '0' && numTarjeta[1] < '6'))
            {
                if(validarSintaxis(numTarjeta))
                {
                    retorno = MASTER;
                }
            }
        }
        else if(strlen(numTarjeta) == 15)
        {
            if(numTarjeta[0] == '3' && (numTarjeta[1] == '4' || numTarjeta[1] == '7'))
            {
                if(validarSintaxis(numTarjeta))
                {
                    retorno = AMERICAN;
                }
            }
        }

    }

    return retorno;
}

int validarSintaxis(char *numTarjeta)
{
    int retorno = 0,i,acum = 0;
    char *auxString;
    int auxArrayInt[strlen(numTarjeta)];

    if(numTarjeta != NULL)
    {
        auxString = numTarjeta;

        strrev(auxString);

        arrayCharToArrayInt(auxString,auxArrayInt);

        for(i=0; i<strlen(numTarjeta); i++)
        {
            if(i%2 == 0)
            {
                continue;
            }

            auxArrayInt[i] *= 2;

            if(auxArrayInt[i] > 9)
            {
                auxArrayInt[i] -= 9;
            }

        }

        for(i=0; i<strlen(numTarjeta); i++)
        {
            acum += auxArrayInt[i];
        }

        if(acum % 10 == 0)
        {
            retorno = 1;
        }

    }

    return retorno;
}

void printearValidos(ArrayList *pTarjetas)
{
    int i;
    eTarjeta *auxTarjeta;

    for(i=0; i<al_len(pTarjetas); i++)
    {
        auxTarjeta = new_tarjeta();
        auxTarjeta = al_get(pTarjetas,i);

        if(auxTarjeta->tipoTarjeta < INVALIDA)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nMail: %s\nNumero Tarjeta: %s\n",auxTarjeta->id,auxTarjeta->nombre,auxTarjeta->apellido,auxTarjeta->mail,auxTarjeta->numTarjeta);
            switch (auxTarjeta->tipoTarjeta)
            {
            case MASTER:
                printf("Tipo de Tarjeta: Master\n\n");
                break;
            case VISA:
                printf("Tipo de Tarjeta: Visa\n\n");
                break;
            case AMERICAN:
                printf("Tipo de Tarjeta: American\n\n");
                break;
            }

        }
    }
}

void printearPorTipo(ArrayList *pTarjetas, int tipo)
{
    int i;
    eTarjeta *auxTarjeta;

    for(i=0; i<al_len(pTarjetas); i++)
    {
        auxTarjeta = new_tarjeta();
        auxTarjeta = al_get(pTarjetas,i);

        if(auxTarjeta->tipoTarjeta == tipo)
        {
            printf("ID: %s\nNombre: %s\nApellido: %s\nMail: %s\nNumero Tarjeta: %s\n",auxTarjeta->id,auxTarjeta->nombre,auxTarjeta->apellido,auxTarjeta->mail,auxTarjeta->numTarjeta);
            switch (tipo)
            {
            case MASTER:
                printf("Tipo de Tarjeta: Master\n\n");
                break;
            case VISA:
                printf("Tipo de Tarjeta: Visa\n\n");
                break;
            case AMERICAN:
                printf("Tipo de Tarjeta: American\n\n");
                break;
            case INVALIDA:
                printf("Error: %s\n\n",auxTarjeta->errorMsg);
                break;
            }

        }
    }
}
