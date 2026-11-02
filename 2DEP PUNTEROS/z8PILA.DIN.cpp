
#include <iostream>
#include <stack>
#include "Persona.cpp"

using namespace std;

class PilaSTL {
private:
    stack<Persona> pila;

public:
    void push(const Persona& p) {
        pila.push(p);
    }

    bool pop(Persona& salida) {
        if (pila.empty()) {
            return false;
        }

        salida = pila.top();
        pila.pop();
        return true;
    }

    bool peek(Persona& salida) const {
        if (pila.empty()) {
            return false;
        }

        salida = pila.top();
        return true;
    }

    bool vacia() const {
        return pila.empty();
    }

    int tamanio() const {
        return (int)pila.size();
    }

    void mostrar() const {
        if (pila.empty()) {
            cout << "(Pila vacia)" << endl;
            return;
        }

        stack<Persona> copia = pila;
        bool primero = true;

        while (!copia.empty()) {
            if (primero) {
                cout << "TOPE -> ";
            } else {
                cout << "        ";
            }

            cout << copia.top() << endl;
            copia.pop();
            primero = false;
        }
    }
};

int main() {
    PilaSTL pila;
    int op = -1;

    do {
        cout << "\n--- PILA (std::stack) ---" << endl;
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

            if (!leerPersona(p)) {
                break;
            }

            pila.push(p);
            cout << "Persona agregada correctamente." << endl;
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

