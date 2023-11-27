// Materia: Programación I, Paralelo 4

// Autor: Valentina Jazmin Angulo Burgoa

// Fecha creación: 22/11/2023

// Fecha modificación: 27/11/2023

// Número de ejericio: 3

// Problema planteado:Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
// los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
// lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
// nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT con toda la
// información correspondiente a los candidatos aceptados.
// Una persona del fichero PERSONAS.DAT se considerará aceptable como candidato si tiene
// diferente sexo y que haya nacido en el mes y año (El programa debe ser capaz de trabajar con
// cualquier número de personas en el fichero PERSONAS.DAT)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar información de una persona
struct Persona {
    char nombre[31];
    int edad;
    char sexo;
    char fechaNacimiento[11];
};

// Función para determinar si una persona es un candidato aceptable
bool esCandidatoAceptable(const Persona& candidato, const Persona& cliente);

int main() {
    ifstream archivoPersonas("PERSONAS.BIN", ios::binary);
    ofstream archivoAceptados("ACEPTADOS.BIN", ios::binary);

    if (!archivoPersonas.is_open() || !archivoAceptados.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return 1;
    }

    // Leer datos de todos los candidatos del archivo PERSONAS.BIN
    Persona candidato;
    cout << "Listado de Candidatos Aceptados:\n";
    cout << "---------------------------------\n";

    // Leer el cliente del teclado
    Persona cliente;
    cout << "Ingrese sus datos como cliente:\n";
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(cliente.nombre, sizeof(cliente.nombre));
    cout << "Edad: ";
    cin >> cliente.edad;
    cout << "Sexo (M/F): ";
    cin >> cliente.sexo;
    cout << "Fecha de Nacimiento (formato dd/mm/yyyy): ";
    cin >> cliente.fechaNacimiento;

    cout << "\nCandidatos Aceptados:\n";

    // Procesar candidatos del archivo PERSONAS.BIN
    while (archivoPersonas.read(reinterpret_cast<char*>(&candidato), sizeof(Persona))) {
        if (esCandidatoAceptable(candidato, cliente)) {
            // Mostrar por pantalla y escribir en el archivo ACEPTADOS.BIN
            cout << "Nombre: " << candidato.nombre << "\n";
            cout << "Edad: " << candidato.edad << "\n";
            cout << "Sexo: " << candidato.sexo << "\n";
            cout << "Fecha de Nacimiento: " << candidato.fechaNacimiento << "\n";
            cout << "---------------------------------\n";

            archivoAceptados.write(reinterpret_cast<char*>(&candidato), sizeof(Persona));
        }
    }

    archivoPersonas.close();
    archivoAceptados.close();

    cout << "Proceso finalizado. Archivo ACEPTADOS.BIN creado.\n";

    return 0;
}

bool esCandidatoAceptable(const Persona& candidato, const Persona& cliente) {
    // Un candidato es aceptable si tiene diferente sexo y nació en el mismo mes y año que el cliente
    return (candidato.sexo != cliente.sexo &&
            strncmp(candidato.fechaNacimiento + 3, cliente.fechaNacimiento + 3, 7) == 0);
}
