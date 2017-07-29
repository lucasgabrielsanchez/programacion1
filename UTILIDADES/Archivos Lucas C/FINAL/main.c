#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

int main()
{
    ArrayList* pUsers = al_newArrayList();
    ArrayList* pMessages = al_newArrayList();
    ArrayList* pFeed = al_newArrayList();

    user_load(pUsers);
    message_load(pMessages);
    feed_add(pFeed, pUsers, pMessages);

    feed_printAll(pFeed);

    feed_sort(pFeed);
    //feed_sortTwo(pFeed);
    puts("\n\n\n\n");

    feed_printAll(pFeed);
    feed_save(pFeed);

    return 0;
}
