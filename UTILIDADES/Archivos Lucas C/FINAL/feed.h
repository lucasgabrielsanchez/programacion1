#ifndef FEED_H
#define FEED_H
typedef struct
{
    int idUser;
    char nick[50];
    int followers;
    int idMessage;
    char message[2500];
    int likes;
}Feed;

int feed_add(ArrayList* pFeed, ArrayList* pUser, ArrayList* pMessage);

int feed_save(ArrayList* this);

Feed* feed_new();

int feed_setUserId(Feed* this, int id);

int feed_getUserId(Feed* this);

int feed_setNick(Feed* this, char* nick);

char* feed_getNick(Feed* this);

int feed_setFollowers(Feed* this, int followers);

int feed_getFollowers(Feed* this);

int feed_setMessageId(Feed* this, int id);

int feed_getMessageId(Feed* this);

int feed_setMessage(Feed* this, char* message);

char* feed_getMessage(Feed* this);

int feed_setLikes(Feed* this, int likes);

int feed_getLikes(Feed* this);

void feed_print(Feed* this);

void feed_printAll(ArrayList* pList);

int feed_compare_two(void* inputA, void* inputB);

int feed_compare_likes(void* inputA, void* inputB);

int feed_compare_followers(void* inputA, void* inputB);

int feed_sort(ArrayList* pFeed);

int feed_sortTwo(ArrayList* this);

#endif // FEED_H

