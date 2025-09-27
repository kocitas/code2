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


