#ifndef READER_HPP
#define READER_HPP

#include<iostream>
#include<fstream>
#include <string> 

using namespace std;

// Define la estructura para almacenar la informacion del cliente
struct Cliente
{
    string nombre, direccion, puesto;
    float ingreso;
};

// Funcion para cargar los datos desde el archivo
void cargar_datos(Cliente *datos, const int filas = 1000)
{
    // Nombre del archivo
    string archivo = "clients.txt";

    string nombre, direccion, puesto, ingresoStr;

    // Abre el archivo
    ifstream archivoEntrada(archivo);

    // Verifica si el archivo se abrio correctamente
    if (!archivoEntrada.is_open())
    {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    int i = 0;
    while(getline(archivoEntrada, nombre, '\t')){
        datos[i].nombre = nombre; // Carga el nombre
        getline(archivoEntrada, direccion, '\t');
        datos[i].direccion = direccion; // Carga la direccion
        getline(archivoEntrada, puesto, '\t');
        datos[i].puesto = puesto; // Carga el puesto
        getline(archivoEntrada, ingresoStr, '\n');
        // Convierte el ingreso de string a float
        datos[i].ingreso = stod(ingresoStr);
        ++i;
    }

    // Cierra el archivo
    archivoEntrada.close();
}
#endif // READER_HPP
