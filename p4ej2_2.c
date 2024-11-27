//gcc -pthread -o p4ej2_2.o p4ej2_2.c -lrt
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

#define FIFO "/tmp/rtf0"
#define DEBUG 1
#define SIMCARGA 1
int temp;
sem_t semaforo;
int debug_sem=0;
void *funcion() {
    while (1) {
        int fd, valor;
        fd = open(FIFO, O_RDONLY);
        if (fd == -1) {
            printf("Error al abrir el FIFO");
            pthread_exit(NULL);
        }

        read(fd, &valor, sizeof(int));
        close(fd);

        temp = valor;
        debug_sem++;
        sem_post(&semaforo);

        if (temp > 90) {
            printf("Temperatura excedida!\n");
        }
        if (DEBUG) {printf("El valor es %d\n", valor);}
    }
    return NULL;
}

void *funcion2() {
    int ultimos[3] = {0, 0, 0};
    int i,carga,simcarga;
    simcarga=SIMCARGA;
    double promedio;
    while (1) {
        sem_wait(&semaforo); // Espera hasta que haya un nuevo dato
        debug_sem--;
        if (DEBUG && debug_sem>0){simcarga=0;printf("\nHILO PRODUCTOR EJECUTO 2 VECES SEGUIDAS\n");}
        ultimos[0] = ultimos[1];
        ultimos[1] = ultimos[2];
        ultimos[2] = temp;
        promedio=0;
        if(DEBUG){printf("\nÚltimas 3 medidas:\n");}
        for (i=0; i<3; i++) {
            promedio=promedio+ultimos[i];
            if(DEBUG){printf("temp[%d]: %d - ", i, ultimos[i]);}
        }
        promedio=(promedio/3);
        printf("\n");
        printf("Promedio ultimos 3: %f\n",promedio);
        carga=2;
        if(simcarga){for(i=0;i<499999999;i++){carga=carga*(i+1);}}

    }
    return NULL;
}

int main(int argc, char *argv[]) {

    sem_init(&semaforo, 0, 0);

    pthread_attr_t attr;
    pthread_t hilo1, hilo2;

    pthread_attr_init(&attr);

    struct sched_param p;

    p.sched_priority = 0; //mas baja
    pthread_attr_setschedparam(&attr,&p);
    pthread_create(&hilo1, &attr, funcion, NULL);

    p.sched_priority = 10000; //mas alta
    pthread_attr_setschedparam(&attr,&p);
    pthread_create(&hilo2, &attr, funcion2, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    sem_destroy(&semaforo);

    pthread_attr_destroy(&attr);
    return 0;
}
