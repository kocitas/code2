#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s ./ej5 n1 n2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

  /* no pasamos las cadenas a enteros porque en execl se trabajan con cadenas*/ 
    pid_t pid1, pid2;

    //primer hijo: calcula factorial de n1
    pid1 = fork();
 if (pid1 == 0) {
        // Proceso hijo
        execl("./factorial", "./ejercicio5_1", argv[1], (char *)NULL);
        perror("Error al ejecutar factorial");
        
    }
    // Segundo hijo
    pid2 = fork();
    if (pid2 == 0) {
        // Proceso hijo
        execl("./factorial", "./ejercicio5_2", argv[2], (char *)NULL);
        perror("Error al ejecutar fibonacci");
        
    }
   wait(NULL);
   wait(NULL);
    // Padre espera a ambos hijos

    return 0;
}



