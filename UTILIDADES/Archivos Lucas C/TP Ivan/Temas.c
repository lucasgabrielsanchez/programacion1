#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Temas.h"
Temas* Temas_newTema(void)
{
    return (Temas*)malloc(sizeof(Temas));
}

void Temas_printTema(Temas *this)
{
    if(this!=NULL)
        printf("ID:%d Nombre del tema:%s Artista: %s\n",this->id,this->tema,this->artista);
}

int Temas_setId(Temas * this,int id)
{
    int returnAux=0;
    if(this!=NULL)
    {
        this->id=id;
        returnAux=1;
    }
    return returnAux;
}

int Temas_setNombre(Temas * this, char *nameArtist)
{
    int returnAux=0;
    if(this!=NULL)
    {
        strcpy(this->artista,nameArtist);
        returnAux=1;
    }
    return returnAux;
}
int Temas_setTema(Temas * this,char *theme)
{
    int returnAux=0;
    if(this!=NULL)
    {
        strcpy(this->tema,theme);
        returnAux=1;
    }
    return returnAux;
}

