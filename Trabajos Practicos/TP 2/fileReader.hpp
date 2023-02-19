#pragma once 
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "routeClasses.hpp"
#include "pointCityClasses.hpp"
#include "RouteSetFitnessClasses.hpp"
#include "status.hpp"

class Reader{
  protected:
    Reader() = default;
public:
    static Reader& getInstance();
   ~Reader(){}
    Reader(const Reader&) = delete;
    Reader(Reader&&) = delete;
    Reader& operator=(const Reader&) = delete;
    Reader& operator=(Reader&&) = delete;
    status_t read(std::string file, std::vector<City*> &cities);
};
