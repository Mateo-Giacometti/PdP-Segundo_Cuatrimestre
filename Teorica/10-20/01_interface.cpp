#include <iostream>

class Printable
{
  public:
    virtual void Print() const = 0;
};


class A : public Printable
{
  public:
    void Print() const override
    {
        std::cout << "Print from A" << std::endl;
    }
};


class B : public Printable
{
  public:
    void Print() const override
    {
        std::cout << "Print from B" << std::endl;
    }
};


void Print(const Printable& var)
{
    var.Print();
}


int main()
{
    Print(A());
    Print(B());

    return 0;
}
