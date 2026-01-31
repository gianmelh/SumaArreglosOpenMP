/*********************************************************
 * Nombre: Gianmel Joannelly Hernández Tosta
 * Matrícula: A01795919
 * Materia: Cómputo en la Nube
 * Actividad: Tarea 1 - Programación de una solución paralela
 * Descripción:
 *   Programa que realiza la suma de dos arreglos utilizando
 *   programación paralela con la librería OpenMP.
 *********************************************************/

 // ==============================
// Inclusión de librerías
// ==============================

// Librería estándar para entrada y salida
#include <iostream>

// Librería para habilitar programación paralela con OpenMP
#include <omp.h>

// Librerías para generación de números pseudoaleatorios
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // ==============================
    // 1. Creación de los arreglos
    // ==============================
    // Se define el tamaño de los arreglos
    const int N = 1000;

    // Declaración de tres arreglos:
    // A y B: arreglos de entrada
    // C: arreglo que almacenará la suma
    int A[N], B[N], C[N];

    // ==============================
    // 2. Generación de información
    // ==============================
    // Inicializa la semilla del generador de números pseudoaleatorios
    // usando el tiempo actual del sistema.
    // Esto permite que los valores generados sean diferentes
    // en cada ejecución del programa.
    srand(time(NULL));

    // Se llenan los arreglos A y B con valores aleatorios
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;   // Valores entre 0 y 99
        B[i] = rand() % 100;
    }

    // ==============================
    // 3. For paralelo con OpenMP
    // ==============================
    // Cada iteración del ciclo realiza una suma independiente,
    // por lo que el trabajo puede dividirse entre varios hilos.
    // OpenMP distribuye automáticamente las iteraciones
    // entre los núcleos disponibles del procesador.
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    // ==============================
    // 4. Impresión de resultados
    // ==============================
    // Se muestran los primeros 10 elementos de los arreglos
    // para verificar que la suma se realizó correctamente.
    cout << "Primeros 10 valores del resultado:\n";

    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i]
             << " + B[" << i << "] = " << B[i]
             << " -> C[" << i << "] = " << C[i] << endl;
    }

    // Fin del programa
    return 0;
}
