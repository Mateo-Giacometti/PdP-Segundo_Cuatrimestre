#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <tuple>


/*
Implemente la clase Matriz, utilizando memoria dinámica. Este debe proveer los siguientes métodos:

ProductoEscalar,
Transpuesta,
EsNula (sólo chequea si es nula),
Elemento (devuelve el elemento i, j).
Además debe poder utilizar los operadores: ==, !=, +, - y *.

Piense en una implementación que permita sobrecargar el operador[] de forma tal que se pueda obtener un elemento de la matriz mediante la operación m[i][j], 
donde m es una instancia de la clase.
*/

class matrizDinamica{
  private:
    int** matriz_;
    int filas_;
    int columnas_;
  public:
    matrizDinamica(int filas, int columnas);
    ~matrizDinamica();
    void showMatriz();
    void fullMatriz(int n);
    void productoEscalar(int n);
    void transpuesta();
    bool esNula();
    int elemento(int i, int j);
    bool operator==(matrizDinamica& mat);
    bool operator!=(matrizDinamica& mat);
    matrizDinamica& operator=(const matrizDinamica& mat);
    matrizDinamica operator+(const matrizDinamica& mat);
    matrizDinamica operator-(const matrizDinamica& mat);
    matrizDinamica operator*(const matrizDinamica& mat);
    // int * matrizDinamica::operator[](int r);

};

matrizDinamica::matrizDinamica(int filas, int columnas): filas_(filas), columnas_(columnas){
    matriz_ = new int*[filas];
    for (int i = 0; i < filas; i++){
        matriz_[i] = new int[columnas];
    }
}

matrizDinamica::~matrizDinamica(){
    for (int i = 0; i < filas_; i++){
        delete[] matriz_[i];
    }
    delete[] matriz_;

    std::cout << "Matriz eliminada" << std::endl;
}

void matrizDinamica::showMatriz(){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            std::cout<< this->matriz_[i][j];
        }
        std::cout<< std::endl;
    }
    std::cout<< std::endl;
}

void matrizDinamica::fullMatriz(int n){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            this->matriz_[i][j] = n;
        }
    }
}

void matrizDinamica::productoEscalar(int n){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            this->matriz_[i][j] = this->matriz_[i][j] * n;
        }
    }
}

void matrizDinamica::transpuesta(){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            this->matriz_[i][j] = this->matriz_[j][i];
        }
    }
}

bool matrizDinamica::esNula(){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            if(this->matriz_[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

int matrizDinamica::elemento(int i, int j){
    return matriz_[i][j];
}

bool matrizDinamica::operator==(matrizDinamica& mat){
    if(mat.filas_ != this->filas_ || mat.columnas_ != this->columnas_){
        return false;
    }
    for (int i = 0; i < filas_; i++){
        for(int j = 0; j < columnas_; j++){
            if (matriz_[i][j] != mat.elemento(i,j)){
                return false;
            }
        }
    }
    return true;
}

bool matrizDinamica::operator!=(matrizDinamica& mat){
    if(mat.filas_ != this->filas_ || mat.columnas_ != this->columnas_){
        return true;
    }
    for (int i = 0; i < filas_; i++){
        for(int j = 0; j < columnas_; j++){
            if (matriz_[i][j] != mat.elemento(i,j)){
                return true;
            }
        }
    }
    return false;
}

matrizDinamica& matrizDinamica::operator=(const matrizDinamica& mat){
    for (int i = 0; i < filas_; i++){
        for (int j = 0; j < columnas_; j++){
            this->matriz_[i][j] = mat.matriz_[i][j];
        }
    }
    return *this;
}

matrizDinamica matrizDinamica::operator+(const matrizDinamica& mat){
    matrizDinamica result(mat.filas_,mat.columnas_);
    for (int i = 0; i < filas_; i++){
        for(int j = 0; j < columnas_; j++){
            result.matriz_[i][j] = matriz_[i][j] + mat.matriz_[i][j];
        }
    }
    return result;
} 

matrizDinamica matrizDinamica::operator-(const matrizDinamica& mat){
    matrizDinamica result(mat.filas_,mat.columnas_);
    for (int i = 0; i < filas_; i++){
        for(int j = 0; j < columnas_; j++){
            result.matriz_[i][j] = this->matriz_[i][j] - mat.matriz_[i][j];
        }
    }
    return result;
}

matrizDinamica matrizDinamica::operator*(const matrizDinamica& mat){
    matrizDinamica result(mat.filas_,mat.columnas_);
    for (int i = 0; i < filas_; i++){
        for(int j = 0; j < columnas_; j++){
            result.matriz_[i][j] = this->matriz_[i][j] * mat.matriz_[i][j];
        }
    }
    return result;
}

// int * matrizDinamica::operator[](int r){
//     return matriz_[r];
// }



int main(void){
    std::tuple<char, int, float> geek;
    geek = std::make_tuple(1,2,3);
    std::cout<< std::tuple_size<decltype(geek)>::value << std::endl;
    matrizDinamica M(5,5);
    matrizDinamica N(5,5);
    matrizDinamica O(5,5);
    matrizDinamica P(7,4);
    M.fullMatriz(3);
    std::cout<< M.elemento(2,3) << std::endl;
    std::cout<< std::endl;
    M.productoEscalar(2);
    M.showMatriz();
    M.transpuesta();
    M.showMatriz();
    std::cout<< M.elemento(2,3) << std::endl;
    std::cout<< std::endl;
    M.fullMatriz(4);
    M.showMatriz();
    N.fullMatriz(4);
    N.showMatriz();
    O = M;
    O.showMatriz();
    O = (O + N);
    O.showMatriz();
    std::cout<< "Es la suma" << std::endl;
    if(N.esNula() == false){
        std::cout<< "Funciona esNula" << std::endl;
    }
    if(M == N){
        std::cout<< "Comparador == funciona" << std::endl;
    }

    if(M != O){
        std::cout<< "Comparador != funciona" << std::endl;
    }
    O = (O * N);
    O.showMatriz();
    std::cout<< "Es la multiplicacion" << std::endl;

    O = (M - N);
    O.showMatriz();
    std::cout<< "Es la resta" << std::endl;

    // O[0][0] = 5;

    // O.showMatriz();

    return EXIT_SUCCESS;

}