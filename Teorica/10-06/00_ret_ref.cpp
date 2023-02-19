#include <iostream>

int& ReturingReference(int number)
{
    int value = 0;
   
    value = 10 * number;

    return value;
}

int main(void) {
    int value;

    value = ReturingReference(123);

    std::cout << "value es: " << value << std::endl;

    return 0;
}
