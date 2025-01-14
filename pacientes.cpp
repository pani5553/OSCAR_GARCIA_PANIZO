#include "pacientes.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor
Paciente::Paciente(int id, const string& nombre, const string& dni, const string& fechaNacimiento, const string& sexo,
    const string& direccion, const string& telefono, const string& correo, const string& grupoSanguineo,
    const string& historialMedico)
    : ID_paciente(id), nombre(nombre), dni(dni), fechaNacimiento(fechaNacimiento), sexo(sexo), direccion(direccion),
    telefono(telefono), correo(correo), grupoSanguineo(grupoSanguineo), historialMedico(historialMedico) {
}

// Mostrar información
void Paciente::mostrarInfo() const {
    cout << "ID Paciente: " << ID_paciente << "\n"
        << "Nombre: " << nombre << "\n"
        << "DNI/NIE: " << dni << "\n"
        << "Fecha de nacimiento: " << fechaNacimiento << "\n"
        << "Sexo: " << sexo << "\n"
        << "Dirección: " << direccion << "\n"
        << "Teléfono: " << telefono << "\n"
        << "Correo electrónico: " << correo << "\n"
        << "Grupo sanguíneo: " << grupoSanguineo << "\n"
        << "Historial médico: " << historialMedico << "\n";
}

// Guardar paciente en archivo
void Paciente::guardarEnArchivo(ofstream& archivo) const {
    archivo << ID_paciente << " " << nombre << " " << dni << " " << fechaNacimiento << " " << sexo << " "
        << direccion << " " << telefono << " " << correo << " " << grupoSanguineo << " " << historialMedico << endl;
}

// Cargar paciente desde archivo
Paciente Paciente::cargarDesdeArchivo(ifstream& archivo) {
    int id;
    string nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico;
    archivo >> id;
    archivo >> nombre >> dni >> fechaNacimiento >> sexo >> direccion >> telefono >> correo >> grupoSanguineo >> historialMedico;
    return Paciente(id, nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico);
}

// Funciones auxiliares
void agregarPaciente(vector<Paciente>& pacientes) {
    int id;
    string nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico;

    cout << "\n=== Agregar Paciente ===\n";
    cout << "Ingrese el ID del paciente: ";
    cin >> id;

    cout << "Ingrese el nombre del paciente: ";
    cin >> nombre;

    cout << "Ingrese el DNI/NIE del paciente: ";
    cin >> dni;

    cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    cin >> fechaNacimiento;

    cout << "Ingrese el sexo (M/F): ";
    cin >> sexo;

    cout << "Ingrese la dirección: ";
    cin >> direccion;

    cout << "Ingrese el teléfono: ";
    cin >> telefono;

    cout << "Ingrese el correo electrónico: ";
    cin >> correo;

    cout << "Ingrese el grupo sanguíneo: ";
    cin >> grupoSanguineo;

    cout << "Ingrese el historial médico: ";
    cin >> historialMedico;

    pacientes.emplace_back(id, nombre, dni, fechaNacimiento, sexo, direccion, telefono, correo, grupoSanguineo, historialMedico);

    cout << "Paciente agregado con éxito.\n";
}

void buscarPacientePorDNI(const vector<Paciente>& pacientes) {
    string dniBuscado;
    cout << "\n=== Buscar Paciente por DNI/NIE ===\n";
    cout << "Ingrese el DNI/NIE del paciente: ";
    cin >> dniBuscado;

    bool encontrado = false;
    for (const auto& paciente : pacientes) {
        if (paciente.dni == dniBuscado) {
            cout << "\nPaciente encontrado:\n";
            paciente.mostrarInfo();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Paciente con DNI/NIE " << dniBuscado << " no encontrado.\n";
    }
}

void mostrarPacientes(const vector<Paciente>& pacientes) {
    cout << "\n=== Lista de Pacientes ===\n";
    for (const auto& paciente : pacientes) {
        paciente.mostrarInfo();
    }
}

void guardarPacientesEnArchivo(const vector<Paciente>& pacientes, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& paciente : pacientes) {
        paciente.guardarEnArchivo(archivo);
    }
    cout << "Datos guardados correctamente.\n";
}

void cargarPacientesDesdeArchivo(vector<Paciente>& pacientes, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo para cargar.\n";
        return;
    }

    while (archivo) {
        Paciente paciente = Paciente::cargarDesdeArchivo(archivo);
        if (archivo) {
            pacientes.push_back(paciente);
        }
    }
    cout << "Pacientes cargados correctamente.\n";
}

void menuPacientes(vector<Paciente>& pacientes) {
    char opcion;
    do {
        cout << "\n=== Gestión de Pacientes ===\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Mostrar todos los pacientes\n";
        cout << "3. Guardar pacientes en archivo\n";
        cout << "4. Buscar paciente por DNI/NIE\n";
        cout << "5. Salir del menú de pacientes\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            agregarPaciente(pacientes);
            break;
        case '2':
            mostrarPacientes(pacientes);
            break;
        case '3':
            guardarPacientesEnArchivo(pacientes, "pacientes.txt");
            break;
        case '4':
            buscarPacientePorDNI(pacientes);
            break;
        case '5':
            cout << "Saliendo del menú de pacientes...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != '5');
}
