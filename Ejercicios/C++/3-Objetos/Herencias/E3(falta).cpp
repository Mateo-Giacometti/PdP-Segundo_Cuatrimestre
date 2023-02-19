#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>

/*
Implementar la clase Animalia, de la que heredan las clases Mammalia y Reptilia. Implementar las clases PantheraLeo, PantheraPink, VaranusKomodoensis, PseudotrapelusSinaitus.
Todas las clases tienen una forma de obtener su nombre como string.
¿Qué comparten Mammalia y Reptilia?
Todos los reptiles tienen la capacidad de poner huevos, pero sólo el VaranusKomodoensis puede cazar para alimentarse.
Todos los mamíferos maman cuando son crías, pero sólo la PantheraLeo ruge, mientras que la PantheraPink puede abrir puertas.

Escribir un programa que cree e inicialice objetos de todas las clases desarrolladas, ejecute todos sus comportamientos y, en ellos, 
imprima qué está haciendo el animal (por ejemplo, en algún momento un objeto de la clase PantheraLeo debe imprimir “ruge”).
*/

class Animalia{
  protected:
    std::string name_;
  public:
    Animalia(std::string name): name_(name){}
    ~Animalia(){}
    std::string get_name(){return name_;}
};

class Mammalia : public Animalia{


};