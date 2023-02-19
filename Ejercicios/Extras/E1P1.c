#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Resalizar una sumatoria de Gauss utilizando el siguiente prototipo

status_t gauss_sum(long *r, int n);

*/

typedef enum {
    ST_OK,
    ST_ERR_NULL_PTR,
    ST_ERR_LZERO_ARRAY,
    ST_ERR_INVALID_ARG,
    ST_ERR_UNKNOWN,
} status_t;


long gauss_sum1(int n){
    long r=0;

    for(int k=0; k<n;k++){
        r+=k;
    }
    return r;
}

status_t gauss_sum2(long *r, int n){
    if (NULL == r){
        return ST_ERR_LZERO_ARRAY;

    }
    if (n <=0){
        return  ST_ERR_INVALID_ARG;
    }

    *r = gauss_sum1(n);

    return ST_OK;

}

int main(void){
    long r;
    gauss_sum2(&r,10);

    printf("%ld\n", r);

    return EXIT_SUCCESS;
}