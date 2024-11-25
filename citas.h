#ifndef CITAS_H
#define CITAS_H

#include <string>
using namespace std;

class CitaMedica {
public:
    string fecha;
    int ID_paciente;
    int ID_medico;

    // Constructor
    CitaMedica(const string& fecha, int idPaciente, int idMedico);

    // Métodos
    void mostrarCita() const;
    void cancelarCita();
};

#endif
