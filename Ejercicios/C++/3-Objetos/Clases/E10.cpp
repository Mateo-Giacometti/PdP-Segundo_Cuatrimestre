#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Escribir un programa que sobrecargue el operador aritmético - para poder restar vectores (clase definida en el ejercicio 7). 
Implementar el siguiente código para comprobar la correcta implementación del ejercicio:
int main() {
  vector v1{3.0, 2.0};
  vector v2{1.0, 5.0};
  vector v3 = v1 - v2;

  v3.printvalues();  // printvalues() es la función miembro que imprime las
                     // coordenadas del vector
}
*/


class vector {
  private:
    double x_;
    double y_;
  public:
    vector(double x, double y) : x_(x), y_(y) {}
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
    vector operator-(const vector v) const {
      return vector(x_ - v.x_, y_ - v.y_);
    }
};

int main() {
  vector v1{3.0, 2.0};
  vector v2{1.0, 5.0};
  vector v3 = v1 - v2;

  v3.print();  // printvalues() es la función miembro que imprime las
                     // coordenadas del vector

    return 0;
}

