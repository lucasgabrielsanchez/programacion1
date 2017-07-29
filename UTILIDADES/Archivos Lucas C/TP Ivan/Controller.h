#include "ArrayList.h"
#include "Temas.h"
#include "Usuarios.h"
#include "funciones.h"
#ifndef __CONTROLLER
#define __CONTROLLER
typedef struct
{
    int idUsuario;
    int idTema;
    char nacionalidad[5];
}TemasEscuchados;
#endif
int loadThemes(ArrayList *pTemas,Temas *tema);

void printThemes(ArrayList *pThemes, Temas * tema);

int loadUsers(ArrayList *pUsuarios, Usuarios *usuario);

void printUsers(ArrayList * pUsuarios,Usuarios *usuario);

int compararUsuariosPorNombreEId(Usuarios * usuarioUno, Usuarios* usuarioDos);

int ordenarUsuariosPorNombreEId(ArrayList *pUser,Usuarios *user);

int user_compare_id(void* usuarioUno, void* usuarioDos);

int user_compare_name(void* usuarioUno, void* usuarioDos);

int user_compare_two(void* usuarioUno, void* usuarioDos);

void escucharTema(ArrayList* pUser, Usuarios* user,ArrayList *pThemes,Temas *temas,ArrayList *pTemaEscuchado);

int loadStatistics(ArrayList *this);

int saveStatistics(ArrayList *this);
