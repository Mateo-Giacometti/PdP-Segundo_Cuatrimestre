#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>
#include <vector>

/*
Escribir las clases para manejar las propiedades en venta de una inmobiliaria: casas, departamentos y terrenos baldíos. 
Debe haber funciones que calculen la comisión del vendedor a partir del precio de venta, sabiendo que éste tiene fórmulas de 
cálculo para distintas casas, departamentos y terrenos. La unidad debe ser autosuficiente y estar correctamente modularizada.
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
  Casa c("Av. Siempreviva 742", 1000000);
  Departamento d("Don Bosco 414", 1000000);
  Terreno t("Vito Dumas 285", 1000000);
  std::cout << c.comision() << std::endl;
  std::cout << d.comision() << std::endl;
  std::cout << t.comision() << std::endl;
  return EXIT_SUCCESS;
}