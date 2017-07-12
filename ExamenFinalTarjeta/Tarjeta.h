#include "ArrayList.h"

typedef struct
{
    char ID[51];
    char nombre[101];
    char apellido[101];
    char mail[101];
    char NumTarjeta[51];
    char error[101];
    int Tarjeta;

}Tarjeta;

Tarjeta* new_tarjeta();
int validarNumTarjetaSintactico(char arrayCharIn[]);
int esVisa(char numTarjeta[]);
int esAmex(char numTarjeta[]);
int esMaster(char numTarjeta[]);
void printearValidos(ArrayList *pTarjetas);
void printearMaster(ArrayList *pTarjetas);
void printearVisa(ArrayList *pTarjetas);
void printearAmex(ArrayList *pTarjetas);
void printearInvalidos(ArrayList *pTarjetas);

