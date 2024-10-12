#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "heap.hpp"

// Declaraciones de funciones
void maxHeapify(Empleado *array, int i, int tamano);
void construirMaxHeap(Empleado *array, int tamano);
void ordenarHeap(Empleado *array, int tamano);

// Construir un MaxHeap para ordenar
void construirMaxHeap(Empleado *array, int tamano){
    for (int i = tamano / 2 - 1; i >= 0; i--)
        maxHeapify(array, i, tamano);
}

// Funcion para ordenar usando el heap
void ordenarHeap(Empleado *array, int tamano){
    construirMaxHeap(array, tamano);

    for (int i = tamano - 1; i > 0; i--)
    {
        swap(array[0], array[i]); // Mueve el mayor al final del array
        maxHeapify(array, 0, i);  // Ajusta el heap
    }
}

#endif 
