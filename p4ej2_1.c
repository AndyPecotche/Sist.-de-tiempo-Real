//gcc -o p4ej2_1.o p4ej2_1.c -lrt
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>       // Para nanosleep
#include <sys/types.h>  // Para mkfifo
#include <sys/stat.h>   // Para mkfifo

//#include <include/rtl_core.h> no existe <rtl.h> ni <rtl_core>
//por lo que rtc_prinf no se usa, rtf_create y rtf_put tampoco
#define DEBUG 1
#define FIFO "/tmp/rtf0"
int main() {
    struct timespec ts; //estructura para pasar tiempo a nanosleep
    FILE *temperaturas;
    int fd,espera,temperatura;
    temperaturas = fopen("./temperatura.txt","r"); //solo lectura

    if (temperaturas == NULL) {
        printf("Error al abrir el archivo");
        return 1;
    }

    mkfifo(FIFO,0777); //crea el pipe (comunicacion por fifo)

    while (!feof(temperaturas)) {
        fscanf(temperaturas, "%d\t%d\n", &espera, &temperatura);
        if (DEBUG){printf("lectura temp: %d tomando siesta de %d nanosec...\n",temperatura,espera);}
        // Configurar la espera con nanosleep
        ts.tv_sec = 0;          // 0 segundos
        ts.tv_nsec = espera;    // Tiempo de espera en nanosegundos
        if (DEBUG){printf("se va a dormir %ld\n",ts.tv_nsec);}
        nanosleep(&ts, NULL);
        if (DEBUG){printf("abriendo pipe...\n");}
        fd = open(FIFO, O_WRONLY);
        if (DEBUG){printf("escribiendo pipe...\n");}
        write(fd, &temperatura, sizeof(int));
        if (DEBUG){printf("pipe escrito, cerrando pipe...\n");}
        close(fd);
    }
    fclose(temperaturas); // Cierra el archivo
    return 0;
}
