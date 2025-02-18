#include "citas.h"
#include <iostream>
using namespace std;

// Constructor
CitaMedica::CitaMedica(const string& fecha, int idPaciente, int idMedico, EstadoCita estado)
    : fecha(fecha), ID_paciente(idPaciente), ID_medico(idMedico), estado(estado) {
}

// Mostrar información
void CitaMedica::mostrarInfo() const {
    cout << "Fecha: " << fecha << " | Paciente ID: " << ID_paciente << " | Médico ID: " << ID_medico;
    cout << " | Estado: " << (estado == ACTIVO ? "Activo" : estado == CANCELADO ? "Cancelado" : "Completado") << endl;
}

// Modificar cita
void CitaMedica::modificarCita(const string& nuevaFecha, int nuevoIDMedico) {
    if (!nuevaFecha.empty()) fecha = nuevaFecha;
    if (nuevoIDMedico > 0) ID_medico = nuevoIDMedico;
    cout << "Cita modificada con éxito." << endl;
}

// Cambiar estado de la cita
void CitaMedica::cambiarEstado(EstadoCita nuevoEstado) {
    estado = nuevoEstado;
    cout << "Estado de la cita actualizado." << endl;
}

// getFecha()
string CitaMedica::getFecha() const {
    return fecha;
}

// getIDPaciente()
int CitaMedica::getIDPaciente() const {
    return ID_paciente;
}

// getIDMedico()
int CitaMedica::getIDMedico() const {
    return ID_medico;
}

// getEstado()
EstadoCita CitaMedica::getEstado() const {
    return estado;
}

// Filtrar citas por fecha
void filtrarCitasPorFecha(const vector<CitaMedica>& citas, const string& fecha) {
    for (const auto& cita : citas) {
        if (cita.getFecha() == fecha) {
            cita.mostrarInfo();
        }
    }
}

// Filtrar citas por paciente
void filtrarCitasPorPaciente(const vector<CitaMedica>& citas, int idPaciente) {
    for (const auto& cita : citas) {
        if (cita.getIDPaciente() == idPaciente) {
            cita.mostrarInfo();
        }
    }
}

// Filtrar citas por médico
void filtrarCitasPorMedico(const vector<CitaMedica>& citas, int idMedico) {
    for (const auto& cita : citas) {
        if (cita.getIDMedico() == idMedico) {
            cita.mostrarInfo();
        }
    }
}

// Menú de gestión de citas
void menuCitas(vector<CitaMedica>& citas) {
    char opcion;
    do {
        cout << "\n=== Gestión de Citas ===\n";
        cout << "1. Agregar cita\n";
        cout << "2. Modificar cita\n";
        cout << "3. Cambiar estado de cita\n";
        cout << "4. Mostrar citas\n";
        cout << "5. Filtrar citas\n";
        cout << "6. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            string fecha;
            int idPaciente, idMedico;
            cout << "Ingrese fecha: "; cin >> fecha;
            cout << "Ingrese ID del paciente: "; cin >> idPaciente;
            cout << "Ingrese ID del médico: "; cin >> idMedico;
            citas.emplace_back(fecha, idPaciente, idMedico, ACTIVO);
            cout << "Cita agregada con éxito.\n";
        }
        else if (opcion == '2') {
            int idCita;
            cout << "Ingrese ID del paciente de la cita a modificar: ";
            cin >> idCita;
            for (auto& cita : citas) {
                if (cita.getIDPaciente() == idCita) {
                    string nuevaFecha;
                    int nuevoIDMedico;
                    cout << "Ingrese nueva fecha: "; cin >> nuevaFecha;
                    cout << "Ingrese nuevo ID de médico: "; cin >> nuevoIDMedico;
                    cita.modificarCita(nuevaFecha, nuevoIDMedico);
                }
            }
        }
        else if (opcion == '3') {
            int idCita;
            cout << "Ingrese ID del paciente de la cita a modificar estado: ";
            cin >> idCita;
            for (auto& cita : citas) {
                if (cita.getIDPaciente() == idCita) {
                    int nuevoEstado;
                    cout << "Seleccione nuevo estado (0=ACTIVO, 1=CANCELADO, 2=COMPLETADO): ";
                    cin >> nuevoEstado;
                    cita.cambiarEstado(static_cast<EstadoCita>(nuevoEstado));
                }
            }
        }
        else if (opcion == '4') {
            for (const auto& cita : citas) {
                cita.mostrarInfo();
            }
        }
        else if (opcion == '5') {
            char filtro;
            cout << "Seleccione filtro (F = Fecha, P = ID Paciente, M = ID Médico): ";
            cin >> filtro;
            if (filtro == 'F') {
                string fecha;
                cout << "Ingrese fecha: "; cin >> fecha;
                filtrarCitasPorFecha(citas, fecha);
            }
            else if (filtro == 'P') {
                int idPaciente;
                cout << "Ingrese ID del paciente: "; cin >> idPaciente;
                filtrarCitasPorPaciente(citas, idPaciente);
            }
            else if (filtro == 'M') {
                int idMedico;
                cout << "Ingrese ID del médico: "; cin >> idMedico;
                filtrarCitasPorMedico(citas, idMedico);
            }
        }
    } while (opcion != '6');
}
