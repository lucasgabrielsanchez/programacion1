#include "includes.h"

int cargaUsuarios(ArrayList *pUsuarios)
{
    int retorno = 0;
    int cont = 0;
    eUsuario *auxUsuario;

    if(pUsuarios!=NULL)
    {
        if(al_len(pUsuarios) != 0)
        {
            al_clear(pUsuarios);
        }

        char auxId[51];
        char auxNick[51];
        char auxFollowers[51];
        int auxIdInt;
        int auxFollowersInt;

        FILE *archivo;
        archivo=fopen("usuarios.csv","r");
        if(archivo!=NULL)
        {
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^\n]\n",auxId,auxNick,auxFollowers);
                if(!cont)
                {
                    cont=1;
                    continue;
                }
                auxIdInt=atoi(auxId);
                auxFollowersInt=atoi(auxFollowers);

                auxUsuario=new_usuario();

                usuario_setId(auxUsuario,auxIdInt);
                usuario_setNick(auxUsuario,auxNick);
                usuario_setFollowers(auxUsuario,auxFollowersInt);

                al_add(pUsuarios,auxUsuario);
            }
        }
        fclose(archivo);
        if(cont)
            retorno=1;
    }
    return retorno;
}

eUsuario* new_usuario()
{
    return (eUsuario*)malloc(sizeof(eUsuario));
}

int usuario_setId(eUsuario* usuario, int id)
{
    int retorno = 0;

    if(usuario != NULL && id>-1)
    {
        usuario->id = id;
        retorno =1;
    }

    return retorno;
}

int usuario_getId(eUsuario* usuario)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        retorno = usuario->id;
    }

    return retorno;
}

int usuario_setNick(eUsuario* usuario, char *nick)
{
    int retorno = 0;

    if(usuario != NULL && nick != NULL)
    {
        strcpy(usuario->nick,nick);
        retorno =1;
    }

    return retorno;
}

char* usuario_getNick(eUsuario* usuario)
{
    char *retorno = NULL;

    if(usuario != NULL)
    {
        //retorno = (char*)malloc(strlen(usuario->nick)+1);
        //strcpy(retorno,usuario->nick);
        retorno = usuario->nick;
    }

    return retorno;
}

int usuario_setFollowers(eUsuario* usuario, int followers)
{
    int retorno = 0;

    if(usuario != NULL && followers>-1)
    {
        usuario->followers = followers;
        retorno =1;
    }

    return retorno;
}

int usuario_getFollowers(eUsuario* usuario)
{
    int retorno = -1;

    if(usuario != NULL)
    {
        retorno = usuario->followers;
    }

    return retorno;
}

void usuario_printAll(ArrayList *pUsuarios)
{
    int i;
    if(pUsuarios != NULL)
    {
        for(i=0; i<al_len(pUsuarios);i++)
        {
            eUsuario *auxUsuario = new_usuario();
            auxUsuario = al_get(pUsuarios,i);
            printf("ID: %d\nNick: %s\nFollowers: %d\n\n",usuario_getId(auxUsuario),usuario_getNick(auxUsuario),usuario_getFollowers(auxUsuario));
        }
    }
}

