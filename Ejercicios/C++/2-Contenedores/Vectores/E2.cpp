#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/*
Escribir una función que dado un vector de enteros, devuelva el vector sin los números primos (suponer números mayores a cero; 1 no es primo). 
La función debe modificar el vector, no crear uno nuevo.
*/


bool is_prime(int n){
    if(n==1){
        return false;
    }
    else{
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}

void remove_primes(std::vector<int> &v){
    for(int i=0; i<v.size(); i++){
        if(is_prime(v[i])){
            v.erase(v.begin() + i);
            i--;
        }
    }
}

int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,17};
    remove_primes(v);
    for(int i=0; i<v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}