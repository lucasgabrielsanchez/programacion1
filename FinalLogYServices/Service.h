


typedef struct
{
    int id;
    char name[33];
    char email[65];

}eService;

int cargaServices(ArrayList *pServices);
eService* new_service();
int service_setId(eService *auxService, int id);
int service_getId(eService *auxService);
int service_setName(eService *auxService, char *name);
char* service_getName(eService *auxService);
int service_setEmail(eService *auxService, char *email);
char* service_getEmail(eService *auxService);
void service_prinAll(ArrayList *pService);
void evaluarGravedad(ArrayList *pLogs, ArrayList *pServices);
void mostrarEstadisticas();

