#ifndef USERS_H
#define USERS_H

typedef struct
{
    int idUser;
    char nick[50];
    int followers;
}User;

int user_load(ArrayList* this);

int user_setId(User* this, int id);

int user_getId(User* this);

int user_setNick(User* this, char* nick);

char* user_getNick(User* this);

int user_setFollowers(User* this, int followers);

int user_getFollowers(User* this);

void user_print(User* this);

void user_printAll(ArrayList* pList);

User* user_new();

#endif // USERS_H
