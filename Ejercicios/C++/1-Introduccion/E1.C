#include <iostream>
#include <string>

/*
Escribir la siguiente frase por pantalla “She sells sea shells by the seashore.”
a. Todo en una sola línea.
b. En siete líneas.
c. Dentro de un recuadro.
*/

int main(void){
    std::cout << "She sells sea shells by the seashore." << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < 7; i++){
        std::cout << "She sells sea shells by the seashore." << std::endl;
    }

    std::string recuadro = "|She sells sea shells by the seashore.|";

    int longitud = recuadro.length();
    for(int i = 0; i < longitud; i++){
        std::cout << "-";
    }

    std::cout << std::endl;
    std::cout << recuadro << std::endl;
    
    for(int i = 0; i < longitud; i++){
        std::cout << "-";
    }

    std::cout << std::endl;    

    return EXIT_SUCCESS;
}