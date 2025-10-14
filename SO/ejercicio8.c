/*Realizar un programa que capture la señal de alarma, de manera que imprima la cadena “RING”
pasados 5 segundos, después pasados otros 3 segundos y por último cada segundo. Implementar
esto último, utilizando un bucle infinito que vaya imprimiendo el número de timbrazos. Pasados 4
timbrazos, el proceso se debe parar utilizando para ello la función kill().
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

int main(){

    pid_t pid=getpid(); //obtener el pid del proceso actual
    int timbrazos=0; 

    //primer ring 

    sleep(5);
    printf("RING\n");

    //segundo ring 
    sleep(3);
    printf("RING\n");

    //cada segundo 
    while(1){
        sleep(1);
        timbrazos++;
        printf("RING %d\n", timbrazos);

        //despues de 4 timbrazos, terminar proceso

        if(timbrazos==4){
            printf("Finalizar proceso...\n");
            kill(pid, SIGTERM);
        }
    }


    return 0;
}

