#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (numero < 0) {
        fprintf(stderr, "El factorial no está definido para números negativos.\n");
        return 1;
    }

    long long resultado = 1;
    for (int i = 1; i <= numero; i++) {
        resultado *= i;
    }

    printf("Factorial de %d = %lld\n", numero, resultado);

    return 0;
}
