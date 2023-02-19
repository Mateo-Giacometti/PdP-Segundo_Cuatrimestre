#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/*
Escribir una función que dado un vector de enteros, devuelva un nuevo vector duplicando cada elemento. El programa debe imprimir lo que se ve en el ejemplo.
*/

int main(void){
    std::vector<int> v1 = {1,2,3,4,5};
    
    //Primera forma
    std::vector<int> v2(v1);
    std::cout << "{ ";
    for(int i=0; i<v2.size(); i++)
        std::cout << v2[i] << " ";
    std::cout<< "}"<< std::endl;
    
    //Segunda forma
    std::vector<int> v3;
    for(int i = 0; i < v1.size(); i++){
        v3.push_back(v1[i]);
    }
    std::cout << "{ ";
    for(int i=0; i<v3.size(); i++)
        std::cout << v3[i] << " ";
    std::cout<< "}"<< std::endl;

    //Tercer forma
    std::vector<int> v4;
    for(auto i : v1){
        v4.push_back(i);
    }
    std::cout << "{ ";
    for(auto each : v4){
        std::cout << each << " ";
     }
    std::cout<< "}"<< std::endl;
    
    return EXIT_SUCCESS;
}