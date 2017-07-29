#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

int loadThemes(ArrayList *pTemas,Temas *tema)
{
    int returnAux=0;
    if(pTemas!=NULL&&tema!=NULL)
    {
        char auxTema[51];
        char auxArtista[51];
        char auxId[11];
        int auxIdInt;
        int cont=0;
        FILE *f;
        f=fopen("temas.dat","r");
        if(f!=NULL)
        {
            while(!feof(f))
            {
                fscanf(f,"%[^,],%[^,],%[^\n]\n",auxId,auxTema,auxArtista);
                if(!cont)
                {
                    cont=1;
                    continue;
                }
                auxIdInt=atoi(auxId);
                tema=Temas_newTema();
                Temas_setId(tema,auxIdInt);
                Temas_setNombre(tema,auxArtista);
                Temas_setTema(tema,auxTema);
                al_add(pTemas,tema);
            }
        }
        fclose(f);
        if(cont)
            returnAux=1;
    }
    return returnAux;
}

void printThemes(ArrayList *pThemes, Temas * tema)
{
    if(pThemes!=NULL&&tema!=NULL)
    {
        int i;
        for(i=0;i<al_len(pThemes);i++)
        {
            tema=al_get(pThemes,i);
            Temas_printTema(tema);
        }
    }
}

int loadUsers(ArrayList *pUsuarios, Usuarios *usuario)
{
    int returnAux=0;
    if(pUsuarios!=NULL&&usuario!=NULL)
    {
        FILE *aUsuario;
        aUsuario=fopen("usuarios.dat","r");
        int flag=0;
        if(aUsuario!=NULL)
        {
            char id[11];
            char name[51];
            char email[101];
            char sexo[11];
            char nacionalidad[5];
            char contra[51];
            char ip[26];
            int idInt;
            while(!feof(aUsuario))
            {
                fscanf(aUsuario,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,email,sexo,nacionalidad,contra,ip);
                if(!flag)
                {
                    flag=1;
                    continue;
                }
                idInt=atoi(id);
                usuario=Usuarios_newUsuario();
                Usuarios_setEmail(usuario,email);
                Usuarios_setId(usuario,idInt);
                Usuarios_setIp(usuario,ip);
                Usuarios_setNacionalidad(usuario,nacionalidad);
                Usuarios_setNombre(usuario,name);
                Usuarios_setPassword(usuario,contra);
                Usuarios_setSexo(usuario,sexo);
                al_add(pUsuarios,usuario);
            }
            fclose(aUsuario);
        }
        if(flag)
            returnAux=1;
    }
    return returnAux;
}

void printUsers(ArrayList * pUsuarios,Usuarios *usuario)
{
    if(pUsuarios!=NULL&&usuario!=NULL)
    {
        int i;
        for(i=0;i</*al_len(pUsuarios)*/20;i++)
        {
            usuario=al_get(pUsuarios,i);
            printf("Usuario %d:\n",i+1);
            Usuarios_printUsuario(usuario);
        }
    }
}

int compararUsuariosPorNombreEId(Usuarios * usuarioUno, Usuarios* usuarioDos)
{
    int returnAux=0;
    if(usuarioUno!=NULL &&usuarioDos!=NULL)
    {
        if(stricmp(usuarioUno->nombre,usuarioDos->nombre)>0)
        {
            returnAux=1;
        }
        else if(stricmp(usuarioUno->nombre,usuarioDos->nombre)<0)
        {
            returnAux=-1;
        }
        else if(!stricmp(usuarioUno->nombre,usuarioDos->nombre))
        {
            if(usuarioUno->id<usuarioDos->id)
            {
                returnAux=-1;
            }
            else if(usuarioUno->id>usuarioDos->id)
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}

int user_compare_two(void* usuarioUno, void* usuarioDos)
{
    int returnAux=0;
    if(usuarioUno!=NULL &&usuarioDos!=NULL)
    {
        char name1[100];
        char name2[100];
        strncpy(name1,Usuarios_getName(usuarioUno),99);
        strncpy(name2,Usuarios_getName(usuarioDos),99);
        int idA = Usuarios_getId(usuarioUno);
        int idB = Usuarios_getId(usuarioDos);
        if(stricmp(name1,name2)>0)
        {
            returnAux=1;
        }
        else if(stricmp(name1,name2)<0)
        {
            returnAux=-1;
        }
        else if(!stricmp(name1,name2))
        {
            if(idA < idB)
            {
                returnAux=-1;
            }
            else if(idA > idB)
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}

int user_compare_name(void* usuarioUno, void* usuarioDos)
{
    int returnAux=0;
    char name1[100];
    char name2[100];
    if(usuarioUno!=NULL &&usuarioDos!=NULL)
    {
        strncpy(name1,Usuarios_getName(usuarioUno),99);
        strncpy(name2,Usuarios_getName(usuarioDos),99);
        if(stricmp(name1,name2)>0)
        {
            returnAux=1;
        }
        else if(stricmp(name1,name2)<0)
        {
            returnAux=-1;
        }
        else if(!stricmp(name1,name2))
        {
            returnAux=0;
        }
    }
    return returnAux;
}

int user_compare_id(void* usuarioUno, void* usuarioDos)
{
    int returnAux=0;
    if(usuarioUno!=NULL &&usuarioDos!=NULL)
    {
        int idA = Usuarios_getId(usuarioUno);
        int idB = Usuarios_getId(usuarioDos);
        if(idA < idB)
        {
            returnAux=-1;
        }
        else if(idA > idB)
        {
            returnAux=1;
        }
        else if(idA==idB)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

int ordenarUsuariosPorNombreEId(ArrayList *pUser,Usuarios *user)
{
    int returnAux=-1;
    if(pUser!=NULL&&user!=NULL)
    {
        if(al_isEmpty(pUser)==1)
        {
            returnAux=0;
        }
        else if(!al_isEmpty(pUser))
        {
            al_sort(pUser,compararUsuariosPorNombreEId,1);
            returnAux=1;
        }
    }
    return returnAux;
}

void escucharTema(ArrayList* pUser, Usuarios* user,ArrayList *pThemes,Temas *temas,ArrayList *pTemaEscuchado)
{
    char email[51];
    char pass[51];
    getString("Ingrese su email",email);
    int i;
    int index=-1;
    for (i=0;i<al_len(pUser);i++)
    {
        user=al_get(pUser,i);
        if(!stricmp(email,user->email))
        {
            index=i;
            break;
        }
    }
    if(index==-1)
        puts("EMAIL INCORRECTO");
    else
    {
        int flag=-1;
        getString("Ingrese su password",pass);
        user=al_get(pUser,index);
        if(!stricmp(pass,user->password))
        {
            flag=1;
        }
        if(flag==-1)
            puts("PASSWORD INCORRECTA");
        else
        {
            printThemes(pThemes,temas);
            char auxId[51];
            int indexTheme=-1;
            getString("Ingrese un ID del tema",auxId);
            if(!esNumeroNatural(auxId,10))
            {
                for(i=0;i<al_len(pThemes);i++)
                {
                    temas=al_get(pThemes,i);
                    if(temas->id==atoi(auxId))
                    {
                        indexTheme=i;
                        break;
                    }
                }
                if(indexTheme!=-1)
                {
                    TemasEscuchados *temaEscuchado=(TemasEscuchados*)malloc(sizeof(TemasEscuchados));
                    temaEscuchado->idUsuario=user->id;
                    strcpy(temaEscuchado->nacionalidad,user->nacionalidad);
                    temaEscuchado->idTema=temas->id;
                    al_add(pTemaEscuchado,temaEscuchado);
                }
                else
                {
                    puts("TEMA NO EXISTENTE");
                }
            }
            else
            {
                puts("ID DEBE SER UN NUMERO");
            }
        }
    }
}

int loadStatistics(ArrayList *this)
{
    int returnAux=0;
    if(this!=NULL)
    {
        FILE *a;
        a=fopen("statistics.dat","rb");
        if(a!=NULL)
        {
            TemasEscuchados * temaE;
            while (!feof(a))
            {
                temaE=(TemasEscuchados*)malloc(sizeof(TemasEscuchados));
                fread(temaE,sizeof(TemasEscuchados),1,a);
                al_add(this,temaE);
            }
            returnAux=1;
        }
        fclose(a);
    }
    return returnAux;
}

int saveStatistics(ArrayList *this)
{
    int returnAux=0;
    if(this!=NULL)
    {
        FILE *a;
        a=fopen("statistics.dat","wb");
        if(a!=NULL)
        {
            TemasEscuchados * temaE=(TemasEscuchados*)malloc(sizeof(TemasEscuchados));
            int i;
            for(i=0;i<al_len(this);i++)
            {
                temaE=al_get(this,i);
                fwrite(temaE,sizeof(TemasEscuchados),1,a);
            }
            returnAux=1;
        }
    }
    return returnAux;
}
