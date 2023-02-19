#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>
#include <vector>

/*
Escribir un programa que, utilizando la implementación del ejercicio anterior, compare dos propiedades (que podrán ser casas, departamentos o terrenos baldíos) e 
imprima los datos de la de mayor precio de venta.
*/

class Propiedad{
    protected:
        std::string direccion_;
        double precio_;
    public:
        Propiedad(std::string direccion, double precio): direccion_(direccion), precio_(precio){}
        Propiedad(Propiedad& p): direccion_(p.direccion_), precio_(p.precio_){}
        virtual ~Propiedad(){}
        virtual double comision() = 0;
        bool operator>(Propiedad& p){
            return precio_ > p.precio_;
        }
};

class Casa: public Propiedad{
  public:
    Casa(std::string direccion, double precio): Propiedad(direccion, precio){}
    Casa(Casa& c): Propiedad(c){}
    ~Casa(){}
    double comision(){
      return precio_ * 0.10;
    }
};

class Departamento: public Propiedad{
  public:
    Departamento(std::string direccion, double precio): Propiedad(direccion, precio){}
    Departamento(Departamento& d): Propiedad(d){}
    ~Departamento(){}
    double comision(){
      return precio_ * 0.25;
    }
};

class Terreno: public Propiedad{
  public:
    Terreno(std::string direccion, double precio): Propiedad(direccion, precio){}
    Terreno(Terreno& t): Propiedad(t){}
    ~Terreno(){}
    double comision(){
      return precio_ * 0.05;
    }
};

int main(){
    Casa c("Av. Siempreviva 742", 1000001);
    Departamento d("Don Bosco 414", 1000000);
    Terreno t("Vito Dumas 285", 1000000);
    std::cout << c.comision() << std::endl;
    std::cout << d.comision() << std::endl;
    std::cout << t.comision() << std::endl;
    if(c > d){
        std::cout << "Casa es mayor" << std::endl;
    }else{
        std::cout << "Departamento es mayor" << std::endl;
    }
    return EXIT_SUCCESS;
}