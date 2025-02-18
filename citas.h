#ifndef CITAS_H
#define CITAS_H

#include "MInformacion.h"
#include <string>
#include <vector>
using namespace std;

enum EstadoCita { ACTIVO, CANCELADO, COMPLETADO };

class CitaMedica : public MInformacion {
protected:
    string fecha;
    int ID_paciente;
    int ID_medico;
    EstadoCita estado;

public:
    CitaMedica(const string& fecha = "", int idPaciente = 0, int idMedico = 0, EstadoCita estado = ACTIVO);
    void mostrarInfo() const override;
    void modificarCita(const string& nuevaFecha, int nuevoIDMedico);
    void cambiarEstado(EstadoCita nuevoEstado);

    string getFecha() const;
    int getIDPaciente() const;
    int getIDMedico() const;
    EstadoCita getEstado() const;
};

void filtrarCitasPorFecha(const vector<CitaMedica>& citas, const string& fecha);
void filtrarCitasPorPaciente(const vector<CitaMedica>& citas, int idPaciente);
void filtrarCitasPorMedico(const vector<CitaMedica>& citas, int idMedico);
void menuCitas(vector<CitaMedica>& citas);

#endif // CITAS_H