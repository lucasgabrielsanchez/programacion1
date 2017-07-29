#include "defines.h"

int message_load(ArrayList* this)
{
    int returnAux=0;
    Message* message;
    if(this!=NULL)
    {
        char auxMessage[2500];
        char auxLikes[51];
        char auxId[11];
        char auxUserId[11];
        int auxIdInt;
        int auxUserIdInt;
        int auxLikesInt;
        int cont=0;
        FILE *f;
        f=fopen("mensajes.csv","r");
        if(f!=NULL)
        {
            while(!feof(f))
            {
                fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n\n",auxId,auxUserId,auxLikes,auxMessage);
                if(!cont)
                {
                    cont=1;
                    continue;
                }
                auxIdInt=atoi(auxId);
                auxUserIdInt=atoi(auxUserId);
                auxLikesInt=atoi(auxLikes);
                message=message_new();
                message_setId(message,auxIdInt);
                message_setMessage(message,auxMessage);
                message_setLikes(message,auxLikesInt);
                message_setUserId(message,auxUserIdInt);
                al_add(this,message);
            }
        }
        fclose(f);
        if(cont)
            returnAux=1;
    }
    return returnAux;
}

Message* message_new()
{
    return (Message*)malloc(sizeof(Message));
}

int message_setId(Message* this, int id)
{
    int returnAux=-1;
    if(this!=NULL&& id>=0)
    {
        this->idMessage=id;
        returnAux=0;
    }
    return returnAux;
}

int message_getId(Message* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->idMessage;
    return returnAux;
}

int message_setMessage(Message* this, char* message)
{
    int returnAux=-1;
    if(this!=NULL&& message!=NULL)
    {
         strcpy(this->message,message);
         returnAux=0;
    }
    return returnAux;
}

char* message_getMessage(Message* this)
{
    char *returnAux=NULL;
    if(this != NULL)
        returnAux=this->message;
    return returnAux;
}

int message_setLikes(Message* this, int likes)
{
    int returnAux=-1;
    if(this!=NULL&& likes>=0)
    {
        this->likes=likes;
        returnAux=0;
    }
    return returnAux;
}

int message_getLikes(Message* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->likes;
    return returnAux;
}

int message_setUserId(Message* this, int idUser)
{
    int returnAux=-1;
    if(this!=NULL&& idUser>=0)
    {
        this->idUser=idUser;
        returnAux=0;
    }
    return returnAux;
}

int message_getUserId(Message* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->idUser;
    return returnAux;
}

void message_print(Message* this)
{
    if(this!=NULL)
        printf("**Message ID: %d\t**User ID: %d\t**Likes: %d\t**%s\n",message_getId(this),message_getUserId(this), message_getLikes(this),message_getMessage(this));
}

void message_printAll(ArrayList* pList)
{
    int i;
    Message* aux;
    aux = message_new();
    if(pList!=NULL && aux!=NULL)
    for(i=0;i<pList->len(pList);i++)
    {
        aux=pList->get(pList,i);
        message_print(aux);
    }
}
