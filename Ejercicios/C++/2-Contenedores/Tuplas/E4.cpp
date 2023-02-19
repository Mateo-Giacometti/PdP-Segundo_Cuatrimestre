#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <tuple> 

/*
Escribir una función reciba un vector de triplas donde cada tripla (tupla con 3 elementos) tiene la forma (string, string, int) representando que una 
persona le debe a otra un monto de dinero (ej: <”Juan”, “Ilaria”, 200> indica que Juan le debe a Ilaria 200 pesos). La función debe devolver un vector 
con los nombres de las personas que deben mas de lo que les deben.

[<"Juan", "Ilaria", 200>, <"Mauricio", "Juan", 100>,<"Ilaria", "Ignacio",100>] --> ["Juan", "Mauricio"]

*/

std::vector<std::string> deudores(std::vector<std::tuple<std::string, std::string, int>> &deudas){
    std::vector<std::string> finalDeuda;
    for(auto &each : deudas){
        int validacion = 0;
        for(auto find : deudas){
            if(std::get<0>(each) == std::get<1>(find)){
                if(std::get<2>(each) > std::get<2>(find)){
                    finalDeuda.emplace_back(std::get<0>(each));
                    validacion = 1;
                }
                else{
                    validacion = 1;
                }
            }
        }
        if(validacion == 0){
            finalDeuda.emplace_back(std::get<0>(each));
        }
    }
    return finalDeuda;
}

int main(void){
    std::vector<std::tuple<std::string, std::string, int>> deudas = {{"Juan", "Ilaria", 200}, {"Mauricio", "Juan", 100}, {"Ilaria", "Ignacio",100}};
    std::vector<std::string> gente_deudora = deudores(deudas);
    for(auto &each : gente_deudora){
        std::cout<< each << std::endl;
    }
    return EXIT_SUCCESS;
}