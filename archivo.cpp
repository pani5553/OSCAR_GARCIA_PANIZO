#include "archivo.h"
#include <fstream>
#include <iostream>
using namespace std;

// Verificar existencia del archivo
bool archivoExiste(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

// Guardar pacientes
void guardarPacientesEnArchivo(const vector<Paciente>& pacientes, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de pacientes." << endl;
        return;
    }
    for (const auto& paciente : pacientes) {
        archivo << paciente.getID() << " " << paciente.getNombre() << " " << paciente.getDNI() << " "
            << paciente.getFechaNacimiento() << " " << paciente.getSexo() << " "
            << paciente.getDireccion() << " " << paciente.getTelefono() << " "
            << paciente.getCorreo() << " " << paciente.getGrupoSanguineo() << " "
            << paciente.getHistorialMedico() << endl;
    }
}

// Cargar pacientes
void cargarPacientesDesdeArchivo(vector<Paciente>& pacientes, const string& nombreArchivo) {
    if (!archivoExiste(nombreArchivo)) {
        cout << "No se encontró el archivo de pacientes, creando uno nuevo..." << endl;
        ofstream nuevoArchivo(nombreArchivo);
        return;
    }
    ifstream archivo(nombreArchivo);
    int id;
    string nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico;
    while (archivo >> id >> nombre >> dni >> fechaNacimiento >> sexo >> direccion >> telefono >> correo >> grupoSanguineo >> historialMedico) {
        pacientes.emplace_back(id, nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico);
    }
}

// Guardar médicos
void guardarMedicosEnArchivo(const vector<Medico>& medicos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de médicos." << endl;
        return;
    }
    for (const auto& medico : medicos) {
        archivo << medico.getID() << " " << medico.getNombre() << " " << medico.getEspecialidad() << endl;
    }
}

// Cargar médicos
void cargarMedicosDesdeArchivo(vector<Medico>& medicos, const string& nombreArchivo) {
    if (!archivoExiste(nombreArchivo)) {
        cout << "No se encontró el archivo de médicos, creando uno nuevo..." << endl;
        ofstream nuevoArchivo(nombreArchivo);
        return;
    }
    ifstream archivo(nombreArchivo);
    int id;
    string nombre, especialidad;
    while (archivo >> id >> nombre >> especialidad) {
        medicos.emplace_back(id, nombre, especialidad);
    }
}

// Guardar citas
void guardarCitasEnArchivo(const vector<CitaMedica>& citas, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de citas." << endl;
        return;
    }
    for (const auto& cita : citas) {
        archivo << cita.getFecha() << " " << cita.getIDPaciente() << " " << cita.getIDMedico() << " " << static_cast<int>(cita.getEstado()) << endl;
    }
}

// Cargar citas
void cargarCitasDesdeArchivo(vector<CitaMedica>& citas, const string& nombreArchivo) {
    if (!archivoExiste(nombreArchivo)) {
        cout << "No se encontró el archivo de citas, creando uno nuevo..." << endl;
        ofstream nuevoArchivo(nombreArchivo);
        return;
    }
    ifstream archivo(nombreArchivo);
    string fecha;
    int idPaciente, idMedico, estadoTemp;
    while (archivo >> fecha >> idPaciente >> idMedico >> estadoTemp) {
        citas.emplace_back(fecha, idPaciente, idMedico, static_cast<EstadoCita>(estadoTemp));
    }
}
