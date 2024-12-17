#include "pacientes.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
Paciente::Paciente(int id, const string& nombre) : ID_paciente(id), nombre(nombre) {}

// Mostrar información
void Paciente::mostrarInfo() const {
    cout << "ID: " << ID_paciente << ", Nombre: " << nombre << endl;
}

// Guardar en archivo
void Paciente::guardarEnArchivo(ofstream& archivo) const {
    archivo << ID_paciente << " " << nombre << endl;
}

// Cargar desde archivo
Paciente Paciente::cargarDesdeArchivo(ifstream& archivo) {
    int id;
    string nombre;
    archivo >> id;
    archivo.ignore();
    getline(archivo, nombre);
    return Paciente(id, nombre);
}
