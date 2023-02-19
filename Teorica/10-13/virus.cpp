#include "virus.hpp"

#include <cstdlib>

Virus::Virus(float newResistance)
{
    reproductionRate = defaultReproductionRate;
    resistance = newResistance;
}


Virus::Virus(float newReproductionRate, float newResistance)
{
    reproductionRate = newReproductionRate;
    resistance = newResistance;
}

// Si el virus se reproduce, devuelve uno nuevo igual a si mismo.
// En caso contrario, retorna NULL.
Virus* Virus::reproduce(float patientImmunity)
{
    float prob = (float) rand() / RAND_MAX;
    // Si la inmunidad del paciente es demasiado alta, no se reproduce
    if (patientImmunity > prob) {
        return NULL;
    }

    // Estadísticamente ¿le toca reproducirse?
    if (prob > reproductionRate) {
        return NULL;
    }
    return new Virus(reproductionRate, resistance);
}

// Devuelve verdadero si el virus sobrevive dada la inmunidad del paciente
bool Virus::survive(float patientImmunity)
{
    // Si la inmunidad del paciente es demasiado alta, no se reproduce
    if (patientImmunity > resistance) {
        return false;
    }
    return true;
}

const float Virus::defaultReproductionRate; 
