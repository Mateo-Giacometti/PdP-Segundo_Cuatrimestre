#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    float i, o, u;
    int entero, decimal;
    char c;

    printf("Ingrese un float: ");
    scanf("%f", &i);

    /*--Como limpiar el buffer--*/

    //Pruebo ingresando "12345aeiou\n"

    while((c = getchar()) != '\n'){ //El getchar() lee caracteres hasta encontarce con el /n
        fputs(c, stdout);
    }

    printf("Ingrese otro float: ");
    scanf("%f", &o);
    while((c = getchar()) != '\n'){
        printf("Lei un %c\n",c);
    }

    u = 0;
    while (u < 7){
        printf("numero: %lf",u);
    }
    
    return 0;
}
