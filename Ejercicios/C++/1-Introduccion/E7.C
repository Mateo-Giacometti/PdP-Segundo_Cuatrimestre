#include <iostream>
#include <string>
#include <cmath>

/*
Escribir un programa que calcule las raíces de un polinomio de segundo
grado. Pruebe los tres tipos de soluciones que existen:
a. Raíz doble.
b. Raíces reales.
c. Raíces complejas
*/


void raices(int a, int b, int c){
    int discriminante = b*b - 4*a*c;
    if(discriminante > 0){
        std::cout << "Raices reales" << std::endl;
        std::cout << "x1 = " << (-b + sqrt(discriminante))/(2*a) << std::endl;
        std::cout << "x2 = " << (-b - sqrt(discriminante))/(2*a) << std::endl;
    }else if(discriminante == 0){
        std::cout << "Raiz doble" << std::endl;
        std::cout << "x1 = x2 = " << (-b)/(2*a) << std::endl;
    }else{
        std::cout << "Raices complejas" << std::endl;
        std::cout << "x1 = " << (-b)/(2*a) << " + " << sqrt(-discriminante)/(2*a) << "i" << std::endl;
        std::cout << "x2 = " << (-b)/(2*a) << " - " << sqrt(-discriminante)/(2*a) << "i" << std::endl;
    }
}

int main(void){
    int a, b, c;
    std::cout << "Ingrese a: ";
    std::cin >> a;
    std::cout << "Ingrese b: ";
    std::cin >> b;
    std::cout << "Ingrese c: ";
    std::cin >> c;
    raices(a, b, c);

    return EXIT_SUCCESS;
}