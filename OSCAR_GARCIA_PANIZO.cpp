#include <iostream>
#include <vector>
#include <fstream>
#include "pacientes.h"
using namespace std;

// Guardar pacientes
void guardarPacientesEnArchivo(const vector<Paciente>& pacientes, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& paciente : pacientes) {
        paciente.guardarEnArchivo(archivo);
    }

    cout << "Datos guardados correctamente.\n";
}

// Cargar pacientes
void cargarPacientesDesdeArchivo(vector<Paciente>& pacientes, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para cargar.\n";
        return;
    }

    while (archivo) {
        Paciente paciente = Paciente::cargarDesdeArchivo(archivo);
        if (archivo) {
            pacientes.push_back(paciente);
        }
    }

    cout << "Datos cargados correctamente.\n";
}

// Agregar paciente
void agregarPaciente(vector<Paciente>& pacientes) {
    int id;
    string nombre;

    cout << "\n=== Agregar Paciente ===\n";
    cout << "Ingrese el ID del paciente: ";
    cin >> id;
    cin.ignore();

    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nombre);

    pacientes.emplace_back(id, nombre);

    cout << "Paciente agregado con éxito.\n";
}

// Mostrar pacientes
void mostrarPacientes(const vector<Paciente>& pacientes) {
    cout << "\n=== Lista de Pacientes ===\n";
    for (const auto& paciente : pacientes) {
        paciente.mostrarInfo();
    }
}

// Menú de pacientes
void menuPacientes(vector<Paciente>& pacientes) {
    char opcion;
    do {
        cout << "\n=== Gestión de Pacientes ===\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Mostrar todos los pacientes\n";
        cout << "3. Guardar pacientes en archivo\n";
        cout << "4. Salir del menú de pacientes\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            agregarPaciente(pacientes);
            break;
        case '2':
            mostrarPacientes(pacientes);
            break;
        case '3':
            guardarPacientesEnArchivo(pacientes, "pacientes.txt");
            break;
        case '4':
            cout << "Saliendo del menú de pacientes...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != '4');
}

int main() {
    vector<Paciente> pacientes;

    // Cargar en el inicio
    cargarPacientesDesdeArchivo(pacientes, "pacientes.txt");

    char opcionPrincipal;
    do {
        cout << "\n=== Sistema de Gestión Médica ===\n";
        cout << "1. Gestión de pacientes\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case '1':
            menuPacientes(pacientes);
            break;
        case '2':
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != '2');

    return 0;
}
