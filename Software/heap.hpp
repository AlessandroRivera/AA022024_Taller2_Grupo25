#ifndef HEAP_HPP
#define HEAP_HPP

#include "reader.hpp"

// Declaraciones de funciones
void maxHeapify(Empleado *heap, int i, int tamano);
void insertarHeap(Empleado *heap, Empleado nuevo, int &tamano);
int buscarHeap(Empleado *heap, string nombre, int tamano);
void modificarIngresoHeap(Empleado *heap, int indice, float nuevoIngreso, int tamano);

// Inserta un nuevo empleado en el heap
void insertarHeap(Empleado *heap, Empleado nuevo, int &tamano)
{
    tamano++;
    int i = tamano - 1;
    heap[i] = nuevo;

    while (i != 0 && heap[(i - 1) / 2].ingreso < heap[i].ingreso)
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Busca un empleado por su nombre en el heap
int buscarHeap(Empleado *heap, string nombre, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        if (heap[i].nombre == nombre)
            return i;
    }
    return -1; // No encontrado
}

// Modifica el salario de un empleado en el heap
void modificarIngresoHeap(Empleado *heap, int indice, float nuevoIngreso, int tamano)
{
    heap[indice].ingreso = nuevoIngreso;
    
    while (indice != 0 && heap[(indice - 1) / 2].ingreso < heap[indice].ingreso)
    {
        swap(heap[indice], heap[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }
    maxHeapify(heap, indice, tamano);
}

// Funcion de maxHeapify
void maxHeapify(Empleado *heap, int i, int tamano)
{
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < tamano && heap[izquierda].ingreso > heap[mayor].ingreso)
        mayor = izquierda;

    if (derecha < tamano && heap[derecha].ingreso > heap[mayor].ingreso)
        mayor = derecha;

    if (mayor != i)
    {
        swap(heap[i], heap[mayor]);
        maxHeapify(heap, mayor, tamano);
    }
}

#endif 
