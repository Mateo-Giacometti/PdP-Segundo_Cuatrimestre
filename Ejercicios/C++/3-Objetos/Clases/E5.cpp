#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Escribir un programa que defina una clase llamada MiClase con un miembro de datos privado de tipo int llamado x y dos funciones miembro. 
La primera función miembro llamada setx(int mivalor) establecerá el valor de x a su parámetro mivalor. La segunda función miembro 
se llama getx(), es de tipo int y devuelve el valor de x. Crear una instancia de la clase y utilizar el objeto para acceder a ambas 
funciones miembro.
*/

class MiClase{
  private:
    int x;
  public:
    MiClase(){}
    ~MiClase(){}
    void setx(int mivalor){x = mivalor;}
    int getx(){return x;}
};

int main(void){
    MiClase m;
    m.setx(5);
    std::cout << m.getx() << std::endl;
    return EXIT_SUCCESS;
}