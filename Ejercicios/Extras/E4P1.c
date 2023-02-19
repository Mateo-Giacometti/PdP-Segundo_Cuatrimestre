#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *strdup(const char *s) {
    
    if (NULL == s) {
        return NULL;
    }

    char *copia = (char *) malloc(strlen(s) * sizeof(char));

    if(copia == NULL){
        return NULL;
    }
    
    strcpy(copia,s);
    
    return copia;

}

int main(void){
    const char s[5] = "holas";

    char *copy = strdup(s);

    for(size_t i = 0; i < 5; i++){
        printf("%c", copy[i]);
    }

    puts("");

    return EXIT_SUCCESS;
}