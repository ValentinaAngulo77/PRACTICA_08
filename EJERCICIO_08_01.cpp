// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 1

// Problema planteado: Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto.
// La encriptación consiste en que dado un fichero de texto de entrada genere otro fichero de
// salida de extensión <nombre>.COD donde el texto estará codificado (encriptado).
// Esta codificación consiste en reemplazar cada carácter por el tercero siguiente según la tabla
// ASCII.
// La opción de desencriptado consiste en leer un fichero <nombre>.COD y recuperar la
// información original.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funciones prototipo
void encriptarArchivo(const string& nombreArchivo);
void desencriptarArchivo(const string& nombreArchivo);

int main() {
    int opcion;
    string nombreArchivo;

    do {
        cout << "Menú:\n";
        cout << "1. Encriptar archivo de texto.\n";
        cout << "2. Desencriptar archivo de texto.\n";
        cout << "3. Salir.\n";
        cout << "Seleccione una opción (1-3): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del archivo a encriptar: ";
                cin >> nombreArchivo;
                encriptarArchivo(nombreArchivo);
                break;
            case 2:
                cout << "Ingrese el nombre del archivo a desencriptar: ";
                cin >> nombreArchivo;
                desencriptarArchivo(nombreArchivo);
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}

void encriptarArchivo(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoSalida(nombreArchivo + ".COD");

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return;
    }

    char caracter;
    while (archivoEntrada.get(caracter)) {
        // Encriptar cada carácter reemplazándolo por el tercero siguiente según la tabla ASCII
        caracter = caracter + 3;
        archivoSalida.put(caracter);
    }

    cout << "Archivo encriptado correctamente.\n";

    archivoEntrada.close();
    archivoSalida.close();
}

void desencriptarArchivo(const string& nombreArchivo) {
    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoSalida(nombreArchivo.substr(0, nombreArchivo.size() - 4) + "_desencriptado.txt");

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return;
    }

    char caracter;
    while (archivoEntrada.get(caracter)) {
        // Desencriptar cada carácter restando 3 según la tabla ASCII
        caracter = caracter - 3;
        archivoSalida.put(caracter);
    }

    cout << "Archivo desencriptado correctamente.\n";

    archivoEntrada.close();
    archivoSalida.close();
}

