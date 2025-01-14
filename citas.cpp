// Archivo: citas.cpp
#include "citas.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor
CitaMedica::CitaMedica(const string& fecha, int idPaciente, int idMedico)
    : fecha(fecha), ID_paciente(idPaciente), ID_medico(idMedico) {
}

// Métodos
void CitaMedica::mostrarCita() const {
    cout << "Fecha: " << fecha << ", ID Paciente: " << ID_paciente
        << ", ID Médico: " << ID_medico << endl;
}

void CitaMedica::cancelarCita() {
    fecha = "Cancelada";
    ID_paciente = -1;
    ID_medico = -1;
    cout << "Cita cancelada.\n";
}

void guardarCitasEnArchivo(const vector<CitaMedica>& citas, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& cita : citas) {
        archivo << cita.fecha << " " << cita.ID_paciente << " " << cita.ID_medico << endl;
    }
    cout << "Citas guardadas correctamente.\n";
}

void cargarCitasDesdeArchivo(vector<CitaMedica>& citas, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para cargar.\n";
        return;
    }

    string fecha;
    int idPaciente, idMedico;
    while (archivo >> fecha >> idPaciente >> idMedico) {
        citas.emplace_back(fecha, idPaciente, idMedico);
    }
    cout << "Citas cargadas correctamente.\n";
}

void menuCitas(vector<CitaMedica>& citas) {
    char opcion;
    do {
        cout << "\n=== Gestión de Citas ===\n";
        cout << "1. Agregar cita\n";
        cout << "2. Mostrar todas las citas\n";
        cout << "3. Cancelar una cita\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case '1': {
            string fecha;
            int idPaciente, idMedico;

            cout << "Ingrese la fecha: (##-##-##)";
            cin >> fecha;

            cout << "Ingrese el ID del paciente: ";
            cin >> idPaciente;

            cout << "Ingrese el ID del médico: ";
            cin >> idMedico;

            citas.emplace_back(fecha, idPaciente, idMedico);
            cout << "Cita agregada con éxito.\n";
            break;
        }
        case '2':
            for (const auto& cita : citas) {
                cita.mostrarCita();
            }
            break;
        case '3': {
            int indice;
            cout << "Ingrese el índice de la cita a cancelar: ";
            cin >> indice;

            if (indice >= 0 && indice < citas.size()) {
                citas[indice].cancelarCita();
            }
            else {
                cout << "Índice no válido.\n";
            }
            break;
        }
        case '4':
            cout << "Saliendo del menú de citas...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != '4');
}
