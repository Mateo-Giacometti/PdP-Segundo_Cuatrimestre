#include <iostream>
#include <string>
#include <utility>

class Vehicle {
  int seats_ = 0;
  double capacity_ = 0;
  std::string brand_;

 public:
  Vehicle(int seats_, double capacity, std::string brand)
      : seats_(seats_), capacity_(capacity), brand_(std::move(brand)) {}

  int seats() const { return seats_; }
  double capacity() const { return capacity_; }
  std::string brand() const { return brand_; }

  void Print() const {
    std::cout << "Vehicle seats available: " << seats_ << std::endl
         << "Vehicle fuel available: " << capacity_ << std::endl
         << "Vehicle brand: " << brand_ << std::endl;
  }
};


class Bus : public Vehicle {
  std::string special_brakes_;
 public:
  Bus(int seats, double capacity, const std::string& brand, std::string brakes)
      : Vehicle(seats, capacity, brand), special_brakes_(std::move(brakes)) {}

  std::string special_brakes() const { return special_brakes_; }

};


class Car : public Vehicle {
  std::string stereo_brand_;
 public:
  Car(int seats, double capacity, const std::string& brand, std::string stereo)
      : Vehicle(seats, capacity, brand), stereo_brand_(std::move(stereo)) {}
  std::string stereo_brand() const { return stereo_brand_; }

};


int main() {
  Vehicle my_vehicle{10, 16, "Honda"};
  Bus my_bus{20, 100, "Volkswagen", "LPM_178"};
  Car my_car{4, 60, "Ford", "Sony"};

  my_vehicle.Print();
  my_bus.Print();
  my_car.Print();

  return 0;
}
