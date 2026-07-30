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
        cout << "\n      MENU       \n";
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

