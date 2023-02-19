#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>

/*
Escriba una clase que represente un paquete de información enviado a través de una red. Los
paquetes tienen las siguientes características que han sido simplificadas para esta aplicación:
 La dirección IP del emisor.
 La dirección IP del receptor.
 Las direcciones IP son arreglos de 4 chars.
 Un número identificador (ID) del paquete que puede estar entre 0 y 65535.
 El dato enviado representado por un array de bytes. Para este problema se supone que
cada paquete tiene una longitud fija de 1000 bytes. Si la información a enviar ocupa menos
espacio se rellena con bytes que van alternando ente valores iguales a -1 y 0.
Escriba la clase que represente a uno de estos paquetes. Dicha clase deberá proveer la siguiente
funcionalidad:
 Defina un constructor con parámetros para las direcciones de IP del emisor y receptor, el ID
del paquete, y un array de tipo byte.
 Implemente el método de acceso para la dirección IP del receptor.
 Escriba un método de modificación para especificar un elemento en el array de datos.
 Sobrecargue el operador '=='. Dos paquetes se consideran iguales si las direccion
*/

class PDI {
    private:
        char IP_E_[4], IP_R_[4];
        float ID_;
        int paquete_[1000];
    public:
        PDI(char Em[4], char Re[4], float ID, int paquete[1000]): ID_(ID) {
            for(size_t i = 0; i < 4; i++){
                IP_E_[i] = Em[i];
                IP_R_[i] = Re[i];
            }
            for(size_t i = 0; i < 1000; i++){
                paquete_[i] = paquete[i];
            }
            std::cout<< "Se creo PDI" << std::endl;
        }
        virtual ~PDI(){}
        char* getReceptorIP(){return IP_R_;}
        char* getEmisorIP(){return IP_E_;}
        int* getPaquete(){return paquete_;}
        void changeValue(int position, int value){
            paquete_[position] = value;
        }
        bool operator==(PDI &comp){
            for(size_t i = 0; i < 1000; i++){
                if(this->paquete_[i] != comp.paquete_[i]){
                    return false;
                }
            }
            return true;
        }
        bool operator!=(PDI &comp){
            for(size_t i = 0; i < 1000; i++){
                if(this->paquete_[i] != comp.paquete_[i]){
                    return true;
                }
            }
            return false;
        }
};

int main(void){
    int a[1000] = {0};
    int b[1000] = {1};
    int c[1000] = {0};
    char IP_R[4] = {'q', 'e', 'r', 'b'};
    char IP_E[4] = {'q', 'e', 'r', 'a'};
    PDI *primero = new PDI(IP_E, IP_R, 11111, a);
    PDI *segundo = new PDI(IP_E, IP_R, 11111, b);
    if(*primero != *segundo){
        std::cout << "Son iguales" << std::endl;
    }
    return EXIT_SUCCESS;
}