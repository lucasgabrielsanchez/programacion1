#ifndef MESSAGES_H
#define MESSAGES_H
typedef struct
{
    int idUser;
    int idMessage;
    char message[2500];
    int likes;
}Message;

int message_load(ArrayList* this);

Message* message_new();

int message_setId(Message* this, int id);

int message_getId(Message* this);

int message_setMessage(Message* this, char* message);

char* message_getMessage(Message* this);

int message_setLikes(Message* this, int likes);

int message_getLikes(Message* this);

int message_setUserId(Message* this, int idUser);

int message_getUserId(Message* this);

void message_print(Message* this);

void message_printAll(ArrayList* pList);



#endif // MESSAGES_H
