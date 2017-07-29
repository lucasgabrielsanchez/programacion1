#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni[10];

}EPersona;

typedef struct {

    char buffer[4000];
    int minimo;
    int maximo;

}eValidar;


void getString(char mensaje[],char destino[]);

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elemento, el estado en valor VACIO
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int cantidad_de_elementos - Cantidad de personas
 * \param int valor - valor del estado al que se va a setear el estado
 *
 */
void inicializarArrayInt(EPersona persona[],int cantidad_de_elementos,int valor);


/** \brief  Busca la primer posición que tenga el estado del valor que le pasamos
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int cantidad_de_elementos - Cantidad de personas
 * \param int valor - valor del estado que se va a buscar
 * \return int Return (valor) si encuentra el valor dentro de los estados - (-2) si no lo encuentra
 *
 */
int buscarValorPosicion(EPersona persona[],int cantidadDeElementos,int valor);

/** \brief muestra un menu predefinido y pide una opción
 *
 * \return retorna la opción elegida
 *
 */
int opcionMenu();

/** \brief  Carga con valores de prueba, una estructura EPersona
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int cantAux - define la cantidad de personas que se van a cargar
 *
 */
void hardcodear(EPersona persona[],int cantAux);

/** \brief  Ordena por nombre un array de estructuras del tipo Epersona
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int C - Cantidad de personas a ordenar
 *
 */
void OrdenarNombres(EPersona persona[],int C);

/** \brief  Da de alta una persona.
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int indice - subindice del array en el cual se cargará la persona
 * \param int estado - valor del estado que se le seteará a la persona cargada
 *
 */
void altaPersona(EPersona persona[],int indice,int estado);

/** \brief  Valida que un string ingresado esté dentro del rango preestablecido
 *
 * \param eValidar cadena - Estructura del tipo eValidar
 *
 * \return retorna (1) si cumple el rango (0) si no
 *
 */
int validarRango(eValidar cadena);

/** \brief  Valida que un string ingresado esté dentro del rango de edad preestablecido
 *
 * \param eValidar cadena - Estructura del tipo eValidar
 *
 * \return retorna (1) si cumple el rango (0) si no
 *
 */
int validarRangoEdad(eValidar cadena);

/** \brief  Valida que un string ingresado sea numérico y esté dentro del rango de DNI preestablecido
 *
 * \param eValidar cadena - Estructura del tipo eValidar
 *
 * \return retorna (1) si cumple el rango (0) si no
 *
 */
int verificarDNI(eValidar cadena);

/** \brief  Valida que un string ingresado sea solo letras
 *
 * \param eValidar cadena - Estructura del tipo eValidar
 *
 * \return retorna (1) si cumple el rango (0) si no
 *
 */
int validarStr(eValidar cadena);

/** \brief  Da de baja una persona mostrando primero la lista de las personas cargadas
 *
 * \param EPersona persona - Estructura del tipo EPersona
 * \param int cant - cantidad de personas, se usa para mostrar las ya cargadas
 * \param int estado - estado que se le seteará a la persona para indicar en este caso, que fué dada de baja
 *
 */
void bajaPersona(EPersona persona[],int cant, int estado);

/** \brief  Ordena por edad un array de estructuras del tipo Epersona
 *
 * \param EPersona persona - Estructura del tipo Epersona
 * \param int C - Cantidad de personas a ordenar
 *
 */
void OrdenarEdades(EPersona persona[],int C);


#endif // FUNCIONES_H_INCLUDED

