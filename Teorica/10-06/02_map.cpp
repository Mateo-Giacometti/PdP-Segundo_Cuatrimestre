#include <iostream>
#include <map>
#include <string>

int main (void)
{
    std::map<int, std::string> alumnos;

    alumnos.emplace(4927523, "Nicolás");
    alumnos.emplace(2812376, "Joaquín");
    alumnos.emplace(3920523, "Lolo");

    for (const auto& [legajo, nombre] : alumnos) {
        std::cout << nombre << " (" << legajo << ")" << std::endl;
    }

    // .size
    // .at
    // .count
    // .contains

    for (const auto& kv : alumnos) {
        const auto& legajo = kv.first;
        const auto& nombre = kv.second;
        std::cout << nombre << " (" << legajo << ")" << std::endl;
    }

    std::cout << alumnos[3920523] << std::endl;
    std::cout << std::boolalpha << alumnos.contains(3920523) << "\n";
    std::cout << std::boolalpha << alumnos.contains(1111111) << "\n";

    std::cout << alumnos.count(3920523) << std::endl;
    std::cout << std::boolalpha << alumnos.contains(3920523) << std::endl;


    return 0;
}
