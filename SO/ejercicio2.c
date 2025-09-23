
#include <sys/types.h>   // Para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      // Para fork() y sleep()
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>    // Para gettimeofday

int main(int argc, char *argv[]) {

    if (argc != 2) {
        perror("solo puede haber dos argumentos");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    pid_t hijo_pid;
    int status;


    for(int i=0;i<n;i++){
        hijo_pid=fork();
        

            if(hijo_pid==-1)
            {
                perror("error al crear proceso");
                exit(EXIT_FAILURE);
            }
            else if(hijo_pid==0)/*es el hijo*/
            {
                printf("Soy el hijo, PID: %d, Padre PID: %d\n", getpid(), getppid());

                //dentro del mismo if, si i=n-1, se sale
                if(i==n-1){
                    exit(EXIT_SUCCESS);
                }
            }
            else
            {
            printf("Padre PID: %d, creó hijo PID: %d\n", getpid(), hijo_pid);

            waitpid(hijo_pid,&status,0);//se espera solo a su hijo, es una cadena, no un arbol
            exit(EXIT_SUCCESS);

            }
        }
                    return EXIT_SUCCESS;

    }    