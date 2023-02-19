#include <iostream>
#include <string>
#include <cmath>

/*El siguiente código imprime 100 números aleatorios:

#include <iostream>

int main(void)
{
    int how_many = 100;

    std::cout << "Print "
              << how_many
              << " random integers."
              << std::endl;

    for (int i = 0; i < how_many; ++i) {
        std::cout << std::rand() << '\t';
    }
    std::cout << std::endl;
}

Agregue el código necesario para determinar el valor medio, máximo y mínimo de los valores generados.
*/

int main(void)
{
    int how_many = 100;
    int numbers;
    int max, min, media;

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
    std::cout << "El numero mas grande es: " << max << std::endl;
    std::cout << "El numero mas chico es : " << min <<std::endl;
    std::cout << "La media es de: " << media << std::endl;
    
    return EXIT_SUCCESS;
}