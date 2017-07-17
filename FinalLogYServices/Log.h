


typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

}eLog;

int cargaLogs(ArrayList *pLogs);
eLog* new_eLog();
int log_setDate(eLog *auxLog, char *date);
char* log_getDate(eLog *auxLog);
int log_setTime(eLog *auxLog, char *time);
char* log_getTime(eLog *auxLog);
int log_setServideId(eLog *auxLog, int serviceId);
int log_getServideId(eLog *auxLog);
int log_setGravedad(eLog *auxLog, int gravedad);
int log_getGravedad(eLog *auxLog);
int log_setMsg(eLog *auxLog, char *msg);
char* log_getMsg(eLog *auxLog);
void log_prinAll(ArrayList *pLog);

