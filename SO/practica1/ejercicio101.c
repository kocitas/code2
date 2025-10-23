// emisor.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){

        if(argc != 2){
            printf("no has introducido los parametros correctos");
            return 1;
        }

        pid_t pid=atoi(argv[1]);

        kill(pid, SIGUSR1);

        sleep(1);

        kill(pid, SIGKILL);
        /*deberia meter ambos kill en un if y comprobar que se ha enviado correctamente*/
        sleep(1); // Esperar a que el sistema elimine el proceso


        // Comprobar si el proceso sigue existiendo
        if (kill(pid, 0) == 0) {
            printf("El proceso %d todavía existe.\n", pid);
        } else {
            if (errno == ESRCH)
                printf("El proceso %d ya no existe.\n", pid);
            else
                perror("Error al comprobar el proceso");
        }
        




    return 0;
}