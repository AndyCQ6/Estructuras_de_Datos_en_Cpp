// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 5: Cola (Queue) — principio FIFO
//             Operaciones básicas y complementarias
// ============================================================

#include <iostream>
using namespace std;

// ---- Estructura del nodo ------------------------------------
struct nodo {
    int valor;
    nodo* siguiente;
};

// ---- Clase Cola ---------------------------------------------
class Cola {
private:
    nodo* frente;
    nodo* final;

public:
    Cola() {
        frente = nullptr;
        final  = nullptr;
    }

    ~Cola() {
        while (frente != nullptr)
            desencolar();
    }

    // ========================================================
    //  OPERACIONES BÁSICAS
    // ========================================================

    // Encolar (Enqueue) — insertar al final
    void encolar(int valor) {
        nodo* nuevo = new nodo();
        nuevo->valor = valor;
        nuevo->siguiente = nullptr;

        if (final == nullptr) {
            frente = nuevo;
            final  = nuevo;
            return;
        }
        final->siguiente = nuevo;
        final = nuevo;
    }

    // Desencolar (Dequeue) — eliminar al frente
    void desencolar() {
        if (frente == nullptr) {
            cout << "La cola esta vacia." << endl;
            return;
        }
        nodo* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr)
            final = nullptr;
        delete temp;
    }

    // Mostrar la cola
    void mostrar() {
        if (frente == nullptr) {
            cout << "La cola esta vacia." << endl;
            return;
        }
        nodo* temp = frente;
        while (temp != nullptr) {
            cout << temp->valor << " -> ";
            temp = temp->siguiente;
        }
        cout << "nullptr" << endl;
    }

    // ========================================================
    //  OPERACIONES COMPLEMENTARIAS
    // ========================================================

    // Consultar el frente sin eliminar (Peek)
    int verFrente() {
        if (frente == nullptr) {
            cout << "La cola esta vacia." << endl;
            return -1;
        }
        return frente->valor;
    }

    // Verificar si está vacía
    bool estaVacia() {
        return frente == nullptr;
    }

    // Contar elementos
    int contarElementos() {
        int contador = 0;
        nodo* temp = frente;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        cout << "Total de elementos: " << contador << endl;
        return contador;
    }

    // Buscar un elemento
    bool buscar(int valor) {
        nodo* temp = frente;
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
};

// ---- main ---------------------------------------------------
int main() {
    Cola cola;
    int opcion, valor;

    do {
        cout << "\n=== COLA (FIFO) ===" << endl;
        cout << "1. Encolar (insertar al final)" << endl;
        cout << "2. Desencolar (eliminar al frente)" << endl;
        cout << "3. Ver frente (peek)" << endl;
        cout << "4. Mostrar cola" << endl;
        cout << "5. Contar elementos" << endl;
        cout << "6. Buscar elemento" << endl;
        cout << "7. Esta vacia?" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a encolar: "; cin >> valor;
                cola.encolar(valor);
                break;
            case 2:
                cola.desencolar();
                break;
            case 3:
                valor = cola.verFrente();
                if (valor != -1)
                    cout << "Frente: " << valor << endl;
                break;
            case 4:
                cola.mostrar();
                break;
            case 5:
                cola.contarElementos();
                break;
            case 6:
                cout << "Valor a buscar: "; cin >> valor;
                cola.buscar(valor);
                break;
            case 7:
                cout << (cola.estaVacia() ? "La cola esta vacia." : "La cola NO esta vacia.") << endl;
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
