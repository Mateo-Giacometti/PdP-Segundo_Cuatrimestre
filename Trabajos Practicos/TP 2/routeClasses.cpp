#include "routeClasses.hpp"

Route::Route(Route& route){
    route_ = route.route_;
}

double Route::getRouteDistance(){
    double sum = 0;
    for (auto city = route_.begin(); city != route_.end()-1; city++){
        sum += (*city)->getDistance(**(city+1));
    }
    sum += (*(route_.end()-1))->getDistance(**(route_.begin()));
    return sum;
}

void Route::mutate(){
    int i = rand() % route_.size();
    int j = rand() % route_.size();
    std::swap(route_[i],route_[j]);
}

void Route::shuffleRoute(){
    std::random_shuffle(route_.begin(),route_.end());
}

void Route::cityAndRouteRepresetation(){
    std::fstream CreateFile("finalGen.csv", std::ios::in);
    CreateFile.open("finalGen.csv", std::ios::out);
    CreateFile<<"#City,X-Coordinate,Y-Coordinate"<<std::endl;
    for (size_t i = 0; i < (this->route_).size(); i++){
        CreateFile<< this->route_[i]->getName() << "," << std::get<0>(this->route_[i]->getCoordinate())
         << "," << std::get<1>(this->route_[i]->getCoordinate()) << std::endl;
    }
    CreateFile.close();
}
Route * Route::breed(Route& parent){
    std::vector<City*> childGenes;
    childGenes.reserve(parent.size());
    std::vector<City*> parent1Genes,parent2Genes;
    int geneA = (int) (rand() % parent.size());
    int geneB = (int) (rand() % parent.size());
    int startGene = std::min(geneA, geneB);
    int endGene = std::max(geneA, geneB);
    for (int i = startGene; i < endGene; i++){
        parent1Genes.emplace_back(parent[i]);
    }
    for (int i = 0; i < this->size(); i++){
        if (find(parent1Genes.begin(), parent1Genes.end(), (*this)[i]) == parent1Genes.end()){
            parent2Genes.emplace_back((*this)[i]);
        }
    }
    for (int i = 0; i < parent2Genes.size(); i++){
        childGenes.emplace_back(parent2Genes[i]);
    }
    for (int i = 0; i < parent1Genes.size(); i++){
        childGenes.emplace_back(parent1Genes[i]);
    }
    return new Route(childGenes);

}