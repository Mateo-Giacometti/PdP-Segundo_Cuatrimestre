#include <iostream>

class Point
{
    double x_, y_;
  public:
    Point(double x, double y) : x_(x), y_(y) { std::cout << "Point()\n";}
    ~Point() { std::cout << "~Point()\n"; }
    void Print() const {
        std::cout << "(" << x_ << ", " << y_ << ")\n";
    }
    double x() const { return x_; }
    double y() const { return y_; }
};

class Vector
{
    Point start;
    Point end;
  public:
    Vector(double x1, double y1, double x2, double y2) :
        start{x1, y1}, end{x2, y2} {
        std::cout << "Vector()\n";
    }
    ~Vector() { std::cout << "~Vector()\n"; }
    void Print() const {
        std::cout << "(" << start.x() << ", " << start.y() << ") -> "
                  << "(" << end.x() << ", " << end.y() << ")\n";
    }
};


int main(void)
{
    Vector vec{-1, -2, 2, 1};

    vec.Print();

    return 0;
}
