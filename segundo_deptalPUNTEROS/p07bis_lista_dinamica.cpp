// Practica 7 bis - LISTA dinamica por medio de punteros al mismo tipo de dato (nodos)
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo(const T& d, Nodo<T>* s = nullptr) : dato(d), siguiente(s) {}
};

template <typename T>
class ListaDinamica {
private:
    Nodo<T>* cabeza;
    int cantidad;
public:
    ListaDinamica() : cabeza(nullptr), cantidad(0) {}
    ListaDinamica(const ListaDinamica&) = delete;
    ListaDinamica& operator=(const ListaDinamica&) = delete;
    ~ListaDinamica() { while (cabeza) { Nodo<T>* a = cabeza; cabeza = cabeza->siguiente; delete a; } }

    bool vacia() const { return cabeza == nullptr; }
    int  tamanio() const { return cantidad; }

    // pos de 0 a cantidad (cantidad = al final)
    bool insertar(int pos, const T& d) {
        if (pos < 0 || pos > cantidad) return false;
        if (pos == 0) cabeza = new Nodo<T>(d, cabeza);
        else {
            Nodo<T>* ant = cabeza;
            for (int i = 0; i < pos - 1; i++) ant = ant->siguiente;
            ant->siguiente = new Nodo<T>(d, ant->siguiente);
        }
        cantidad++;
        return true;
    }
    bool insertarFinal(const T& d) { return insertar(cantidad, d); }

    bool eliminar(int pos, T& salida) {
        if (pos < 0 || pos >= cantidad) return false;
        Nodo<T>* borrar;
        if (pos == 0) { borrar = cabeza; cabeza = cabeza->siguiente; }
        else {
            Nodo<T>* ant = cabeza;
            for (int i = 0; i < pos - 1; i++) ant = ant->siguiente;
            borrar = ant->siguiente;
            ant->siguiente = borrar->siguiente;
        }
        salida = borrar->dato;
        delete borrar;
        cantidad--;
        return true;
    }
    int buscar(const T& d) const {
        int i = 0;
        for (Nodo<T>* p = cabeza; p != nullptr; p = p->siguiente, i++)
            if (p->dato == d) return i;
        return -1;
    }
    bool obtener(int pos, T& salida) const {
        if (pos < 0 || pos >= cantidad) return false;
        Nodo<T>* p = cabeza;
        for (int i = 0; i < pos; i++) p = p->siguiente;
        salida = p->dato;
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(lista vacia)" << endl; return; }
        int i = 0;
        for (Nodo<T>* p = cabeza; p != nullptr; p = p->siguiente, i++)
            cout << i << ": " << p->dato << endl;
    }
};

int main() {
    ListaDinamica<Persona> lista;
    int op = -1, pos = 0;
    do {
        cout << "\n--- LISTA DINAMICA ---\n1.Insertar en posicion 2.Insertar al final 3.Eliminar posicion\n"
                "4.Buscar 5.Obtener 6.Mostrar 7.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            if (!lista.insertar(pos, p)) cout << "Posicion invalida." << endl;
            break;
        case 2:
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            lista.insertarFinal(p); break;
        case 3:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            if (lista.eliminar(pos, p)) cout << "Eliminado: " << p << endl;
            else cout << "Posicion invalida." << endl;
            break;
        case 4:
            cout << "Nombre ApPat ApMat Genero Edad a buscar: "; if (!leerPersona(p)) break;
            pos = lista.buscar(p);
            if (pos >= 0) cout << "Encontrado en posicion " << pos << endl;
            else cout << "No encontrado." << endl;
            break;
        case 5:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            if (lista.obtener(pos, p)) cout << p << endl;
            else cout << "Posicion invalida." << endl;
            break;
        case 6: lista.mostrar(); break;
        case 7: cout << "Elementos: " << lista.tamanio() << endl; break;
        }
    } while (op != 0);
    return 0;
}
