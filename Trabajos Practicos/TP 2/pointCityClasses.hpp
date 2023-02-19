#pragma once
#include <tuple>
#include <fstream>
#include <cmath>

class Point{
    double x_,y_;
  public:
    Point(int x, int y):x_(x),y_(y){}
    ~Point(){}
    double x() const { return x_; }
    double y() const { return y_; }
};

class City{
    Point * coordinate_;
    std::string name_;
  public:
    City(Point * coordinate,std::string name):coordinate_(coordinate),name_(name){}
    ~City();
    std::tuple<double, double> getCoordinate() const {
    return std::make_tuple(coordinate_->x(), coordinate_->y());}
    std::string getName() const {return name_;}
    double getDistance(City& cityEnd) const;
};