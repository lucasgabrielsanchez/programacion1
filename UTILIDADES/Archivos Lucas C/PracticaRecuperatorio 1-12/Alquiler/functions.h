
typedef struct
    {
        int idCliente;
        char nombre[50];
        char apellido[50];
        char dni[10];
        int estado_cliente;

    }ECliente;

typedef struct
    {
        int idAlquiler;
        int idCliente;
        int equipo;
        int tiempo;
        int estado_alquiler;

    }EAlquiler;

typedef struct {

    char buffer[4000];
    int minimo;
    int maximo;

}eValidar;


void inicializarArrayCliente(ECliente cliente[],int cantida,int valor);

void inicializarArrayAlquiler(EAlquiler alquiler[],int cantidad_de_elementos,int valor);

void altaCliente(ECliente cliente[],int indice,int estado);

int validarRango(eValidar cadena);

int validarRangoEdad(eValidar cadena);

int verificarDNI(eValidar cadena);

int validarStr(eValidar cadena);

int buscarPosicionCliente(ECliente cliente[],int cantidadDeElementos,int valor);

int opcionMenu();

void bajaCliente(ECliente cliente[],int cant_elementos, int estado);

void modificarCliente(ECliente cliente[],int cant_elementos);

int buscarPosicionAlquiler(EAlquiler alquiler[],int cantidadDeElementos,int valor);

void altaAlquiler(EAlquiler alquiler[],ECliente cliente[],int cant_elemClientes,int indice,int estado);

void finAlquiler(EAlquiler alquiler[],int cantElemAlquiler,int estado);


