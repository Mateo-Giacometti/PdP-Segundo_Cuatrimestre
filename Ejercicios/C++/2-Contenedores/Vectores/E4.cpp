#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/*Escribir una función que dado un vector de enteros y un número entero devuelva true solamente si en el vector hay al menos 3 de sus 
primeros 5 múltiplos (un número es múltiplo de si mismo).*/

bool numeros_multiplos(std::vector<int> &v, int n){
    int cont = 0;
    int aux[5];
    for(int i = 1; i <= 5; i++){
        aux[i-1] = n*i;
    }
    for(int z = 0; z < 5; z++){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == aux[z]){
                cont++;
            }
        }
    }
    if(cont >= 3){
        return true;
    }
    return false;
}

int main(void){
    std::vector<int> v1 = {1,2,3,4,5};
    std::vector<int> v2 = {1,2,3,4,5,6};
    std::vector<int> v3;
    v3.reserve(5);	
    v3 = v1;
    if(numeros_multiplos(v2,2)){
        printf("True\n");
    }

    if(numeros_multiplos(v1,2) == false){
        printf("False\n");
    }

    return EXIT_SUCCESS;
}