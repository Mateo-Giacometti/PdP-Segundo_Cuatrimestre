#include "RouteSetFitnessClasses.hpp"
#include "routeClasses.hpp"
#include "pointCityClasses.hpp"
#include "parser.hpp"
#include "fileReader.hpp"
#include "geneticAlg.hpp"


int main(int argc, char *argv[]){
    srand(time(NULL));

    Reader& reader = Reader::getInstance();
    Parser& parser = Parser::getInstance();

    std::string csvFile;
    double variationThreshold;
    int generations = 1000;
    std::string outputFormat = "none";
    int population = 100;
    int elite = 20;
    double mutation = 0.1;
    status_t st;

    st = parser.assign(argc, argv, csvFile,
    variationThreshold, generations, outputFormat, population, elite, mutation);

    if (st != ST_OK) {
        return st;
    }

    std::vector<City*> cityList;
    st = reader.read(csvFile, cityList);

    if (st != ST_OK) {
        return st;
    }

    GeneticAlg * ga = new GeneticAlg(variationThreshold, elite, generations,
    population, mutation, cityList, outputFormat);

    ga->run();

    delete ga;

    return 0;
}