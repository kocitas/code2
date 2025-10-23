#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <calculadora> <editor> <ficheros...>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*Guardan los nombres de los ejecutables que vamos a ejecutar*/
    char *calc = argv[1];    
    char *editor = argv[2];  

    pid_t pid1, pid2;
    int status;

    // Primer hijo: ejecuta la calculadora
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0) { // hijo calculadora
        execlp(calc, calc, (char *)NULL); // exelclp, reemplaza el programa actual por el programa indicado
        perror("Error al ejecutar calculadora");
        exit(EXIT_FAILURE);
    }

    // Segundo hijo: ejecuta el editor con los ficheros restantes
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid2 == 0) { // hijo editor
        // argv[3..argc-1] son los ficheros
        execvp(editor, &argv[2]);//usamos execvp() porque necesitamos pasar un array de argumentos y reemplaza al hijo con el editor 
        perror("Error al ejecutar editor");
        exit(EXIT_FAILURE);
    }

    // Padre espera a ambos hijos
    waitpid(pid1, &status, 0);
    printf("Hijo calculadora finalizado\n");

    waitpid(pid2, &status, 0);
    printf("Hijo editor finalizado\n");

    return 0;
}

