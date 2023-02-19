#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que compare (reciba) 2 números enteros a y b. La función debe retornar 
un número menor, igual o mayor que cero si a es, respectivamente, menor que, igual a, o mayor que b.*/

int mom(int a){
    if(a >= 0){
        printf("%i\n",1);
        return 1;
    }
    else{
        printf("%i\n",-1);
        return -1;
    }
}

int main(void){
    int a1;
    printf("Ingrese un numero: ");
    scanf("%i",&a1);
    mom(a1);
    return 0;
}