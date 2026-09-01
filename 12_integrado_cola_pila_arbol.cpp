// ============================================================
// Manual del Inexperto - Estructuras de Datos en C++
// PROGRAMA INTEGRADO: Cola (FIFO) + Pila (LIFO) + Árbol BST
// ============================================================

#include <iostream>
#include <algorithm> // max()
using namespace std;

// ============================================================
//  NODO GENÉRICO (compartido por Cola y Pila)
// ============================================================
struct NodoLineal {
    int valor;
    NodoLineal* siguiente;
};

// ============================================================
//  COLA (FIFO - First In, First Out)
// ============================================================
class Cola {
private:
    NodoLineal* frente;
    NodoLineal* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (frente != nullptr) desencolar();
    }

    void encolar(int valor) {
        NodoLineal* nuevo = new NodoLineal();
        nuevo->valor = valor;
        nuevo->siguiente = nullptr;
        if (final == nullptr) { frente = final = nuevo; return; }
        final->siguiente = nuevo;
        final = nuevo;
    }

    void desencolar() {
        if (frente == nullptr) { cout << "Cola vacia." << endl; return; }
        NodoLineal* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete temp;
    }

    void mostrar() {
        if (frente == nullptr) { cout << "Cola vacia." << endl; return; }
        NodoLineal* temp = frente;
        while (temp != nullptr) { cout << temp->valor << " -> "; temp = temp->siguiente; }
        cout << "nullptr" << endl;
    }

    int verFrente() {
        if (frente == nullptr) { cout << "Cola vacia." << endl; return -1; }
        return frente->valor;
    }

    bool estaVacia() { return frente == nullptr; }

    int contarElementos() {
        int c = 0;
        NodoLineal* temp = frente;
        while (temp != nullptr) { c++; temp = temp->siguiente; }
        cout << "Total elementos: " << c << endl;
        return c;
    }

    bool buscar(int valor) {
        NodoLineal* temp = frente;
        while (temp != nullptr) {
            if (temp->valor == valor) { cout << valor << " encontrado." << endl; return true; }
            temp = temp->siguiente;
        }
        cout << valor << " no encontrado." << endl;
        return false;
    }
};

// ============================================================
//  PILA (LIFO - Last In, First Out)
// ============================================================
class Pila {
private:
    NodoLineal* tope;

public:
    Pila() : tope(nullptr) {}

    ~Pila() { vaciar(); }

    void apilar(int valor) {
        NodoLineal* nuevo = new NodoLineal();
        nuevo->valor = valor;
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    void desapilar() {
        if (tope == nullptr) { cout << "Pila vacia." << endl; return; }
        NodoLineal* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }

    void mostrar() {
        if (tope == nullptr) { cout << "Pila vacia." << endl; return; }
        NodoLineal* temp = tope;
        while (temp != nullptr) { cout << temp->valor << " -> "; temp = temp->siguiente; }
        cout << "nullptr" << endl;
    }

    int verTope() {
        if (tope == nullptr) { cout << "Pila vacia." << endl; return -1; }
        return tope->valor;
    }

    bool estaVacia() { return tope == nullptr; }

    int contarElementos() {
        int c = 0;
        NodoLineal* temp = tope;
        while (temp != nullptr) { c++; temp = temp->siguiente; }
        cout << "Total elementos: " << c << endl;
        return c;
    }

    bool buscar(int valor) {
        NodoLineal* temp = tope;
        while (temp != nullptr) {
            if (temp->valor == valor) { cout << valor << " encontrado." << endl; return true; }
            temp = temp->siguiente;
        }
        cout << valor << " no encontrado." << endl;
        return false;
    }

    void vaciar() {
        while (tope != nullptr) desapilar();
    }
};

// ============================================================
//  ÁRBOL BINARIO DE BÚSQUEDA (BST)
// ============================================================
struct NodoBST {
    int dato;
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(int valor) : dato(valor), izquierda(NULL), derecha(NULL) {}
};

NodoBST* insertarNodo(NodoBST* raiz, int valor) {
    if (raiz == NULL) return new NodoBST(valor);
    if (valor < raiz->dato)      raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    else if (valor > raiz->dato) raiz->derecha   = insertarNodo(raiz->derecha,   valor);
    else cout << "Valor duplicado: " << valor << endl;
    return raiz;
}

bool buscarNodo(NodoBST* raiz, int valor) {
    if (raiz == NULL) { cout << valor << " no encontrado." << endl; return false; }
    if (raiz->dato == valor) { cout << valor << " encontrado." << endl; return true; }
    return (valor < raiz->dato) ? buscarNodo(raiz->izquierda, valor)
                                : buscarNodo(raiz->derecha,   valor);
}

void inOrden(NodoBST* raiz) {
    if (raiz != NULL) { inOrden(raiz->izquierda); cout << raiz->dato << " "; inOrden(raiz->derecha); }
}

void preOrden(NodoBST* raiz) {
    if (raiz != NULL) { cout << raiz->dato << " "; preOrden(raiz->izquierda); preOrden(raiz->derecha); }
}

void postOrden(NodoBST* raiz) {
    if (raiz != NULL) { postOrden(raiz->izquierda); postOrden(raiz->derecha); cout << raiz->dato << " "; }
}

NodoBST* MinimoRecursivo(NodoBST* raiz) {
    while (raiz != NULL && raiz->izquierda != NULL) raiz = raiz->izquierda;
    return raiz;
}

int mostrarMinimo(NodoBST* raiz) {
    if (raiz == NULL) { cout << "Arbol vacio." << endl; return -1; }
    NodoBST* a = raiz;
    while (a->izquierda != NULL) a = a->izquierda;
    return a->dato;
}

int mostrarMaximo(NodoBST* raiz) {
    if (raiz == NULL) { cout << "Arbol vacio." << endl; return -1; }
    NodoBST* a = raiz;
    while (a->derecha != NULL) a = a->derecha;
    return a->dato;
}

NodoBST* eliminarValor(NodoBST* raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->dato)      raiz->izquierda = eliminarValor(raiz->izquierda, valor);
    else if (valor > raiz->dato) raiz->derecha   = eliminarValor(raiz->derecha,   valor);
    else {
        if (raiz->izquierda == NULL && raiz->derecha == NULL) { delete raiz; return NULL; }
        if (raiz->derecha == NULL)   { NodoBST* t = raiz->izquierda; delete raiz; return t; }
        if (raiz->izquierda == NULL) { NodoBST* t = raiz->derecha;   delete raiz; return t; }
        NodoBST* sucesor = MinimoRecursivo(raiz->derecha);
        raiz->dato   = sucesor->dato;
        raiz->derecha = eliminarValor(raiz->derecha, sucesor->dato);
    }
    return raiz;
}

int contarNodos(NodoBST* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

int altura(NodoBST* raiz) {
    if (raiz == NULL) return 0;
    return 1 + max(altura(raiz->izquierda), altura(raiz->derecha));
}

NodoBST* liberarArbol(NodoBST* raiz) {
    if (raiz != NULL) { liberarArbol(raiz->izquierda); liberarArbol(raiz->derecha); delete raiz; }
    return NULL;
}

// ============================================================
//  SUBMENÚS
// ============================================================
void menuCola() {
    Cola cola;
    int op, val;
    do {
        cout << "\n--- COLA ---" << endl;
        cout << "1.Encolar  2.Desencolar  3.Frente  4.Mostrar" << endl;
        cout << "5.Contar   6.Buscar      7.Vacia?  0.Volver" << endl;
        cout << "Opcion: "; cin >> op;
        switch (op) {
            case 1: cout << "Valor: "; cin >> val; cola.encolar(val); break;
            case 2: cola.desencolar(); break;
            case 3: { int f = cola.verFrente(); if(f!=-1) cout << "Frente: " << f << endl; break; }
            case 4: cola.mostrar(); break;
            case 5: cola.contarElementos(); break;
            case 6: cout << "Valor: "; cin >> val; cola.buscar(val); break;
            case 7: cout << (cola.estaVacia() ? "Si, esta vacia." : "No, tiene elementos.") << endl; break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (op != 0);
}

void menuPila() {
    Pila pila;
    int op, val;
    do {
        cout << "\n--- PILA ---" << endl;
        cout << "1.Apilar   2.Desapilar  3.Tope    4.Mostrar" << endl;
        cout << "5.Contar   6.Buscar     7.Vaciar  8.Vacia?  0.Volver" << endl;
        cout << "Opcion: "; cin >> op;
        switch (op) {
            case 1: cout << "Valor: "; cin >> val; pila.apilar(val); break;
            case 2: pila.desapilar(); break;
            case 3: { int t = pila.verTope(); if(t!=-1) cout << "Tope: " << t << endl; break; }
            case 4: pila.mostrar(); break;
            case 5: pila.contarElementos(); break;
            case 6: cout << "Valor: "; cin >> val; pila.buscar(val); break;
            case 7: pila.vaciar(); break;
            case 8: cout << (pila.estaVacia() ? "Si, esta vacia." : "No, tiene elementos.") << endl; break;
            case 0: break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (op != 0);
}

void menuArbol() {
    NodoBST* raiz = NULL;
    int op, val;
    do {
        cout << "\n--- ARBOL BST ---" << endl;
        cout << "1.Insertar  2.Buscar    3.Eliminar" << endl;
        cout << "4.InOrden   5.PreOrden  6.PostOrden" << endl;
        cout << "7.Min/Max   8.Contar    9.Altura   0.Volver" << endl;
        cout << "Opcion: "; cin >> op;
        switch (op) {
            case 1: cout << "Valor: "; cin >> val; raiz = insertarNodo(raiz, val); break;
            case 2: cout << "Valor: "; cin >> val; buscarNodo(raiz, val); break;
            case 3: cout << "Valor: "; cin >> val; raiz = eliminarValor(raiz, val); break;
            case 4: cout << "InOrden: "; inOrden(raiz); cout << endl; break;
            case 5: cout << "PreOrden: "; preOrden(raiz); cout << endl; break;
            case 6: cout << "PostOrden: "; postOrden(raiz); cout << endl; break;
            case 7: {
                int mn = mostrarMinimo(raiz), mx = mostrarMaximo(raiz);
                if (mn != -1) cout << "Min: " << mn << " | Max: " << mx << endl;
                break;
            }
            case 8: cout << "Nodos: " << contarNodos(raiz) << endl; break;
            case 9: cout << "Altura: " << altura(raiz) << endl; break;
            case 0: raiz = liberarArbol(raiz); break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (op != 0);
}

// ============================================================
//  MENÚ PRINCIPAL
// ============================================================
int main() {
    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "  ESTRUCTURAS DE DATOS EN C++" << endl;
        cout << "========================================" << endl;
        cout << "1. Cola  (FIFO)" << endl;
        cout << "2. Pila  (LIFO)" << endl;
        cout << "3. Arbol Binario de Busqueda (BST)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuCola();   break;
            case 2: menuPila();   break;
            case 3: menuArbol();  break;
            case 0: cout << "Hasta luego." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
