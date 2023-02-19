#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>

/*Escribir una función que compare (reciba) 2 números enteros a y b. La función debe retornar 
un número menor, igual o mayor que cero si a es, respectivamente, menor que, igual a, o mayor que b.*/

int mom(int a, int b){
    if(a >= b){
        printf("%i\n",a);
        return a;
    }
    else{
        printf("%i\n",b);
        return b;
    }
}

int main(void){
    int a1,b1;
    printf("Ingrese un numero: ");
    scanf("%i%i",&a1,&b1);
    mom(a1,b1);
    return 0;
}