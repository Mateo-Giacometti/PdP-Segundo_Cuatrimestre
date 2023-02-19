#include <array>
#include <iostream>

int main (void)
{
    std::array<float, 5> data{1.0f, 10.0f, 11.0f, 100.0f, 101.0f};

    for (const auto& elem : data) {
        std::cout << elem << std::endl;
    }

    std::cout << "array at(0): " << data.at(0) << std::endl;
    data.at(0) = 0.0f;
    std::cout << "array at(0) after set: " << data.at(0) << std::endl;

    std::cout << "array operator[0]: " << data[0] << std::endl;
    data[0] = 10000.0f;
    std::cout << "array operator[0] after set: " << data[0] << std::endl;

    std::cout << "std::array::front: " << data.front() << std::endl;
    std::cout << "std::array::back: " << data.back() << std::endl;

    std::cout << std::boolalpha;
    std::cout << "array empty: " << data.empty() << std::endl;
    std::cout << "array size: " << data.size() << std::endl;

    return 0;
}
