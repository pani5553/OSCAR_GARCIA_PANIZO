#ifndef PACIENTES_H
#define PACIENTES_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Paciente {
public:
    int ID_paciente;
    string nombre;
    string dni;
    string fechaNacimiento;
    string sexo;
    string direccion;
    string telefono;
    string correo;
    string grupoSanguineo;
    string historialMedico;

    // Constructor de pacientes
    Paciente(int id = 0, const string& nombre = "", const string& dni = "", const string& fechaNacimiento = "",
        const string& sexo = "", const string& direccion = "", const string& telefono = "",
        const string& correo = "", const string& grupoSanguineo = "", const string& historialMedico = "");

    
    void mostrarInfo() const;
    void guardarEnArchivo(ofstream& archivo) const;
    static Paciente cargarDesdeArchivo(ifstream& archivo);
};

// Funciones del txt
void agregarPaciente(vector<Paciente>& pacientes);
void mostrarPacientes(const vector<Paciente>& pacientes);
void guardarPacientesEnArchivo(const vector<Paciente>& pacientes, const string& nombreArchivo);
void cargarPacientesDesdeArchivo(vector<Paciente>& pacientes, const string& nombreArchivo);
void buscarPacientePorDNI(const vector<Paciente>& pacientes);
void menuPacientes(vector<Paciente>& pacientes);

#endif // PACIENTES_H