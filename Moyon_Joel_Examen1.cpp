/*
Nombre del estudiante: Joel Moyón
Fecha: 29/07/2026
Tema: Sistema de registro y análisis de notas
Entrada: cantidad, nombres, notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda
*/

#include <iostream>
#include <string>

using namespace std;

// Función para mostrar el menú y validar la opción ingresada
int mostrarMenu() {
    int opcion;
    do {
        cout << "\n         MENU        \n";
        cout << "1. Registrar estudiantes y notas\n";
        cout << "2. Mostrar reporte general\n";
        cout << "3. Buscar estudiante por nombre\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (opcion < 1 || opcion > 4) {
            cout << "Opcion invalida. Por favor, ingrese un numero entre 1 y 4.\n";
        }
    } while (opcion < 1 || opcion > 4);
    
    return opcion;
}

int registrarEstudiantes(string nombres[], float notas[]) {
    int cantidad;
    do {
        cout << "\nIngrese la cantidad de estudiantes (1-20): ";
        cin >> cantidad;
        if (cantidad < 1 || cantidad > 20) {
            cout << "Error: La cantidad debe estar entre 1 y 20.\n";
        }
    } while (cantidad < 1 || cantidad > 20);

    for (int i = 0; i < cantidad; i++) {
        cout << "\nIngrese el primer nombre del estudiante " << (i + 1) << " (sin espacios): ";
        cin >> nombres[i];
        do {
            cout << "Ingrese la nota final de " << nombres[i] << " (0-20): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 20) {
                cout << "Error: La nota debe estar entre 0 y 20.\n";
            }
        } while (notas[i] < 0 || notas[i] > 20);
    }
    cout << "\nDatos registrados exitosamente.\n";
    return cantidad;
}

int main() {
    
    string nombres[20];
    float notas[20];
    
    int cantidadActual = 0;
    int opcionSeleccionada;

    do {
        opcionSeleccionada = mostrarMenu();

        switch (opcionSeleccionada) {
            case 1:
                cout << "\n[Registro en construccion...]\n";
                // En el siguiente paso aquí llamaremos a la función de registro
                break;
                
            case 2:
                // Control obligatorio: validar que existan datos
                if (cantidadActual == 0) {
                    cout << "\nError: Todavia no existen datos en el sistema. Registre estudiantes primero.\n";
                } else {
                    cout << "\n[Reporte en construccion...]\n";
                }
                break;
                
            case 3:
                // Control obligatorio: validar que existan datos
                if (cantidadActual == 0) {
                    cout << "\nError: Todavia no existen datos en el sistema. Registre estudiantes primero.\n";
                } else {
                    cout << "\n[Busqueda en construccion...]\n";
                }
                break;
                
            case 4:
                cout << "\nFinalizando el programa de forma controlada...\n";
                break;
        }
    } while (opcionSeleccionada != 4);

    return 0;
}
