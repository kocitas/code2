#include <sys/types.h>   // Para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      // Para fork() y sleep()
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>    // Para gettimeofday

int main(int argc, char *argv[]) {

    if (argc != 3) {
        perror("solo puede haber tres argumentos");
        return EXIT_FAILURE;
    }
    int x=atoi(argv[2]);
    int n = atoi(argv[1]);
    pid_t hijo_pid, childpid;
    int status;

    for (int i = 0; i < n; i++) {
        hijo_pid = fork();

        if (hijo_pid == -1) {
            perror("fork error");
            printf("errno value= %d\n", errno);
            exit(EXIT_FAILURE);
        }
        else if (hijo_pid == 0) { // hijo
            struct timeval tv;
            gettimeofday(&tv, NULL);
            printf("[%ld.%06ld] Soy el hijo, PID: %d, Padre PID: %d\n",
                   tv.tv_sec, tv.tv_usec, getpid(), getppid());

            x++;
            exit(EXIT_SUCCESS);
        }
        else { // padre
            struct timeval tv;
            gettimeofday(&tv, NULL);
            printf("[%ld.%06ld] Padre PID: %d, creó hijo PID: %d\n",
                   tv.tv_sec, tv.tv_usec, getpid(), hijo_pid);
        }
    }

    // Padre espera a todos los hijos
    while ((childpid = waitpid(-1, &status, WUNTRACED)) > 0) {
        if (WIFEXITED(status)) {
            printf("Proceso Padre %d, hijo PID %ld finalizado, status = %d\n",
                   getpid(), (long int)childpid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) {
            printf("Proceso Padre %d, hijo PID %ld finalizado al recibir señal %d\n",
                   getpid(), (long int)childpid, WTERMSIG(status));
        }
        else if (WIFSTOPPED(status)) {
            printf("Proceso Padre %d, hijo PID %ld PARADO al recibir señal %d\n",
                   getpid(), (long int)childpid, WSTOPSIG(status));
        }
        else if (WIFCONTINUED(status)) {
            printf("Proceso Padre %d, hijo PID %ld REANUDADO\n",
                   getpid(), (long int)childpid);
        }
    }

    if (childpid == (pid_t)-1 && errno == ECHILD) {
        printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n",
               getpid(), errno, "No child processes");
    } else {
        printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n",
               errno, "Error");
        exit(EXIT_FAILURE);
    }
    
    printf("el valor de la variable digitada ahora es: %d\n", x);

    exit(EXIT_SUCCESS);
}


