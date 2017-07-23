#include "includes.h"

int cargaMensajes(ArrayList *pMensajes)
{
    int retorno = 0;
    int cont = 0;
    eMensaje *auxMensajeStruct;

    if(pMensajes!=NULL)
    {
        if(al_len(pMensajes) != 0)
        {
            al_clear(pMensajes);
        }

        char auxIdMensaje[51];
        char auxIdUsuario[51];
        char auxLikes[51];
        char auxMensaje[3001];
        int auxIdMensajeInt;
        int auxIdUsuarioInt;
        int auxLikesInt;

        FILE *archivo;
        archivo=fopen("mensajes.csv","r");
        if(archivo!=NULL)
        {
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxIdMensaje,auxIdUsuario,auxLikes,auxMensaje);
                if(!cont)
                {
                    cont=1;
                    continue;
                }

                auxMensajeStruct = new_mensaje();

                auxIdMensajeInt = atoi(auxIdMensaje);
                auxIdUsuarioInt = atoi(auxIdUsuario);
                auxLikesInt = atoi(auxLikes);

                mensaje_setIdMensaje(auxMensajeStruct,auxIdMensajeInt);
                mensaje_setIdUsuario(auxMensajeStruct,auxIdUsuarioInt);
                mensaje_setLikes(auxMensajeStruct,auxLikesInt);
                mensaje_setMensaje(auxMensajeStruct,auxMensaje);

                al_add(pMensajes,auxMensajeStruct);
            }
        }
        fclose(archivo);
        if(cont)
            retorno=1;
    }
    return retorno;
}

eMensaje* new_mensaje()
{
    return (eMensaje*)malloc(sizeof(eMensaje));
}

int mensaje_setIdMensaje(eMensaje* mensaje, int idMensaje)
{
    int retorno = 0;

    if(mensaje != NULL && idMensaje>-1)
    {
        mensaje->id_mensaje = idMensaje;
        retorno = 1;
    }

    return retorno;
}

int mensaje_getIdMensaje(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->id_mensaje;
    }

    return retorno;
}

int mensaje_setIdUsuario(eMensaje* mensaje, int id)
{
    int retorno = 0;

    if(mensaje != NULL && id > -1)
    {
        mensaje->id_usuario = id;
        retorno = 1;
    }

    return retorno;
}

int mensaje_getIdUsuario(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->id_usuario;
    }

    return retorno;
}

int mensaje_setLikes(eMensaje* mensaje, int likes)
{
    int retorno = 0;

    if(mensaje != NULL && likes > -1)
    {
        mensaje->likes = likes;
        retorno = 1;
    }

    return retorno;
}

int mensaje_getLikes(eMensaje* mensaje)
{
    int retorno = -1;

    if(mensaje != NULL)
    {
        retorno = mensaje->likes;
    }

    return retorno;
}

int mensaje_setMensaje(eMensaje* mensaje, char *mensajeString)
{
    int retorno = 0;

    if(mensaje != NULL && mensajeString != NULL)
    {
        strcpy(mensaje->mensaje,mensajeString);
        retorno=1;
    }

    return retorno;
}

char* mensaje_getMensaje(eMensaje* mensaje)
{
    char *mensajeAux = NULL;

    if(mensaje != NULL)
    {
        mensajeAux = mensaje->mensaje;
    }

    return mensajeAux;
}

void mensaje_printAll(ArrayList *pMensajes)
{
    int i;
    if(pMensajes != NULL)
    {
        for(i=0; i<al_len(pMensajes);i++)
        {
            eMensaje *auxMensaje = new_mensaje();
            auxMensaje = al_get(pMensajes,i);
            printf("IDMensaje: %d\nIDUsuario: %d\nLikes: %d\nParteMensaje: %.40s\n\n",mensaje_getIdMensaje(auxMensaje),mensaje_getIdUsuario(auxMensaje),mensaje_getLikes(auxMensaje),mensaje_getMensaje(auxMensaje));
        }
    }
}

