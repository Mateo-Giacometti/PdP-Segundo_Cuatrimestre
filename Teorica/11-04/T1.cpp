#include <iostream>

/* pizza */
class Pizza {
  public:
    virtual ~Pizza() {}
    virtual std::string Precio() const = 0;
};

class PizzaMozzarella : public Pizza {
  public:
    static std::string name;
    std::string Precio() const override {
        return "Precio de la pizza de mozzarela";
    }
};
std::string PizzaMozzarella::name = "Muzza";

class PizzaFugazzetta : public Pizza {
  public:
    static std::string name;
    std::string Precio() const override {
        return "Precio de la fugazzetta";
    }
};
std::string PizzaFugazzetta::name = "Fugazzetta";


/* pizzero */
class Pizzero {
  public:
    virtual ~Pizzero(){};
    virtual Pizza* PrepararPizza() const = 0;
    std::string CocinarUnaPizza() const {
        // Crear una pizza
        Pizza* pizza = this->PrepararPizza();
        // Usarla (imprime, pero la usamos para algo (agregar a pedido, pero no hay pedido)
        std::string resultado = pizza->Precio();
        delete pizza;
        return resultado;
    }
};

class PizzeroMuzza : public Pizzero {
  public:
    Pizza* PrepararPizza() const override { return new PizzaMozzarella(); }
};

class PizzeroFuga : public Pizzero {
  public:
    Pizza* PrepararPizza() const override { return new PizzaFugazzetta(); }
};



void Pizzeria(const Pizzero& pizzero) {
    std::cout << "No sé que pizza es, pero es una pizza.\n"
              << pizzero.CocinarUnaPizza() << std::endl;
}

int main() {
    std::cout << "Sólo hacemos Muzza.\n";
    Pizzero* pizzero = new PizzeroMuzza();
    Pizzeria(*pizzero);
    std::cout << std::endl;
    delete pizzero;

    std::cout << "Sólo vendemos Fugazzetta.\n";
    pizzero = new PizzeroFuga();
    Pizzeria(*pizzero);
    delete pizzero;

    return 0;
}