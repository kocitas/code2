#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>


int contador=0;

// Función manejadora de la señal SIGUSR1
void tratarSennal(int sig) {
    contador++;
    printf("Hijo: He recibido la señal SIGUSR1 (%d)\n", contador);

    if (contador == 5) {
        printf("Hijo: Recibidas 5 señales. Terminando...\n");
        exit(0);
    }
}

int main(){

    pid_t pid=fork();

    
    if (pid < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    }
    sleep(1);

    if(pid==0){
        signal(SIGUSR1, tratarSennal);//asociar señal a la funcion 
        fflush(stdout);

        //el hijo queda esperando señales del padre 

        while(1){
            pause();//espera una señal 
        }

    }else{
        for(int i=0;i<5;i++){
            sleep(1);
            printf("Padre: Enviando señal SIGUSR1 (%d)\n", i+1);
            kill(pid, SIGUSR1); //enviar señal al hijo 
        }

        sleep(1);

        printf("Padre: terminando proceso padre.\n");
    }


return 0;
}