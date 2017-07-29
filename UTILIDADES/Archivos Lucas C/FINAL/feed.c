#include "defines.h"

int feed_add(ArrayList* pFeed, ArrayList* pUser, ArrayList* pMessage)
{
    int returnAux = 0;
    Feed* auxFeed;
    User* auxUser = user_new();
    Message* auxMessage = message_new();
    int i, j;
    if (pUser !=NULL && pMessage !=NULL && pFeed !=NULL)
    {
        for (i=0; i<al_len(pUser); i++)
        {
            auxUser = pUser->get(pUser,i);
            for (j=0; j<al_len(pMessage); j++)
            {
                auxMessage = pMessage->get(pMessage,j);
                if(user_getId(auxUser) == message_getUserId(auxMessage))
                {
                    auxFeed = feed_new();
                    feed_setFollowers(auxFeed,user_getFollowers(auxUser));
                    feed_setLikes(auxFeed,message_getLikes(auxMessage));
                    feed_setMessage(auxFeed,message_getMessage(auxMessage));
                    feed_setMessageId(auxFeed, message_getId(auxMessage));
                    feed_setNick(auxFeed,user_getNick(auxUser));
                    feed_setUserId(auxFeed,user_getId(auxUser));
                    al_add(pFeed,auxFeed);
                }
            }
        }
    }
    return returnAux;
}

int feed_save(ArrayList* this)
{
    int returnAux=0;
    if(this!=NULL)
    {
        FILE *f;
        f=fopen("feed.csv","w");
        if(f!=NULL)
        {
            Feed* feed=(Feed*)malloc(sizeof(Feed));
            int i;
            for(i=0;i<al_len(this);i++)
            {
                feed=al_get(this,i);
                fprintf(f,"%d,%s,%d,%d,%s,%d\n",feed_getMessageId(feed),feed_getMessage(feed),feed_getLikes(feed),feed_getUserId(feed),feed_getNick(feed),feed_getFollowers(feed));
            }
            returnAux=1;
        }
        fclose(f);
    }
    return returnAux;
}

Feed* feed_new()
{
    return (Feed*)malloc(sizeof(Feed));
}

int feed_setUserId(Feed* this, int id)
{
    int returnAux=-1;
    if(this!=NULL&& id>=0)
    {
        this->idUser=id;
        returnAux=0;
    }
    return returnAux;
}

int feed_getUserId(Feed* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->idUser;
    return returnAux;
}

int feed_setNick(Feed* this, char* nick)
{
    int returnAux=-1;
    if(this!=NULL&& nick!=NULL)
    {
         strcpy(this->nick,nick);
         returnAux=0;
    }
    return returnAux;
}

char* feed_getNick(Feed* this)
{
    char *returnAux=NULL;
    if(this != NULL)
        returnAux=this->nick;
    return returnAux;
}

int feed_setFollowers(Feed* this, int followers)
{
    int returnAux=-1;
    if(this!=NULL&& followers>=0)
    {
        this->followers=followers;
        returnAux=0;
    }
    return returnAux;
}

int feed_getFollowers(Feed* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->followers;
    return returnAux;
}

int feed_setMessageId(Feed* this, int id)
{
    int returnAux=-1;
    if(this!=NULL&& id>=0)
    {
        this->idMessage=id;
        returnAux=0;
    }
    return returnAux;
}

int feed_getMessageId(Feed* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->idMessage;
    return returnAux;
}

int feed_setMessage(Feed* this, char* message)
{
    int returnAux=-1;
    if(this!=NULL&& message!=NULL)
    {
         strcpy(this->message,message);
         returnAux=0;
    }
    return returnAux;
}

char* feed_getMessage(Feed* this)
{
    char *returnAux=NULL;
    if(this != NULL)
        returnAux=this->message;
    return returnAux;
}

int feed_setLikes(Feed* this, int likes)
{
    int returnAux=-1;
    if(this!=NULL&& likes>=0)
    {
        this->likes=likes;
        returnAux=0;
    }
    return returnAux;
}

int feed_getLikes(Feed* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->likes;
    return returnAux;
}

void feed_print(Feed* this)
{
    if(this!=NULL)
        printf("*User ID: %d *Nick: %s *Followers: %d *Message ID: %d *Likes: %d *%.10s\n",feed_getUserId(this),feed_getNick(this), feed_getFollowers(this),feed_getMessageId(this),feed_getLikes(this),feed_getMessage(this));
}

void feed_printAll(ArrayList* pList)
{
    int i;
    Feed* aux;
    aux = feed_new();
    if(pList!=NULL && aux!=NULL)
    for(i=0;i<pList->len(pList);i++)
    {
        aux=pList->get(pList,i);
        feed_print(aux);
    }
}

int feed_compare_two(void* inputA, void* inputB)
{
    int returnAux=0;
    if(inputA!=NULL &&inputB!=NULL)
    {
        int followersA = feed_getFollowers(inputA);
        int followersB = feed_getFollowers(inputB);
        int likesA = feed_getLikes(inputA);
        int likesB = feed_getLikes(inputB);
        if(followersA>followersB)
        {
            returnAux=1;
        }
        else if(followersA<followersB)
        {
            returnAux=-1;
        }
        else if(followersA==followersB)
        {
            if(likesA < likesB)
            {
                returnAux=-1;
            }
            else if(likesA > likesB)
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}


int feed_compare_likes(void* inputA, void* inputB)
{
    int returnAux=0;
    if(inputA!=NULL &&inputB!=NULL)
    {
        int likesA = feed_getLikes(inputA);
        int likesB = feed_getLikes(inputB);
        if(likesA < likesB)
        {
            returnAux=-1;
        }
        else if(likesA > likesB)
        {
            returnAux=1;
        }
        else if(likesA==likesB)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

int feed_compare_followers(void* inputA, void* inputB)
{
    int returnAux=0;
    if(inputA!=NULL &&inputB!=NULL)
    {
        int followersA = feed_getFollowers(inputA);
        int followersB = feed_getFollowers(inputB);
        if(followersA < followersB)
        {
            returnAux=-1;
        }
        else if(followersA > followersB)
        {
            returnAux=1;
        }
        else if(followersA==followersB)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

int feed_sort(ArrayList* pFeed)
{
    int returnAux=-1;
    if(pFeed!=NULL)
    {
        if(al_isEmpty(pFeed)==1)
        {
            returnAux=0;
        }
        else if(!al_isEmpty(pFeed))
        {
            al_sort(pFeed,feed_compare_two,0);
            returnAux=1;
        }
    }
    return returnAux;
}

int feed_sortTwo(ArrayList* this)
{
    int returnAux = -1;
    if (this!= NULL)
    {
        al_sortByDoubleParameter(this,feed_compare_followers,feed_compare_likes,0,0);
        returnAux = 0;
    }
    return returnAux;
}
