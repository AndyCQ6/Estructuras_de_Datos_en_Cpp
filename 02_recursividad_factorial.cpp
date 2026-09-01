// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 2: Recursividad - Factorial
// ============================================================

#include <iostream>
using namespace std;

int factorial(int n) {
    // Paso 1: caso base
    if (n == 0) return 1;
    // Paso 2: caso recursivo combinando la solución
    return n * factorial(n - 1); // n decrece hacia 0 (terminación garantizada)
}

int main() {
    int numero;
    cout << "Ingresa un numero entero no negativo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Error: el factorial no esta definido para numeros negativos." << endl;
    } else {
        cout << numero << "! = " << factorial(numero) << endl;
    }

    return 0;
}
