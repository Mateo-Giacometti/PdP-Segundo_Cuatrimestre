#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Implementar una función recursiva que reciba un double z y un entero k y retorne:
- z+k
- z*k
- z**k
*/

int sum_r(double z, int k){
    if(k == 0){
        return z;
    }
    else{
        return z + k;
    }
}

int mul_r(double z, int k){
    if((k == 0) || (z == 0)){
        return 0;
    }
    else if(k == 1){
        return z;
    }
    else{
        return z + mul_r(z, k - 1);
    }
}

int pot_r(double z, int k){
    if(k == 0){
        return 1;
    }
    else if(k == 1){
        return z;
    }
    else{
        return z * pot_r(z, k-1);
    }
}

int main(void){
    double z;
    int k;
    printf("Ingrese un numero: ");
    scanf("%lf", &z);
    printf("Ingrese un numero: ");
    scanf("%d", &k);
    printf("La suma es recursiva es: %d\n", sum_r(z, k));
    printf("La multiplicacion recursiva es: %d\n", mul_r(z, k));
    printf("La potencia recursiva es igual a %d\n", pot_r(z, k));

    return EXIT_SUCCESS;
}