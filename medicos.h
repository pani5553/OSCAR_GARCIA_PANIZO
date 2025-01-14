// Archivo: medicos.h
#ifndef MEDICOS_H
#define MEDICOS_H

#include <string>
using namespace std;

class Medico {
public:
    int ID_medico;
    string nombre;
    string especialidad;

    // Constructor
    Medico(int id = 0, const string& nombre = "", const string& especialidad = "");

    // Métodos
    void mostrarInfo() const;
};

#endif // MEDICOS_H