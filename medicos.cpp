#include "medicos.h"
#include <iostream>
using namespace std;

// Constructor
Medico::Medico(int id, const string& nombre, const string& especialidad)
    : ID_medico(id), nombre(nombre), especialidad(especialidad) {
}

// Mostrar información
void Medico::mostrarInfo() const {
    cout << "ID Médico: " << ID_medico << " | Nombre: " << nombre << " | Especialidad: " << especialidad << endl;
}

// Modificar datos
void Medico::modificarDatos(const string& nuevoNombre, const string& nuevaEspecialidad) {
    if (!nuevoNombre.empty()) nombre = nuevoNombre;
    if (!nuevaEspecialidad.empty()) especialidad = nuevaEspecialidad;
    cout << "Datos del médico actualizados con éxito." << endl;
}

// Obtener atributos
int Medico::getID() const { return ID_medico; }
string Medico::getNombre() const { return nombre; }
string Medico::getEspecialidad() const { return especialidad; }

// Listar médicos por especialidad
void listarMedicosPorEspecialidad(const vector<Medico>& medicos, const string& especialidad) {
    cout << "\nMédicos con especialidad en " << especialidad << ":\n";
    bool encontrado = false;
    for (const auto& medico : medicos) {
        if (medico.getEspecialidad() == especialidad) {
            medico.mostrarInfo();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay médicos registrados en esta especialidad." << endl;
    }
}

// Menú de gestión de médicos
void menuMedicos(vector<Medico>& medicos) {
    char opcion;
    do {
        cout << "\n=== Gestión de Médicos ===\n";
        cout << "1. Agregar médico\n";
        cout << "2. Modificar médico\n";
        cout << "3. Mostrar médicos\n";
        cout << "4. Listar médicos por especialidad\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            string nombre, especialidad;
            cout << "Ingrese nombre del médico: "; cin >> nombre;
            cout << "Ingrese especialidad: "; cin >> especialidad;
            int id = medicos.size() + 1;
            medicos.emplace_back(id, nombre, especialidad);
            cout << "Médico agregado con éxito.\n";
        }
        else if (opcion == '2') {
            int id;
            cout << "Ingrese ID del médico a modificar: ";
            cin >> id;
            for (auto& medico : medicos) {
                if (medico.getID() == id) {
                    string nuevoNombre, nuevaEspecialidad;
                    cout << "Ingrese nuevo nombre: "; cin >> nuevoNombre;
                    cout << "Ingrese nueva especialidad: "; cin >> nuevaEspecialidad;
                    medico.modificarDatos(nuevoNombre, nuevaEspecialidad);
                    cout << "Médico actualizado con éxito.\n";
                }
            }
        }
        else if (opcion == '3') {
            for (const auto& medico : medicos) {
                medico.mostrarInfo();
            }
        }
        else if (opcion == '4') {
            string especialidad;
            cout << "Ingrese especialidad a listar: "; cin >> especialidad;
            listarMedicosPorEspecialidad(medicos, especialidad);
        }
    } while (opcion != '5');
}