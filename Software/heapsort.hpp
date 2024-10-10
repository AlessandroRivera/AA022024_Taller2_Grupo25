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

// Funcion para mantener la propiedad del MonticuloMax
void MonticuloMax::maxHeapify(Cliente *array, int i, int tamano) { 
    int l = izquierda(i); 
    int r = derecha(i); 
    int mayor = i; 

    // Compara el nodo actual con sus hijos para mantener el MonticuloMax
    if (l < tamano && array[l].ingreso > array[i].ingreso) 
        mayor = l; 
    if (r < tamano && array[r].ingreso > array[mayor].ingreso) 
        mayor = r; 
    
    // Si el mayor no es el nodo actual, intercambia y llama a maxHeapify de nuevo
    if (mayor != i) { 
        swap(array[i], array[mayor]); 
        maxHeapify(array, mayor, tamano); 
    } 
} 

// Funcion principal de ordenamiento
void MonticuloMax::ordenarMonticulo(Cliente *arr, int n) { 
    int tamano_monticulo = n; 
    construirMonticuloMax(arr, tamano_monticulo); 
    // Extrae los elementos uno a uno del MonticuloMax
    for (int i = n - 1; i > 0; i--) { 
        swap(arr[0], arr[i]); // Intercambia el mayor elemento a la posicion final
        tamano_monticulo--; 
        maxHeapify(arr, 0, tamano_monticulo); // Llama a maxHeapify en el monticulo reducido
    } 
} 

// Funciones para obtener los indices de los hijos en el MonticuloMax
int MonticuloMax::izquierda(int i) { 
    return 2 * i + 1; 
} 

int MonticuloMax::derecha(int i) { 
    return 2 * i + 2; 
}