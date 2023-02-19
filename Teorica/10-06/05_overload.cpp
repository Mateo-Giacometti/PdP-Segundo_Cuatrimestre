#include <iostream>
#include <string>


std::string ShowMeTheType(int i) {
    return "int";
}

std::string ShowMeTheType(const std::string& s) {
    return "string";
}

int main(void)
{
    std::cout << "El tipo es: " << ShowMeTheType(1) << std::endl;

    std::cout << "El tipo es: " << ShowMeTheType("pato") << std::endl;

    return 0;
}
