#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <vector>

/*
Escribir una función de dado un vector de nombres (strings) devuelva un mapa con los nombres como claves y como valores, para cada clave, la cantidad de veces 
que aparece en el vector.
*/


std::map<std::string, int> nombres(std::vector<std::string> v){
    std::map<std::string, int> dic;
    for(int i = 0; i < v.size(); i++){
        dic[v[i]]++;
    }
    return dic;
}

int main(void){
    std::vector<std::string> names = {"Mariano", "Julia", "Pepe", "Mariano", "Mariano", "Julia"};
    std::map<std::string, int> dic = nombres(names);

    for(auto each : dic){
        std::cout << each.first << " " << each.second << std::endl;
    }

    return EXIT_SUCCESS;
}