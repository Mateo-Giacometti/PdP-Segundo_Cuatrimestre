#include <iostream>
#include <string>

/*
Escribir un programa que encuentre el valor máximo y mínimo de una
serie de valores numéricos ingresados por el usuario. El programa debe
primero preguntar cuantos valores se ingresarán, y luego leerlos.
*/

void max_and_min(int *list, int arr){
    int max = list[0];
    int min = list[0];
    for(int i = 0; i < arr; i++){
        max < list[i] ? : max = list[i]; 
        min > list[i] ? : min = list[i];
    }
    std::cout << "El valor maximo es: " << max << std::endl;
    std::cout << "El valor minimo es: " << min << std::endl; 
}

int main(void){
    int arr;

    std::cout << "Cuantos numeros quiere ingresar? - ";
    std::cin >> arr;

    int lista[arr];

    for(int i = 0; i < arr; i++){
        std::cout << "Ingrese numero: ";
        std::cin >> lista[i];
    }

    max_and_min(lista, arr);

    return EXIT_SUCCESS;

}