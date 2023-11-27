// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 22/11/2023

// Fecha modificaci�n: 27/11/2023

// N�mero de ejericio: 4

// Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los art�culos de
// un almac�n.
// Para cada art�culo habr� de guardar la siguiente informaci�n:
// � C�digo del art�culo (Num�rico)
// � Nombre del art�culo (Cadena de caracteres)
// � Existencias actuales (Num�rico)
// � Precio (Num�rico decimal).
// Se deber�n pedir datos de cada art�culo por teclado hasta que como c�digo se teclee el c�digo
// 0.
// El fichero se habr� de crear ordenado por el c�digo del art�culo.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para almacenar informaci�n de un art�culo
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

    // Solicitar datos de los art�culos hasta que se ingrese un c�digo igual a 0
    while (true) {
        Articulo nuevoArticulo;

        // Ingresar c�digo del art�culo
        cout << "Ingrese el c�digo del art�culo (0 para terminar): ";
        cin >> nuevoArticulo.codigo;

        if (nuevoArticulo.codigo == 0) {
            break; // Salir del bucle si se ingresa 0
        }

        // Ingresar nombre del art�culo
        cout << "Ingrese el nombre del art�culo: ";
        cin.ignore();
        getline(cin, nuevoArticulo.nombre);

        // Ingresar existencias actuales del art�culo
        cout << "Ingrese las existencias actuales del art�culo: ";
        cin >> nuevoArticulo.existencias;

        // Ingresar precio del art�culo
        cout << "Ingrese el precio del art�culo: ";
        cin >> nuevoArticulo.precio;

        // Agregar el art�culo al vector
        articulos.push_back(nuevoArticulo);
    }

    // Ordenar el vector de art�culos por el c�digo del art�culo
    sort(articulos.begin(), articulos.end(), compararArticulos);

    // Crear y escribir en el archivo "almacen.txt"
    ofstream archivoAlmacen("almacen.txt");

    if (!archivoAlmacen.is_open()) {
        cerr << "Error al abrir el archivo.\n";
        return 1;
    }

    // Escribir la informaci�n de los art�culos en el archivo
    for (const auto& articulo : articulos) {
        archivoAlmacen << setw(5) << articulo.codigo << setw(30) << articulo.nombre
                       << setw(10) << articulo.existencias << setw(10) << fixed << setprecision(2) << articulo.precio << endl;
    }

    archivoAlmacen.close();

    cout << "Proceso finalizado. Archivo 'almacen.txt' creado y ordenado por c�digo de art�culo.\n";

    return 0;
}

// Funci�n para comparar art�culos por el c�digo
bool compararArticulos(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}
