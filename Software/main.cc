#include <iostream> 
#include "./reader.hpp" 
#include "./heapsort.hpp" 

using namespace std; 

int main(int argc, char *argv[]) { 
    const int Filas = 1000; // Numero de filas a procesar
    Cliente datos[Filas]; // Arreglo para almacenar los datos de los clientes
    cargar_datos(datos, Filas); // Carga los datos desde el archivo
    MonticuloMax monticuloMax; // Crea una instancia del MonticuloMax

    // Ordenando con Heapsort
    monticuloMax.ordenarMonticulo(datos, Filas); 

    // Imprimiendo los datos de los empleados ordenados
    cout << "---------------DATOS ORDENADOS------------" << endl; 
    for (int i = 0; i < Filas; i++) { 
        cout << "nombre: " << datos[i].nombre << " puesto: " << datos[i].puesto 
             << " direccion: " << datos[i].direccion << " ingreso: " << datos[i].ingreso << endl; 
    } 
    return 0; 
}
