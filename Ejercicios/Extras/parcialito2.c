/// punto 2
/// [1, 2, 3, 4, 5], 3
/// u0= (1 +2 +3) /3
/// s0= abs(1- 2)+ abs(2-2)+ abs(3-2) / 3 => 2/3
/// u1=(2+ 3+ 4)/ 3
/// s1= (abs(2-3) + abs(3-3) + abs (4-3)) / 3 => 2/3


#include <stdio.h>
#include <stdlib.h>
#include <math.h>




double mean(const double *v, size_t n){
    double suma =0;

    for (size_t i=0; i< n; i++){
        suma += v[i];

    }
    return suma / n;

}

double std(const double *v, size_t n){
    double s= 0;
    double mu= mean (v,n);

    for (size_t i =0; i<n; i++){
        s += fabs(v[i]-mu);

    }
    return s /n;

}

ssize_t search(const double *v, size_t l, int n){
    ssize_t index = 0;
    double s_min = 0;


    if (NULL == v) {
        return -1;
    }

    if (n <= 0 || l == 0 || n>l ){
        return -1;
    }


    s_min = std(v,n);
    index =0;

    for (size_t i =1; i <l-n; i){
        double s= std(&v[i],n);
        if ( s <s_min){
            index = i;
            s_min= s;
        }


    return i;

}

double x[]= {1, 2, 3, 4};
ssize_t i = search (x, 4, 2);
