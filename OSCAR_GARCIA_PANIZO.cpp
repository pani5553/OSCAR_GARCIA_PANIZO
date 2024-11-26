#include <iostream>
#include <vector>
#include <Windows.h>  // areglar UTF-8!!!!!!!!!!!!!!!!!!
#include <string>
#include "citas.h"
#include "pacientes.h"
#include "medicos.h"
using namespace std;

// Configura la consola para manejar caracteres especiales en UTF-8
void configurarConsola() {
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);       // no funciona !!!!!!!!!!!!!!!!!!
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

// Buscar paciente
void buscarPaciente(const vector<Paciente>& pacientes) {
    int id;
    cout << "\n=== Buscar Paciente ===\n";
    cout << "Ingrese el ID del paciente que desea buscar: ";
    cin >> id;

    bool encontrado = false;
    for (const auto& paciente : pacientes) {
        if (paciente.ID_paciente == id) {
            cout << "\nPaciente encontrado:\n";
            paciente.mostrarInfo();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Paciente con ID " << id << " no encontrado.\n";
    }
}

// Menú pacientes
void menuPacientes(vector<Paciente>& pacientes) {
    char opcion;
    do {
        cout << "\n=== Gestión de Pacientes ===\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Buscar paciente\n";
        cout << "3. Mostrar todos los pacientes\n";
        cout << "4. Salir del menú de pacientes\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            agregarPaciente(pacientes);
            break;
        case '2':
            buscarPaciente(pacientes);
            break;
        case '3':
            cout << "\n=== Lista de Pacientes ===\n";
            for (const auto& paciente : pacientes) {
                paciente.mostrarInfo();
            }
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
    configurarConsola();

    vector<CitaMedica> citas;
    vector<Paciente> pacientes;

    // Citas predefinidas
    citas.emplace_back("2024-12-01", 1, 101);
    citas.emplace_back("2024-12-02", 2, 102);

    char opcionPrincipal;
    do {
        cout << "\n=== Sistema de Gestión Médica ===\n";
        cout << "1. Gestión de citas\n";
        cout << "2. Gestión de pacientes\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case '1': {
            char opcionCitas;
            do {
                cout << "\n=== Gestión de Citas ===\n";
                cout << "1. Cancelar una cita\n";
                cout << "2. Mostrar citas\n";
                cout << "3. Salir del menú de citas\n";
                cout << "Seleccione una opción: ";
                cin >> opcionCitas;

                switch (opcionCitas) {
                case '1': {
                    cout << "\nIngrese el índice de la cita a cancelar (0-" << citas.size() - 1 << "): ";
                    int indice;
                    cin >> indice;

                    if (indice >= 0 && indice < citas.size()) {
                        citas[indice].cancelarCita();
                    }
                    else {
                        cout << "Índice no válido.\n";
                    }
                    break;
                }
                case '2': {
                    cout << "\n=== Citas Médicas ===\n";
                    for (size_t i = 0; i < citas.size(); ++i) {
                        cout << "[" << i << "] ";
                        citas[i].mostrarCita();
                    }
                    break;
                }
                case '3':
                    cout << "Saliendo del menú de citas...\n";
                    break;
                default:
                    cout << "Opción no válida.\n";
                }
            } while (opcionCitas != '3');
            break;
        }
        case '2':
            menuPacientes(pacientes);
            break;
        case '3':
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != '3');

    return 0;
}
