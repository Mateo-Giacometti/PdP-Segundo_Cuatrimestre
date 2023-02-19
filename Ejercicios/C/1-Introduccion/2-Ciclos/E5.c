#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>

/*El algoritmo babilonio para calcular la raíz cuadrada de un número N consta de los siguientes pasos:

a- Se propone que el resultado de la raíz X vale un valor arbitrario, por ejemplo N.
b- Se inicializa Y en 1.
c- Mientras que la diferencia entre X e Y sea superior a nuestro margen de error:
    i- El nuevo valor de X se calcula como el promedio entre X e Y.
    ii- El nuevo valor de Y se calcula como N/X.

Implementar una función que calcule la raíz cuadrada de N según este método.*/


float babilonio(float a){
    float x = a/2;
    for(int i = 0; i < 25; i++){
        if(x * x == a){
            return x;
        }
        else{
            x = ((x + (a/x))/2);
        }
    }
    return x;
}
int main(void){
    float a1;
    printf("Ingrese el numero a buscar la raiz cuadrada: ");
    scanf("%f",&a1);
    printf("%f\n", babilonio(a1));
    return 0;
}