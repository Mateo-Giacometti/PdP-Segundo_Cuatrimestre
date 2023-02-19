#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/* C++ */
/* ejercicio 1: greet */
void greet(const std::string &name)
{
    std::cout << "Hola " << name << "\n";
}

/* ejercicio 3: swap */
void intercambiar(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

/* ejercicio 2: lectura */

int main(void)
{
    int var;
    int a = 5;
    int b = 7;
    std::string name = "Mateo";

    std::cin >> var;

    if (var % 2) {
        std::cout << "No es par\n";
    } else {
        std::cout << "Es par\n";
    }

    greet(name);

    intercambiar(a,b);

    std::cout << a << " " << b << std::endl;

    return EXIT_SUCCESS;
}
