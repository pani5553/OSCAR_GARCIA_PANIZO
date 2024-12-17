#ifndef PACIENTES_H
#define PACIENTES_H

#include <string>
#include <fstream>
using namespace std;

class Paciente {
public:
    int ID_paciente;
    string nombre;

    // Constructor
    Paciente(int id = 0, const string& nombre = "");

    // Mostrar información
    void mostrarInfo() const;

    // Guardar
    void guardarEnArchivo(ofstream& archivo) const;

    // Cargar
    static Paciente cargarDesdeArchivo(ifstream& archivo);
};

#endif // PACIENTES_H
