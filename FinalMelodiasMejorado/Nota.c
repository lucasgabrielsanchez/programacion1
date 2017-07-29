#include "Includes.h"

int crearNotas(ArrayList *pNotas)
{
    int retorno = 0;
    int cont = 0,cont1 = 0;
    eNota *auxNota;
    FILE *archivo;
    FILE *archivo2;
    char auxNombre[3];
    char auxNombre2[3];
    char auxFrecuencia[11];
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

                ///Verifico que la duración no sea menor a 500 o mayor a 4000.
                if(atoi(auxDuracion)<500)
                {
                    strcpy(auxDuracion,"500");
                }
                else if(atoi(auxDuracion)>4000)
                {
                    strcpy(auxDuracion,"4000");
                }

                ///verifico que el volumen no sea mayor a 100.
                if(atoi(auxVolume)>100)
                {
                    strcpy(auxVolume,"100");
                }

                if(!cont)
                {
                    cont=1;
                    continue;
                }

                archivo2=fopen("notas.txt","r");

                while(!feof(archivo2))
                {
                    fscanf(archivo2,"%[^;];%[^\n]\n",auxNombre2,auxFrecuencia);

                    ///uso esto para determinar que se leyo al menos una linea de ambos archivos.
                    if(!cont1)
                    {
                        cont1=1;
                        continue;
                    }

                    if(strcmp(auxNombre,auxNombre2) == 0)
                    {
                        auxNota = new_nota();

                        nota_setNombre(auxNota,auxNombre);
                        nota_setFrecuencia(auxNota,atoi(auxFrecuencia));
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
        if(cont1)
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
        auxNota->nombre = nombre[0];
        retorno = 1;
    }

    return retorno;
}

char nota_getNombre(eNota *auxNota)
{
    char aux = NULL;

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
    eNota *auxNota;
    int i;

    if(pNotas != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas,i);
            printf("Nota: %c\nFrecuencia: %d\nDuracion: %d\nVolume: %d\n\n",nota_getNombre(auxNota),
                   nota_getFrecuencia(auxNota),nota_getDuracion(auxNota),nota_getVolume(auxNota));
        }
    }
}

void ecualizar(ArrayList *pNotas)
{
    eNota *auxNota;
    int i;

    if(pNotas != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas,i);

            if(nota_getFrecuencia(auxNota)>250 && nota_getFrecuencia(auxNota)<331)
            {
                nota_setVolume(auxNota,(nota_getVolume(auxNota)*1.30));
            }
            else if(nota_getFrecuencia(auxNota)>330)
            {
                nota_setVolume(auxNota,(nota_getVolume(auxNota)*1.50));
            }

            if(nota_getVolume(auxNota)>100)
            {
                nota_setVolume(auxNota,100);
            }

            al_set(pNotas,i,auxNota);
        }
    }
}

void corregir(ArrayList *pNotas)
{
    eNota *auxNota;
    int i;
    FILE *f = fopen("melodia_corregida.txt","w");
    char auxLetra = NULL;

    if(pNotas != NULL && f != NULL)
    {
        for(i=0; i<al_len(pNotas); i++)
        {
            auxNota = al_get(pNotas,i);

            if(i == 0)
            {
                fprintf(f,"%s;%s;%s\n","NOTA","DURACION","VOLUMEN");
            }

            switch (nota_getNombre(auxNota))
            {
            case 'C':
                auxLetra = 'D';
                break;
            case 'D':
                auxLetra = 'E';
                break;
            case 'E':
                auxLetra = 'C';
                break;
            default:
                auxLetra = nota_getNombre(auxNota);
                break;
            }

            fprintf(f,"%c;%d;%d\n",auxLetra,nota_getDuracion(auxNota),nota_getVolume(auxNota));
        }

        fclose(f);
    }
}
