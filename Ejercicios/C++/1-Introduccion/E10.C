#include <iostream>
#include <string>
#include <cmath>

/*
Utilizar sizeof para determinar el número de bytes que requiere cada tipo
en su sistema:
• bool
• char
• short
• int
• long
• float
• double
• long double
• enum bounds {lb = -1, ub = 511};
• enum suit {clubs, diamonds, hears, spades};
*/
enum class bounds {lb = -1, ub = 511};
enum class suit {clubs, diamonds, hears, spades};

int main(void){
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long double) << std::endl;
    std::cout << sizeof(bounds) << std::endl;
    std::cout << sizeof(suit) << std::endl;
    return EXIT_SUCCESS;
}