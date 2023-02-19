#include <iostream>
#define MAX_SIZE 1000

using namespace std;

class errorsubindice{ //este error lo vamos a lanzar cuando tengamos un error con el operador '[]'
  public:
    errorsubindice();
};
//solo definimos un constructor
errorsubindice::errorsubindice(){cout<<"Error de subindice"<<endl;}


class Array{
  public:
    Array();  // default
    Array(size_t); // recibe un size_t
    Array(const Array &); // copia
    ~Array();
    
    int getSize() const;
    void emitir() const;

    // operadores
    Array &operator=(const Array &);
    bool operator==(const Array &) const;
    int &operator[](int);
        
  private:
        int size_;
        int *ptr_;
};

Array::Array(){
    try{
        ptr_ = new int[10];
        size_ = 10;
        }
    catch(bad_alloc &b)
        {
            cout<<"No hay memoria suficiente"<<endl;
            throw; //relanza: quien lo haya invocado decidira que hacer
        }
}

Array::Array(size_t size){
    try{
        if((size<1)||(size>MAX_SIZE)) size_ = 10; else size_ = size;
        ptr_ = new int[size];
        }
    catch(bad_alloc &b)
        {
            cout<<"No hay memoria suficiente"<<endl;
            throw; //relanza: quien lo haya invocado decidira que hacer
        }
}

Array::Array(const Array& init){
    try{
        size_ = init.size_;
        ptr_ = new int[size_];
        for (size_t i = 0; i<size_; i++)
            ptr_[i] = init.ptr_[i];
        }
    catch(bad_alloc &b)
        {
            cout<<"No hay memoria suficiente"<<endl;
            throw; //relanza: quien lo haya invocado decidira que hacer
        }
}

Array::~Array(){
    if(ptr_)
    delete[] ptr_;
    cout<<"Array liberado"<<endl;
}

int Array::getSize() const{return size_;}

Array& Array::operator=(const Array &right){
    if(&right!=this){//check para evitar autoasignaciones
        try{
            if(size_!=right.size_){ //si tienen distinto tamano, libero y vuelvo a pedir memoria
                int *aux = new int[right.size_];
                delete[] ptr_;
                size_ = right.size_;
                for(size_t i=0; i<size_; i++) aux[i]=right.ptr_[i];
                return *this; //al retornar una referencia permite hacer cosas como x=y=z
            }
            else{ //si tienene el mismo tamano directamente reemplazo los valores
                for(size_t i=0;i<size_;i++)  ptr_[i] = right.ptr_[i];
                return *this;
                }
            } 
        catch(bad_alloc &b){
            cout<<"No se realizo la copia, ni se modifico ningun objeto"<<endl;
            return *this;
        }
    }
    return *this;
}

//operador que determina si dos arrays son iguales
bool Array::operator==(const Array &right)const{
    if(size_!=right.size_) return false; //lo primero a validar: nos ahorra tiempo
    else //observar que no hace falta el uso de llaves para la siguiente secuencia de instrucciones
        for(size_t i = 0; i<size_; i++)
            if(ptr_[i]!=right.ptr_[i]) return false;
    return true;
}

//sobrecarga operador indexacion:la referencia retornada es un lvalue
int& Array::operator[](int subscript){
    if((0>subscript)||(subscript>size_)) throw errorsubindice();
    else
        return ptr_[subscript];
}

void Array::emitir() const{
    for(size_t i=0;i<size_;i++) cout<<ptr_[i];
    cout<<endl;
}


int main(void){
    Array a,b(5),c(a);
    for(size_t i=0;i<10;i++) a[i]=i+1;
    c=a;
    for(size_t i=0;i<5;i++) b[i]=i*2;
    a.emitir();
    b.emitir();
    c.emitir();

    return EXIT_SUCCESS;

}