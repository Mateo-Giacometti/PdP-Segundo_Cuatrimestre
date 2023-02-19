#include <stdio.h>
#include <math.h>

int main(void){
    float flotante = 0.80;
    int entero = 12345;
    char caracter = 'a';
    printf("El valor de entero es: %i\n", entero);
    printf("El valor de float es: %f\n", flotante);
    printf("El valor de entero es: %i\nEl valor de float es: %f\n", entero, flotante);
    printf("%c\n", 'a');
    printf("%c\n", 64); //Ver tabla ASCII
    printf("%c\n", caracter);
    printf("%i\n", caracter - 97);

    printf("Un char ocupa %lu bytes\n", sizeof(char));
    printf("Un short ocupa %lu bytes\n", sizeof(short));
    printf("Un int ocupa %lu bytes\n", sizeof(int));
    printf("Un long int ocupa %lu bytes\n", sizeof(long int));

    int c, d;

    c = 45;
    d = 32;
    c++; //Incrementa c en 1 (se hace efectivo en la siguiente lines)
    d--; //Disminuye d en 1 (se hace efectivo en la siguiente lines)
    ++c; //Incrementa c en 1 (se hace efectivo en la misma lines)
    --d; //Disminuye d en 1 (se hace efectivo en la misma lines)

    c += 5;
    d -= 5;


    int x,y,z;
   
    x = 32; 
    y = 23;
    z = 5;

    printf("%i + %i = %i\n", x,y,z); 
    printf("%i + %i = %i\n", x,y,x+y);
    printf("%i - %i = %i\n", x,y,x-y);
    printf("%i * %i = %i\n", x,y,x*y);
    printf("%i / %i = %i\n", x,y,x/y);
    printf("%i / %i = %f\n", x,y,x/(float)y);


    double a,b;
    a = 3;
    b = 5;
    
    //printf("%lf ^ %lf = %lf", a, b, pow(a, b));
    
    if (x > 20){
        puts("x es mayor a 20");
    } else {
        puts("x no es mayor a 20");
    }
        
    
    return 0;
}

