#include <iostream>
#include <iomanip>
#include "reader.hpp"
#include "heapsort.hpp"
#include "heap.hpp"

using namespace std;

const int Filas = 2000; // Numero de filas (Datos de los empleados) a leer 

int main(int argc, char *argv[]){
    
    Empleado datos[Filas];
    int tamano = 0; // Para manejar el tamaño dinamico del heap

    cargar_datos(datos, Filas);
    tamano = Filas; // El tamaño se iguala al numero de filas cargadas

    int opcion = 0;
    do{
        cout << "\n\t=============== Almacenes Salem ===============\n" << endl;
        cout << "1. Ordenar salarios" << endl;
        cout << "2. Salir" << endl;
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Ordenar los empleados por salario
            ordenarHeap(datos, tamano);

            // Mostrar los datos ordenados 
            cout << left << setw(25) << "Nombre"
                 << setw(30) << "Puesto"
                 << setw(15) << "Ingreso" << endl;
            cout << "-------------------------------------------------------------" << endl;

            for (int i = tamano - 1; i >= 0; i--)
            {
                cout << left << setw(25) << datos[i].nombre
                     << setw(30) << datos[i].puesto
                     << "$ " << setw(14) << fixed << setprecision(2) << datos[i].ingreso << endl;
            }
            break;

        case 2:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida....." << endl;
            break;
        }

    } while (opcion != 2);

    return 0;
}
