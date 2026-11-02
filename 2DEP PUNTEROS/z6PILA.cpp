
#include <iostream>
#include "Persona.cpp"

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(const T& d, Nodo<T>* s = NULL)
        : dato(d), siguiente(s) {
    }
};

template <typename T>
class PilaDinamica {
private:
    Nodo<T>* tope;
    int cantidad;

public:
    PilaDinamica() : tope(NULL), cantidad(0) {
    }

    // Evitar copias de la pila en compiladores antiguos
private:
    PilaDinamica(const PilaDinamica&);
    PilaDinamica& operator=(const PilaDinamica&);

public:
    ~PilaDinamica() {
        while (tope != NULL) {
            Nodo<T>* aux = tope;
            tope = tope->siguiente;
            delete aux;
        }
    }

    bool vacia() const {
        return tope == NULL;
    }

    int tamanio() const {
        return cantidad;
    }

    void push(const T& d) {
        tope = new Nodo<T>(d, tope);
        cantidad++;
    }

    bool pop(T& salida) {
        if (vacia()) {
            return false;
        }

        Nodo<T>* aux = tope;
        salida = aux->dato;
        tope = aux->siguiente;

        delete aux;
        cantidad--;

        return true;
    }

    bool peek(T& salida) const {
        if (vacia()) {
            return false;
        }

        salida = tope->dato;
        return true;
    }

    void mostrar() const {
        if (vacia()) {
            cout << "(Pila vacia)" << endl;
            return;
        }

        Nodo<T>* p = tope;

        while (p != NULL) {
            if (p == tope) {
                cout << "TOPE -> ";
            } else {
                cout << "        ";
            }

            cout << p->dato << endl;
            p = p->siguiente;
        }
    }
};

int main() {
    PilaDinamica<Persona> pila;
    int op = -1;

    do {
        cout << "\n--- PILA DINAMICA ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Tamanio" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!leerEntero(op)) {
            break;
        }

        Persona p;

        switch (op) {
        case 1:
            cout << "Nombre ApPat ApMat Genero Edad: ";

            if (leerPersona(p)) {
                pila.push(p);
                cout << "Persona agregada correctamente." << endl;
            }
            break;

        case 2:
            if (pila.pop(p)) {
                cout << "Sacado: " << p << endl;
            } else {
                cout << "Pila vacia." << endl;
            }
            break;

        case 3:
            if (pila.peek(p)) {
                cout << "Tope: " << p << endl;
            } else {
                cout << "Pila vacia." << endl;
            }
            break;

        case 4:
            pila.mostrar();
            break;

        case 5:
            cout << "Elementos: " << pila.tamanio() << endl;
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }

    } while (op != 0);

    return 0;
}

