#include <iostream>
#include <string>
#include <cmath>

/*
Escribir una clase que implemente el TDA Racional (número racional). Esta debe manejar los números racionales de modo tal de poder realizar las siguientes operaciones:

-Creación en base al numerador y denominador,
-Igualdad,
-Suma,
-Resta,
-Producto,
-Cociente,
-Conversión a real, y
-Simplificación (4 / 16 se puede simplificar a 1 / 4).
*/

class Racional{
    private:
        int numerador_;
        int denominador_;
    public:
        Racional(int numerador, int denominador) : numerador_(numerador), denominador_(denominador) {}
        ~Racional(){}
        int numerador() const {return numerador_;}
        int denominador() const {return denominador_;}
        bool operator==(const Racional& other){
            return numerador_ == other.numerador_ && denominador_ == other.denominador_;
        }
        Racional operator+(const Racional& other){
            return Racional(numerador_ * other.denominador_ + denominador_ * other.numerador_, denominador_ * other.denominador_);
        }
        Racional operator-(const Racional& other){
            return Racional(numerador_ * other.denominador_ - denominador_ * other.numerador_, denominador_ * other.denominador_);
        }
        Racional operator*(const Racional& other){
            return Racional(numerador_ * other.numerador_, denominador_ * other.denominador_);
        }
        Racional operator/(const Racional& other){
            return Racional(numerador_ * other.denominador_, denominador_ * other.numerador_);
        }
        double convertionToReal(){
            return (double)numerador_ / denominador_;
        }
        void simplificar(){
            int mcd = 1;
            for(int i = 2; i <= std::min(numerador_, denominador_); i++){
                if(numerador_ % i == 0 && denominador_ % i == 0){
                    mcd = i;
                }
            }
            numerador_ /= mcd;
            denominador_ /= mcd;
        }
};

int main() {
    Racional *num = new Racional(4, 16);
    std::cout << num->numerador() << "/" << num->denominador() << std::endl;
    num->simplificar();
    std::cout << num->numerador() << "/" << num->denominador() << std::endl;
    std::cout << num->convertionToReal() << std::endl;

    return EXIT_SUCCESS;
}