#include <iostream>
#include <string>

/*
Escribir un programa que reciba tres enteros (por ejemplo a, b y c) ingresados
por el usuario, y devuelva el resultado de la siguiente ecuación:
sum = (a + b + c) * 2 + c
*/

int suma(int a, int b, int c){
    return (a + b + c) * 2 + c;
}

int main(void){
    int a, b, c, sum;

    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el valor de c: ";
    std::cin >> c;

    std::cout << "El resultado de la ecuación es: " << suma(a,b,c) << std::endl;

    return EXIT_SUCCESS;
}