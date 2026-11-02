#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "Persona.cpp"

using namespace std;

class ListaSTL {
private:
    list<Persona> lista;

public:
    bool vacia() const {
        return lista.empty();
    }

    int tamanio() const {
        return (int)lista.size();
    }

    bool insertar(int pos, const Persona& p) {
        if (pos < 0 || pos > (int)lista.size()) {
            return false;
        }

        list<Persona>::iterator it = lista.begin();
        advance(it, pos);
        lista.insert(it, p);
        return true;
    }

    bool insertarFinal(const Persona& p) {
        lista.push_back(p);
        return true;
    }

    bool eliminar(int pos, Persona& salida) {
        if (pos < 0 || pos >= (int)lista.size()) {
            return false;
        }

        list<Persona>::iterator it = lista.begin();
        advance(it, pos);
        salida = *it;
        lista.erase(it);
        return true;
    }

    int buscar(const Persona& p) const {
        list<Persona>::const_iterator it;
        it = find(lista.begin(), lista.end(), p);

        if (it == lista.end()) {
            return -1;
        }

        return (int)distance(lista.begin(), it);
    }

    bool obtener(int pos, Persona& salida) const {
        if (pos < 0 || pos >= (int)lista.size()) {
            return false;
        }

        list<Persona>::const_iterator it = lista.begin();
        advance(it, pos);
        salida = *it;
        return true;
    }

    void mostrar() const {
        if (lista.empty()) {
            cout << "(Lista vacia)" << endl;
            return;
        }

        int i = 0;
        list<Persona>::const_iterator it;

        for (it = lista.begin(); it != lista.end(); ++it) {
            cout << i++ << ": " << *it << endl;
        }
    }
};

int main() {
    ListaSTL lista;
    int op = -1;
    int pos = 0;

    do {
        cout << "\n--- LISTA (std::list) ---" << endl;
        cout << "1. Insertar en posicion" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Eliminar posicion" << endl;
        cout << "4. Buscar" << endl;
        cout << "5. Obtener" << endl;
        cout << "6. Mostrar" << endl;
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
            cout << "Persona insertada correctamente." << endl;
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
                cout << "Encontrado en posicion " << pos << endl;
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
                cout << p << endl;
            } else {
                cout << "Posicion invalida." << endl;
            }
            break;

        case 6:
            lista.mostrar();
            break;

        case 7:
            cout << "Elementos: " << lista.tamanio() << endl;
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
