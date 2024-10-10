#include <iostream> 

using namespace std;

// Funciones para la implementación del Max Heap
void construirMaxHeap(Empleado *array, int tamano);
void maxHeapify(Empleado *array, int i, int tamano);
void ordenarHeap(Empleado *array, int n);

void construirMaxHeap(Empleado *array, int tamano)
{
    for (int i = tamano / 2 - 1; i >= 0; i--)
        maxHeapify(array, i, tamano);
}

void maxHeapify(Empleado *array, int i, int tamano)
{
    int mayor = i; 
    int izquierda = 2 * i + 1; 
    int derecha = 2 * i + 2; 

    // Verifica si el hijo izquierdo es mayor
    if (izquierda < tamano && array[izquierda].ingreso > array[mayor].ingreso)
        mayor = izquierda;

    // Verifica si el hijo derecho es mayor
    if (derecha < tamano && array[derecha].ingreso > array[mayor].ingreso)
        mayor = derecha;

    // Si el mayor no es el padre
    if (mayor != i) 
    {
        swap(array[i], array[mayor]); // Intercambia
        maxHeapify(array, mayor, tamano); // Recursivamente aplica maxHeapify
    }
}

void ordenarHeap(Empleado *array, int n)
{
    construirMaxHeap(array, n); // Construir el heap

    for (int i = n - 1; i > 0; i--)
    {
        swap(array[0], array[i]); // Intercambia el primero (mayor) con el último
        maxHeapify(array, 0, i); // Aplica maxHeapify en el resto
    }
}
