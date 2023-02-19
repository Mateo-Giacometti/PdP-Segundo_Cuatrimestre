#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "RouteSetFitnessClasses.hpp"
#include "routeClasses.hpp"
#include "pointCityClasses.hpp"

class GeneticAlg{
    std::string outputFormat_;
    double variationThreshold_;
    int elitePopulationSize_;
    int generationsNumber_;
    int routesNumber_;
    double mutationRate_;
    std::vector<City*> cityList_;
  public:
    GeneticAlg(double variationUmbral, int elitePopulationSize, int generationsNumber,
    int routesNumber, double mutationRate, std::vector<City*> cityList, std::string& outputFormat);
    ~GeneticAlg();
    void run();
    RouteSet * setFirstPopulation ();
    RouteSet * nextGeneration (RouteSet* rs);
    std::vector<Route*> elitism(RouteSet& rs, int elitePopulationSize);
    std::vector<Route*> selection(RouteSet& rs, int elitePopulationSize);
    std::vector<Route*> crossover (std::vector<Route*>& parents, std::vector<Route*>& eliteRoutes);
    void mutation(Route& r);
    void routeEvolutionRep(std::vector<double>& bestRoutes);
    void showGraph(std::vector<double>& bestRoutes, RouteSet *& rs);
    bool variationThreshold(RouteSet *& rs, double& pastAverage);
    void showGenerationDistance(size_t i, int distance);
};

