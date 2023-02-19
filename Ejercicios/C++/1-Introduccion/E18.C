#include <iostream>
#include <string>
#include <cmath>

/*
Escriba una función que imprima los primeros N nùmeros de la sucesión de Fibonacci.
*/

int main(void){
    int n;
    int a = 0;
    int b = 1;
    int c = 0;

    std::cout << "Ingrese N: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        std::cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
