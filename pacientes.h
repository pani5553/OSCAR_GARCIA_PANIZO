#ifndef PACIENTES_H
#define PACIENTES_H

#include <string>
using namespace std;

class Paciente {
public:
    int ID_paciente;
    string nombre;

    // Constructor
    Paciente(int id, const string& nombre);

    // M�todos
    void mostrarInfo() const;
};

#endif
