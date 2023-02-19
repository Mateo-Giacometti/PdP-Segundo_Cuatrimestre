#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Desarrollar una clase vector que contenga lo siguiente:

-Sus coordenadas (x,y), como fin del vector, suponiendo que siempre el inicio está en el par (0, 0).
-Un constructor que recibe estos dos valores y los almacena en los miembros correspondientes.
-Una función que imprime por pantalla el valor de las coordenadas del vector.
-Una función que devuelve la norma del vector.
-Una función que devuelve el cuadrante donde se encuentra el vector.

Escribir un programa que permita tomar coordenadas introducidas por el usuario, y que imprima por pantalla la norma del vector y el cuadrante donde se encuentra.
*/

class Vector {
  private:
        int x_ = 0;
        int y_ = 0;
  public:
        Vector(int x, int y): x_(x), y_(y) {}
        ~Vector() {}
        void print(){std::cout << "x: " << x_ << " --- y : " << y_ << std::endl;}
        double norm(){return sqrt(pow(x_, 2) + pow(y_, 2));}
        int quadrant() {
            if (x_ > 0 && y_ > 0) {
                return 1;
            } else if (x_ < 0 && y_ > 0) {
                return 2;
            } else if (x_ < 0 && y_ < 0) {
                return 3;
            } else if (x_ > 0 && y_ < 0) {
                return 4;
            } else {
                return 0;
            }
        }
};

int main() {
    Vector v(5, 8);
    v.print();
    std::cout << "Norma: " << v.norm() << std::endl;
    std::cout << "Cuadrante: " << v.quadrant() << std::endl;
    return 0;
}