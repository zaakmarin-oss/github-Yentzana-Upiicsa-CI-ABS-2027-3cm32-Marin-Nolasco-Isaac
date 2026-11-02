#include <iostream>
#include "Persona.cpp"

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(const T& d) : dato(d), siguiente(NULL) {
    }
};

template <typename T>
class ColaDinamica {
private:
    Nodo<T>* frente;
    Nodo<T>* fin;
    int cantidad;

public:
    ColaDinamica() : frente(NULL), fin(NULL), cantidad(0) {
    }

private:
    ColaDinamica(const ColaDinamica&);
    ColaDinamica& operator=(const ColaDinamica&);

public:
    ~ColaDinamica() {
        while (frente != NULL) {
            Nodo<T>* aux = frente;
            frente = frente->siguiente;
            delete aux;
        }
        fin = NULL;
        cantidad = 0;
    }

    bool vacia() const {
        return frente == NULL;
    }

    int tamanio() const {
        return cantidad;
    }

    void encolar(const T& d) {
        Nodo<T>* nuevo = new Nodo<T>(d);

        if (vacia()) {
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }

        cantidad++;
    }

    bool desencolar(T& salida) {
        if (vacia()) {
            return false;
        }

        Nodo<T>* aux = frente;
        salida = aux->dato;
        frente = frente->siguiente;

        if (frente == NULL) {
            fin = NULL;
        }

        delete aux;
        cantidad--;

        return true;
    }

    bool verFrente(T& salida) const {
        if (vacia()) {
            return false;
        }

        salida = frente->dato;
        return true;
    }

    void mostrar() const {
        if (vacia()) {
            cout << "(Cola vacia)" << endl;
            return;
        }

        Nodo<T>* p = frente;

        while (p != NULL) {
            if (p == frente) {
                cout << "FRENTE -> ";
            } else {
                cout << "           ";
            }

            cout << p->dato << endl;
            p = p->siguiente;
        }
    }
};

int main() {
    ColaDinamica<Persona> cola;
    int op = -1;

    do {
        cout << "\n--- COLA DINAMICA ---" << endl;
        cout << "1. Encolar" << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Ver frente" << endl;
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

            if (!leerPersona(p)) {
                break;
            }

            cola.encolar(p);
            cout << "Persona agregada correctamente." << endl;
            break;

        case 2:
            if (cola.desencolar(p)) {
                cout << "Atendido: " << p << endl;
            } else {
                cout << "Cola vacia." << endl;
            }
            break;

        case 3:
            if (cola.verFrente(p)) {
                cout << "Frente: " << p << endl;
            } else {
                cout << "Cola vacia." << endl;
            }
            break;

        case 4:
            cola.mostrar();
            break;

        case 5:
            cout << "Elementos: " << cola.tamanio() << endl;
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

