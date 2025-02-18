#include "medicos.h"
#include <iostream>
using namespace std;

// Constructor
Medico::Medico(int id, const string& nombre, const string& especialidad)
    : ID_medico(id), nombre(nombre), especialidad(especialidad) {
}

// Mostrar informaci�n
void Medico::mostrarInfo() const {
    cout << "ID M�dico: " << ID_medico << " | Nombre: " << nombre << " | Especialidad: " << especialidad << endl;
}

// Modificar datos
void Medico::modificarDatos(const string& nuevoNombre, const string& nuevaEspecialidad) {
    if (!nuevoNombre.empty()) nombre = nuevoNombre;
    if (!nuevaEspecialidad.empty()) especialidad = nuevaEspecialidad;
    cout << "Datos del m�dico actualizados con �xito." << endl;
}

// Obtener atributos
int Medico::getID() const { return ID_medico; }
string Medico::getNombre() const { return nombre; }
string Medico::getEspecialidad() const { return especialidad; }

// Listar m�dicos por especialidad
void listarMedicosPorEspecialidad(const vector<Medico>& medicos, const string& especialidad) {
    cout << "\nM�dicos con especialidad en " << especialidad << ":\n";
    bool encontrado = false;
    for (const auto& medico : medicos) {
        if (medico.getEspecialidad() == especialidad) {
            medico.mostrarInfo();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay m�dicos registrados en esta especialidad." << endl;
    }
}

// Men� de gesti�n de m�dicos
void menuMedicos(vector<Medico>& medicos) {
    char opcion;
    do {
        cout << "\n=== Gesti�n de M�dicos ===\n";
        cout << "1. Agregar m�dico\n";
        cout << "2. Modificar m�dico\n";
        cout << "3. Mostrar m�dicos\n";
        cout << "4. Listar m�dicos por especialidad\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        if (opcion == '1') {
            string nombre, especialidad;
            cout << "Ingrese nombre del m�dico: "; cin >> nombre;
            cout << "Ingrese especialidad: "; cin >> especialidad;
            int id = medicos.size() + 1;
            medicos.emplace_back(id, nombre, especialidad);
            cout << "M�dico agregado con �xito.\n";
        }
        else if (opcion == '2') {
            int id;
            cout << "Ingrese ID del m�dico a modificar: ";
            cin >> id;
            for (auto& medico : medicos) {
                if (medico.getID() == id) {
                    string nuevoNombre, nuevaEspecialidad;
                    cout << "Ingrese nuevo nombre: "; cin >> nuevoNombre;
                    cout << "Ingrese nueva especialidad: "; cin >> nuevaEspecialidad;
                    medico.modificarDatos(nuevoNombre, nuevaEspecialidad);
                    cout << "M�dico actualizado con �xito.\n";
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