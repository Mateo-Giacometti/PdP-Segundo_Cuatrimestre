#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int index = 0;
    size_t max_len;

    if (argc < 2) {
        return 1;
    }

    max_len= strlen(argv[1]);
    index =1;


    for (size_t i =1; i<argc; i++){
        size_t len = strlen(argv[i]);
        if (len > max_len){
            index = i;
            max_len= len;
        }
    }
    puts(argv[index]);

    return 0;
}
