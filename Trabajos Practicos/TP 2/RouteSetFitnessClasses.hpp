#pragma once
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include "routeClasses.hpp"

class Fitness{
    Route * route_;
    double fitness_;
  public:
    Fitness(Route * route): route_(route){
        fitness_ = 1/route->getRouteDistance();
    }
    ~Fitness(){}
    double getFitness() const {return fitness_;}
};

class RouteSet{
    std::vector<Route*> routeSet_;
  public:
    RouteSet(std::vector<Route*> routeSet):routeSet_(routeSet){}
    ~RouteSet();
    double getTotalDistance() const;
    void sortRouteSet();
    std::vector<Route*> selection(int elitePopulationSize, int routesNumber);
    std::vector<Route*> elitism(int elitePopulationSize);
    Route * getBestRoute() const;
    double getAverageDistance() const;
    Route * operator[](size_t i) const { return routeSet_[i]; }
    std::vector<Fitness*> fitnessVector();
    std::vector<Route*> rouletteWheelSelection(std::vector<Route*> selectionRoutes,
    std::vector<Fitness*> fitness, int elitePopulationSize, int routesNumber);
};