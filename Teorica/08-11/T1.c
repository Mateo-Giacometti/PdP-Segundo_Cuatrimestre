#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*
&& --> AND 
|| --> OR
!= --> NOT
*/

int main(void){
    int i, entero, decimal, a = 15, v1, v2;

    // Condicionales
    if ((a < 20) && (a > 10)){
        puts("i esta entre (10, 20)");
    }
    if ((a <= 10)||(a >= 20)){
        puts("i no esta entre (10, 20)");
    }
    if (!(a < 20) && (a > 10)){
        puts("i no esta entre (10, 20)");  
    } 

    // Parte de scanf
    scanf("%i", &i);
    printf("%i\n", i);

    scanf("%i.%i",&entero, &decimal);
    printf("Entero: %i\n", entero);
    printf("Decimal: %i\n", decimal);

    puts("Ingrese un entero: ");
    v1 = scanf("%i", &i);
    if (v1 == 1){
        printf("Valor de v1 = %i\n", v1);
        printf("%i\n", i);
    }
    else{
        puts("Ingresaste cualquier cosa monstruo\n");
    }

    puts("Ingrese dos enteros separados por un punto (.): ");
    v2 = scanf("%i.%i",&entero, &decimal); 
    if(v2 == 1){
        printf("Valor de v2 = %i\n", v2); //El valor se lo da la cantidad de elementos a los que les estas asignando un valor
        printf("Entero: %i\n", entero);
        puts("Ingresaste cualquier cosa en el segundo monstruo\n");
    }
    else if (v2 == 2){
        printf("Valor de v2 = %i\n", v2); //El valor se lo da la cantidad de elementos a los que les estas asignando un valor
        printf("Entero: %i\n", entero); 
        printf("Decimal: %i\n", decimal);
    }
    else{ 
        puts("Ingresaste cualquier cosa monstruo\n");
    }

    //switch (Buscar bien como es su funcionamiento)
    switch(v2){
    case 1:
        printf("Valor de v2 = %i\n", v2); //El valor se lo da la cantidad de elementos a los que les estas asignando un valor
        printf("Entero: %i\n", entero);
        puts("Ingresaste cualquier cosa en el segundo monstruo\n");
        break;
    case 2: 
        printf("Valor de v2 = %i\n", v2); //El valor se lo da la cantidad de elementos a los que les estas asignando un valor
        printf("Entero: %i\n", entero); 
        printf("Decimal: %i\n", decimal);
        break;
    default: 
        puts("Ingresaste cualquier cosa monstruo\n");
    }

    //Ciclos
    


    return 0;
}