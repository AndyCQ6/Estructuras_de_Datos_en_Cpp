// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 2: Método rápido (Quick Sort)
// ============================================================

#include <iostream>
#include <vector>
using namespace std;

/*
 Función «partition»
 Reorganiza el arreglo alrededor de un pivote (último elemento).
 Todos los menores quedan a la izquierda, los mayores a la derecha.
 Devuelve la posición final del pivote.
*/
int partition(vector<int>& arr, int low, int high) {
    // Elegimos el último elemento como pivote
    int pivot = arr[high];

    // i indica la posición del último elemento menor que el pivote
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Agrupamos menores a la izquierda
        }
    }

    // Colocamos el pivote en su posición correcta
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

/*
 Función «quickSort»
 1. Elige un pivote
 2. Particiona el arreglo
 3. Aplica quickSort recursivamente a los subarreglos
*/
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);   // Subarreglo izquierdo
        quickSort(arr, pi + 1, high);  // Subarreglo derecho
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Arreglo original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Salida esperada: 1 5 7 8 9 10

    return 0;
}
