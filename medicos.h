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
    Medico(int id, const string& nombre, const string& especialidad);

    // Métodos
    void mostrarInfo() const;
};

#endif
