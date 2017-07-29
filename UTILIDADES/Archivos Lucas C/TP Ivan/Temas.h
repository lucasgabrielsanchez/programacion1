#ifndef __TEMAS
#define __TEMAS

typedef struct
{
    int id;
    char tema[51];
    char artista[51];
}Temas;

#endif

Temas* Temas_newTema(void);

void Temas_printTema(Temas *this);

int Temas_setId(Temas * this,int id);

int Temas_setTema(Temas * this,char *theme);

int Temas_setNombre(Temas * this, char *nameArtist);
