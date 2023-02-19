#pragma once

class Virus {
    float reproductionRate;
    float resistance;
    static constexpr float defaultReproductionRate = 0.1;
  public:
    Virus(float newResistance);
    Virus(float newReproductionRate, float newResistance);
    Virus* reproduce(float immunity);
    bool survive(float immunity);
};
