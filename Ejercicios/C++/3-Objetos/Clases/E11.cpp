#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Implementar una clase arreglo con las operaciones necesarias para poder ejecutar el siguiente programa:


int main() {
  arreglo a(7);

  a[0] = 3;
  a[1] = 6;
  a[2] = a[0] + a[1];
  arreglo b = a;
  std::cout << b[2] << std::endl;
}
*/

class Arreglo{
  private:
    int *data_;
    int size_;
  public:
    Arreglo(int size) : size_(size) {
        data_ = new int[size_];
    }
    int& operator[](int index){
        return data_[index];
    }
    Arreglo& operator=(const Arreglo& other){
        if(this != &other){
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            for(int i = 0; i < size_; i++){
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }
};

int main() {
    Arreglo a(7);
    a[0] = 3;
    a[1] = 6;
    a[2] = a[0] + a[1];
    Arreglo b = a;
    std::cout << b[2] << std::endl;

    return 0;
}