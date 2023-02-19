#include "fileReader.hpp"


status_t Reader::read(std::string file, std::vector<City*> &cities){
    std::ifstream textFile;
    textFile.open(file);
    
    if (textFile.fail()){
        return ST_ERR_FILE_NOT_FOUND;
    }
    while (textFile.peek() != EOF){
        std::string line;
        std::getline(textFile, line, '\n');

        if (line[0] == '#'){
            continue;
        }

        std::stringstream ss(line);
        std::string cityName;
        std::string cityX;
        std::string cityY;
        std::getline(ss, cityName, ',');
        std::getline(ss, cityX, ',');
        std::getline(ss, cityY, ',');

        int x = std::stod(cityX);
        int y = std::stod(cityY);
        Point * point = new Point(x, y);
        City * city = new City(point, cityName);

        cities.emplace_back(city);
        
    }
    textFile.close();

    return ST_OK;
}
Reader& Reader::getInstance(){
    static Reader instance;
    return instance;
}
