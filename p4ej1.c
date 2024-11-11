#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>
#define NUM_THREADS 2

#define PERIOD_MS 10  // Periodo de 10 ms
/*
double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}
*/
double dnanowalltime() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // Convertir el tiempo a segundos con precisión de nanosegundos
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void *funcion(void *arg) {
    int id = *(int*)arg;
    int i=0;
    double lat=0;
    double time1=0;
    double time2=0;

    for (i=0;i<1000;i++){
        time1=dnanowalltime();
        usleep(10000); //dormir 10ms
        time2=dnanowalltime()-0.010000000;
        lat=lat+(time2-time1);
    }
    lat=lat/1000;
    printf("soy el hilo %d, latencia: %f9\n",id,lat);
    return NULL;
}

int main(int argc, char *argv[])
{
  int i;
  int id;
  int thread_id[NUM_THREADS];
  pthread_attr_t attr;
  pthread_t hilos[NUM_THREADS];
  pthread_attr_init(&attr);

  for (i=0;i<NUM_THREADS;i++){
    thread_id[i]=i;
    pthread_create(&hilos[i],&attr,funcion,(void*)&thread_id[i]);
  }

  for (i=0; i<NUM_THREADS; i++){
    pthread_join(hilos[i], NULL);
  }

    pthread_attr_destroy(&attr);
    return 0;

}

