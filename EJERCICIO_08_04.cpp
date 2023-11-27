// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 4

// Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los artículos de
// un almacén.
// Para cada artículo habrá de guardar la siguiente información:
// • Código del artículo (Numérico)
// • Nombre del artículo (Cadena de caracteres)
// • Existencias actuales (Numérico)
// • Precio (Numérico decimal).
// Se deberán pedir datos de cada artículo por teclado hasta que como código se teclee el código
// 0.
// El fichero se habrá de crear ordenado por el código del artículo.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para almacenar información de un artículo
struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

// Funciones prototipo
bool compararArticulos(const Articulo& a, const Articulo& b);

int main() {
    vector<Articulo> articulos;

    // Solicitar datos de los artículos hasta que se ingrese un código igual a 0
    while (true) {
        Articulo nuevoArticulo;

        // Ingresar código del artículo
        cout << "Ingrese el código del artículo (0 para terminar): ";
        cin >> nuevoArticulo.codigo;

        if (nuevoArticulo.codigo == 0) {
            break; // Salir del bucle si se ingresa 0
        }

        // Ingresar nombre del artículo
        cout << "Ingrese el nombre del artículo: ";
        cin.ignore();
        getline(cin, nuevoArticulo.nombre);

        // Ingresar existencias actuales del artículo
        cout << "Ingrese las existencias actuales del artículo: ";
        cin >> nuevoArticulo.existencias;

        // Ingresar precio del artículo
        cout << "Ingrese el precio del artículo: ";
        cin >> nuevoArticulo.precio;

        // Agregar el artículo al vector
        articulos.push_back(nuevoArticulo);
    }

    // Ordenar el vector de artículos por el código del artículo
    sort(articulos.begin(), articulos.end(), compararArticulos);

    // Crear y escribir en el archivo "almacen.txt"
    ofstream archivoAlmacen("almacen.txt");

    if (!archivoAlmacen.is_open()) {
        cerr << "Error al abrir el archivo.\n";
        return 1;
    }

    // Escribir la información de los artículos en el archivo
    for (const auto& articulo : articulos) {
        archivoAlmacen << setw(5) << articulo.codigo << setw(30) << articulo.nombre
                       << setw(10) << articulo.existencias << setw(10) << fixed << setprecision(2) << articulo.precio << endl;
    }

    archivoAlmacen.close();

    cout << "Proceso finalizado. Archivo 'almacen.txt' creado y ordenado por código de artículo.\n";

    return 0;
}

// Función para comparar artículos por el código
bool compararArticulos(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}
