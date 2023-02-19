#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "status_t.h"

/*Estamos armando nuestra propia plaforma social y decidimos que vamos a permitir que las personas se envíen mensajes que a lo sumo 
tengan 143 caracteres. Para ello, vamos a utilizar una estructura. La misma tiene que tener un número no signado que identifica al mensaje
dentro de los millones y millones de mensajes que nos van a mandar, un time_t para la fecha, un arreglo para almacenar el mensaje y 
un arreglo para almacenar el nombre de usuario de quien lo publica.

Definir la estructura del enunciado.
Implementar una función que tome un mensaje y lo publique en la terminal, con el siguiente formato:

YYYY-MM-DD HH:mm:ss

<MENSAJE>

            Sos lo mejor. Besos. <usuario>
*/

typedef struct red_social{
    int number_not_sig;
    time_t hora;
    char mensaje[143];
    char usuario[100];
}red_social_t;

status_t message(red_social_t *social, char *msg, char *user){
    if((social == NULL) || (msg == NULL) || (user == NULL)){
        return ST_ERR_NULL_PTR;
    }
    srand(time(NULL));
    social->number_not_sig = rand();
    strcpy(social->usuario, user);
    strcpy(social->mensaje, msg);
    time(&social->hora);

    printf("\n%sId: %d\n",ctime(&social->hora), social->number_not_sig);
    printf("%s\n", social->mensaje);
    printf("Sos lo mejor. Besos. %s\n", social->usuario);

    return ST_OK;
}


int main(void){
    red_social_t Twiter;
    char m[100];
    char u[100];
    printf("Ingrese su nombre de usuario: ");
    fgets(u, 101, stdin);
    for(int i = 0; i < 100; i++){
        if(u[i] == '\n'){
            u[i] = '\0';
        }
    }	
    printf("Ingrese un mensaje: ");
    fgets(m, 101, stdin);
    for(int i = 0; i < 100; i++){
        if(m[i] == '\n'){
            m[i] = '\0';
        }
    }	

    message(&Twiter, m, u);
    
    return EXIT_SUCCESS;
}