// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 2: Método de mezcla (Merge Sort)
// ============================================================

#include <iostream>
#include <vector>
using namespace std;

/*
 Función «merge»
 Combina dos subarreglos ordenados en un solo subarreglo ordenado.
*/
void merge(vector<int>& arr, int left, int mid, int right) {
    // Calculamos el tamaño de cada mitad
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Vectores temporales para cada mitad
    vector<int> L(n1), R(n2);

    // Copiamos los datos
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Índices: i->L, j->R, k->posición en arr
    int i = 0, j = 0, k = left;

    // Comparamos elemento por elemento y colocamos el menor
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiamos los elementos restantes de L (si los hay)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiamos los elementos restantes de R (si los hay)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
 Función «mergeSort»
 1. Divide el arreglo en dos mitades
 2. Aplica mergeSort recursivamente a cada mitad
 3. Combina las mitades ordenadas con merge
*/
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Calculamos el punto medio evitando desbordamiento
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Mitad izquierda
        mergeSort(arr, mid + 1, right);  // Mitad derecha
        merge(arr, left, mid, right);    // Combinamos
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Arreglo original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Salida esperada: 1 5 7 8 9 10

    return 0;
}
