#pragma once

#include "virus.hpp"

#include <vector>

#define MAX_VIRUS_POP 1000

class Patient {
    std::vector<Virus *> virusPop;
    float immunity; // degree of immunity, in %
    bool checkRep();
  public:
    Patient(float initImmunity, int initNumViruses);
    ~Patient();
    void takeDrug();
    bool simulateStep();
    auto numViruses();
};
