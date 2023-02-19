#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <tuple> 

/*
Escribir una función que dado un vector de pares de strings representando el nombre de una persona y el nombre de alguno de sus ancestros (padre, madre, abuelo, bisabuelo) y 
una tupla con dos nombres que aparecen en el vector, devuelva verdadero solamente si el primer nombre es ancestro del segundo (tener encuenta que si A es ancestro de B y B 
es ancestro de C, necesariamente A es ancestro de C).
Asumir que la entrada está “bien formada”, es decir, si A es ancestro de B y B es ancestro de C, C no puede tener un “camino de ancestros” hasta A (ej, una persona no puede 
ser nieto de su padre).

[<"Abraham", "Homero">, <"Homero", "Bart">, <"Marge", "Lisa">], "Homero", "Bart" --> _verdadero_
[<"Abraham", "Homero">, <"Homero", "Bart">, <"Krusty", "Sophie">], "Krusty", "Bart" --> _falso_
[<"Abraham", "Homero">, <"Homero", "Bart">, <"Homero", "Lisa">], "Lisa", "Bart" --> _falso_

*/

bool ancestro(const std::vector<std::tuple<std::string,std::string>> &dinastia, const std::tuple<std::string,std::string> &seleccion) {
    for(auto each : dinastia){
        if(std::get<0>(each) == std::get<0>(seleccion) && std::get<1>(each) == std::get<1>(seleccion)){
            return true;
        }
        if(std::get<0>(each) == std::get<0>(seleccion)){
            return ancestro(dinastia, {std::get<0>(each), std::get<1>(seleccion)});
        }
    }
    return false;
}

int main(void){
    std::vector<std::tuple<std::string, std::string>> v = {{"Abraham", "Homero"}, {"Homero", "Bart"}, {"Marge", "Lisa"}};
    std::tuple<std::string, std::string> n = { "Homero", "Bart"};
    std::tuple<std::string, std::string> b = {"Krusty", "Bart"};
    if(ancestro(v,n)){
        std::cout<<"Anda"<<std::endl;
    }
    if(ancestro(v,b) == false){
        std::cout<<"Anda"<<std::endl;
    }
    return EXIT_SUCCESS;
}