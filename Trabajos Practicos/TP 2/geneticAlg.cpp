#include "geneticAlg.hpp"
#include "progressbar.hpp"

GeneticAlg::~GeneticAlg(){
    for (auto& city : cityList_){
        delete city;
    }
}

GeneticAlg::GeneticAlg(double variationThreshold, int elitePopulationSize, int generationsNumber,
int routesNumber,double mutationRate,std::vector<City*> cityList, std::string& outputFormat):

variationThreshold_(variationThreshold), elitePopulationSize_(elitePopulationSize),
generationsNumber_(generationsNumber),routesNumber_(routesNumber), mutationRate_(mutationRate),
cityList_(std::move(cityList)), outputFormat_(outputFormat){}

std::vector<Route*> GeneticAlg::elitism(RouteSet& rs, int elitePopulationSize){
    return rs.elitism(elitePopulationSize);
}

std::vector<Route*> GeneticAlg::selection(RouteSet& rs, int elitePopulationSize){
    return rs.selection(elitePopulationSize, routesNumber_);
}

std::vector<Route*> GeneticAlg::crossover(std::vector<Route*>& parents, std::vector<Route*>& eliteRoutes){
    std::vector<Route*> children;
    children.reserve(routesNumber_);

    for (size_t i = 0; i < eliteRoutes.size(); i++){
        children.emplace_back(new Route(*eliteRoutes[i]));
    }
    
    std::random_shuffle(parents.begin(), parents.end());
    for (size_t i = 0; i < parents.size(); i+=2){
        children.emplace_back(parents[i]->breed(*parents[i+1]));
    }
    return children;
}

void GeneticAlg::mutation(Route& r){
    r.mutate();
}

void GeneticAlg::routeEvolutionRep(std::vector<double>& bestRoutes){
    std::fstream CreateFile("routeEvolution.csv", std::ios::in);
    CreateFile.open("routeEvolution.csv", std::ios::out);
    CreateFile<<"#Generation, Best Route"<<std::endl;

    size_t counter = 0;
    for(const auto &i : bestRoutes){
        CreateFile<<counter<<","<<i<<std::endl;
        counter++;
    }
    CreateFile.close();
}

RouteSet * GeneticAlg::nextGeneration (RouteSet* rs){

    std::vector<Route*> eliteRoutes = elitism(*rs, elitePopulationSize_);

    std::vector<Route*> selectionRoutes = selection(*rs, elitePopulationSize_);

    std::vector<Route*> children = crossover(selectionRoutes, eliteRoutes);


    for (int i = elitePopulationSize_; i < children.size(); i++){
        if (rand() % 100 < mutationRate_){
            mutation(*children[i]);
        }
    }
    delete rs;

    return new RouteSet(children);
}
RouteSet * GeneticAlg::setFirstPopulation (){
    std::vector<Route*> routeSet;
    routeSet.reserve(routesNumber_);

    for (int i = 0; i < routesNumber_; i++){
        Route * route = new Route(cityList_);
        route->shuffleRoute();
        routeSet.push_back(route);
    }

    return new RouteSet(routeSet);
}
void GeneticAlg::showGenerationDistance(size_t i, int distance){
    std::cout<<"Generation "<< i <<" : "<< distance <<std::endl;
}
void GeneticAlg::run(){

    double pastAverage = 0;
    size_t i;
    progressbar bar(generationsNumber_);
    std::vector<double> bestRoutes;

    RouteSet * rs = setFirstPopulation();
    rs->sortRouteSet();
    showGenerationDistance(0, rs->getBestRoute()->getRouteDistance());
    
    for (i = 0; i <= generationsNumber_; i++){
        bar.update();
        rs->sortRouteSet();
        bestRoutes.emplace_back(rs->getBestRoute()->getRouteDistance());
        rs = nextGeneration(rs);
        
        if (i%50 == 0){
            if (variationThreshold(rs, pastAverage)){
                i++;
                break;
            }
        }
    }
    rs->sortRouteSet();
    bestRoutes.emplace_back(rs->getBestRoute()->getRouteDistance());
    
    std::cout<<std::endl;
    showGenerationDistance(i-1, rs->getBestRoute()->getRouteDistance());
    
    if (outputFormat_ == "graphic"){
        showGraph(bestRoutes,rs);
    }
    delete rs;
}

void GeneticAlg::showGraph(std::vector<double>& bestRoutes, RouteSet *& rs){
    rs->getBestRoute()->cityAndRouteRepresetation();
    this->routeEvolutionRep(bestRoutes);
    system("python3 graphic.py");
    remove("routeEvolution.csv");
    remove("finalGen.csv");
}

bool GeneticAlg::variationThreshold(RouteSet *& rs, double& pastAverage){
    double average = rs->getAverageDistance();
    if (pastAverage == 0){
        pastAverage = average;
    }
    else{
        double variation = abs(pastAverage - average);
        if (variation < variationThreshold_){
            std::cout<<std::endl<<"Variation Threshold reached";
            return true;
        }
        pastAverage = average;
    }
    return false;
}