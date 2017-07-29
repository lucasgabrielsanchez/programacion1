#include <stdio.h>
#include "funciones.h"

void InicializarPelicula(ePelicula pelicula[])
{
    int i=0;
    int id[3]={1,2,3};
    char titulo[3][20]={"La Naranja Mecanica","La vida es bella","Superman"};
    char genero[3][20]={"Drama","Drama","Accion"};
    char descripcion[3][300]={"Gran Bretaña, en un futuro indeterminado. Alex (Malcolm McDowell) es un joven muy agresivo que tiene dos pasiones: la violencia desaforada y Beethoven. Es el jefe de la banda de los drugos, que dan rienda suelta a sus instintos más salvajes apaleando, violando y aterrorizando a la población","Gran Bretaña, en un futuro indeterminado. Alex (Malcolm McDowell) es un joven muy agresivo que tiene dos pasiones: la violencia desaforada y Beethoven. Es el jefe de la banda de los drugos, que dan rienda suelta a sus instintos más salvajes apaleando, violando y aterrorizando a la población","Gran Bretaña, en un futuro indeterminado. Alex (Malcolm McDowell) es un joven muy agresivo que tiene dos pasiones: la violencia desaforada y Beethoven. Es el jefe de la banda de los drugos, que dan rienda suelta a sus instintos más salvajes apaleando, violando y aterrorizando a la población"};
    int duracion[3]={100,120,180};
    int puntaje[3]={7,8,9};
    int estado[3]={1,1,1};
    char link[3][300]={"http://culturacolectiva.com/wp-content/uploads/2014/03/45.jpg","http://4.bp.blogspot.com/-THiEXe2_7Qo/TWJ9byGIwEI/AAAAAAAAABc/h_WD6bRwE3k/s320/La+vida+es+bella.jpg","http://media.dcentertainment.com/sites/default/files/GalleryChar_1900x900_MOS_52e05e3fe24a61.04593858.jpg"};

    for (i=0;i<3; i++)
    {
        pelicula[i].id=id[i];
        strcpy(pelicula[i].titulo,titulo[i]);
        strcpy(pelicula[i].genero,genero[i]);
        strcpy(pelicula[i].descripcion,descripcion[i]);
        strcpy(pelicula[i].linkImagen,link[i]);
        pelicula[i].duracion=duracion[i];
        pelicula[i].puntaje=puntaje[i];
        pelicula[i].estado=estado[i];

        savePelicula(&pelicula[i]);
    }
}


int AgregarPelicula(ePelicula* this)
{
    char buffer[4000];
    int retorno=0;

    getInt("Ingrese Id: ",buffer,1,10);
    this->id = atoi(buffer);
    getString("Ingrese el titulo: ",this->titulo,20);
    getString ("Ingrese el genero: ",this->genero,20);
    getString("Ingrese la descripcion: ",this->descripcion,100);
    getString("Ingrese el link de la imagen: ",this->linkImagen,50);
    getInt("Ingrese la duracion: ",buffer,10,300);
    this->duracion = atoi(buffer);
    getInt("Ingrese el puntaje: ",buffer,1,100);
    this->puntaje = atoi(buffer);

    this->estado=1;
    retorno =1;

    return retorno;
}


/** \brief Busca en el archivo la struct con el apellido pasado como argumento y la devuelve
 * \param char* surname apellido
 * \return Puntero a struct que se leyo del archivo o NULL si no existe el apellido
 */
int BorrarPelicula(int id)
{
    ePelicula* auxPelicula;
    FILE* fp, *fd;
    int encontrado=0;

    fp=fopen("bin.dat","rb");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return NULL;
    }
    else
    {
        fd=fopen("binAux.dat","ab+");
        if(!(fd))
            printf("Error. Imposible crear archivo auxiliar\n");
        else
        {
            auxPelicula = malloc(sizeof(ePelicula));
            while ((fread(auxPelicula, sizeof(ePelicula), 1, fp))!=0)
            {
                if(auxPelicula->id!=id)
                    fwrite(auxPelicula, sizeof(ePelicula), 1, fd);
                else
                    encontrado=1;
            }

            fclose(fd);
        }
        fclose(fp);
        if(encontrado)
        {
            system("del bin.dat");
            system("ren binAux.dat bin.dat");
            printf("Registro eliminado con exito!\n");
        }
        else
        {
            system("del binAux.dat");
            printf("El id no es encontro.\n");
        }
    }
    return encontrado;
}

int ListarPeliculasHtml(ePelicula this[])
{
    FILE* fp, *f1, *f2;
    int flagFound=0;
    char buffer[2048];
    int cantidad;
    int i=0;

    fp=fopen("peliculas.html","w");
    f1=fopen("html1.txt","r+");
    f2=fopen("html2.txt","r+");

    if(fp==NULL || f1==NULL || f2==NULL)
    {
        printf("Error opening file");
        return 0;
    }

    while (!feof(f1))
    {
        cantidad=fread(buffer,1,sizeof(buffer),f1);
        fwrite(buffer,1,cantidad,fp);
    }
    fclose(f1);

    while (this[i].estado==1)
    {
        fprintf(fp,"<article class='col-md-4 article-intro'>");
        fputs("",fp);
        fprintf(fp,"<a href='#'>");
        fputs("",fp);
        fprintf(fp,"<img class='img-responsive img-rounded' src='%s' alt=''>",this[i].linkImagen);
        fputs("",fp);
        fprintf(fp,"</a>");
        fputs("",fp);
        fprintf(fp,"<h3>");
        fputs("",fp);
        fprintf(fp,"<a href='#'>%s</a>",this[i].titulo);
        fputs("",fp);
        fprintf(fp,"</h3>");
        fputs("",fp);
        fprintf(fp,"<ul>");
        fputs("",fp);
        fprintf(fp,"<li>Genero: %s</li>",this[i].genero);
        fputs("",fp);
        fprintf(fp,"<li>Puntaje: %d</li>",this[i].puntaje);
        fputs("",fp);
        fprintf(fp,"<li>Duracion: %d</li>",this[i].duracion);
        fputs("",fp);
        fprintf(fp,"<ul>");
        fputs("",fp);
        fprintf(fp,"<li>%s</li>",this[i].descripcion);
        fputs("",fp);
        fprintf(fp,"</article>");

        i++;
    }
    while (!feof(f2))
    {
        cantidad=fread(buffer,1,sizeof(buffer),f2);
        fwrite(buffer,1,cantidad,fp);
    }
    fclose(f2);
    fclose(fp);

    return 1;

}


void crearArrayPelicula (ePelicula this[])
{
    ePelicula auxPelicula;
    //ePelicula arrayPelicula[20];
    int i = 0;

    FILE* fp;

    fp=fopen("bin.dat","rb");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        //return NULL;
    }
    else
    {
        while ((fread(&auxPelicula, sizeof(ePelicula), 1, fp))!=0)
        {
            this[i]=auxPelicula;
            i++;
        }
    }

}


void ListarPeliculasFull()
{
    FILE* fp;
    int flagFound=0;
    ePelicula* pPelicula;

    fp=fopen("bin.dat","rb");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return NULL;
    }

    pPelicula = malloc(sizeof(ePelicula));

    while(fread(pPelicula,sizeof(ePelicula),1,fp)!=0 && pPelicula->estado==1)
    {
        printf("%d %s %s %s %d\r\n",pPelicula->id,pPelicula->genero,pPelicula->titulo,pPelicula->descripcion,pPelicula->duracion);
    }
    fclose(fp);

    free(pPelicula);
}


void ListarPeliculasBasic()
{
    FILE* fp;
    int flagFound=0;
    ePelicula* pPelicula;

    fp=fopen("bin.dat","rb");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return NULL;
    }

    pPelicula = malloc(sizeof(ePelicula));

    while(fread(pPelicula,sizeof(ePelicula),1,fp)!=0 && pPelicula->estado==1)
    {
        printf("%d %s\r\n",pPelicula->id,pPelicula->titulo);
    }
    fclose(fp);

    free(pPelicula);
}



ePelicula* readPelicula(int id)
{
    FILE* fp;
    int flagFound=0;
    ePelicula* pRet;

    fp=fopen("bin.dat","rb"); // lectura binaria
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return NULL;
    }

    pRet = malloc(sizeof(ePelicula));

    while(fread(pRet,sizeof(ePelicula),1,fp)!=0)
    {

        //printf("Leo %s %s %d\r\n",pRet->name,pRet->surname,pRet->age);
        if(id==pRet->id)
        {
            flagFound=1;
            break;
        }
    }
    fclose(fp);
    if(flagFound)
        return pRet;
    free(pRet);
    return NULL;
}

int modificarPelicula (int id)
{
    ePelicula* auxPelicula;
    FILE* fp, *fd;
    int encontrado=0;

    fp=fopen("bin.dat","rb");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return NULL;
    }
    else
    {
        fd=fopen("binAux.dat","ab+");
        if(!(fd))
            printf("Error. Imposible crear archivo auxiliar\n");
        else
        {
            auxPelicula = malloc(sizeof(ePelicula));
            while ((fread(auxPelicula, sizeof(ePelicula), 1, fp))!=0)
            {
                if(auxPelicula->id!=id)
                    fwrite(auxPelicula, sizeof(ePelicula), 1, fd);
                else if (auxPelicula->id==id)
                {
                    printf("Ingrese el nuevo Titulo: ");
                    gets(auxPelicula->titulo);
                    printf("Ingrese el nuevo Genero: ");
                    gets(auxPelicula->genero);
                    printf("Ingrese la nueva descripcion: ");
                    gets(auxPelicula->descripcion);
                    printf("Ingrese el nuevo link: ");
                    gets(auxPelicula->linkImagen);
                    printf("Ingrese la nueva duracion: ");
                    scanf("%d",&auxPelicula->duracion);
                    printf("Ingrese el nuevo puntaje: ");
                    scanf("%d",&auxPelicula->puntaje);

                    fwrite(auxPelicula, sizeof(ePelicula), 1, fd);
                    encontrado=1;
                }
            }
            fclose(fd);
        }
        fclose(fp);
        if(encontrado)
        {
            system("del bin.dat");
            system("ren binAux.dat bin.dat");
            printf("Registro modificado con exito!\n");
        }
        else
        {
            system("del binAux.dat");
            printf("El id no se encontro.\n");
        }
    }
    return encontrado;

}




/** \brief Guarda una struct al final de un archivo binario bin.dat
 * \param struct S_Person* p puntero a struct a ser escrita
 * \return 0: error, 1:OK
 */
int savePelicula(ePelicula * pelicula)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+");
    if(fp==NULL)
    {
        printf("Error de apuertura del archivo\n");
        return 0;
    }
    fwrite(pelicula,sizeof(ePelicula),1,fp);

    fclose(fp);
    return 1;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer array ingresado por el usuario
 * \param minimo y maximo del rango
 * \return Devuelve 1 si es numerico y esta dentro del rango, sino 0
 *
 */

int getInt(char mensaje[],char buffer[],int minimo, int maximo)
{
    int retorno=0;
    char seguir='s';
    int auxiliar;
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(buffer);
        if(esNumerico(buffer))
        {
            auxiliar=atoi(buffer);
            if(verificarRangoInt(auxiliar, minimo, maximo))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Dato ingresado fuera del rango permitido. Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            printf("Dato ingresado no es numerico. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor numerico recibido esta dentro del rango permitido
 * \param numero entero a ser analizado
 * \param minimo y maximo del rango
 * \return 1 si esta dentro de los parametros y 0 si no
 */
int verificarRangoInt(int auxiliar, int minimo, int maximo)
{
    int retorno=0;

    if(auxiliar>=minimo && auxiliar<=maximo)
    {
        retorno=1;
    }

    return retorno;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si la longitud del dato ingresado es correcta
 */
int getString(char mensaje[],char buffer[], int longitud)
{
    char seguir='s';
    int retorno=0;

    do
    {
        system("cls");
        printf("%s", mensaje);
        fflush(stdin);
        gets(buffer);

        if(VerificarRangoChar(buffer,longitud))
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado muy extenso. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }
    while(seguir=='s');

    return retorno;
}


int VerificarRangoChar(char buffer[], int longitud)
{
    int retorno=0;
    if(strlen(buffer)<=longitud)
    {
        retorno=1;
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param buffer Array donde se cargará el texto ingresado
 * \param longitud para validar la longitud del array
 * \return 1 si el texto contiene solo letras y longitud acorde.
 */
int getStringLetras(char mensaje[], char buffer[], int longitud)
{
    int retorno=0;
    int seguir='s';
    do
    {
        if(getString(mensaje,buffer,longitud))
        {
            if(esSoloLetras(buffer))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Deben ser solo letras. Desea continuar?s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            seguir='n';
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i = 0;
    char letra;
    int retorno=1;

    while(str[i] != '\0')
    {
        letra=str[i];
        if(isalpha(letra)!=0 || letra==' ')
        {
            //retorno =1;
            i++;
            continue;
        }
        else
        {
            retorno=0;
            break;
        }

    }
    return retorno;
}
