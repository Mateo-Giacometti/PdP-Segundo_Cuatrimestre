#include <iostream>
#include <string>
#include <cmath>

/*
Modifique el programa desarrollado en el punto 16 de forma que se le pregunte al usuario cuantos números se generarán. 
Además, el programa debe cortar cuando el usuario ingresa 0 o un número negativo.
*/

int main(void){

    int how_many;
    int numbers;
    int max, min, media;

    std::cout<< "Cuantos numeros desea generar ?: ";
    std::cin>> how_many;
    std::cout << std::endl;

    if(how_many > 0){
        std::cout << "Print "
                << how_many
                << " random integers."
                << std::endl;

        for (int i = 0; i < how_many; ++i){
            numbers = std::rand();
            std::cout << numbers << '\t';
            if(i == 0){
                min = numbers;
                max = numbers;
            }
            if(numbers < min){
                min = numbers;
            }
            if(numbers > max){
                max = numbers;
            }
            media += numbers/100;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "El numero mas grande es: " << max << std::endl;
        std::cout << "El numero mas chico es : " << min <<std::endl;
        std::cout << "La media es de: " << media << std::endl;
    }
    else{
        std::cout<< "El programa ha terminado" <<std::endl;
    }

    return EXIT_SUCCESS;
}