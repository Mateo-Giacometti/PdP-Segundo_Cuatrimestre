#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Escribir un programa que defina una clase llamada MiClase, la cual tenga una función miembro que imprima por 
pantalla “Hola Mundo!”. Crear una instancia de esa clase y utilice el objecto para llamar a la función miembro.
*/

class MiClase{
  public:
    MiClase();
    ~MiClase();
    void saludo();
};

MiClase::MiClase(){}
MiClase::~MiClase(){}
void MiClase::saludo(){
    printf("Hola Mundo!\n");
}

int main(void){
    MiClase *objeto = new MiClase();
    objeto->saludo();
    return EXIT_SUCCESS;
}