#include <iostream>
#include <string>

/*
Escribir un programa que reciba la cantidad de distintas monedas ingresadas
(de a un tipo de moneda a la vez), a saber:
• 5 centavos
• 10 centavos
• 25 centavos
• 50 centavos
• 1 peso
• 2 pesos
• 5 pesos
• 10 pesos
Y devuelva el monto total con un mensaje por pantalla de la forma:
a. "Su monto total es de $PP.CC"
b. "Su monto total es de PP peso(s) y CC centavo(s).
*/

int main(void){
    float pesos = 0, centavos = 0, total = 0, moneda;
    for (int i = 0; i < 8; i++){
        std::cout << "Ingrese la cantidad de monedas correspondiente: ";
        std::cin >> moneda;
        if(i == 0){
            centavos += moneda * 5;
            total += moneda * 0.05;
        }
        if(i == 1){
            centavos += moneda * 10;
            total += moneda * 0.10;
        }
        if(i == 2){
            centavos += moneda * 25;
            total += moneda * 0.25; 
        }
        if(i == 3){
            centavos += moneda * 50;
            total += moneda * 0.50;
        }
        if(i == 4){
            pesos += moneda;
            total += moneda;
        }
        if(i == 5){
            pesos += moneda * 2;
            total += moneda * 2;
        }
        if(i == 6){
            pesos += moneda * 5;
            total += moneda * 5;
        }
        if(i == 7){
            pesos += moneda * 10;
            total += moneda * 10;
        }
    }
    std::cout << "Su monto total es de $" << total << std::endl;
    std::cout << "Su monto total es de " << pesos << " peso(s) y " << centavos << " centavo(s)." << std::endl;
    return 0;
}