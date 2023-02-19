#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Escribir un programa que defina una clase llamada MiClase, que tenga definido un constructor y un destructor. Ambos deben imprimir 
por pantalla un mensaje acorde (por ej: “Hola Mundo” y “Adiós Mundo”).
*/

class MiClase{
  public:
    MiClase(){std::cout << "Hola Mundo" << std::endl;}
    ~MiClase(){std::cout << "Adios Mundo" << std::endl;}
};

int main(void){
    MiClase m;
    return EXIT_SUCCESS;
}