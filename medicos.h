#ifndef MEDICOS_H
#define MEDICOS_H

#include "MInformacion.h"
#include <string>
#include <vector>
using namespace std;

class Medico : public MInformacion {
protected:
    int ID_medico;
    string nombre;
    string especialidad;

public:
    Medico(int id = 0, const string& nombre = "", const string& especialidad = "");
    void mostrarInfo() const override;
    void modificarDatos(const string& nuevoNombre, const string& nuevaEspecialidad);
    int getID() const;
    string getNombre() const;
    string getEspecialidad() const;
};

void listarMedicosPorEspecialidad(const vector<Medico>& medicos, const string& especialidad);
void menuMedicos(vector<Medico>& medicos);

#endif // MEDICOS_H
