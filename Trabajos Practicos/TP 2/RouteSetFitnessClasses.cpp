#include "RouteSetFitnessClasses.hpp"

double RouteSet::getTotalDistance() const {
    double sum = 0;
    for(auto& route : routeSet_){
        sum += route->getRouteDistance();
    }
    return sum;
}

void RouteSet::sortRouteSet(){
    std::sort(routeSet_.begin(),routeSet_.end(),[](Route* a, Route* b){
        return a->getRouteDistance() < b->getRouteDistance();});   
}

Route* RouteSet::getBestRoute() const{
    return (*this)[0];
}

double RouteSet::getAverageDistance() const {
    return this->getTotalDistance()/routeSet_.size();
}

std::vector<Route*> RouteSet::elitism(int elitePopulationSize){
    std::vector<Route*> selectionRoutes;
    for (int i = 0; i < elitePopulationSize; i++){
        selectionRoutes.emplace_back(routeSet_[i]);
    }
    return selectionRoutes;
}

std::vector<Fitness*> RouteSet::fitnessVector(){
    std::vector<Fitness*> fitnessVector;
    for ( auto const& i : routeSet_ ){
        fitnessVector.emplace_back(new Fitness(i));
    }
    return fitnessVector;
}

void deleteFitnessVector(std::vector<Fitness*>& fitnessVector){
    for (auto& i : fitnessVector){
        delete i;
    }
}

std::vector<Route*> RouteSet::rouletteWheelSelection(std::vector<Route*> selectionRoutes,
std::vector<Fitness*> fitness, int elitePopulationSize, int routesNumber){\
    for (int i = 0; i < 2*routesNumber - 3*elitePopulationSize; i++){
        double sum = 0;
        for (auto const& j : fitness){
            sum += j->getFitness();
        }
        double random = (double)rand() / RAND_MAX;
        double acum = 0;
        for (size_t t = 0; t < fitness.size(); t++){
            acum += fitness[t]->getFitness()/sum;
            if (acum >= random){
                selectionRoutes.emplace_back(routeSet_[t]);
                break;
            }
        }
    }
    deleteFitnessVector(fitness);
    return selectionRoutes;
}

std::vector<Route*> RouteSet::selection(int elitePopulationSize, int routesNumber){
    std::vector<Route*> selectionRoutes = this->elitism(elitePopulationSize);
    std::vector<Fitness*> fitness = this->fitnessVector();    
    return this->rouletteWheelSelection(selectionRoutes, fitness, elitePopulationSize, routesNumber);
}

RouteSet::~RouteSet(){
    for (auto& i : routeSet_){
        delete i;
    }
}