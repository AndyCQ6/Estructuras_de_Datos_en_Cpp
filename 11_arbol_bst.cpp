// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// Capítulo 7: Árbol Binario de Búsqueda (BST)
//             Operaciones básicas y complementarias
// ============================================================

#include <iostream>
#include <algorithm> // max()
using namespace std;

// ---- Estructura del nodo ------------------------------------
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo() {
        izquierda = NULL;
        derecha   = NULL;
    }

    Nodo(int valor) {
        dato      = valor;
        izquierda = NULL;
        derecha   = NULL;
    }
};

// ============================================================
//  OPERACIONES BÁSICAS
// ============================================================

// Insertar un nodo
Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return new Nodo(valor);

    if (valor < raiz->dato)
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    else if (valor > raiz->dato)
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    else
        cout << "Valor duplicado: " << valor << " (no insertado)" << endl;

    return raiz;
}

// Buscar un elemento
bool buscarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        cout << "Elemento " << valor << " no encontrado." << endl;
        return false;
    }
    if (raiz->dato == valor) {
        cout << "Elemento " << valor << " encontrado." << endl;
        return true;
    }
    if (valor < raiz->dato)
        return buscarNodo(raiz->izquierda, valor);
    return buscarNodo(raiz->derecha, valor);
}

// Recorridos
void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierda);
        cout << raiz->dato << " ";
        inOrden(raiz->derecha);
    }
}

void postOrden(Nodo* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierda);
        postOrden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

void preOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierda);
        preOrden(raiz->derecha);
    }
}

// Mínimo — iterativo
int mostrarMinimo(Nodo* raiz) {
    if (raiz == NULL) { cout << "Arbol vacio." << endl; return -1; }
    Nodo* actual = raiz;
    while (actual->izquierda != NULL)
        actual = actual->izquierda;
    return actual->dato;
}

// Máximo — iterativo
int mostrarMaximo(Nodo* raiz) {
    if (raiz == NULL) { cout << "Arbol vacio." << endl; return -1; }
    Nodo* actual = raiz;
    while (actual->derecha != NULL)
        actual = actual->derecha;
    return actual->dato;
}

// Mínimo — recursivo (auxiliar para eliminación)
Nodo* MinimoRecursivo(Nodo* raiz) {
    while (raiz != NULL && raiz->izquierda != NULL)
        raiz = raiz->izquierda;
    return raiz;
}

// Eliminar un nodo
Nodo* eliminarValor(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->dato)
        raiz->izquierda = eliminarValor(raiz->izquierda, valor);
    else if (valor > raiz->dato)
        raiz->derecha = eliminarValor(raiz->derecha, valor);
    else {
        // Caso 1: nodo sin hijos (hoja)
        if (raiz->izquierda == NULL && raiz->derecha == NULL) {
            delete raiz;
            return NULL;
        }
        // Caso 2: solo hijo izquierdo
        if (raiz->derecha == NULL) {
            Nodo* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }
        // Caso 2: solo hijo derecho
        if (raiz->izquierda == NULL) {
            Nodo* temp = raiz->derecha;
            delete raiz;
            return temp;
        }
        // Caso 3: dos hijos — reemplazar por sucesor inorden
        Nodo* sucesor = MinimoRecursivo(raiz->derecha);
        raiz->dato = sucesor->dato;
        raiz->derecha = eliminarValor(raiz->derecha, sucesor->dato);
    }
    return raiz;
}

// ============================================================
//  OPERACIONES COMPLEMENTARIAS
// ============================================================

// Contar nodos
int contarNodos(Nodo* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

// Calcular altura
int altura(Nodo* raiz) {
    if (raiz == NULL) return 0;
    int altIzq = altura(raiz->izquierda);
    int altDer = altura(raiz->derecha);
    return 1 + max(altIzq, altDer);
}

// Liberar toda la memoria del árbol
Nodo* liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        delete raiz;
    }
    return NULL;
}

// ---- main ---------------------------------------------------
int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        cout << "\n=== ARBOL BINARIO DE BUSQUEDA ===" << endl;
        cout << "1. Insertar nodo" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Eliminar nodo" << endl;
        cout << "4. Recorrido InOrden (ascendente)" << endl;
        cout << "5. Recorrido PreOrden" << endl;
        cout << "6. Recorrido PostOrden" << endl;
        cout << "7. Minimo y Maximo" << endl;
        cout << "8. Contar nodos" << endl;
        cout << "9. Altura del arbol" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: "; cin >> valor;
                raiz = insertarNodo(raiz, valor);
                break;
            case 2:
                cout << "Valor a buscar: "; cin >> valor;
                buscarNodo(raiz, valor);
                break;
            case 3:
                cout << "Valor a eliminar: "; cin >> valor;
                raiz = eliminarValor(raiz, valor);
                break;
            case 4:
                cout << "InOrden: "; inOrden(raiz); cout << endl;
                break;
            case 5:
                cout << "PreOrden: "; preOrden(raiz); cout << endl;
                break;
            case 6:
                cout << "PostOrden: "; postOrden(raiz); cout << endl;
                break;
            case 7: {
                int mn = mostrarMinimo(raiz);
                int mx = mostrarMaximo(raiz);
                if (mn != -1) cout << "Minimo: " << mn << " | Maximo: " << mx << endl;
                break;
            }
            case 8:
                cout << "Total de nodos: " << contarNodos(raiz) << endl;
                break;
            case 9:
                cout << "Altura: " << altura(raiz) << endl;
                break;
            case 0:
                raiz = liberarArbol(raiz);
                cout << "Memoria liberada. Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
