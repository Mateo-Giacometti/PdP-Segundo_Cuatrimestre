#include <iostream>
#include <string>
#include <cmath>

void sumar(double *a, double b, double c){
    if(a){
        *a = b + c;
    }
}

void suma(double &a, double b, double c){
    a = b + c;
}

auto sumar(const auto &a, const auto &b){
    return a + b;
}

int& ReturningReference(int number){
    int value = 0;

    value = 10 * number;

    return value;
}

int increment(void){

    int counter = 0;

    std::cout << "\tcounter: " << counter++ << std::endl;

    return counter;  
}

int static_increment(void){
    
    static int counter = 0;

    std::cout << "\tcounter: " << counter++ << std::endl;

    return counter;
}

std::string Greet(const std::string whom = "world"){
    return "Hello " + whom + "!";
}

int main(void){
    return EXIT_SUCCESS;
}