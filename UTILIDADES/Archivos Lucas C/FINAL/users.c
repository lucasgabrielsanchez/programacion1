#include "defines.h"

int user_load(ArrayList* this)
{
    int returnAux=0;
    User* user;
    if(this!=NULL)
    {
        char auxNick[51];
        char auxFollowers[51];
        char auxId[11];
        int auxIdInt;
        int auxFollowersInt;
        int cont=0;
        FILE *f;
        f=fopen("usuarios.csv","r");
        if(f!=NULL)
        {
            while(!feof(f))
            {
                fscanf(f,"%[^,],%[^,],%[^\n]\n",auxId,auxNick,auxFollowers);
                if(!cont)
                {
                    cont=1;
                    continue;
                }
                auxIdInt=atoi(auxId);
                auxFollowersInt=atoi(auxFollowers);
                user=user_new();
                user_setId(user,auxIdInt);
                user_setNick(user,auxNick);
                user_setFollowers(user,auxFollowersInt);
                al_add(this,user);
            }
        }
        fclose(f);
        if(cont)
            returnAux=1;
    }
    return returnAux;
}

User* user_new()
{
    return (User*)malloc(sizeof(User));
}

int user_setId(User* this, int id)
{
    int returnAux=-1;
    if(this!=NULL&& id>=0)
    {
        this->idUser=id;
        returnAux=0;
    }
    return returnAux;
}

int user_getId(User* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->idUser;
    return returnAux;
}

int user_setNick(User* this, char* nick)
{
    int returnAux=-1;
    if(this!=NULL&& nick!=NULL)
    {
         strcpy(this->nick,nick);
         returnAux=0;
    }
    return returnAux;
}

char* user_getNick(User* this)
{
    char *returnAux=NULL;
    if(this != NULL)
        returnAux=this->nick;
    return returnAux;
}

int user_setFollowers(User* this, int followers)
{
    int returnAux=-1;
    if(this!=NULL&& followers>=0)
    {
        this->followers=followers;
        returnAux=0;
    }
    return returnAux;
}

int user_getFollowers(User* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->followers;
    return returnAux;
}

void user_print(User* this)
{
    if(this!=NULL)
        printf("**User ID: %d\t**Nickname: %s\t**Followers: %d\n",user_getId(this),user_getNick(this), user_getFollowers(this));
}

void user_printAll(ArrayList* pList)
{
    int i;
    User* aux;
    aux = user_new();
    if(pList!=NULL && aux!=NULL)
    for(i=0;i<pList->len(pList);i++)
    {
        aux=pList->get(pList,i);
        user_print(aux);
    }
}
