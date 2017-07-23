#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

typedef struct
{
    int id_mensaje;
    int id_usuario;
    int likes;
    char mensaje[3001];

}eMensaje;

int cargaMensajes(ArrayList *pMensajes);
eMensaje* new_mensaje();
int mensaje_setIdMensaje(eMensaje* mensaje, int idMensaje);
int mensaje_getIdMensaje(eMensaje* mensaje);
int mensaje_setIdUsuario(eMensaje* mensaje, int id);
int mensaje_getIdUsuario(eMensaje* mensaje);
int mensaje_setLikes(eMensaje* mensaje, int likes);
int mensaje_getLikes(eMensaje* mensaje);
int mensaje_setMensaje(eMensaje* mensaje, char* mensajeString);
char* mensaje_getMensaje(eMensaje* mensaje);
void mensaje_printAll(ArrayList *pMensajes);
