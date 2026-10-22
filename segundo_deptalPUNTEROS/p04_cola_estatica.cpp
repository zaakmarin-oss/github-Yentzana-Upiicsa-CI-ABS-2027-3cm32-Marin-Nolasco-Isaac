// Practica 4 - COLA estatica por medio de un arreglo (circular)
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T, int MAX = 5>
class ColaEstatica {
private:
    T datos[MAX];
    int frente, fin, cantidad;
public:
    ColaEstatica() : frente(0), fin(0), cantidad(0) {}
    bool vacia() const { return cantidad == 0; }
    bool llena() const { return cantidad == MAX; }
    int  tamanio() const { return cantidad; }

    bool encolar(const T& d) {
        if (llena()) return false;
        datos[fin] = d;
        fin = (fin + 1) % MAX;
        cantidad++;
        return true;
    }
    bool desencolar(T& salida) {
        if (vacia()) return false;
        salida = datos[frente];
        frente = (frente + 1) % MAX;
        cantidad--;
        return true;
    }
    bool verFrente(T& salida) const {
        if (vacia()) return false;
        salida = datos[frente];
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(cola vacia)" << endl; return; }
        for (int i = 0; i < cantidad; i++)
            cout << (i == 0 ? "FRENTE -> " : "           ") << datos[(frente + i) % MAX] << endl;
    }
};

int main() {
    ColaEstatica<Persona, 5> cola;
    int op = -1;
    do {
        cout << "\n--- COLA ESTATICA ---\n1.Encolar 2.Desencolar 3.Ver frente 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1:
            if (cola.llena()) { cout << "Cola llena." << endl; break; }
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            cola.encolar(p); break;
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
