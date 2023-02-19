#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Escribir una clase point que tenga 3 coordenadas (x, y, z). ¿Cómo se puede acceder a los miembros individuales?
*/

class Point{
  private:
    double x_, y_, z_;
  public:
    Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}
    ~Point(){}
    void Print(){std::cout << "(" << x_ << "-" << y_ << "-" << z_ <<")\n";}
    double x(){return x_;}
    double y(){return y_;}
    double z(){return z_;}
};

int main(void){
  Point p(1, 2, 3);
  p.Print();
  std::cout << p.x() << " " << p.y() << " " << p.z() << std::endl;
  return EXIT_SUCCESS;
}
