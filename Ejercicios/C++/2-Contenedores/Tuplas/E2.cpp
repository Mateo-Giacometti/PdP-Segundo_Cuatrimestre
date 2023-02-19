#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <tuple> 

/*
Escribir una función que dada una cadena y un vector de tuplas que contienen una cadena y un arreglo de enteros, devuelva un nuevo vector de tuplas que 
contenga únicamente las tuplas cuyo primer elemento concuerda con la cadena pasada como argumento de la función.
*/

std::vector<std::tuple<std::string, int>> selection(const std::string &clave, const std::vector<std::tuple<std::string, int>>& origen){
    std::vector<std::tuple<std::string, int>> finalSelection;

    for(auto &each : origen){
        if(std::get<0>(each) == clave){
            finalSelection.push_back({std::get<0>(each), std::get<1>(each)});
        }
    }
    return finalSelection;
}

int main(void){
    std::vector<std::tuple<std::string, int>> select = {{"EEG", 10000}, {"ECG", 120000}, {"EEG", 780000}, {"EMG", 22}};
    std::vector<std::tuple<std::string, int>> final = selection("EEG", select);
    for(auto each : final){
        std::cout<< "{ "<< std::get<0>(each) << " - " << std::get<1>(each) << " } ";
    }
    std::cout<< std::endl;
    return EXIT_SUCCESS;
}