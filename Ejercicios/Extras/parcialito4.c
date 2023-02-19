#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *strdup(const char *s) {
    char *copy;

    if (NULL == s) {
        return NULL;
    
    }

    copy= (char *) malloc(strlen(s) +1);
    return strcpy(copy,s);

}
