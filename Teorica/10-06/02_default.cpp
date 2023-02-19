#include <iostream>
#include <string>

std::string Greet(const std::string& whom = "world")
{
    return "Hello " + whom + "!";
}

int main(int argc, char *argv[])
{
    std::string to_whom;

    if (argc > 1) {
        to_whom = Greet(argv[1]);
    } else {
        to_whom = Greet();
    }
    std::cout << to_whom << std::endl;

    return 0;
}
