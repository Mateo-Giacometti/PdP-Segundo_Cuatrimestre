#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*Implemente sus propias versiones de las funciones de la biblioteca string.h que se detallan:

size_t strlen(const char *);
char * strcpy(char *dest, const char *orig);
char * strncpy(char *dest, const char *orig, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char * strcat(char *dest, const char *orig);
void * memmove(void *dest, const void *src, size_t n);
void * memcpy(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
*/ 

size_t strlen1(char *c){
    size_t i = 0;
    while(c[i] != '\0'){
        i++;
    }
    return i;
}

char * strcpy1(char *dest, const char *orig){
    for(int i = 0; i < strlen1(dest); i++){
        dest[i] = orig[i];
    }
    return dest;
}

char * strncpy1(char *dest, const char *orig, size_t n){
    for(int i = 0; i < n; i++){
        dest[i] = orig[i];
    }
    return dest;
}

int strcmp1(char *s1, char *s2){
    for(int i = 0; i < strlen1(s1); i++){
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int strncmp1(const char *s1, const char *s2, size_t n){
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
    }
    return 0;
}

char * strcat1(char *dest, const char *orig){
    int i = 0;
    int j = 0;
    while(dest[i] != '\0'){
        i++;
    }
    while(orig[j] != '\0'){
        dest[i] = orig[j];
        i++;
        j++;
    }
    return dest;
}


int main(void){
    size_t n = 2;
    char sum[20] = "Hola ";
    const char a[4] = "chau";
    char b[4] = "chau";
    char c[5] = "no es";
    char d[5] = "no es";
    char r[4] = "hola";
    char v[4] = "ol";
    printf("%ld\n", strlen1(r));

    printf("%s\n", strcpy1(r,a));

    printf("%s\n", strncpy1(v,a,n));

    printf("%d\n", strcmp1(c,b));
    printf("%d\n", strcmp1(d,c));

    printf("%d\n", strncmp1(c,b,n));
    printf("%d\n", strncmp1(d,c,n));

    printf("%s\n", strcat1(sum,b));

    return EXIT_SUCCESS;
}