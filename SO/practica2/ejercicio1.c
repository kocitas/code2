#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

void * funcion_hebra(void * puntero_x)
{
	int *mi_puntero = (int *) puntero_x; 
   
    printf("Hebra hija: valor de x = %d, incrementandolo 1000.000 veces.\n", *mi_puntero);

	//incrementar x hasta 1000.000
	for(int i=0; i<1000000;i++)
	{
	   *mi_puntero = *mi_puntero + 1;
	} 

	printf("Hebra hija: incremento de x finalizado.\n");
 
	pthread_exit(NULL); 
}


int main(){


    int x=0; 

    pthread_t hebra_incr1, hebra_incr2;

    printf("Hebra principal o main(): valor de variable x = %d\n", x);


    //Creación de la hebra
	if(pthread_create(&hebra_incr1, NULL, (void *) funcion_hebra, (void *) &x)) 
	{
	  fprintf(stderr, "Error creating thread\n");
	  exit(EXIT_FAILURE); 
	}

      //Creación de la hebra
	if(pthread_create(&hebra_incr2, NULL, (void *) funcion_hebra, (void *) &x)) 
	{
	  fprintf(stderr, "Error creating thread\n");
	  exit(EXIT_FAILURE); 
	}

    //Espera de la hebra
	if(pthread_join(hebra_incr1, NULL)) 
	{
	  fprintf(stderr, "Error joining thread\n");
	  exit(EXIT_FAILURE);  
	}

     //Espera de la hebra
	if(pthread_join(hebra_incr2, NULL)) 
	{
	  fprintf(stderr, "Error joining thread\n");
	  exit(EXIT_FAILURE);  
	}

	printf("Hebra principal o main(): valor de x = %d\n",x);
	
	exit(EXIT_SUCCESS);

}