#include <iostream>
#include <vector>
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
using namespace std;

int main() {
    // Vectores para almacenar objetos
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

    // Crear y agregar pacientes
    pacientes.emplace_back(1, "Juan Perez");
    pacientes.emplace_back(2, "Maria Gomez");

    // Crear y agregar médicos
    medicos.emplace_back(101, "Dr. Smith", "Cardiología");
    medicos.emplace_back(102, "Dra. Lopez", "Pediatría");

    // Crear y agregar citas
    citas.emplace_back("2024-12-01", 1, 101);
    citas.emplace_back("2024-12-02", 2, 102);

    // Mostrar pacientes
    cout << "\n=== Pacientes ===\n";
    for (const auto& paciente : pacientes) {
        paciente.mostrarInfo();
    }

    // Mostrar médicos
    cout << "\n=== Médicos ===\n";
    for (const auto& medico : medicos) {
        medico.mostrarInfo();
    }

    // Mostrar citas
    cout << "\n=== Citas Médicas ===\n";
    for (const auto& cita : citas) {
        cita.mostrarCita();
    }

    // Cancelar la primera cita
    cout << "\nCancelando la primera cita...\n";
    citas[0].cancelarCita();

    // Mostrar citas después de cancelar
    cout << "\n=== Citas Después de Cancelar ===\n";
    for (const auto& cita : citas) {
        cita.mostrarCita();
    }

    return 0;
}
