#include "print_map.hpp"

#include <iostream>
#include <map>
#include <string>


std::string ShowMeTheType(int i) {
    return "int";
}

std::string ShowMeTheType(const std::string& s) {
    return "string";
}

std::map<std::string, int> NonAutoFunction (void)
{
    return std::map<std::string, int>{{"a", 1}, {"b", 0}, {"c", 2}};
}

auto AutoFunction (void)
{
    return std::map<std::string, int>{{"a", 10}, {"b", 0}, {"c", 20}};
}

int main(void)
{
    std::map<std::string, int> m;
    

    m = AutoFunction();
    print_map("AutoFunction(): ", m);

    std::cout << "m tiene " << m.size() << " elementos" << std::endl;


    m = NonAutoFunction();
    print_map("NonAutoFunction(): ", m);

    std::cout << m["a"] << std::endl;

    return 0;
}
