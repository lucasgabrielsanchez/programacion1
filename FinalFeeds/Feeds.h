
typedef struct
{
    int idMensaje;
    char mensaje[2500];
    int likes;
    int idUsuario;
    char nick [100];
    int followers;
}eFeed;


eFeed* new_feed ();
int feed_setIdMensaje(eFeed *feed, int idMensaje);
int feed_getIdMensaje(eFeed *feed);
int feed_setMensaje(eFeed *feed, char *mensajeString);
char* feed_getMensaje(eFeed *feed);
int feed_setLikes(eFeed *feed, int likes);
int feed_getLikes(eFeed *feed);
int feed_setIdUsuario(eFeed *feed, int id);
int feed_getIdUsuario(eFeed *feed);
int feed_setNick(eFeed *feed, char *nick);
char* feed_getNick(eFeed *feed);
int feed_setFollowers(eFeed *feed, int followers);
int feed_getFollowers(eFeed *feed);
void crearFeed(ArrayList *pUsuarios, ArrayList *pMensajes, ArrayList *pFeeds);
void feed_printAll(ArrayList *pFeeds);
int compararFeeds(void* inputA, void* inputB);
int guardarFeed (ArrayList* pFeed);



