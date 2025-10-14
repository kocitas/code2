/*
Realizar un programa que este permanentemente a la espera de capturar una señal SIGUSR1 (en un
bucle while(1) infinito por ejemplo), de forma que cuando la capture imprima su ID. Compílelo y
láncelo por consola.
Creo otro programa aparte que reciba por línea de argumentos un ID de un proceso, y su cometido
sea enviar una señal SIGUSR1 al proceso cuyo ID ha recibido por dicha línea de argumentos. Una
vez enviada la señal SIGUSR1 esperará durante 1 segundo y enviará al mismo proceso al que envió
la señal SIGUSR1 la señal de KILL. Compruebe por consola si el proceso al que ha enviado ambas
señales existe ya en el sistema.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

void manejar_SIGUSR1(int sig){
    printf("He recibido la señal SIGUSR1. Mi pid es: %d\n", getpid());
}


int main(){

    pid_t pid=getpid();
    signal(SIGUSR1, manejar_SIGUSR1);

    printf("Esperando señales SIGUSR1... Mi PID es: %d\n", getpid());


    while(1){
        pause();
    }


    return 0;
}