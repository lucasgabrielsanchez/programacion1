#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
Usuarios * Usuarios_newUsuario(void)
{
    return (Usuarios*)malloc(sizeof(Usuarios));
}

void Usuarios_printUsuario(Usuarios *this)
{
    if(this!=NULL)
        printf("ID:%d\nIP:%s\nEMAIL:%s\nPASS:%s\nNACIONALIDAD:%s\nNOMBRE:%s\nSEXO:%s \n\n",this->id,this->ip,this->email,this->password,this->nacionalidad,this->nombre,this->sexo);
}

int Usuarios_setId(Usuarios *this, int id)
{
    int returnAux=0;
    if(this!=NULL&&id>0)
    {
        this->id=id;
        returnAux=1;
    }
    return returnAux;
}

int Usuarios_setIp(Usuarios *this, char *ip)
{
    int returnAux=0;
    if(this!=NULL&&ip!=NULL)
    {
        strcpy(this->ip,ip);
        returnAux=1;
    }
    return returnAux;
}

int Usuarios_setEmail(Usuarios *this, char *email)
{
    int returnAux=0;
    if(this!=NULL&&email!=NULL)
    {
        strcpy(this->email,email);
        returnAux=1;
    }
    return returnAux;
}

int Usuarios_setNacionalidad(Usuarios *this, char *nacionalidad)
{
    int returnAux=0;
    if(this!=NULL&&nacionalidad!=NULL)
    {
        strcpy(this->nacionalidad,nacionalidad);
        returnAux=1;
    }
    return returnAux;
}
int Usuarios_setNombre(Usuarios *this, char *nombre)
{
    int returnAux=0;
    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        returnAux=1;
    }
    return returnAux;
}

int Usuarios_setSexo(Usuarios *this, char *sexo)
{
    int returnAux=0;
    if(this!=NULL&&sexo!=NULL)
    {
        strcpy(this->sexo,sexo);
        returnAux=1;
    }
    return returnAux;
}

int Usuarios_setPassword(Usuarios *this, char *password)
{
    int returnAux=0;
    if(this!=NULL&&password!=NULL)
    {
        strcpy(this->password,password);
        returnAux=1;
    }
    return returnAux;
}

char* Usuarios_getName(Usuarios* this)
{
    char *returnAux=NULL;
    if(this != NULL)
        returnAux=this->nombre;
    return returnAux;
}

int Usuarios_getId(Usuarios* this)
{
    int returnAux=-1;
    if(this!=NULL)
        returnAux=this->id;
    return returnAux;
}
