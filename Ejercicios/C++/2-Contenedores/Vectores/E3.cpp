#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

/*Escribir una función que dado un vector ordenado y uno desordenado devuelva un vector ordenado con los elementos de ambos.
Sugerencia: Aplicar el algoritmo de ordenamiento por inserción (insertion sort). Una alternativa un poco más desafiante (y eficiente) 
es ordenar el segundo arreglo utilizando ordenamiento por mezcla (merge sort) y luego hacer la mezcla (merge) de ambos arreglos ordenados.*/


using namespace std;

void ordenar(vector<int> &v){
    int aux;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(v[i] < v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void mezclar(vector<int> &v1, vector<int> &v2){
    for(int i = 0; i < v2.size(); i++){
        v1.emplace_back(v2[i]);
    }
    ordenar(v1);
}


int main(){
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 = {10, 11, 12, 13, 14, 22, 16, 17, 18, 19, 20};
    mezclar(v1, v2);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    return 0;
}