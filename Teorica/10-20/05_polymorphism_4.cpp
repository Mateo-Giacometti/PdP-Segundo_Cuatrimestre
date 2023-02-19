#include <iostream>


class PrintableShape
{
  public:
    virtual void Print() const = 0;
};


class Rectangle : public PrintableShape
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
    virtual void Print() const override
    {
        std::cout << "Rectangle: " << width_ << " " << height_ << std::endl;
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
        std::cout << "Square: " << width_ << " " << height_ << std::endl;
    }
};


void PrintShape(const PrintableShape& r)
{
    r.Print();
}


int main(void)
{
    Rectangle rec(10, 15);
    Square sq(10);

    PrintShape(rec);
    PrintShape(sq);

    return 0;
}
