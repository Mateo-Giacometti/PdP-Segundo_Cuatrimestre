#include <iostream>
#include <tuple>

auto ThreeValues (int x)
{
    return std::make_tuple(x, "squared", x * x);
}


int main(void)
{
    auto [first, second, third] = ThreeValues(9);

    std::cout << "(" << first << ", " << second << ", " << third << ")" << std::endl;

    return 0;
}
