

typedef struct
{
    int id;
    char nick[51];
    int followers;

}eUsuario;

int cargaUsuarios(ArrayList *pUsuarios);
eUsuario* new_usuario();

int usuario_setId(eUsuario* usuario, int id);
int usuario_getId(eUsuario* usuario);
int usuario_setNick(eUsuario* usuario, char *nick);
char* usuario_getNick(eUsuario* usuario);
int usuario_setFollowers(eUsuario* usuario, int followers);
int usuario_getFollowers(eUsuario* usuario);
void usuario_printAll(ArrayList *pUsuarios);
