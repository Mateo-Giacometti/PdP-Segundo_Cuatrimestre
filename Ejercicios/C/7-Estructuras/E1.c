#include <stdio.h>
#include <math.h> // Recordar usar gcc -x c main.c -lm 
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*
Definir las estructuras que se piden en los siguientes incisos:

a- Una estructura para manejar inventarios que contenga un campo para la descripción del producto (máximo 30 caracteres), un número 
para el número de parte en el inventario, un punto flotante para el precio, un entero para la cantidad que hay en el almacén y 
un entero para el lugar donde se almacena.

b- Una para manejar una dirección física que contiene arreglos para el país (máximo 40 caracteres), la provincia (máximo 30 caracteres), 
la ciudad (máx. 20), la dirección (máx. 30) y el código postal (10).

c- Una persona, con un arreglo para el nombre, otro para el apellido y una estructura como la del inciso anterior.

d- Una estructura, registro, que nos sirva para mantener un registro de los consumos de un vehículo, como en el último ejercicio de la guía 1. 
Para ello, debe contener un número para almacenar una cantidad de kilómetros, un número real para almacenar el costo del combustible, 
un número real para almacenar el dinero utilizado en una recarga, un time_t para almacenar la fecha, un booleano para indicar si se llenó 
el tanque y un arreglo para almacenar algún comentario.
*/

//A
typedef struct inventario{
    char descripcion[30];
    int partes;
    int lugar;
    int cantidad;
    float precio;

}inventarios_t;

//B
typedef struct direccion_fisica{
    char pais[40];
    char provincia[30];
    char ciudad[20];
    char direccion[30];
    char codigo_postal[10];

}direccion_fisica_t;

//C 
typedef struct persona{
    char nombre[10];
    char apellido[20];
    direccion_fisica_t *direccion;

}persona_t;

//D 
typedef struct fecha{
    int dia;
    int mes;
    int ano;
}tiempo_t;

typedef struct auto_registro{
    float kilometros;
    float costo_combustible;
    float recarga_combustible;
    time_t *fecha;
    bool tanque_full;
    char comentario[50];

}auto_registro_t;

int main(void){
    return EXIT_SUCCESS;
}