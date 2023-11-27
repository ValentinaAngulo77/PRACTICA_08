// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 5

// Problema planteado: Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados
// genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros.
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream archivo1("almacen1.txt");
    ifstream archivo2("almacen2.txt");
    ofstream archivoResultado("almacen_mezclado.txt");

    if (!archivo1.is_open() || !archivo2.is_open() || !archivoResultado.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return 1;
    }

    int codigo1, codigo2;
    string nombre1, nombre2;
    int existencias1, existencias2;
    double precio1, precio2;

    // Leer el primer artículo de cada archivo
    archivo1 >> codigo1 >> nombre1 >> existencias1 >> precio1;
    archivo2 >> codigo2 >> nombre2 >> existencias2 >> precio2;

    while (!archivo1.eof() && !archivo2.eof()) {
        // Comparar códigos y escribir en el archivo resultado de forma ordenada
        if (codigo1 < codigo2) {
            archivoResultado << codigo1 << " " << nombre1 << " " << existencias1 << " " << precio1 << endl;
            archivo1 >> codigo1 >> nombre1 >> existencias1 >> precio1;
        } else {
            archivoResultado << codigo2 << " " << nombre2 << " " << existencias2 << " " << precio2 << endl;
            archivo2 >> codigo2 >> nombre2 >> existencias2 >> precio2;
        }
    }

    // Completar la mezcla si quedan elementos en alguno de los archivos
    while (!archivo1.eof()) {
        archivoResultado << codigo1 << " " << nombre1 << " " << existencias1 << " " << precio1 << endl;
        archivo1 >> codigo1 >> nombre1 >> existencias1 >> precio1;
    }

    while (!archivo2.eof()) {
        archivoResultado << codigo2 << " " << nombre2 << " " << existencias2 << " " << precio2 << endl;
        archivo2 >> codigo2 >> nombre2 >> existencias2 >> precio2;
    }

    archivo1.close();
    archivo2.close();
    archivoResultado.close();

    cout << "Proceso finalizado. Archivo 'almacen_mezclado.txt' creado.\n";

    return 0;
}
