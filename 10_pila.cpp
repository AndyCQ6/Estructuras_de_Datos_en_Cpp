// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 6: Pila (Stack) — principio LIFO
//             Operaciones básicas y complementarias
// ============================================================

#include <iostream>
using namespace std;

// ---- Estructura del nodo ------------------------------------
struct nodo {
    int valor;
    nodo* siguiente;
};

// ---- Clase Pila ---------------------------------------------
class Pila {
private:
    nodo* tope;

public:
    Pila() {
        tope = nullptr;
    }

    ~Pila() {
        vaciar();
    }

    // ========================================================
    //  OPERACIONES BÁSICAS
    // ========================================================

    // Apilar (Push) — insertar en el tope
    void apilar(int valor) {
        nodo* nuevo = new nodo();
        nuevo->valor = valor;
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    // Desapilar (Pop) — eliminar del tope
    void desapilar() {
        if (tope == nullptr) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }

    // Mostrar la pila
    void mostrar() {
        if (tope == nullptr) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        nodo* temp = tope;
        while (temp != nullptr) {
            cout << temp->valor << " -> ";
            temp = temp->siguiente;
        }
        cout << "nullptr" << endl;
    }

    // ========================================================
    //  OPERACIONES COMPLEMENTARIAS
    // ========================================================

    // Consultar el tope sin eliminar (Peek)
    int verTope() {
        if (tope == nullptr) {
            cout << "La pila esta vacia." << endl;
            return -1;
        }
        return tope->valor;
    }

    // Verificar si está vacía
    bool estaVacia() {
        return tope == nullptr;
    }

    // Contar elementos
    int contarElementos() {
        int contador = 0;
        nodo* temp = tope;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        cout << "Total de elementos: " << contador << endl;
        return contador;
    }

    // Buscar un elemento
    bool buscar(int valor) {
        nodo* temp = tope;
        while (temp != nullptr) {
            if (temp->valor == valor) {
                cout << "Elemento " << valor << " encontrado." << endl;
                return true;
            }
            temp = temp->siguiente;
        }
        cout << "Elemento " << valor << " no encontrado." << endl;
        return false;
    }

    // Vaciar la pila
    void vaciar() {
        while (tope != nullptr)
            desapilar();
        cout << "Pila vaciada." << endl;
    }
};

// ---- main ---------------------------------------------------
int main() {
    Pila pila;
    int opcion, valor;

    do {
        cout << "\n=== PILA (LIFO) ===" << endl;
        cout << "1. Apilar (push)" << endl;
        cout << "2. Desapilar (pop)" << endl;
        cout << "3. Ver tope (peek)" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Contar elementos" << endl;
        cout << "6. Buscar elemento" << endl;
        cout << "7. Vaciar pila" << endl;
        cout << "8. Esta vacia?" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a apilar: "; cin >> valor;
                pila.apilar(valor);
                break;
            case 2:
                pila.desapilar();
                break;
            case 3:
                valor = pila.verTope();
                if (valor != -1)
                    cout << "Tope: " << valor << endl;
                break;
            case 4:
                pila.mostrar();
                break;
            case 5:
                pila.contarElementos();
                break;
            case 6:
                cout << "Valor a buscar: "; cin >> valor;
                pila.buscar(valor);
                break;
            case 7:
                pila.vaciar();
                break;
            case 8:
                cout << (pila.estaVacia() ? "La pila esta vacia." : "La pila NO esta vacia.") << endl;
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
