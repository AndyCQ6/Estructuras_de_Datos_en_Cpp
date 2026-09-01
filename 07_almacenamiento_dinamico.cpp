// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 3: Almacenamiento dinámico
//             Punteros, new, delete, arreglos dinámicos
// ============================================================

#include <iostream>
using namespace std;

int main() {
    // ---- 1. Puntero básico y desreferenciación ----
    int x = 5;
    int* p = &x;

    cout << "=== Puntero basico ===" << endl;
    cout << "Direccion de x: " << p << endl;
    cout << "Valor de x via puntero: " << *p << endl;

    // ---- 2. Operador new y delete ----
    cout << "\n=== new y delete ===" << endl;
    int* q = new int(42);
    cout << "Valor reservado con new: " << *q << endl;
    delete q;
    q = nullptr; // Buena práctica: evitar puntero colgante

    // ---- 3. Arreglo dinámico con new[] y delete[] ----
    cout << "\n=== Arreglo dinamico ===" << endl;
    int n = 5;
    int* arreglo = new int[n];

    for (int i = 0; i < n; i++)
        arreglo[i] = i * 2;

    cout << "Contenido: ";
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
    // Salida esperada: 0 2 4 6 8

    delete[] arreglo;
    arreglo = nullptr;

    // ---- 4. Tamaño definido en tiempo de ejecución ----
    cout << "\n=== Tamanio en tiempo de ejecucion ===" << endl;
    cout << "¿Cuantos elementos? ";
    cin >> n;

    int* datos = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> datos[i];
    }

    cout << "Ingresaste: ";
    for (int i = 0; i < n; i++)
        cout << datos[i] << " ";
    cout << endl;

    delete[] datos;

    return 0;
}
