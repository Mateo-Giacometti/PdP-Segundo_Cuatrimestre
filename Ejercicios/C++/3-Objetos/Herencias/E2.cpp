#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>

/*
Implementar la clase Pieza y las clases Peon, Torre, Caballo, Alfil, Reina y Rey.
-Todas las piezas tienen una ubicación en un tablero.
-Todas las piezas se pueden mover.

Escribir el código necesario para poder crear piezas de ajedrez, ubicarlas en una posición del tablero y moverlas.
*/

class Pieza{
  protected:
    std::string name_; 
    std::string color_;
    std::tuple<int,int> position_;
    bool exist_ = false;
  public:
    Pieza(std::string name ,std::string color, int x, int y);
    ~Pieza(){}
    virtual void change_position(int x, int y);
    void see_position();

};

Pieza::Pieza(std::string name, std::string color, int x, int y){
    if(color != "Black" && color != "White"){
        std::cout<< "Color invalido - No se creo la pieza\n";
    }
    else{
        if(x > 8 || y > 8 || x < 0 || y < 0){
            std::cout<< "Posicion invalida- No se creo la pieza\n";  
        }
        else{
            color_ = color;
            position_ = std::make_tuple(x,y);
            name_ = name; 
            exist_ = true;
        }
    }
}

void Pieza::change_position(int x, int y){
    if(exist_){
        if(x > 8 || y > 8 || x < 0 || y < 0){
            std::cout<< "Posicion invalida\n";
        }
        else{
            std::cout<< color_ << " "<< name_ << " se movio a la posicion (" << x << "," << y << ")" << std::endl;
            position_ = std::make_tuple(x,y);
        }
    }
    else{
        std::cout<< "La pieza no existe\n";
    }
}

void Pieza::see_position(){
    if(exist_){
         std::cout<< color_ << " "<< name_ <<" esta en la posicion (" << std::get<0>(position_) << "," << std::get<1>(position_) << ")" << std::endl;
    }
    else{
        std::cout<< "La pieza no existe\n";
    }
}

class Peon : public Pieza{
  public:
    Peon(std::string name, std::string color, int x, int y);
    ~Peon(){}
    void change_position(int x, int y);
};

Peon::Peon(std::string name, std::string color, int x, int y): Pieza(name, color, x, y){
    if(x != 2 || x != 7){
        std::cout<< "Posicion invalida- No se creo la pieza\n";
    }
}

void Peon::change_position(int x, int y){
    if(exist_){
        if(x > 8 || y > 8 || x < 0 || y < 0){
            std::cout<< "Posicion invalida\n";
        }
        else if(std::get<0>(position_) - x != 1 && std::get<0>(position_) - x != -1 && std::get<0>(position_) - x != 0 || std::get<1>(position_) - y != 1 && 
        std::get<1>(position_) - y != -1 && std::get<1>(position_) - y != 0){
            std::cout<< color_<< " "<< name_ << " no puede realizar este movimiento" << std::endl;
        }
        else{
            std::cout<< color_ << " "<< name_ << " se movio a la posicion (" << x << "," << y << ")" << std::endl;
            position_ = std::make_tuple(x,y);
        }
    }
    else{
        std::cout<< "La pieza no existe\n";
    }
     

}

int main(void){
    Pieza caca("Pieza","Black", 5, 7);
    caca.see_position();
    caca.change_position(3, 4);
    caca.see_position();
    Peon peon("Peon", "White", 5, 2);
    peon.see_position();
    peon.change_position(3,2);
    peon.see_position();

    return EXIT_SUCCESS;;
}
