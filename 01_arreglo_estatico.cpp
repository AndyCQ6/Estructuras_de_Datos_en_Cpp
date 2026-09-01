// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 1: Arreglos estáticos
// ============================================================

#include <iostream>
using namespace std;

int main() {
    // Declaramos un arreglo con cinco elementos. Ni más, ni menos.
    int arr[5];

    // Asignamos valores manualmente
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // Mostramos los valores
    cout << "Contenido del arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
