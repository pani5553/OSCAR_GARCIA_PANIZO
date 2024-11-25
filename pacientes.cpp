#include "pacientes.h"
#include <iostream>
using namespace std;

// Constructor
Paciente::Paciente(int id, const string& nombre)
    : ID_paciente(id), nombre(nombre) {}

// Mostrar información del paciente
void Paciente::mostrarInfo() const {
    cout << "ID Paciente: " << ID_paciente << ", Nombre: " << nombre << endl;
}
