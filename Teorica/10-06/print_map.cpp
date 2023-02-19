#include "print_map.hpp"

#include <iostream>
#include <map>
#include <string>

void print_map(const std::string& preface,
               const std::map<std::string, int>& m)
{
    std::cout << preface ;

    for (const auto& [key, value] : m) {
        std::cout << '[' << key << "] = " << value << "; ";
    }

    std::cout << '\n';
}
