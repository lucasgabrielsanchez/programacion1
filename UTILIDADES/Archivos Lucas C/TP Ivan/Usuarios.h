#ifndef __USUARIOS
#define __USUARIOS
typedef struct
{
    int id;
    char nombre[51];
    char email[101];
    char sexo[10];
    char nacionalidad[5];
    char password[51];
    char ip[26];
}Usuarios;
#endif // __USUARIOS

Usuarios * Usuarios_newUsuario(void);

void Usuarios_printUsuario(Usuarios *this);

int Usuarios_setId(Usuarios *this, int id);

int Usuarios_setIp(Usuarios *this, char *ip);

int Usuarios_setEmail(Usuarios *this, char *email);

int Usuarios_setNacionalidad(Usuarios *this, char *nacionalidad);

int Usuarios_setNombre(Usuarios *this, char *nombre);

int Usuarios_setSexo(Usuarios *this, char *sexo);

int Usuarios_setPassword(Usuarios *this, char *password);

int Usuarios_getId(Usuarios* this);

char* Usuarios_getName(Usuarios* this);
