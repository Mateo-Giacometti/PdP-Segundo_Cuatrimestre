#include <iostream>
#include <string>
#include <cmath>

/*Escribir un programa que acepte grados Celsius y Fahrenheit, y produzca la conversión correspondiente. Por ejemplo, una 
entrada 0C devuelve 32F, mientras una entrada 212F devuelve 100C. Asuma una opción por defecto cuando no se especifica la unidad de entrada.*/

float F2C(float Fahrenheit){
    return (Fahrenheit - 32)*(5.0/9.0);
}

float C2F(float Celsius){
    return (Celsius / (5.0/9.0)) + 32;
}

int main(void){
    std::string temp;
    std::cout<< "Ingrese la temperatura a convertir: ";
    std::cin>> temp;
    if(temp[(temp.length())-1] == 'C' || temp[(temp.length())-1] == 'c'){
        std::cout<< C2F(std::stof(temp))<< "F" <<std::endl;
    }
    else if(temp[(temp.length())-1] == 'F' || temp[(temp.length())-1] == 'f'){
        std::cout<< F2C(std::stof(temp))<< "C" <<std::endl;
    }
    else{
        std::cout<< "Ingreso de forma incorrecta la informacion. Vuelva a intentarlo"<<std::endl;
    }
    return EXIT_SUCCESS;
}