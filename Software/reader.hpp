#ifndef READER_HPP
#define READER_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define la estructura para almacenar la información del empleado
struct Empleado
{
    string nombre, puesto;
    float ingreso;
};

// Carga los datos de los empleados desde el archivo
void cargar_datos(Empleado *datos, const int filas = 1000)
{
    string nombre, puesto, ingresoStr;
    const int numFilas = filas;

    // Abre el archivo
    ifstream archivo("empleados_salem.txt");

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int i = 0;
    while (getline(archivo, nombre, '\t'))
    {
        datos[i].nombre = nombre;
        getline(archivo, puesto, '\t');
        datos[i].puesto = puesto;
        getline(archivo, ingresoStr, '\n');
        datos[i].ingreso = stof(ingresoStr);  // Convertir el ingreso a float
        ++i;
    }

    // Cierra el archivo
    archivo.close();
}

#endif // READER_HPP
