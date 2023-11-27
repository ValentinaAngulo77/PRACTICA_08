// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 9

// Problema planteado: Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma
// horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se
// introduzca por pantalla.
// El resultado en texto sería el siguiente:
// Ej:
// 1.23 3.45 12.5 17,18
// 4.8 3.9 0.83 9,53
// 6,03 7,35 13,33 26,71
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    string nombreArchivoEntrada, nombreArchivoSalida;
    char tipoSalida;

    // Solicitar nombres de archivos y tipo de salida al usuario
    cout << "Ingrese el nombre del archivo de entrada (con extensión .BIN): ";
    cin >> nombreArchivoEntrada;
    cout << "Ingrese el nombre del archivo de salida: ";
    cin >> nombreArchivoSalida;
    cout << "Ingrese el tipo de salida (T para texto, B para binario): ";
    cin >> tipoSalida;

    // Abrir el archivo de entrada en formato binario
    ifstream archivoEntrada(nombreArchivoEntrada, ios::binary);

    // Verificar si el archivo de entrada se abrió correctamente
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada.\n";
        return 1;
    }

    // Leer la tabla de números del archivo de entrada
    vector<vector<double>> tabla;
    double numero;
    while (archivoEntrada.read(reinterpret_cast<char*>(&numero), sizeof(double))) {
        tabla.push_back({numero});
    }

    // Cerrar el archivo de entrada
    archivoEntrada.close();

    // Calcular la suma horizontal y vertical
    vector<double> sumaVertical(tabla[0].size(), 0.0);
    for (size_t i = 0; i < tabla.size(); ++i) {
        double sumaHorizontal = 0.0;
        for (size_t j = 0; j < tabla[i].size(); ++j) {
            sumaHorizontal += tabla[i][j];
            sumaVertical[j] += tabla[i][j];
        }
        tabla[i].push_back(sumaHorizontal);
    }

    // Agregar la fila de sumas verticales
    vector<double> sumaHorizontal(tabla[0].size(), 0.0);
    for (size_t j = 0; j < sumaVertical.size(); ++j) {
        sumaHorizontal[j] = sumaVertical[j];
    }
    tabla.push_back(sumaHorizontal);

    // Abrir el archivo de salida según el tipo seleccionado
    ofstream archivoSalida;
    if (tipoSalida == 'T' || tipoSalida == 't') {
        archivoSalida.open(nombreArchivoSalida + ".txt");
    } else if (tipoSalida == 'B' || tipoSalida == 'b') {
        archivoSalida.open(nombreArchivoSalida + ".BIN", ios::binary);
    } else {
        cerr << "Tipo de salida no válido.\n";
        return 1;
    }

    // Verificar si el archivo de salida se abrió correctamente
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida.\n";
        return 1;
    }

    // Escribir la tabla y los resultados en el archivo de salida
    for (const auto& fila : tabla) {
        for (const auto& elemento : fila) {
            if (tipoSalida == 'T' || tipoSalida == 't') {
                archivoSalida << setw(8) << fixed << setprecision(2) << elemento << " ";
            } else {
                archivoSalida.write(reinterpret_cast<const char*>(&elemento), sizeof(double));
            }
        }
        archivoSalida << endl;
    }

    // Cerrar el archivo de salida
    archivoSalida.close();

    cout << "Proceso finalizado. Archivo '" << nombreArchivoSalida << "' creado.\n";

    return 0;
}
