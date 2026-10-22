// Practica 7 - COLA dinamica por medio de punteros al mismo tipo de dato (nodos)
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo(const T& d) : dato(d), siguiente(nullptr) {}
};

template <typename T>
class ColaDinamica {
private:
    Nodo<T>* frente;
    Nodo<T>* fin;
    int cantidad;
public:
    ColaDinamica() : frente(nullptr), fin(nullptr), cantidad(0) {}
    ColaDinamica(const ColaDinamica&) = delete;
    ColaDinamica& operator=(const ColaDinamica&) = delete;
    ~ColaDinamica() { T t; while (desencolar(t)); }

    bool vacia() const { return frente == nullptr; }
    int  tamanio() const { return cantidad; }

    void encolar(const T& d) {
        Nodo<T>* nuevo = new Nodo<T>(d);
        if (vacia()) frente = fin = nuevo;
        else { fin->siguiente = nuevo; fin = nuevo; }
        cantidad++;
    }
    bool desencolar(T& salida) {
        if (vacia()) return false;
        Nodo<T>* aux = frente;
        salida = aux->dato;
        frente = frente->siguiente;
        if (frente == nullptr) fin = nullptr;
        delete aux;
        cantidad--;
        return true;
    }
    bool verFrente(T& salida) const {
        if (vacia()) return false;
        salida = frente->dato;
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(cola vacia)" << endl; return; }
        for (Nodo<T>* p = frente; p != nullptr; p = p->siguiente)
            cout << (p == frente ? "FRENTE -> " : "           ") << p->dato << endl;
    }
};

int main() {
    ColaDinamica<Persona> cola;
    int op = -1;
    do {
        cout << "\n--- COLA DINAMICA ---\n1.Encolar 2.Desencolar 3.Ver frente 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1: cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break; cola.encolar(p); break;
        case 2:
            if (cola.desencolar(p)) cout << "Atendido: " << p << endl;
            else cout << "Cola vacia." << endl;
            break;
        case 3:
            if (cola.verFrente(p)) cout << "Frente: " << p << endl;
            else cout << "Cola vacia." << endl;
            break;
        case 4: cola.mostrar(); break;
        case 5: cout << "Elementos: " << cola.tamanio() << endl; break;
        }
    } while (op != 0);
    return 0;
}
