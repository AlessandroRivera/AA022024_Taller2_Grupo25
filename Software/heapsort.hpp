#include <iostream>
#include "./reader.hpp"

using namespace std;

// Estructura para el MonticuloMax
struct MonticuloMax {
    void construirMonticuloMax(Cliente *array, int tamano); 
    void maxHeapify(Cliente *array, int i, int tamano); 
    void ordenarMonticulo(Cliente *arr, int n); 
    int izquierda(int i); 
    int derecha(int i); 
}; 

// Funcion para construir el MonticuloMax
void MonticuloMax::construirMonticuloMax(Cliente *array, int tamano) { 
    for (int i = (tamano / 2) - 1; i >= 0; i--) 
        maxHeapify(array, i, tamano); 
} 