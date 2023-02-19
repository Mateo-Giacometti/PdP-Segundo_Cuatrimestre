#include <iostream>


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
    Rectangle(int w, int h) : width_{w}, height_{h} {}
    int width() const
    {
        return width_;
    }
    int height() const
    {
        return height_;
    }
    // Class Shape requires Area
    double Area() const override
    {
        return width_ * height_;
    }
    virtual void Print() const override
    {
        std::cout << "Rectangle: " << width_ << " " << height_ << " (" << Area() << ")" << std::endl;
    }
  protected:
    int width_ = 0;
    int height_ = 0;
};


class Square : public Rectangle
{
  public:
    Square(int size) : Rectangle{size, size} {}
    void Print() const override
    {
        std::cout << "Square: " << width_ << " " << height_ << " (" << Area() << ")" << std::endl;
    }
};


class Pato : public Printable
{
  public:
    void Print() const override
    {
        std::cout << "Yo soy un pato" << std::endl;
    }
};


void PrintShape(const Printable& r)
{
    r.Print();
}


int main(void)
{
    Rectangle rec(10, 15);
    Square sq(10);
    Pato yo;

    PrintShape(rec);
    PrintShape(sq);
    PrintShape(yo);

    return 0;
}
