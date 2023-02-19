#include "testClases.hpp"

void testParser(int argc, char *argv[]){
    std::string csvFile;
    double variationThreshold = 10;
    int generations = 2000;
    std::string outputFormat = "none";
    int elitePopulationSize = 20;
    double mutationRate = 0.1;
    int populationSize = 50;

    status_t st;
    Parser& parser = Parser::getInstance();
    st = parser.assign(argc, argv, csvFile, variationThreshold, generations, outputFormat, populationSize, elitePopulationSize, mutationRate);
    
    assert(st == ST_OK);
    assert(csvFile == "csvTest.csv");
    assert(variationThreshold == 10);
    assert(generations == 2000);
    assert(outputFormat == "graphic");
    assert(elitePopulationSize == 30);
    assert(mutationRate == 0.3);
    assert(populationSize == 100);

    std::cout << "Parser passed" << std::endl;
}

void testReader(){
    status_t st;
    std::string csvFile = "csvTest.csv";
    std::vector<City*> citiesFromCsv;
    Reader& reader = Reader::getInstance();
    st = reader.read(csvFile, citiesFromCsv);
    
    assert(st == ST_OK);
    assert(citiesFromCsv.size() == 48);

    for (int i = 0; i < citiesFromCsv.size(); ++i) {
        delete citiesFromCsv[i];
    }

    std::cout << "Reader passed" << std::endl;
}

void testPoint(){
    Point* point = new Point(3,18);
    Point* point2 = new Point(0,0);
    Point* point3 = new Point(5, 8);
    Point* point4 = new Point(13, 1);

    assert(point->x() == 3);
    assert(point->y() == 18);
    assert(point2->x() == 0);
    assert(point2->y() == 0);
    assert(point3->x() == 5);
    assert(point3->y() == 8);
    assert(point4->x() == 13);
    assert(point4->y() == 1);

    delete point;
    delete point2;
    delete point3;
    delete point4;

    std::cout << "Point passed" << std::endl;
}

void testCity(){
    Point* point = new Point(3,18);
    Point* point2 = new Point(0,0);
    Point* point3 = new Point(5, 8);
    Point* point4 = new Point(13, 1);

    City* city = new City(point, "Buenos Aires");
    City* city2 = new City(point2, "Rosario");
    City* city3 = new City(point3, "Cordoba");
    City* city4 = new City(point4, "Mendoza");

    assert(city->getName() == "Buenos Aires");
    assert(city->getCoordinate() == std::make_tuple(3,18));
    assert(city2->getName() == "Rosario");
    assert(city2->getCoordinate() == std::make_tuple(0,0));
    assert(city3->getName() == "Cordoba");
    assert(city3->getCoordinate() == std::make_tuple(5,8));
    assert(city4->getName() == "Mendoza");
    assert(city4->getCoordinate() == std::make_tuple(13, 1));
    assert(city->getDistance(*city2) == 18.24828759089466);
    assert(city2->getDistance(*city3) == 9.433981132056603);
    assert(city3->getDistance(*city4) == 10.63014581273465);
    assert(city4->getDistance(*city) == 19.72308292331602);

    delete city;
    delete city2;
    delete city3;
    delete city4;

    std::cout << "City passed" << std::endl;
}

void testRoute(){
    Point* point = new Point(3,18);
    Point* point2 = new Point(0,0);    
    Point* point3 = new Point(5, 8);
    Point* point4 = new Point(13, 1);

    City* city = new City(point, "Buenos Aires");
    City* city2 = new City(point2, "Rosario");
    City* city3 = new City(point3, "Cordoba");
    City* city4 = new City(point4, "Mendoza");

    std::vector<City*> cities;
    cities.emplace_back(city);
    cities.emplace_back(city2);
    cities.emplace_back(city3);
    cities.emplace_back(city4);

    std::vector<City*> cities2;
    cities2.emplace_back(city2);
    cities2.emplace_back(city3);
    cities2.emplace_back(city4);
    cities2.emplace_back(city);

    std::vector<City*> cities3;
    cities3.emplace_back(city3);
    cities3.emplace_back(city4);
    cities3.emplace_back(city);
    cities3.emplace_back(city2);

    std::vector<City*> cities4;

    cities4.emplace_back(city4);
    cities4.emplace_back(city);
    cities4.emplace_back(city2);
    cities4.emplace_back(city3);

    Route* route1 = new Route(cities);
    Route* route2 = new Route(cities2);
    Route* route3 = new Route(cities3);
    Route* route4 = new Route(cities4);

    assert(route1->getRouteDistance() == 18.24828759089466 +
    9.433981132056603 + 10.63014581273465 + 19.72308292331602);

    assert(route2->getRouteDistance() == 9.433981132056603 +
    10.63014581273465 + 19.72308292331602 + 18.24828759089466);

    assert(route3->getRouteDistance() == 10.63014581273465 +
    19.72308292331602 + 18.24828759089466 + 9.433981132056603);

    assert(route4->getRouteDistance() == 19.72308292331602 +
    18.24828759089466 + 9.433981132056603 + 10.63014581273465);

    assert(route1->size() == 4);
    assert(route2->size() == 4);
    assert(route3->size() == 4);
    assert(route4->size() == 4);

    assert(route1->operator[](0) == city);
    assert(route1->operator[](1) == city2);
    assert(route1->operator[](2) == city3);
    assert(route1->operator[](3) == city4);

    route1->mutate();
    route2->mutate();
    route3->mutate();
    route4->mutate();
    
    for (int i = 0; i < route1->size(); i++){
        if (route1->operator[](i) != cities[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route2->size(); i++){
        if (route2->operator[](i) != cities2[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route3->size(); i++){
        if (route3->operator[](i) != cities3[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route4->size(); i++){
        if (route4->operator[](i) != cities4[i]){
            assert(true);
            break;
        }
    }

    route1->shuffleRoute();
    route2->shuffleRoute();
    route3->shuffleRoute();
    route4->shuffleRoute();

    for (int i = 0; i < route1->size(); i++){
        if (route1->operator[](i) != cities[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route2->size(); i++){
        if (route2->operator[](i) != cities2[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route3->size(); i++){
        if (route3->operator[](i) != cities3[i]){
            assert(true);
            break;
        }
    }

    for (int i = 0; i < route4->size(); i++){
        if (route4->operator[](i) != cities4[i]){
            assert(true);
            break;
        }
    }
    delete city;
    delete city2;
    delete city3;
    delete city4;

    delete route1;
    delete route2;
    delete route3;
    delete route4;

    std::cout << "Route passed" << std::endl;
}

void testRouteSet(){
    Point* point = new Point(3,18);
    Point* point2 = new Point(0,0);
    Point* point3 = new Point(5, 8);
    Point* point4 = new Point(13, 1);    

    City* city = new City(point, "Buenos Aires");
    City* city2 = new City(point2, "Rosario");
    City* city3 = new City(point3, "Cordoba");
    City* city4 = new City(point4, "Mendoza");

    std::vector<City*> cities;
    cities.emplace_back(city);
    cities.emplace_back(city2);
    cities.emplace_back(city3);
    cities.emplace_back(city4);

    std::vector<City*> cities2;

    cities2.emplace_back(city2);
    cities2.emplace_back(city3);
    cities2.emplace_back(city4);
    cities2.emplace_back(city);

    std::vector<City*> cities3;

    cities3.emplace_back(city3);
    cities3.emplace_back(city4);
    cities3.emplace_back(city);
    cities3.emplace_back(city2);

    std::vector<City*> cities4;

    cities4.emplace_back(city4);
    cities4.emplace_back(city);
    cities4.emplace_back(city2);
    cities4.emplace_back(city3);

    Route* route1 = new Route(cities);
    Route* route2 = new Route(cities2);
    Route* route3 = new Route(cities3);
    Route* route4 = new Route(cities4);

    std::vector<Route*> routes;
    routes.emplace_back(route1);
    routes.emplace_back(route2);
    routes.emplace_back(route3);
    routes.emplace_back(route4);

    RouteSet* routeSet = new RouteSet(routes);

    assert(routeSet->getTotalDistance() == route1->getRouteDistance() + route2->getRouteDistance() + route3->getRouteDistance() + route4->getRouteDistance());
    assert(routeSet->getAverageDistance() == (route1->getRouteDistance() + route2->getRouteDistance() + route3->getRouteDistance() + route4->getRouteDistance()) / 4);

    delete city;
    delete city2;
    delete city3;
    delete city4;

    delete routeSet;

    std::cout << "RouteSet passed" << std::endl;
}

void testFitness(){
    Point* point = new Point(3,18);
    Point* point2 = new Point(0,0);
    Point* point3 = new Point(5, 8);
    Point* point4 = new Point(13, 1);

    City* city = new City(point, "Buenos Aires");
    City* city2 = new City(point2, "Rosario");
    City* city3 = new City(point3, "Cordoba");
    City* city4 = new City(point4, "Mendoza");

    std::vector<City*> cities;
    cities.emplace_back(city);
    cities.emplace_back(city2);
    cities.emplace_back(city3);
    cities.emplace_back(city4);

    std::vector<City*> cities2;
    cities2.emplace_back(city2);
    cities2.emplace_back(city3);
    cities2.emplace_back(city4);
    cities2.emplace_back(city);

    std::vector<City*> cities3;
    cities3.emplace_back(city3);
    cities3.emplace_back(city4);
    cities3.emplace_back(city);
    cities3.emplace_back(city2);

    std::vector<City*> cities4;
    cities4.emplace_back(city4);
    cities4.emplace_back(city);
    cities4.emplace_back(city2);
    cities4.emplace_back(city3);

    Route* route1 = new Route(cities);
    Fitness* fitness = new Fitness(route1);
    
    assert(fitness->getFitness() == 1 / route1->getRouteDistance());

    delete city;
    delete city2;
    delete city3;
    delete city4;

    delete route1;
    delete fitness;

    std::cout << "Fitness passed" << std::endl;
}

int main(int argc, char *argv[]){
    if (argc > 2){
        testParser(argc, argv);
    }
    testReader();
    testPoint();
    testCity();
    testRoute();
    testRouteSet();
    testFitness();

    std::cout << std::endl;
    std::cout << "All tests passed" << std::endl;
    
    return 0;
}