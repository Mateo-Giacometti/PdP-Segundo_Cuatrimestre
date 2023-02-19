#include <iostream>
#include <cmath>
#include <vector>

/*Se tienen las clases A, B, C, D donde A es superclase de B y C, y C es superclase de D, y no hay otra relación de herencia entre ellas cuatro. ¿Cómo debe hacerse para conseguir que valga lo siguiente?

x.esA() debe devolver true para cada instancia x de A o de sus subclases, y false para cada x que no sea instancia de A ni de sus subclases.
x.esBoC() debe devolver true para cada instancia x de B o de C, o de las subclases de ambas, pero false para cada x que no sea instancia de B ni de C ni de subclases de ellas.
x.esSoloC() debe devolver true./*

*/

class A{
    public:
        virtual bool esA() const {return true;}
        virtual bool esBoC() const {return false;}
        virtual bool esSoloC() const {return false;}
};

class B : public A{
    public:
        bool esA() const override { return true; }
        bool esBoC() const override { return true; }
        bool esSoloC() const override { return false; }
};

class C : public A{
    public:
        virtual bool esA() const override { return true; }
        virtual bool esBoC() const override { return true; }
        virtual bool esSoloC() const override { return true; }
};

class D : public C{
    public:
        bool esA() const override { return true; }
        bool esBoC() const override { return true; }
        bool esSoloC() const override { return false; }
};

int main(void){
    A* a = new A();
    B* b = new B();
    C* c = new C();
    D* d = new D();
    std::cout << a->esA() << std::endl;
    std::cout << a->esBoC() << std::endl;
    std::cout << a->esSoloC() << std::endl;
    std::cout << b->esA() << std::endl;
    std::cout << b->esBoC() << std::endl;
    std::cout << b->esSoloC() << std::endl;
    std::cout << c->esA() << std::endl;
    std::cout << c->esBoC() << std::endl;
    std::cout << c->esSoloC() << std::endl;
    std::cout << d->esA() << std::endl;
    std::cout << d->esBoC() << std::endl;
    std::cout << d->esSoloC() << std::endl;
   
    return EXIT_SUCCESS;
}