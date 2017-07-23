#include "includes.h"

eFeed* new_feed()
{
    return (eFeed*)malloc(sizeof(eFeed));
}

int feed_setIdMensaje(eFeed *feed, int idMensaje)
{
    int retorno = 0;

    if(feed != NULL && idMensaje>-1)
    {
        feed->idMensaje = idMensaje;
        retorno = 1;
    }

    return retorno;
}

int feed_getIdMensaje(eFeed *feed)
{
    int retorno = -1;

    if(feed != NULL)
    {
        retorno = feed->idMensaje;
    }

    return retorno;
}

int feed_setMensaje(eFeed *feed, char *mensajeString)
{
    int retorno = 0;

    if(feed != NULL && mensajeString != NULL)
    {
        strcpy(feed->mensaje,mensajeString);
        retorno=1;
    }

    return retorno;
}

char* feed_getMensaje(eFeed *feed)
{
    char *mensajeAux = NULL;

    if(feed != NULL)
    {
        mensajeAux = feed->mensaje;
    }

    return mensajeAux;
}

int feed_setLikes(eFeed *feed, int likes)
{
    int retorno = 0;

    if(feed != NULL && likes > -1)
    {
        feed->likes = likes;
        retorno = 1;
    }

    return retorno;
}

int feed_getLikes(eFeed *feed)
{
    int retorno = -1;

    if(feed != NULL)
    {
        retorno = feed->likes;
    }

    return retorno;
}

int feed_setIdUsuario(eFeed *feed, int id)
{
    int retorno = 0;

    if(feed != NULL && id>-1)
    {
        feed->idUsuario = id;
        retorno =1;
    }

    return retorno;
}

int feed_getIdUsuario(eFeed *feed)
{
    int retorno = -1;

    if(feed != NULL)
    {
        retorno = feed->idUsuario;
    }

    return retorno;
}

int feed_setNick(eFeed *feed, char *nick)
{
    int retorno = 0;

    if(feed != NULL && nick != NULL)
    {
        strcpy(feed->nick,nick);
        retorno =1;
    }

    return retorno;
}

char* feed_getNick(eFeed *feed)
{
    char *retorno = NULL;

    if(feed != NULL)
    {
        //retorno = (char*)malloc(strlen(feed->nick)+1);
        //strcpy(retorno,feed->nick);
        retorno = feed->nick;
    }

    return retorno;
}

int feed_setFollowers(eFeed *feed, int followers)
{
    int retorno = 0;

    if(feed != NULL && followers>-1)
    {
        feed->followers = followers;
        retorno =1;
    }

    return retorno;
}

int feed_getFollowers(eFeed *feed)
{
    int retorno = -1;

    if(feed != NULL)
    {
        retorno = feed->followers;
    }

    return retorno;
}

void crearFeed(ArrayList *pUsuarios, ArrayList *pMensajes, ArrayList *pFeeds)
{
    int i,j;
    eMensaje *auxMensaje = new_mensaje();
    eUsuario *auxUsuario = new_usuario();
    eFeed *auxFeed;

    if(pUsuarios != NULL && pMensajes != NULL && pFeeds != NULL)
    {
        if(!al_isEmpty(pFeeds))
        {
            al_clear(pFeeds);
        }

        for (i=0 ; i<al_len(pMensajes) ; i++)
        {
            auxMensaje = al_get(pMensajes,i);

                for (j=0 ; j<al_len(pUsuarios) ; j++)
                {
                    auxUsuario = al_get(pUsuarios,j);

                    if(auxMensaje->id_usuario == auxUsuario->id)
                    {
                        auxFeed = new_feed();

                        feed_setIdMensaje(auxFeed,auxMensaje->id_mensaje);
                        feed_setMensaje(auxFeed,auxMensaje->mensaje);
                        feed_setLikes(auxFeed,auxMensaje->likes);
                        feed_setIdUsuario(auxFeed,auxUsuario->id);
                        feed_setNick(auxFeed,auxUsuario->nick);
                        feed_setFollowers(auxFeed,auxUsuario->followers);

                        al_add(pFeeds,auxFeed);
                    }
                }
        }
    }
}

void feed_printAll(ArrayList *pFeeds)
{
    int i;
    if(pFeeds != NULL)
    {
        for(i=0; i<al_len(pFeeds);i++)
        {
            eFeed *auxFeed = new_feed();
            auxFeed = al_get(pFeeds,i);
            printf("IDMensaje: %d\nMensaje: %.30s\nLikes: %d\nidUsuario: %d\nNick: %s\nFollowers: %d\n\n",feed_getIdMensaje(auxFeed),
                   feed_getMensaje(auxFeed),feed_getLikes(auxFeed),feed_getIdUsuario(auxFeed),feed_getNick(auxFeed),
                   feed_getFollowers(auxFeed));

        }
    }
}

int compararFeeds(void* inputA, void* inputB)
{
    int returnAux = 0;

    if(inputA != NULL && inputB != NULL)
    {
        int followersA = feed_getFollowers(inputA);
        int followersB = feed_getFollowers(inputB);
        int likesA = feed_getLikes(inputA);
        int likesB = feed_getLikes(inputB);

        if(followersA>followersB)
        {
            returnAux = 1;
        }
        else if(followersA<followersB)
        {
            returnAux = -1;
        }
        else if(followersA==followersB)
        {
            if(likesA > likesB)
            {
                returnAux = 1;
            }
            else if(likesA < likesB)
            {
                returnAux = -1;
            }
        }
    }
    return returnAux;
}

int guardarFeed (ArrayList* pFeed)
{
    int returnAux = 0;
    FILE *f;
    eFeed* auxFeed;
    int i;

    if(pFeed != NULL)
    {
        f = fopen("feed.csv","w");

        if(f!=NULL)
        {
            auxFeed = new_feed();

            for(i=0;i<al_len(pFeed);i++)
            {
                auxFeed = al_get(pFeed,i);
                if(i==0)
                {
                    fprintf(f,"%s,%s,%s,%s,%s,%s\n","IdMensaje","Mensaje","Likes","IdUsuario","Nick","Followers");
                }
                fprintf(f,"%d,%.20s,%d,%d,%s,%d\n",feed_getIdMensaje(auxFeed),feed_getMensaje(auxFeed),feed_getLikes(auxFeed),feed_getIdUsuario(auxFeed),feed_getNick(auxFeed),feed_getFollowers(auxFeed));
            }
            returnAux=1;
        }
        fclose(f);
    }
    return returnAux;
}

