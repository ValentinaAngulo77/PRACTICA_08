// Materia: Programaci�n I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creaci�n: 22/11/2023

// Fecha modificaci�n: 27/11/2023

// N�mero de ejericio: 2

// Problema planteado:Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se
// guarde la informaci�n de un n�mero indeterminado de personas.
// La informaci�n que se guardar� por cada persona ser�:
// � Nombre: De 1 a 30 caracteres.
// � Edad num�rico (>= 1 y <=100)
// � Sexo CHAR (M/F).
// � FechaNacimiento CHAR(10) (formato dd/mm/yyyy)
// La informaci�n correspondiente a cada persona se leer� del teclado.
// El proceso finalizar� cuando se teclee un campo "Nombre" que est� solamente con el car�cter
// de espacio.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar informaci�n de una persona
struct Persona {
    char nombre[31];
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

int main() {
    ofstream archivoPersonas("PERSONAS.BIN", ios::binary);

    if (!archivoPersonas.is_open()) {
        cerr << "Error al abrir el archivo de personas.\n";
        return 1;
    }

    Persona persona;

    cout << "Ingrese la informaci�n de las personas:\n";

    while (true) {
        // Ingresar nombre
        cout << "Nombre (deje en blanco para finalizar): ";
        cin.ignore();
        cin.getline(persona.nombre, sizeof(persona.nombre));

        // Verificar si el nombre est� en blanco para finalizar el ingreso
        if (persona.nombre[0] == '\0' || (persona.nombre[0] == ' ' && persona.nombre[1] == '\0')) {
            break;
        }

        // Ingresar edad
        cout << "Edad (1-100): ";
        cin >> persona.edad;

        // Verificar rango de edad
        if (persona.edad < 1 || persona.edad > 100) {
            cerr << "Error: La edad debe estar en el rango de 1 a 100.\n";
            continue;
        }

        // Ingresar sexo
        cout << "Sexo (M/F): ";
        cin >> persona.sexo;

        // Verificar sexo
        if (persona.sexo != 'M' && persona.sexo != 'F') {
            cerr << "Error: El sexo debe ser M o F.\n";
            continue;
        }

        // Ingresar fecha de nacimiento
        cout << "Fecha de Nacimiento (formato dd/mm/yyyy): ";
        cin >> persona.fechaNacimiento;

        // Escribir la informaci�n de la persona en el archivo
        archivoPersonas.write(reinterpret_cast<char*>(&persona), sizeof(Persona));

        cout << "Persona registrada correctamente.\n";
    }

    archivoPersonas.close();

    cout << "Proceso finalizado. Archivo PERSONAS.BIN creado.\n";

    return 0;
}
