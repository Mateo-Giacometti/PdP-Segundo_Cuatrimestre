#include <math.h>
#include "my_math.h"

float fsuma(float a, float b){
    return a + b;
}

float fresta(float a, float b){
    return a - b;
}

float fmult(float a, float b){
    return a*b;
}

float fdiv(float a, float b){
    return a / b;
}

float distancia(float x1, float y1, float x2, float y2){
    float dy = fresta(y2, y1);
    float dx = fresta(x2, x1);

    return sqrt(dx * dx + dy * dy);
}