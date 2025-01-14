// Archivo: medicos.cpp
#include "medicos.h"
#include <iostream>
using namespace std;

// Constructor
Medico::Medico(int id, const string& nombre, const string& especialidad)
    : ID_medico(id), nombre(nombre), especialidad(especialidad) {
}

// Métodos
void Medico::mostrarInfo() const {
    cout << "ID Médico: " << ID_medico << ", Nombre: " << nombre
        << ", Especialidad: " << especialidad << endl;
}
