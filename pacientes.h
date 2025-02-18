
#ifndef PACIENTES_H
#define PACIENTES_H

#include "MInformacion.h"
#include <string>
#include <vector>
using namespace std;

class Paciente : public MInformacion {
protected:
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

public:
    Paciente(int id = 0, const string& nombre = "", const string& dni = "", const string& fechaNacimiento = "",
        const string& sexo = "", const string& direccion = "", const string& telefono = "",
        const string& correo = "", const string& grupoSanguineo = "", const string& historialMedico = "");

    void mostrarInfo() const override;
    void modificarDatos(const string& nuevoNombre, const string& nuevoDNI, const string& nuevaDireccion,
        const string& nuevoTelefono, const string& nuevoCorreo);
    int getID() const;
    string getDNI() const;
    string getNombre() const;
    string getFechaNacimiento() const;
    string getSexo() const;
    string getDireccion() const;
    string getTelefono() const;
    string getCorreo() const;
    string getGrupoSanguineo() const;
    string getHistorialMedico() const;
};

void menuPacientes(vector<Paciente>& pacientes);

#endif // PACIENTES_H