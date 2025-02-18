#include "pacientes.h"
#include <iostream>
using namespace std;

// Constructor
Paciente::Paciente(int id, const string& nombre, const string& dni, const string& fechaNacimiento,
    const string& sexo, const string& direccion, const string& telefono,
    const string& correo, const string& grupoSanguineo, const string& historialMedico)
    : ID_paciente(id), nombre(nombre), dni(dni), fechaNacimiento(fechaNacimiento), sexo(sexo),
    direccion(direccion), telefono(telefono), correo(correo), grupoSanguineo(grupoSanguineo),
    historialMedico(historialMedico) {
}

// Mostrar información
void Paciente::mostrarInfo() const {
    cout << "ID Paciente: " << ID_paciente << " | Nombre: " << nombre << " | DNI: " << dni
        << " | Fecha de Nacimiento: " << fechaNacimiento << " | Sexo: " << sexo
        << " | Dirección: " << direccion << " | Teléfono: " << telefono
        << " | Correo: " << correo << " | Grupo Sanguíneo: " << grupoSanguineo
        << " | Historial Médico: " << historialMedico << endl;
}

// Modificar datos
void Paciente::modificarDatos(const string& nuevoNombre, const string& nuevoDNI,
    const string& nuevaDireccion, const string& nuevoTelefono,
    const string& nuevoCorreo) {
    if (!nuevoNombre.empty()) nombre = nuevoNombre;
    if (!nuevoDNI.empty()) dni = nuevoDNI;
    if (!nuevaDireccion.empty()) direccion = nuevaDireccion;
    if (!nuevoTelefono.empty()) telefono = nuevoTelefono;
    if (!nuevoCorreo.empty()) correo = nuevoCorreo;
    cout << "Datos del paciente actualizados con éxito." << endl;
}

// Obtener atributos
int Paciente::getID() const { return ID_paciente; }
string Paciente::getDNI() const { return dni; }
string Paciente::getNombre() const { return nombre; }
string Paciente::getFechaNacimiento() const { return fechaNacimiento; }
string Paciente::getSexo() const { return sexo; }
string Paciente::getDireccion() const { return direccion; }
string Paciente::getTelefono() const { return telefono; }
string Paciente::getCorreo() const { return correo; }
string Paciente::getGrupoSanguineo() const { return grupoSanguineo; }
string Paciente::getHistorialMedico() const { return historialMedico; }

// Menú de gestión de pacientes
void menuPacientes(vector<Paciente>& pacientes) {
    char opcion;
    do {
        cout << "\n=== Gestión de Pacientes ===\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Modificar paciente\n";
        cout << "3. Mostrar pacientes\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            string nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico;
            cout << "Ingrese nombre: "; cin >> nombre;
            cout << "Ingrese DNI: "; cin >> dni;
            cout << "Ingrese fecha de nacimiento: "; cin >> fechaNacimiento;
            cout << "Ingrese sexo: "; cin >> sexo;
            cout << "Ingrese dirección: "; cin >> direccion;
            cout << "Ingrese teléfono: "; cin >> telefono;
            cout << "Ingrese correo: "; cin >> correo;
            cout << "Ingrese grupo sanguíneo: "; cin >> grupoSanguineo;
            cout << "Ingrese historial médico: "; cin >> historialMedico;

            int id = pacientes.size() + 1;
            pacientes.emplace_back(id, nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico);
            cout << "Paciente agregado con éxito.\n";
        }
        else if (opcion == '2') {
            int id;
            cout << "Ingrese ID del paciente a modificar: ";
            cin >> id;
            for (auto& paciente : pacientes) {
                if (paciente.getID() == id) {
                    string nuevoNombre, nuevoDNI, nuevaDireccion, nuevoTelefono, nuevoCorreo;
                    cout << "Ingrese nuevo nombre: "; cin >> nuevoNombre;
                    cout << "Ingrese nuevo DNI: "; cin >> nuevoDNI;
                    cout << "Ingrese nueva dirección: "; cin >> nuevaDireccion;
                    cout << "Ingrese nuevo teléfono: "; cin >> nuevoTelefono;
                    cout << "Ingrese nuevo correo: "; cin >> nuevoCorreo;
                    paciente.modificarDatos(nuevoNombre, nuevoDNI, nuevaDireccion, nuevoTelefono, nuevoCorreo);
                    cout << "Paciente actualizado con éxito.\n";
                }
            }
        }
        else if (opcion == '3') {
            for (const auto& paciente : pacientes) {
                paciente.mostrarInfo();
            }
        }
    } while (opcion != '4');
}
