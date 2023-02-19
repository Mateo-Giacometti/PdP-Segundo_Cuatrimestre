#include <iostream>

class Rectangle
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
  protected:
    int width_ = 0;
    int height_ = 0;
};

class Square : public Rectangle
{
  public:
    Square(int size) : Rectangle{size, size} {}
};

int main(void)
{
    Rectangle rec(10, 15);
    Square sq(10);

    std::cout << "Rectangle: " << rec.width() << " " << rec.height() << std::endl;
    std::cout << "Square: " << sq.width() << " " << sq.height() << std::endl;

    return 0;
}
