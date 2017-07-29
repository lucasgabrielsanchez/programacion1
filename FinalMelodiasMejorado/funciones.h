/** \brief Función que permite ingresar un array de enteros que servirá como salida y un array de Char de entrada
 *y la misma se encargará de transformar el array de char en un array de ints.
 * \param
 * \param
 * \return
 *
 */

int esNumerico(char stringIn[]);
int esNumericoFloat(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int esEdad(char edad[]);
int esDni(char auxDni[]);
int esSoloLetras(char stringIn[]);
int esMail(char stringIn[]);
void arrayIntInverter(int arrayInt[], int cantElemArray);
int arrayCharToArrayInt(char arrayStringIn[], int arrayIntOut[]);
int menu (char menuTexto[],char errorTexto[],int desde,int hasta);

