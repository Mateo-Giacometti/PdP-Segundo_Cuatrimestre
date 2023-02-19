#include <iostream>
#include <numbers>


class Shape
{
  public:
    virtual double Area() const = 0;
};

class Printable
{
  public:
    virtual void Print() const = 0;
};


class Rectangle : public Shape, public Printable
{
  public:
    Rectangle(double w, double h) : width_{w}, height_{h} {}
    double width() const
    {
        return width_;
    }
    double height() const
    {
        return height_;
    }
    double Area() const override
    {
        return width_ * height_;
    }
    virtual void Print() const override
    {
        std::cout << "Rectangle: " << width_ << " " << height_ << " (" << Area() << ")" << std::endl;
    }
  protected:
    double width_ = 0;
    double height_ = 0;
};


class Square : public Rectangle
{
  public:
    Square(double size) : Rectangle{size, size} {}
    void Print() const override
    {
        std::cout << "Square: " << width_ << " " << height_ << " (" << Area() << ")" << std::endl;
    }
};


class Circle : public Shape, public Printable
{
  public:
    Circle(double radius) : radius_{radius} {}
    double Area() const override
    {
        return 2 * std::numbers::pi * radius_ * radius_;
    }
    void Print() const override
    {
        std::cout << "Circle: " << radius_ << " (" << Area() << ")" << std::endl;
    }
  protected:
    double radius_ = 0;
};


void PrintShape(const Printable& r)
{
    r.Print();
}


int main(void)
{
    Rectangle rec(10, 15);
    Square sq(10);
    Circle c(5);

    PrintShape(rec);
    PrintShape(sq);
    PrintShape(c);

    return 0;
}
