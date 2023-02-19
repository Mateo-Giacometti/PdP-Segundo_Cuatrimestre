#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <vector>
#include <tuple>

/*
Para el mapa del ejercicio anterior, escribir una función que devuelva, para cada empresa, un mapa que contenga como clave el nombre de cada empresa 
y como valor una tupla de 2 Empleados, el de mayor sueldo y el de menor sueldo.
El tipo del resultado es: std::map<std::string, std::tuple<Empleado, Empleado>>.
*/

class Empleado{
  private:
    std::string nombre_;
    std::string apellido_;
    float sueldo_;
  public:
    std::string empresa_;
    Empleado(std::string nombre, std::string apellido, std::string empresa, float sueldo): nombre_(nombre), apellido_(apellido), empresa_(empresa), sueldo_(sueldo) {}
    ~Empleado(){}
    std::map<std::string, std::tuple<std::string, std::string , float>> datos(){
        std::map<std::string, std::tuple<std::string, std::string , float>> info = {{apellido_, {nombre_, empresa_, sueldo_}}};
        return info;
    }
};



int main(void){
    std::map<std::string, Empleado> dic;
    std::string nombre, apellido, empresa;
    float sueldo;
    std::cout << "Ingrese nombre, apellido, empresa y sueldo de un empleado: ";
    std::cin >> nombre >> apellido >> empresa >> sueldo;
    Empleado Mateo(nombre, apellido, empresa, sueldo);
    std::map<std::string, std::tuple<std::string, std::string , float>> info = Mateo.datos();
    for(auto each : info){
        std::cout << each.first << " " << std::get<0>(each.second) << " " << std::get<1>(each.second) << " " << std::get<2>(each.second) << std::endl;
    }

    return EXIT_SUCCESS;

}
