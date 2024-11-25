#include "citas.h"
#include <iostream>
using namespace std;

// Constructor
CitaMedica::CitaMedica(const string& fecha, int idPaciente, int idMedico)
    : fecha(fecha), ID_paciente(idPaciente), ID_medico(idMedico) {}

// Mostrar información de la cita
void CitaMedica::mostrarCita() const {
    cout << "Fecha: " << fecha << ", ID Paciente: " << ID_paciente
        << ", ID Médico: " << ID_medico << endl;
}

// Cancelar la cita
void CitaMedica::cancelarCita() {
    fecha = "Cancelada";
    ID_paciente = -1;
    ID_medico = -1;
    cout << "Cita cancelada.\n";
}
