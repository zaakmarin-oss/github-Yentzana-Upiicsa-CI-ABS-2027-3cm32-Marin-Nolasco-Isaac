// Practica 6 - PILA dinamica por medio de punteros al mismo tipo de dato (nodos)
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;             // puntero al mismo tipo de dato
    Nodo(const T& d, Nodo<T>* s = nullptr) : dato(d), siguiente(s) {}
};

template <typename T>
class PilaDinamica {
private:
    Nodo<T>* tope;
    int cantidad;
public:
    PilaDinamica() : tope(nullptr), cantidad(0) {}
    PilaDinamica(const PilaDinamica&) = delete;
    PilaDinamica& operator=(const PilaDinamica&) = delete;
    ~PilaDinamica() { T t; while (pop(t)); }

    bool vacia() const { return tope == nullptr; }
    int  tamanio() const { return cantidad; }

    void push(const T& d) {         // referencia: no copia el dato al llamar
        tope = new Nodo<T>(d, tope);
        cantidad++;
    }
    bool pop(T& salida) {
        if (vacia()) return false;
        Nodo<T>* aux = tope;
        salida = aux->dato;
        tope = aux->siguiente;
        delete aux;
        cantidad--;
        return true;
    }
    bool peek(T& salida) const {
        if (vacia()) return false;
        salida = tope->dato;
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(pila vacia)" << endl; return; }
        for (Nodo<T>* p = tope; p != nullptr; p = p->siguiente)
            cout << (p == tope ? "TOPE -> " : "        ") << p->dato << endl;
    }
};

int main() {
    PilaDinamica<Persona> pila;
    int op = -1;
    do {
        cout << "\n--- PILA DINAMICA ---\n1.Push 2.Pop 3.Peek 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1: cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break; pila.push(p); break;
        case 2:
            if (pila.pop(p)) cout << "Sacado: " << p << endl;
            else cout << "Pila vacia." << endl;
            break;
        case 3:
            if (pila.peek(p)) cout << "Tope: " << p << endl;
            else cout << "Pila vacia." << endl;
            break;
        case 4: pila.mostrar(); break;
        case 5: cout << "Elementos: " << pila.tamanio() << endl; break;
        }
    } while (op != 0);
    return 0;
}
