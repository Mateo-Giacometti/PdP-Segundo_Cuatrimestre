#include <iostream>

int increment(void)
{
    int counter = 0;

    std::cout << "\tcounter: " << counter++ << std::endl;

    return counter;
}

int static_increment(void)
{
    static int counter = 0;

    std::cout << "\tcounter: " << counter++ << std::endl;

    return counter;
}

int main(void)
{
    int counter;
    int static_counter;
    std::cout << "Increment: " << std::endl;
    increment();
    increment();
    increment();
    increment();

    std::cout << "static Increment: " << std::endl;
    static_counter = static_increment();
    std::cout << " static counter: " << static_counter << std::endl;
    static_counter = static_increment();
    std::cout << " static counter: " << static_counter << std::endl;
    static_counter = static_increment();
    std::cout << " static counter: " << static_counter << std::endl;
    static_counter = static_increment();
    std::cout << " static counter: " << static_counter << std::endl;

    return 0;
}
