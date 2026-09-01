// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 2: Métodos de ordenamiento iterativos
//             Burbuja, Selección, Inserción
// ============================================================

#include <iostream>
using namespace std;

// ---- Burbuja -----------------------------------------------
void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// ---- Selección ---------------------------------------------
void seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
}

// ---- Inserción ---------------------------------------------
void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

// ---- Utilidad: imprimir arreglo ----------------------------
void imprimirArreglo(int arr[], int n, const string& etiqueta) {
    cout << etiqueta << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---- Utilidad: copiar arreglo ------------------------------
void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origen[i];
}

int main() {
    int original[] = {64, 25, 12, 22, 11};
    int n = 5;
    int arr[5];

    copiarArreglo(original, arr, n);
    burbuja(arr, n);
    imprimirArreglo(arr, n, "Burbuja   ");

    copiarArreglo(original, arr, n);
    seleccion(arr, n);
    imprimirArreglo(arr, n, "Seleccion ");

    copiarArreglo(original, arr, n);
    insercion(arr, n);
    imprimirArreglo(arr, n, "Insercion ");

    return 0;
}
