#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <vector>
#include <tuple>

/*Dada una clase Empleado, con atributos como nombre, apellido y sueldo, escribir una función que permita leer de std::cin el nombre, el apellido y 
el sueldo de un empleado, la empresa en la que trabaja, y los cargue en un mapa.
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
