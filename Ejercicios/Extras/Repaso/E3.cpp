#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>
#include <map>

/*
Un tren de carga lleva dos clases de vagones: VagonCaja que tienen forma de prisma rectangular
y VagonTanque que tienen forma cilíndrica.
Deberá diseñar tres clases para representar vagones de tren, una clase base (Vagon) abstracta
con un dato miembro que represente la longitud de los vagones y dos clases derivadas
(VagonCaja y VagonTanque) para representar los dos tipos de vagones. Para el vagón de tipo
VagonCaja deberá almacenar su alto, ancho (aparte de la longitud). Para el vagón de tipo
VagonTanque deberá almacenar su radio (aparte de su longitud). Las tres clases deben
poseer un método volumen() que retorna un valor de tipo double que representa la capacidad
en metros cúbicos del vagón. Parte de su trabajo será decidir si el método volumen() en cada
una de las clases es declarado abstracto o no.
Recuerde que el volumen de un prisma rectangular es: alto * ancho * longitud y el del
cilindro es PI * r2 * longitud.
Cree una clase Tren que represente a un tren de carga con sus vagones. Utilice un array de
punteros de tipo Vagon. La clase debe tener una función miembro bool añadirVagon(Vagon*
v); que permita añadir un vagón de algún tipo al Tren (si es que no supera la cantidad de
vagones límite del tren) y otra que retorne el volumen total del tren.
Cree una aplicación de prueba que permita crear trenes y calcular la capacidad total de carga de
cada tren.
*/

class Vagon{
    public:
    virtual double volumen() = 0;
};

class VagonCaja : public Vagon{
    private:
        double longitud_;
        double alto_;
        double ancho_;
    public:
        VagonCaja(double longitud, double alto, double ancho): longitud_(longitud), alto_(alto), ancho_(ancho) {}
        VagonCaja(VagonCaja& cop): longitud_(cop.longitud_), alto_(cop.alto_), ancho_(cop.ancho_) {}
        virtual ~VagonCaja() {}
        const VagonCaja& operator=(VagonCaja& ig){
            this->longitud_= ig.longitud_;
            this->alto_= ig.alto_;
            this->ancho_ = ig.ancho_;
            return *this;
        }
        bool operator==(VagonCaja& eq){
            return (this->longitud_ == eq.longitud_ && this->alto_ == eq.alto_ && this->ancho_ == eq.ancho_);
        }
        bool operator!=(VagonCaja& eq){
            return (this->longitud_ != eq.longitud_ || this->alto_ != eq.alto_ || this->ancho_ != eq.ancho_);
        }
        double volumen() override {
            return alto_ * ancho_ * longitud_;
        }
};

class VagonTanque : public Vagon{
    private:
        double longitud_;
        double radio_;
    public:
        VagonTanque(double longitud, double radio): longitud_(longitud), radio_(radio) {}
        VagonTanque(VagonTanque& cop): longitud_(cop.longitud_), radio_(cop.radio_) {}
        virtual ~VagonTanque() {}
        const VagonTanque& operator=(VagonTanque& ig){
            this->longitud_ = ig.longitud_;
            this->radio_ = ig.radio_;
            return *this;
        }
        bool operator==(VagonTanque& ig){
            return this->longitud_ == ig.longitud_ && this->radio_ == ig.radio_;
        }
        bool operator!=(VagonTanque& ig){
            if(*this == ig){
                return false;
            }
            return true;
        }
        double volumen() override {
            return 3.14 * radio_ * longitud_;
        }
};

class Tren{
    private:
        std::vector<Vagon *> vagones_;
        std::string name_;
        int cantVag_;
    public:
        Tren(std::string name, int cantVag): name_(name), cantVag_(cantVag) {}
        Tren(Tren& cop): name_(cop.name_), cantVag_(cop.cantVag_) {}
        virtual ~Tren() {}
        const Tren& operator=(Tren& ig){
            this->name_ = ig.name_;
            this->cantVag_ = ig.cantVag_;
            this->vagones_.clear();
            for(int i = 0; i < ig.vagones_.size(); i++){
                this->vagones_[i] = ig.vagones_[i];
            }
            return *this;
        }
        bool operator ==(Tren& ig){
            if(this->name_ != ig.name_ || this->cantVag_ != ig.cantVag_){
                return false;
            }
            for(int i = 0; i < ig.vagones_.size(); i++){
                if(this->vagones_[i] != ig.vagones_[i]){
                    return false;
                }
            }
            return true;
        }
        bool operator !=(Tren& ig){
            if(*this == ig){
                return false;
            }
            return true;
        }
        bool addVagon(Vagon* add){
            if(vagones_.size() >= cantVag_){
                return false;
            }
            else{
                vagones_.emplace_back(add);
                return true;
            }
        }
        double volumen(){
            double totalVol = 0;
            for(auto &each : vagones_){
                totalVol += each->volumen();
            }
            return totalVol;
        }

};

int main(void){
    Tren* t1 = new Tren("Tren1", 3);
    VagonCaja *v1 = new VagonCaja(10, 10, 10);
    VagonTanque *v2 = new VagonTanque(10, 10);
    t1->addVagon(v1);
    t1->addVagon(v2);
    std::cout << t1->volumen() << std::endl;
    return 0;

}