#include "Includes.h"

int cargaNotas(ArrayList *pNotas)
{
    int retorno = 0;
    int cont = 0;
    eNota *auxNota;
    FILE *archivo;
    FILE *archivo2;
    char auxNombre[3];
    char auxNombre2[3];
    char auxFrecuencua[11];
    char auxDuracion[11];
    char auxVolume[11];

    ///Verifico que el arraylist no sea nulo.
    if(pNotas!=NULL)
    {
        ///Si contiene elementos lo vacío para cargarlo limpio.
        if(al_len(pNotas) != 0)
        {
            al_clear(pNotas);
        }

        archivo=fopen("melodia.txt","r");

        ///verifico que el archivo no sea nulo.
        if(archivo!=NULL)
        {
            ///Mientras NO sea el final del archivo, se leerá el mismo.
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^;];%[^;];%[^\n]\n",auxNombre,auxDuracion,auxVolume);

                archivo2=fopen("notas.txt","r");

                while(!feof(archivo2))
                {
                    fscanf(archivo2,"%[^=]=%[^\n]\n",auxNombre2,auxFrecuencua);

                    ///uso esto para determinar que se leyo al menos una linea de ambos archivos.
                    if(!cont)
                    {
                    cont=1;
                    }

                    if(strcmp(auxNombre,auxNombre2) == 0)
                    {
                        auxNota = new_nota();

                        nota_setNombre(auxNota,auxNombre);
                        nota_setFrecuencia(auxNota,atoi(auxFrecuencua));
                        nota_setDuracion(auxNota,atoi(auxDuracion));
                        nota_setVolume(auxNota,atoi(auxVolume));

                        al_add(pNotas,auxNota);
                    }
                }

            }
        }
        fclose(archivo);
        fclose(archivo2);

        ///si el cont es 1, significa que se leyó aunque sea una línea.
        if(cont)
        {
            retorno=1;
        }
    }
    return retorno;

}

eNota* new_nota()
{
    return (eNota*)malloc(sizeof(eNota));
}

int nota_setNombre(eNota *auxNota, char *nombre)
{
    int retorno = 0;

    if(auxNota != NULL && nombre != NULL)
    {
        strcpy(auxNota->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

char* nota_getNombre(eNota *auxNota)
{
    char *aux = NULL;

    if(auxNota != NULL)
    {
        aux = auxNota->nombre;
    }

    return aux;
}

int nota_setFrecuencia(eNota *auxNota, int frecuencia)
{
    int retorno = 0;

    if(auxNota != NULL && frecuencia > -1)
    {
        auxNota->frecuencia = frecuencia;
        retorno = 1;
    }

    return retorno;
}

int nota_getFrecuencia(eNota *auxNota)
{
    int retorno = -1;

    if(auxNota != NULL)
    {
        retorno = auxNota->frecuencia;
    }

    return retorno;
}

int nota_setDuracion(eNota *auxNota, int duracion)
{
    int retorno = 0;

    if(auxNota != NULL && duracion > -1)
    {
        auxNota->duracion = duracion;
        retorno = 1;
    }

    return retorno;
}

int nota_getDuracion(eNota *auxNota)
{
    int retorno = -1;

    if(auxNota != NULL)
    {
        retorno = auxNota->duracion;
    }

    return retorno;
}

int nota_setVolume(eNota *auxNota, int volume)
{
    int retorno = 0;

    if(auxNota != NULL && volume > -1)
    {
        auxNota->volume = volume;
        retorno = 1;
    }

    return retorno;
}

int nota_getVolume(eNota *auxNota)
{
    int retorno = -1;

    if(auxNota != NULL)
    {
        retorno = auxNota->volume;
    }

    return retorno;
}

void printearNotas(ArrayList *pNotas)
{
    int i;
    eNota *auxNota;

    if(pNotas != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas,i);

            printf("Nombre: %s\nFrecuencia: %d\nDuracion: %d\nVolume: %d\n\n",nota_getNombre(auxNota),
                   nota_getFrecuencia(auxNota),nota_getDuracion(auxNota),nota_getVolume(auxNota));
        }
    }
}

void Ecualizar(ArrayList *pNotas)
{
    int i;
    eNota *auxNota;

    if(pNotas != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas, i);

            if(auxNota->frecuencia > 250 && auxNota->frecuencia < 330)
            {
                auxNota->volume *= 1.30;

                if(auxNota->volume > 100)
                {
                    auxNota->volume = 100;
                }

                al_set(pNotas,i,auxNota);
            }
            else if(auxNota->frecuencia > 330)
            {
                auxNota->volume *= 1.50;

                if(auxNota->volume > 100)
                {
                    auxNota->volume = 100;
                }

                al_set(pNotas,i,auxNota);
            }
        }
    }

}

void Corregir(ArrayList *pNotas)
{
    int i;
    eNota *auxNota;
    FILE *f;

    if(pNotas != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas,i);

            if(strcmp(auxNota->nombre,"C")==0)
            {
                f = fopen("melodia_corregida.txt","a");

                if(f!=NULL)
                {
                    fprintf(f,"%s;%d;%d\n","D",nota_getDuracion(auxNota),nota_getVolume(auxNota));
                }

                fclose(f);
            }
            else if(strcmp(auxNota->nombre,"D")==0)
            {
                f = fopen("melodia_corregida.txt","a");

                if(f!=NULL)
                {
                    fprintf(f,"%s;%d;%d\n","E",nota_getDuracion(auxNota),nota_getVolume(auxNota));
                }

                fclose(f);
            }
            else if(strcmp(auxNota->nombre,"E")==0)
            {
                f = fopen("melodia_corregida.txt","a");

                if(f!=NULL)
                {
                    fprintf(f,"%s;%d;%d\n","C",nota_getDuracion(auxNota),nota_getVolume(auxNota));
                }

                fclose(f);
            }
        }
    }
}

int compararNotas(void* inputA, void* inputB)
{
    int returnAux = 0;
    if(inputA != NULL && inputB != NULL)
    {
        char *NombreA = nota_getNombre(inputA);
        char *NombreB = nota_getNombre(inputB);

        if(strcmp(NombreA,NombreB)>0)
        {
            returnAux=1;
        }
        else if(strcmp(NombreA,NombreB)<0)
        {
            returnAux=-1;
        }
    }
    return returnAux;
}
