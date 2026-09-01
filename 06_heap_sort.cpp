// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 2: Método por montículos (Heap Sort)
// ============================================================

#include <iostream>
#include <vector>
using namespace std;

/*
 Función «heapify»
 Mantiene la propiedad del Max Heap:
 cada nodo padre es mayor o igual que sus hijos.

 Parámetros:
   arr -> arreglo que representa el árbol
   n   -> tamaño del heap (se va reduciendo en fase 2)
   i   -> índice del nodo a revisar
*/
void heapify(vector<int>& arr, int n, int i) {
    int mayor = i;          // Asumimos que el nodo actual es el mayor
    int izq = 2 * i + 1;   // Hijo izquierdo
    int der = 2 * i + 2;   // Hijo derecho

    // ¿El hijo izquierdo existe y es mayor que el nodo actual?
    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;

    // ¿El hijo derecho existe y es mayor que el mayor actual?
    if (der < n && arr[der] > arr[mayor])
        mayor = der;

    // Si el mayor ya no es el nodo original, intercambiamos
    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        // Llamada recursiva para restaurar el heap en el subárbol afectado
        heapify(arr, n, mayor);
    }
}

/*
 Función «heapSort»
 Fase 1: Construye el Max Heap desde el arreglo.
 Fase 2: Extrae el mayor repetidamente y lo coloca al final.
*/
void heapSort(vector<int>& arr, int n) {
    // FASE 1: Construir el Max Heap
    // Empezamos desde el último nodo con hijos (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // FASE 2: Extraer elementos uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Movemos la raíz (mayor elemento) al final
        swap(arr[0], arr[i]);
        // Restauramos el heap sobre el tamaño reducido
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Arreglo original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Arreglo ordenado: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Salida esperada: 1 5 7 8 9 10

    return 0;
}
