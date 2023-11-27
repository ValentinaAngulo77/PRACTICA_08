// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 8

// Problema planteado: Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
// números reales otro fichero de salida <nombre>.BIN grabado en formato binario.
// Ej:
// 1.23      3.45       12.5
// 4.8       3.9        0.83 ........................
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nombreArchivoEntrada, nombreArchivoSalida;

    // Solicitar nombres de archivos al usuario
    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> nombreArchivoEntrada;
    cout << "Ingrese el nombre del archivo de salida (con extensión .BIN): ";
    cin >> nombreArchivoSalida;

    // Abrir el archivo de entrada
    ifstream archivoEntrada(nombreArchivoEntrada);

    // Verificar si el archivo de entrada se abrió correctamente
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada.\n";
        return 1;
    }

    // Abrir el archivo de salida en formato binario
    ofstream archivoSalida(nombreArchivoSalida, ios::binary);

    // Verificar si el archivo de salida se abrió correctamente
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida.\n";
        archivoEntrada.close();
        return 1;
    }

    // Leer números del archivo de entrada y escribir en el archivo de salida en formato binario
    double numero;
    while (archivoEntrada >> numero) {
        archivoSalida.write(reinterpret_cast<char*>(&numero), sizeof(double));
    }

    // Cerrar los archivos
    archivoEntrada.close();
    archivoSalida.close();

    cout << "Proceso finalizado. Archivo '" << nombreArchivoSalida << "' creado.\n";

    return 0;
}
