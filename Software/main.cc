#include <iostream> 
#include <iomanip>  // Para manejar el formato de la salida
#include "./reader.hpp" 
#include "./heapsort.hpp" 

using namespace std; 

int main(int argc, char *argv[]) 
{ 
    const int Filas = 1000; 
    Empleado datos[Filas]; 
    cargar_datos(datos, Filas); 
    ordenarHeap(datos, Filas); // Llama a la función de ordenar

    // Mostrar los datos ordenados en formato de tabla
    cout << left << setw(25) << "Nombre" 
         << setw(30) << "Puesto" 
         << setw(15) << "Ingreso" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = Filas - 1; i >= 0; i--) { 
        cout << left << setw(25) << datos[i].nombre 
             << setw(30) << datos[i].puesto 
             << "$ " << setw(14) << fixed << setprecision(2) << datos[i].ingreso << endl;  // Ajuste aquí
    } 

    return 0; 
}
