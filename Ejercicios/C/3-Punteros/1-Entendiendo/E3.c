#include <stdio.h>

int main(void){
    float var, set[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float *p;

    p = set;
    var = *p;
    *p=10.0;

    int conj[5], list[]={5, 4, 3, 2, 1};
    int *punt;

    punt = list;
    conj = punt;
    list = conj;
    punt = &conj;

    int *pint, arrayint[5];
    float *pfloat, arrayfloat[5];

    pint = arrayint;
    pfloat = arrayfloat;
    pint += 1;
    pfloat += 1;
    pint++;
    pfloat++;
    pint -= 1;
    pfloat -=1;


    return 0;
}