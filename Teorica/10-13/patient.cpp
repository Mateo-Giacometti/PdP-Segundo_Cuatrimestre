#include "patient.hpp"
#include "virus.hpp"

#include <cassert>
#include <cstdlib>
#include <iostream>

bool Patient::checkRep()
{
    return (immunity >= 0.0) && (immunity <= 1.0) && (virusPop.size() < MAX_VIRUS_POP);
}

Patient::Patient(float initImmunity, int initNumVirusCells)
{
    float resistance;

    immunity = initImmunity;
    initNumVirusCells = std::min(MAX_VIRUS_POP, initNumVirusCells);

    virusPop.reserve(MAX_VIRUS_POP);

    for (int i = 0; i < initNumVirusCells; i++) {
        // randomly generate resistance, between 0.0 and 1.0
        resistance = (float) std::rand() / RAND_MAX;
        virusPop.emplace_back(new Virus(resistance));
    }
}


Patient::~Patient()
{
    for (auto& virus : virusPop) {
        delete virus;
    }
}


bool Patient::simulateStep()
{
    bool survived = false;

    for (size_t i = 0; i < std::size(virusPop); ++i) {
        if (nullptr != virusPop[i]) {
            survived = virusPop[i]->survive(immunity);
            if (survived) {
                std::cout << "survived" << std::endl;
            } else {
                std::cout << "~survived" << std::endl;
                delete virusPop[i];
                virusPop[i] = nullptr;
            }
        }
    }

    return true;
}


void Patient::takeDrug()
{
    assert(checkRep());
    immunity = immunity + 0.1;
    assert(checkRep());
}


auto Patient::numViruses() {
    return std::size(virusPop);
}
