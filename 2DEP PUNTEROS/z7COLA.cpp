
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
class ListaDinamica {
private:
    Nodo<T>* cabeza;
    int cantidad;

public:
    ListaDinamica() : cabeza(NULL), cantidad(0) {
    }

private:
    // Evitar copias de la lista en compiladores antiguos
    ListaDinamica(const ListaDinamica&);
    ListaDinamica& operator=(const ListaDinamica&);

public:
    ~ListaDinamica() {
        while (cabeza != NULL) {
            Nodo<T>* aux = cabeza;
            cabeza = cabeza->siguiente;
            delete aux;
        }
    }

    bool vacia() const {
        return cabeza == NULL;
    }

    int tamanio() const {
        return cantidad;
    }

    bool insertar(int pos, const T& d) {
        if (pos < 0 || pos > cantidad) {
            return false;
        }

        if (pos == 0) {
            cabeza = new Nodo<T>(d, cabeza);
        } else {
            Nodo<T>* anterior = cabeza;

            for (int i = 0; i < pos - 1; i++) {
                anterior = anterior->siguiente;
            }

            anterior->siguiente =
                new Nodo<T>(d, anterior->siguiente);
        }

        cantidad++;
        return true;
    }

    bool insertarFinal(const T& d) {
        return insertar(cantidad, d);
    }

    bool eliminar(int pos, T& salida) {
        if (pos < 0 || pos >= cantidad) {
            return false;
        }

        Nodo<T>* borrar;

        if (pos == 0) {
            borrar = cabeza;
            cabeza = cabeza->siguiente;
        } else {
            Nodo<T>* anterior = cabeza;

            for (int i = 0; i < pos - 1; i++) {
                anterior = anterior->siguiente;
            }

            borrar = anterior->siguiente;
            anterior->siguiente = borrar->siguiente;
        }

        salida = borrar->dato;
        delete borrar;
        cantidad--;

        return true;
    }

    int buscar(const T& d) const {
        int i = 0;
        Nodo<T>* p = cabeza;

        while (p != NULL) {
            if (p->dato == d) {
                return i;
            }

            p = p->siguiente;
            i++;
        }

        return -1;
    }

    bool obtener(int pos, T& salida) const {
        if (pos < 0 || pos >= cantidad) {
            return false;
        }

        Nodo<T>* p = cabeza;

        for (int i = 0; i < pos; i++) {
            p = p->siguiente;
        }

        salida = p->dato;
        return true;
    }

    void mostrar() const {
        if (vacia()) {
            cout << "(Lista vacia)" << endl;
            return;
        }

        int i = 0;
        Nodo<T>* p = cabeza;

        while (p != NULL) {
            cout << i << ": " << p->dato << endl;
            p = p->siguiente;
            i++;
        }
    }
};

int main() {
    ListaDinamica<Persona> lista;

    int op = -1;
    int pos = 0;

    do {
        cout << "\n--- LISTA DINAMICA ---" << endl;
        cout << "1. Insertar en posicion" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Eliminar posicion" << endl;
        cout << "4. Buscar persona" << endl;
        cout << "5. Obtener persona" << endl;
        cout << "6. Mostrar lista" << endl;
        cout << "7. Tamanio" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!leerEntero(op)) {
            break;
        }

        Persona p;

        switch (op) {
        case 1:
            cout << "Posicion: ";

            if (!leerEntero(pos)) {
                break;
            }

            cout << "Nombre ApPat ApMat Genero Edad: ";

            if (!leerPersona(p)) {
                break;
            }

            if (!lista.insertar(pos, p)) {
                cout << "Posicion invalida." << endl;
            } else {
                cout << "Persona insertada correctamente." << endl;
            }
            break;

        case 2:
            cout << "Nombre ApPat ApMat Genero Edad: ";

            if (!leerPersona(p)) {
                break;
            }

            lista.insertarFinal(p);
            cout << "Persona agregada al final." << endl;
            break;

        case 3:
            cout << "Posicion: ";

            if (!leerEntero(pos)) {
                break;
            }

            if (lista.eliminar(pos, p)) {
                cout << "Eliminado: " << p << endl;
            } else {
                cout << "Posicion invalida." << endl;
            }
            break;

        case 4:
            cout << "Nombre ApPat ApMat Genero Edad a buscar: ";

            if (!leerPersona(p)) {
                break;
            }

            pos = lista.buscar(p);

            if (pos >= 0) {
                cout << "Encontrado en posicion "
                     << pos << endl;
            } else {
                cout << "No encontrado." << endl;
            }
            break;

        case 5:
            cout << "Posicion: ";

            if (!leerEntero(pos)) {
                break;
            }

            if (lista.obtener(pos, p)) {
                cout << "Persona: " << p << endl;
            } else {
                cout << "Posicion invalida." << endl;
            }
            break;

        case 6:
            lista.mostrar();
            break;

        case 7:
            cout << "Elementos: "
                 << lista.tamanio() << endl;
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

