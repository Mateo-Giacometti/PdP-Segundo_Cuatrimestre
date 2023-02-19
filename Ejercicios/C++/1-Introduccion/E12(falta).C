#include <iostream>
#include <string>
#include <cmath>

/*Escriba un programa que imprima el estado del agua (sólido, líquido o gaseoso) según su temperatura en Fahrenheit. 
Puede implementar una función con lo desarrollado en el punto anterior para consultar los puntos de cambio de estado (0 y 100 grados para 
presión atmosférica de 1 atm). 
Utilice un tipo enumerado:
enum class State {kSolid = SOLID_TEMP, kLiquid = LIQUID_TEMP, KGas = GAS_TEMP};
*/

int main(void){
    float temperatura;
    std::cout<< "A que temperatura se encuentra ? (Colocar en grados Fahrenheit)"<<std::endl;
    std::cin>> temperatura;
    if(temperatura >= 212){

    }
    return EXIT_SUCCESS;
}