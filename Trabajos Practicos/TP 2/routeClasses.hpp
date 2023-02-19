#pragma once
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include "pointCityClasses.hpp"

class Route{
    std::vector<City*> route_;
  public:
    Route(std::vector<City*>& route) : route_(route){}
    Route(Route& route);
    ~Route(){};
    double getRouteDistance();
    void mutate();
    void shuffleRoute();
    size_t size() const { return route_.size(); }
    City* operator[](size_t i) const { return route_[i]; }
    void cityAndRouteRepresetation();
    Route * breed(Route& parent);
    
};