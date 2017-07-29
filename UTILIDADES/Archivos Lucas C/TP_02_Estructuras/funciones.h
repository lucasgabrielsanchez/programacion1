typedef struct {

    char menu[500];
    char error[100];
    int desde;
    int hasta;

}eMenu;


typedef struct {

    char buffer[4000];
    int minimo;
    int maximo;

}eValidar;


typedef struct {

    char nombre[50];
    int edad;
    char dni[20];
    int estado;

}ePersona;

/**
 * Hardcodea personas para poder realizar pruebas.
 * @param array de estructura persona.
 * @param  maxima cantidad de componentes del vector.
 */
void hardcodeo(ePersona persona[],int Caux);

/**
 * Se asigna estado 'Vacío' a todos los componentes del vector persona.
 * @param array de estructura persona.
 * @param maxima cantidad de componentes del vector.
 * @param estado.
 */
void asignarEstado (ePersona persona[],int C,int estado);

/**
 * Valida que la opcion ingresada del menu sea correcta.
 * @param array de estructura menu.
 * @return Opcion valida o, en el caso de ser invalida, devuelve -1.
 */
int validarMenu(eMenu opciones);

/** \brief Carga una persona.
 *
 * @param  Epersona persona - array de estructura persona.
 * @param cantidad maxima de elementos posibles del vector.
 * @param posicion del vector
 * @param estado del registro.
 */
void altaPersona(ePersona persona[],int indice,int estado);

/**
 * Eliminar una persona mediante baja logica.
 * @param cantidad maxima de elementos posibles del vector, posicion del vector.
 * @param estructura persona.
 */
void bajaPersona (ePersona persona[],int C, int indice);

/**
 * Realizar una lista de registros activos, ordenada por nombre.
 * @param array de estructura persona.
 * @param cantidad maxima de elementos posibles del vector.
 */
void listarPersonas(ePersona persona[],int);

/**
 * Valida el dni ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @param rango de numeros permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int verificarDNI(eValidar cadena);

/**
 * Valida el dato char ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario y cantidad de caracteres permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarRango(eValidar cadena);

/**
 * Valida el dato char ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarStr(eValidar cadena);

/**
 * Valida el dato int ingresado por el usuario.
 * @param estructura que incluye: String ingresado por usuario.
 * @param rango de numeros permitidos.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int validarRangoEdad(eValidar cadena);

/**
 * Cuenta cantidad de personas de cada rango etario.
 * @param array de estructura persona.
 * @param cantidad maxima de elementos posibles del vector.
 * @param punteros de cada rango etario.
 * @return 1 si es correcto, 0 si es incorrecto.
 */
int contarPorEdad (ePersona persona[],int C,int* menor18,int* de18a35,int* mayor35);

/**
 * Grafico que muestra cantidad de personas por rango etario.
 * @param punteros de cada rango etario.
 */
void graficar (int cantidadMenor18,int cantidadDe18a35, int cantidadMayor35);


/**
 * Obtiene el primer indice libre del array.
 * @param array de estructura persona.
 * @return el primer indice disponible
 */
int buscarIndiceLibre (ePersona persona[],int C);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param array de estructura persona.
 * @param dni ingresado por el usuario.
 * @param cantidad maxima de elementos posibles del vector.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(ePersona persona[], char dni[], int C);


