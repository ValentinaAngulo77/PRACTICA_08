// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 22/11/2023

// Fecha modificaci�n: 27/11/2023

// N�mero de ejericio: 6

// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condici�n sobre el
// campo Precio. La condici�n podr� ser:
// Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado.
// Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
// aquellos art�culos para los que se cumple la condici�n de entrada.
// Mostrar el archivo de salida �salida.dat�
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar informaci�n de un art�culo
struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

// Funci�n para mostrar informaci�n de un art�culo en la pantalla
void mostrarArticulo(const Articulo& articulo);

int main() {
    ifstream archivoEntrada("almacen.txt", ios::binary);
    ofstream archivoSalida("salida.dat", ios::binary);

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return 1;
    }

    Articulo articulo;
    double condicionPrecio;

    // Solicitar la condici�n sobre el campo Precio
    cout << "Ingrese la condici�n sobre el campo Precio (mayor o igual a): ";
    cin >> condicionPrecio;

    // Leer datos del archivo de entrada y escribir en el archivo de salida
    while (archivoEntrada.read(reinterpret_cast<char*>(&articulo), sizeof(Articulo))) {
        if (articulo.precio >= condicionPrecio) {
            mostrarArticulo(articulo);
            archivoSalida.write(reinterpret_cast<char*>(&articulo), sizeof(Articulo));
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Proceso finalizado. Archivo 'salida.dat' creado.\n";

    return 0;
}

void mostrarArticulo(const Articulo& articulo) {
    cout << "C�digo: " << articulo.codigo << "\n";
    cout << "Nombre: " << articulo.nombre << "\n";
    cout << "Existencias: " << articulo.existencias << "\n";
    cout << "Precio: " << articulo.precio << "\n";
    cout << "---------------------------------\n";
}
