// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 4: Lista Ligada (Simply Linked List)
//             Operaciones básicas y complementarias
// ============================================================

#include <iostream>
using namespace std;

// ---- Estructura del nodo ------------------------------------
struct nodo {
    int valor;
    nodo* siguiente;
};

// ---- Clase Lista --------------------------------------------
class Lista {
private:
    nodo* inicial;

public:
    // Constructor
    Lista() {
        inicial = nullptr;
    }

    // Destructor: libera toda la memoria al destruir el objeto
    ~Lista() {
        nodo* temp = inicial;
        while (temp != nullptr) {
            nodo* sig = temp->siguiente;
            delete temp;
            temp = sig;
        }
    }

    // ========================================================
    //  OPERACIONES BÁSICAS
    // ========================================================

    // Insertar al inicio
    void insertarInicio(int valor) {
        nodo* nuevo = new nodo();
        nuevo->valor = valor;
        nuevo->siguiente = inicial;
        inicial = nuevo;
    }

    // Insertar al final
    void insertarFinal(int valor) {
        nodo* nuevo = new nodo();
        nuevo->valor = valor;
        nuevo->siguiente = nullptr;

        if (inicial == nullptr) {
            inicial = nuevo;
            return;
        }

        nodo* temp = inicial;
        while (temp->siguiente != nullptr)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }

    // Eliminar al inicio
    void eliminarInicio() {
        if (inicial == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        nodo* temp = inicial;
        inicial = inicial->siguiente;
        delete temp;
    }

    // Eliminar al final
    void eliminarFinal() {
        if (inicial == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        if (inicial->siguiente == nullptr) {
            delete inicial;
            inicial = nullptr;
            return;
        }
        nodo* temp = inicial;
        while (temp->siguiente->siguiente != nullptr)
            temp = temp->siguiente;
        delete temp->siguiente;
        temp->siguiente = nullptr;
    }

    // Mostrar / Recorrer la lista
    void mostrar() {
        if (inicial == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        nodo* temp = inicial;
        while (temp != nullptr) {
            cout << temp->valor << " -> ";
            temp = temp->siguiente;
        }
        cout << "nullptr" << endl;
    }

    // ========================================================
    //  OPERACIONES COMPLEMENTARIAS
    // ========================================================

    // Buscar un elemento
    bool buscar(int valor) {
        nodo* temp = inicial;
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

    // Insertar en una posición específica (0 = inicio)
    void insertarEnPosicion(int valor, int posicion) {
        if (posicion == 0) {
            insertarInicio(valor);
            return;
        }
        nodo* nuevo = new nodo();
        nuevo->valor = valor;

        nodo* temp = inicial;
        for (int i = 0; i < posicion - 1; i++) {
            if (temp == nullptr) {
                cout << "Posicion fuera de rango." << endl;
                delete nuevo;
                return;
            }
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }

    // Eliminar un elemento por valor
    void eliminarPorValor(int valor) {
        if (inicial == nullptr) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        if (inicial->valor == valor) {
            eliminarInicio();
            return;
        }
        nodo* aux = inicial;
        while (aux->siguiente != nullptr) {
            if (aux->siguiente->valor == valor) {
                nodo* temp = aux->siguiente;
                aux->siguiente = temp->siguiente;
                delete temp;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "Elemento no encontrado." << endl;
    }

    // Contar nodos
    int contarNodos() {
        int contador = 0;
        nodo* aux = inicial;
        while (aux != nullptr) {
            contador++;
            aux = aux->siguiente;
        }
        cout << "Total de nodos: " << contador << endl;
        return contador;
    }

    // Invertir la lista
    void invertir() {
        nodo* anterior = nullptr;
        nodo* actual   = inicial;
        nodo* siguiente = nullptr;

        while (actual != nullptr) {
            siguiente = actual->siguiente;
            actual->siguiente = anterior;
            anterior = actual;
            actual = siguiente;
        }
        inicial = anterior;
    }
};

// ---- main ---------------------------------------------------
int main() {
    Lista lista;
    int opcion, valor, posicion;

    do {
        cout << "\n=== LISTA LIGADA ===" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posicion" << endl;
        cout << "4. Eliminar al inicio" << endl;
        cout << "5. Eliminar al final" << endl;
        cout << "6. Eliminar por valor" << endl;
        cout << "7. Buscar elemento" << endl;
        cout << "8. Mostrar lista" << endl;
        cout << "9. Contar nodos" << endl;
        cout << "10. Invertir lista" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: "; cin >> valor;
                lista.insertarInicio(valor);
                break;
            case 2:
                cout << "Valor a insertar: "; cin >> valor;
                lista.insertarFinal(valor);
                break;
            case 3:
                cout << "Valor: "; cin >> valor;
                cout << "Posicion: "; cin >> posicion;
                lista.insertarEnPosicion(valor, posicion);
                break;
            case 4:
                lista.eliminarInicio();
                break;
            case 5:
                lista.eliminarFinal();
                break;
            case 6:
                cout << "Valor a eliminar: "; cin >> valor;
                lista.eliminarPorValor(valor);
                break;
            case 7:
                cout << "Valor a buscar: "; cin >> valor;
                lista.buscar(valor);
                break;
            case 8:
                lista.mostrar();
                break;
            case 9:
                lista.contarNodos();
                break;
            case 10:
                lista.invertir();
                cout << "Lista invertida." << endl;
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
