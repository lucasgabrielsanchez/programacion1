#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Temas.h"
#include "Usuarios.h"
#include "Controller.h"
#include "funciones.h"
int main()
{
    ArrayList* pTemas=al_newArrayList();
    ArrayList *pUsuarios=al_newArrayList();
    ArrayList *pTemasEscuchados=al_newArrayList();
    Temas* tema=Temas_newTema();
    Usuarios* usuario=Usuarios_newUsuario();
    if(loadThemes(pTemas,tema)&&loadUsers(pUsuarios,usuario))
        printf("Usuarios y temas cargados exitosamente\n");
    /*printThemes(pTemas,tema);*/
    /*printUsers(pUsuarios,usuario);*/
    int opcion=7;
    char auxOpcion[51];
    char seguir='s';
    int i;
    int j,k;
    TemasEscuchados *temaEscuchado = (TemasEscuchados*) malloc(sizeof(TemasEscuchados));
    if(loadStatistics(pTemasEscuchados))
        pausa("ESTADISTICAS CARGADAS EXITOSAMENTE");
    while(seguir=='s')
    {
        opcion=menu(auxOpcion);
        if(opcion) opcion=atoi(auxOpcion);
        else opcion=6;
        switch(opcion)
        {
        case 1:
            if(ordenarUsuariosPorNombreEId(pUsuarios,usuario)==1)
                puts("USUARIOS ORDENADOS ASCENDENTEMENTE POR NOMBRE E ID");
            break;
        case 2:
            break;
        case 3:
            system("cls");
            escucharTema(pUsuarios,usuario,pTemas,tema,pTemasEscuchados);
            break;
        case 4:


            break;
        case 5:
            system("cls");
            for(i=0;i<al_len(pTemasEscuchados);i++)
            {
                temaEscuchado=al_get(pTemasEscuchados,i);
                for(j=0;j<al_len(pUsuarios);j++)
                {
                    usuario=al_get(pUsuarios,j);
                    if(temaEscuchado->idUsuario==usuario->id)
                    {
                        break;
                       // printf("EMAIL:%s\tPASS:%s\n",usuario->email,usuario->password);
                    }
                }
                for(k=0;k<al_len(pTemas);k++)
                {
                    tema=al_get(pTemas,k);
                    if(tema->id==temaEscuchado->idTema)
                    {
                        printf("USUARIO:%s\t CANCION: %s\n",usuario->email,tema->tema);
                    }
                }
            }
            break;
        case 6:
            seguir='n';
            if(saveStatistics(pTemasEscuchados))
            {
                puts("ARCHIVO GUARDADO CORRECTAMENTE");
            }
            break;
        }
    }
    return 0;
}


