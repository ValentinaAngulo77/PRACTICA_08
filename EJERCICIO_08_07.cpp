// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 22/11/2023

// Fecha modificaci�n: 27/11/2023

// N�mero de ejericio: 7

// Problema planteado:Escriba un programa que tenga como entrada un fichero que contenga un texto y d� como
// resultado una estad�stica del n�mero de palabras.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Funci�n para contar el n�mero de palabras en una cadena
int contarPalabras(const string& texto);

int main() {
    string nombreArchivo;

    // Solicitar el nombre del archivo al usuario
    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> nombreArchivo;

    // Abrir el archivo
    ifstream archivoTexto(nombreArchivo);

    // Verificar si el archivo se abri� correctamente
    if (!archivoTexto.is_open()) {
        cerr << "Error al abrir el archivo.\n";
        return 1;
    }

    // Leer el contenido del archivo
    stringstream contenido;
    contenido << archivoTexto.rdbuf();
    string texto = contenido.str();

    // Contar el n�mero de palabras en el texto
    int numPalabras = contarPalabras(texto);

    // Mostrar el resultado
    cout << "N�mero de palabras en el archivo: " << numPalabras << endl;

    // Cerrar el archivo
    archivoTexto.close();

    return 0;
}

int contarPalabras(const string& texto) {
    stringstream ss(texto);
    string palabra;
    int contador = 0;

    while (ss >> palabra) {
        contador++;
    }

    return contador;
}
