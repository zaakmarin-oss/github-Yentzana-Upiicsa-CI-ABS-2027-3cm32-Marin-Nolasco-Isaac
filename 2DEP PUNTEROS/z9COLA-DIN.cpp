
#include <iostream>
#include <queue>
#include "Persona.cpp"

using namespace std;

class ColaSTL {
private:
    queue<Persona> cola;

public:
    void encolar(const Persona& p) {
        cola.push(p);
    }

    bool desencolar(Persona& salida) {
        if (cola.empty()) {
            return false;
        }

        salida = cola.front();
        cola.pop();
        return true;
    }

    bool verFrente(Persona& salida) const {
        if (cola.empty()) {
            return false;
        }

        salida = cola.front();
        return true;
    }

    bool vacia() const {
        return cola.empty();
    }

    int tamanio() const {
        return (int)cola.size();
    }

    void mostrar() const {
        if (cola.empty()) {
            cout << "(Cola vacia)" << endl;
            return;
        }

        queue<Persona> copia = cola;
        bool primero = true;

        while (!copia.empty()) {
            if (primero) {
                cout << "FRENTE -> ";
            } else {
                cout << "           ";
            }

            cout << copia.front() << endl;
            copia.pop();
            primero = false;
        }
    }
};

int main() {
    ColaSTL cola;
    int op = -1;

    do {
        cout << "\n--- COLA (std::queue) ---" << endl;
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

