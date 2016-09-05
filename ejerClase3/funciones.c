/** \brief Solicita un numero y lo retorna, en este caso se usa para solicitar el radio
 * \return devuelve el numero que el usuario ingresa
 *
 */


float pideNum()
{
    float numIng;

    printf("Ingrese el radio del circulo: ");
    scanf("%f",&numIng);
    return numIng;
}

/** \brief Recibe el radio y calcula el area del mismo
 *
 * \param Rad es el radio que recibe y corresponde al radio del circulo
 * \return devuelve el area calculada
 *
 */


float areaCirc(float rad)
{
    float area;
    area=3.14*rad*rad;
    return area;

}

