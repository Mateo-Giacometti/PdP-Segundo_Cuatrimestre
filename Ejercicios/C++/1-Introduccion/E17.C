#include <iostream>
#include <string>
#include <cmath>

/*
Escriba una función que devuelve el resultado de tirar una moneda (cara o ceca) sin utilizar el operador '%'.

a) Escriba un programa que realice 100 lanzamientos y que imprima la cantidad de caras y cecas obtenidas, junto con los porcentajes. 
Imprima la cantidad de veces seguida que salió cara.

b) Repita incrementando la escala de la cantidad de ensayos ¿Qué valores esperaría encontrar si la moneda se lanzara infinitas veces?
*/

int main(void){
    //Cara = 1 -- Ceca = 0
    float limit, cunt_car = 0, cunt_cec = 0, base;
    std::cout<< "Ingrese la cantidad de tiros: ";
    std::cin>> limit;

    for(int i = 0; i < limit; i++){
        base = std::rand()%2;
        if(base == 0){
            cunt_car += 1;
        }
        else{
            cunt_cec += 1;
        }
    }
    std::cout<< "Salieron " << cunt_car << " caras (" << (cunt_car*100)/limit << "%)" <<std::endl;
    std::cout<< "Salieron " << cunt_cec << " cecas (" << (cunt_cec*100)/limit << "%)" <<std::endl;
    return EXIT_SUCCESS;
}
