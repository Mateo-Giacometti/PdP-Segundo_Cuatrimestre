#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <tuple> 

/*
Escribir una función que dado el código de una materia retorne una tupla con el nombre de la materia y el nombre del docente a cargo. 
Por ejemplo, para el código “I102” la función devuelve la tupla (“Paradigmas de Programación”, “Patricio Moreno”).
*/

std::tuple<std::string,std::string> get_materia(std::string codigo){
    std::vector<std::tuple<std::string,std::string, std::string>> materias = {{"I102","Paradigmas de Programacion", "Patricio Moreno"}, 
    {"I101","Algoritmos y Estructuras de Datos", "Patricio Moreno"}, {"I103","Sistemas Operativos", "Patricio Moreno"}, {"I104","Redes de Computadoras", "Patricio Moreno"}, 
    {"I105","Ingenieria de Software", "Patricio Moreno"}};

    for(auto materia : materias){
        if(std::get<0>(materia) == codigo){
            return std::make_tuple(std::get<1>(materia), std::get<2>(materia));
        }
    }
    return std::make_tuple("La materia no existe","El profesor tampoc existe");

}	

int main(){
    std::string codigo;
    std::cout << "Ingrese el codigo de la materia: ";
    std::cin >> codigo;
    std::tuple<std::string,std::string> materia = get_materia(codigo);
    std::cout << "{" << std::get<0>(materia) << ", " << std::get<1>(materia) << "}" << std::endl;
    return EXIT_SUCCESS;
}