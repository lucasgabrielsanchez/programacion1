
typedef struct
{
    char id[21];
    char nombre[51];
    char apellido[51];
    char mail[51];
    char numTarjeta[51];
    char errorMsg[51];
    int tipoTarjeta;
}eTarjeta;

int cargaTarjeta(ArrayList *pTarjetas);
eTarjeta* new_tarjeta();
int validarTarjeta(char *numTarjeta);
int validarSintaxis(char *numTarjeta);
int tarjeta_setId(eTarjeta *auxTarjeta, char *id);
int tarjeta_setNombre(eTarjeta *auxTarjeta, char *nombre);
int tarjeta_setApellido(eTarjeta *auxTarjeta, char *apellido);
int tarjeta_setMail(eTarjeta *auxTarjeta, char *mail);
int tarjeta_setNumTarjeta(eTarjeta *auxTarjeta, char *numTarjeta);
void printearValidos(ArrayList *pTarjetas);
void printearPorTipo(ArrayList *pTarjetas, int tipo);

