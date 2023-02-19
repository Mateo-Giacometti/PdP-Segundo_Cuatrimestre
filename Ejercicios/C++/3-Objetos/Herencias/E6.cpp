#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>
#include <vector>

/*
Implementar clase Operador como clase abstracta; derivar de ésta la clase OperadorSuma, que opera con 2 expresiones para sumar su valor.
*/

class Operador{
  public:
    virtual int operar(int a, int b) = 0;
};

class OperadorSuma: public Operador{
  public:
    int operar(int a, int b){
      return a + b;
    }
};

int main(){
  OperadorSuma op;
  std::cout << op.operar(2, 3) << std::endl;
  return EXIT_SUCCESS;
}