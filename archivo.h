#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
#include <vector>
#include <string>
using namespace std;

// Funciones para gestionar archivos
void guardarPacientesEnArchivo(const vector<Paciente>& pacientes, const string& nombreArchivo);
void cargarPacientesDesdeArchivo(vector<Paciente>& pacientes, const string& nombreArchivo);
void guardarMedicosEnArchivo(const vector<Medico>& medicos, const string& nombreArchivo);
void cargarMedicosDesdeArchivo(vector<Medico>& medicos, const string& nombreArchivo);
void guardarCitasEnArchivo(const vector<CitaMedica>& citas, const string& nombreArchivo);
void cargarCitasDesdeArchivo(vector<CitaMedica>& citas, const string& nombreArchivo);

#endif // ARCHIVO_H
