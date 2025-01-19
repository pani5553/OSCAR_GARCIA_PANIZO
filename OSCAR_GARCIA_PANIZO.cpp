#include <iostream>
#include <vector>
#include <wchar.h>
#include <locale>
#include <windows.h>
#include "pacientes.h"
#include "citas.h"
#include "medicos.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "");
    vector<Paciente> pacientes;
    vector<CitaMedica> citas;

    cargarPacientesDesdeArchivo(pacientes, "pacientes.txt");
    cargarCitasDesdeArchivo(citas, "citas.txt");

    char opcionPrincipal;
    do {
        cout << "\n=== Sistema de Gestión Médica ===\n";
        cout << "1. Gestión de pacientes\n";
        cout << "2. Gestión de citas\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case '1':
            menuPacientes(pacientes);
            break;
        case '2':
            menuCitas(citas);
            break;
        case '3':
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != '3');

    guardarPacientesEnArchivo(pacientes, "pacientes.txt");
    guardarCitasEnArchivo(citas, "citas.txt");

    return 0;
}