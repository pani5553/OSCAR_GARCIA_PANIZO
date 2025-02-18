#include <iostream>
#include <vector>
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
#include "archivo.h"
#include <wchar.h>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

    // Cargar datos desde archivos
    cargarPacientesDesdeArchivo(pacientes, "pacientes.txt");
    cargarMedicosDesdeArchivo(medicos, "medicos.txt");
    cargarCitasDesdeArchivo(citas, "citas.txt");

    char opcionPrincipal;
    do {
        cout << "\n=== Sistema de Gestión Médica ===\n";
        cout << "1. Gestión de pacientes\n";
        cout << "2. Gestión de médicos\n";
        cout << "3. Gestión de citas\n";
        cout << "4. Guardar y salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case '1': menuPacientes(pacientes); break;
        case '2': menuMedicos(medicos); break;
        case '3': menuCitas(citas); break;
        case '4':
            cout << "Guardando datos y saliendo del sistema...\n";
            guardarPacientesEnArchivo(pacientes, "pacientes.txt");
            guardarMedicosEnArchivo(medicos, "medicos.txt");
            guardarCitasEnArchivo(citas, "citas.txt");
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != '4');

    return 0;
}
