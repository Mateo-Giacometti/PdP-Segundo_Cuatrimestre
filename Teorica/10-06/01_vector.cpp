#include <vector>
#include <iostream>
#include <string>

int main (void)
{
    std::vector<std::string> data;
    data.reserve(10);

    std::cout << "Capacity: " << data.capacity() << std::endl;
    for (size_t i = 0; i < data.capacity(); i++) {
        std::string input;
        std::cin >> input;
        data.emplace_back(input);
    }

    for (const auto& elem : data) {
        std::cout << elem << std::endl;
    }

    std::cout << "vector at(0): " << data.at(0) << std::endl;
    data.at(0) = "Pato";
    std::cout << "vector at(0) after set: " << data.at(0) << std::endl;

    std::cout << "vector operator[0]: " << data[0] << std::endl;
    data[0] = "Patricio";
    std::cout << "vector operator[0] after set: " << data[0] << std::endl;

    std::cout << "std::vector::front: " << data.front() << std::endl;
    std::cout << "std::vector::back: " << data.back() << std::endl;

    std::cout << std::boolalpha;
    std::cout << "vector empty: " << data.empty() << std::endl;
    std::cout << "vector size: " << data.size() << std::endl;

    std::cout << ">> Emplace" << std::endl;
    data.emplace_back("Emilio");
    data.emplace_back("José");

    for (const auto& elem : data) {
        std::cout << elem << std::endl;
    }
    std::cout << "vector size: " << data.size() << std::endl;
    std::cout << "std::vector::front: " << data.front() << std::endl;
    std::cout << "std::vector::back: " << data.back() << std::endl;

    std::cout << ">> Clear" << std::endl;
    data.clear();
    std::cout << std::boolalpha;
    std::cout << "vector empty: " << data.empty() << std::endl;
    std::cout << "vector size: " << data.size() << std::endl;

    return 0;
}
