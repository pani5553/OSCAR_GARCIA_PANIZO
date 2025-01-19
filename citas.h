#ifndef CITAS_H
#define CITAS_H

#include <string>
#include <vector>
using namespace std;

class CitaMedica {
public:
    string fecha;
    int ID_paciente;
    int ID_medico;

    // Constructor
    CitaMedica(const string& fecha = "", int idPaciente = 0, int idMedico = 0);

    // Métodos
    void mostrarCita() const;
    void cancelarCita();
};

// Funciones auxiliares
void menuCitas(vector<CitaMedica>& citas);
void guardarCitasEnArchivo(const vector<CitaMedica>& citas, const string& nombreArchivo);
void cargarCitasDesdeArchivo(vector<CitaMedica>& citas, const string& nombreArchivo);

#endif // CITAS_H