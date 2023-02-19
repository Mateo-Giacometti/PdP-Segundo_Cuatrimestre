#include "patient.hpp"
#include "virus.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(0));

    Patient *patient = new Patient(0.3, 5);

    std::cout << "Step 0: " << std::endl;
    patient->simulateStep();
    patient->takeDrug();
    patient->takeDrug();
    patient->takeDrug();
    std::cout << "Step 1: " << std::endl;
    patient->simulateStep();
    patient->takeDrug();
    patient->takeDrug();
    std::cout << "Step 2: " << std::endl;
    patient->simulateStep();

    delete patient;

    return 0;
}
