#include "pointCityClasses.hpp"

City::~City(){
    delete coordinate_;
}

double City::getDistance(City& cityEnd) const{   

        double x1,x2,y1,y2;
        std::tie(x1,y1)=this->getCoordinate();
        std::tie(x2,y2)=cityEnd.getCoordinate();
        return sqrt(pow(x1-x2,2)+pow(y2-y1,2));
}