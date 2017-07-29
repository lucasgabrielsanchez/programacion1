
typedef struct
{
    char nombre;
    int frecuencia;
    int duracion;
    int volume;
}eNota;

int crearNotas(ArrayList *pNotas);
eNota* new_nota();
int nota_setNombre(eNota *auxNota, char *nombre);
char nota_getNombre(eNota *auxNota);
int nota_setFrecuencia(eNota *auxNota, int frecuencia);
int nota_getFrecuencia(eNota *auxNota);
int nota_setDuracion(eNota *auxNota, int duracion);
int nota_getDuracion(eNota *auxNota);
int nota_setVolume(eNota *auxNota, int volume);
int nota_getVolume(eNota *auxNota);
void printearNotas(ArrayList *pNotas);
void ecualizar(ArrayList *pNotas);
void corregir(ArrayList *pNotas);

