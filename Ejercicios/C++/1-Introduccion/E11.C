#include <iostream>
#include <string>
#include <cmath>

/*
Escriba una función para convertir grados Celsius a grados Fahrenheit,
y otra para convertir grados Fahrenheit a Celsius. Escriba un programa
(main) que permita validar distintas conversiones. Si las funciones se llaman
C2F() y F2C() respectivamente, verifique que se cumpla:
C2F(F2C(temperatura)) = temperatura y F2C(C2F(temperatura)) = temperatura
*/

float F2C(float Fahrenheit){
    return (Fahrenheit - 32)*(5.0/9.0);
}

float C2F(float Celsius){
    return (Celsius / (5.0/9.0)) + 32;
}

int main(void){
    float f;
    float c;

    std::cout << "Ingrese grados C: ";
    std::cin >> c;

    std::cout << "En F son igual a " << C2F(c) << " F" << std::endl;

    std::cout << "Ingrese grados F: ";
    std::cin >> f;

    std::cout << "En C son iguales a " << F2C(f) << " C" << std::endl;
    
    return EXIT_SUCCESS;
}