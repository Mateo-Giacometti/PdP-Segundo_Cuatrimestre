#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Tomar la clase vector desarrollada en el ejercicio anterior, y agregar una función constructora de copia que copie todos sus miembros.
En un programa de prueba, generar un objeto de clase llamado v1, inicializándolo con algun par de coordenadas cualquiera. Luego, generar otro objeto llamado v2, e inicializarlo 
con el objeto v1. Imprimir por pantalla los datos de ambos vectores.
*/


class Vector {
  private:
        int x_ = 0;
        int y_ = 0;
  public:
        Vector(int x, int y): x_(x), y_(y) {}
        Vector(Vector& v): x_(v.x_), y_(v.y_) {} 
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

int main(void){
    Vector v1(9,6);
    Vector v2(v1);

    v1.print();
    std::cout << "Norma: " << v1.norm() << std::endl;
    std::cout << "Cuadrante: " << v1.quadrant() << std::endl <<std::endl;

    v2.print();
    std::cout << "Norma: " << v2.norm() << std::endl;
    std::cout << "Cuadrante: " << v2.quadrant() << std::endl;
   
    return EXIT_SUCCESS;
}
