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
        cout << "\n========== MENU ==========\n";
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

// Función para registrar la cantidad, nombres y notas de los estudiantes
int registrarEstudiantes(string nombres[], float notas[]) {
    int cantidad;
    
    // Validación de la cantidad de estudiantes (1 a 20)
    do {
        cout << "\nIngrese la cantidad de estudiantes (1-20): ";
        cin >> cantidad;
        if (cantidad < 1 || cantidad > 20) {
            cout << "Error: La cantidad debe estar entre 1 y 20.\n";
        }
    } while (cantidad < 1 || cantidad > 20);

    // Ingreso y validación de datos para cada estudiante
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

// Función para procesar y mostrar el reporte completo
void mostrarReporte(string nombres[], float notas[], int cantidad) {
    float sumaNotas = 0;
    int aprobados = 0;
    int reprobados = 0;
    
    float notaMayor = -1; // Inicializada por debajo del mínimo posible
    float notaMenor = 21; // Inicializada por encima del máximo posible
    string estudianteMayor = "";
    string estudianteMenor = "";

    cout << "\n--- REPORTE GENERAL ---\n";
    
    // Recorrido único para imprimir listado y calcular métricas
    for (int i = 0; i < cantidad; i++) {
        string estado = (notas[i] >= 14) ? "APROBADO" : "REPROBADO";
        
        // Listado numerado
        cout << (i + 1) << ". Nombre: " << nombres[i] << " | Nota: " << notas[i] << " | Estado: " << estado << "\n";
        
        // Acumulador para el promedio
        sumaNotas += notas[i];
        
        // Contadores de estado
        if (notas[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }
        
        // Determinación de nota mayor (guarda la primera coincidencia por usar '>')
        if (notas[i] > notaMayor) {
            notaMayor = notas[i];
            estudianteMayor = nombres[i];
        }
        
        // Determinación de nota menor (guarda la primera coincidencia por usar '<')
        if (notas[i] < notaMenor) {
            notaMenor = notas[i];
            estudianteMenor = nombres[i];
        }
    }
    
    // Cálculo e impresión de los resultados consolidados
    float promedio = sumaNotas / cantidad;
    cout << "\nPromedio general del curso: " << promedio << "\n";
    cout << "Estudiante con la nota mayor: " << estudianteMayor << " (" << notaMayor << ")\n";
    cout << "Estudiante con la nota menor: " << estudianteMenor << " (" << notaMenor << ")\n";
    cout << "Total de estudiantes APROBADOS: " << aprobados << "\n";
    cout << "Total de estudiantes REPROBADOS: " << reprobados << "\n";
}

// Función para realizar una búsqueda secuencial exacta
void buscarEstudiante(string nombres[], float notas[], int cantidad) {
    string nombreBuscado;
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscado;

    // Búsqueda secuencial
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombreBuscado) {
            string estado = (notas[i] >= 14) ? "APROBADO" : "REPROBADO";
            cout << "\n--- RESULTADO DE BUSQUEDA ---\n";
            cout << "Nombre: " << nombres[i] << "\n";
            cout << "Nota: " << notas[i] << "\n";
            cout << "Estado: " << estado << "\n";
            return; // Finaliza en la primera coincidencia exacta
        }
    }
    
    // Si el bucle termina sin un 'return', el estudiante no existe
    cout << "\nEl estudiante '" << nombreBuscado << "' no se encuentra registrado en el sistema.\n";
}

int main() {
    // Arreglos paralelos de tamaño máximo 20 según requerimientos
    string nombres[20];
    float notas[20];
    
    int cantidadActual = 0; // Controla cuántos datos válidos existen
    int opcionSeleccionada;

    do {
        opcionSeleccionada = mostrarMenu();

        switch (opcionSeleccionada) {
            case 1:
                cantidadActual = registrarEstudiantes(nombres, notas);
                break;
                
            case 2:
                // Control obligatorio de datos vacíos
                if (cantidadActual == 0) {
                    cout << "\nError: Todavia no existen datos en el sistema. Registre estudiantes primero.\n";
                } else {
                    mostrarReporte(nombres, notas, cantidadActual);
                }
                break;
                
            case 3:
                // Control obligatorio de datos vacíos
                if (cantidadActual == 0) {
                    cout << "\nError: Todavia no existen datos en el sistema. Registre estudiantes primero.\n";
                } else {
                    buscarEstudiante(nombres, notas, cantidadActual);
                }
                break;
                
            case 4:
                cout << "\nFinalizando el programa de forma segura...\n";
                break;
        }
    } while (opcionSeleccionada != 4);

    return 0;
}
