
typedef struct
{
    char nombre[3];
    int frecuencia;
    int duracion;
    int volume;
}eNota;

int cargaNotas(ArrayList *pNotas);
eNota* new_nota();
int nota_setNombre(eNota *auxNota, char *nombre);
char* nota_getNombre(eNota *auxNota);
int nota_setFrecuencia(eNota *auxNota, int frecuencia);
int nota_getFrecuencia(eNota *auxNota);
int nota_setDuracion(eNota *auxNota, int duracion);
int nota_getDuracion(eNota *auxNota);
int nota_setVolume(eNota *auxNota, int volume);
int nota_getVolume(eNota *auxNota);
void printearNotas(ArrayList *pNotas);
void Ecualizar(ArrayList *pNotas);
void Corregir(ArrayList *pNotas);
int compararNotas(void* inputA, void* inputB);
