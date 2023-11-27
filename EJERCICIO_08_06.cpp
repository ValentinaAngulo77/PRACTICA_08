// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 6

// Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el
// campo Precio. La condición podrá ser:
// Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado.
// Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
// aquellos artículos para los que se cumple la condición de entrada.
// Mostrar el archivo de salida “salida.dat”
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar información de un artículo
struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

// Función para mostrar información de un artículo en la pantalla
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

    // Solicitar la condición sobre el campo Precio
    cout << "Ingrese la condición sobre el campo Precio (mayor o igual a): ";
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
    cout << "Código: " << articulo.codigo << "\n";
    cout << "Nombre: " << articulo.nombre << "\n";
    cout << "Existencias: " << articulo.existencias << "\n";
    cout << "Precio: " << articulo.precio << "\n";
    cout << "---------------------------------\n";
}
