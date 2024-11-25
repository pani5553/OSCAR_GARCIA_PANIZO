#include <iostream>
#include <vector>
#include "citas.h"
using namespace std;
// añadir idioma español, caracteres corruptos !!!!!!!!!!!!!!!!!!!

int main() {
    vector<CitaMedica> citas;

    // Citas !!! Enlazar base de datos !!!!!!!!!!
    citas.emplace_back("2024-12-01", 1, 101);
    citas.emplace_back("2024-12-02", 2, 102);

    char opcion;
    do {
        cout << "\n=== Gestión de Citas ===\n";
        cout << "1. Cancelar una cita\n";
        cout << "2. Mostrar citas\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción:";
        cin >> opcion;

        switch (opcion) {
        case '1': {
            cout << "\nIngrese el índice de la cita a cancelar (0-" << citas.size() - 1 << "): ";
            int indice;
            cin >> indice;

            if (indice >= 0 && indice < citas.size()) {
                citas[indice].cancelarCita();
            }
            else {
                cout << "opcíon no válida.\n";
            }
            break;
        }
        case '2': {
            cout << "\n=== Citas Médicas ===\n";
            for (size_t i = 0; i < citas.size(); ++i) {
                cout << "[" << i << "] ";
                citas[i].mostrarCita();
            }
            break;
        }
        case '3':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != '3');

    return 0;
}
