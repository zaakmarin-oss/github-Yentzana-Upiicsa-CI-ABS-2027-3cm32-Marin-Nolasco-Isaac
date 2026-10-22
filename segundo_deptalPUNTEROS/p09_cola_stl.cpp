// Practica 9 - COLA dinamica con las librerias del IDE (std::queue)
#include <iostream>
#include <queue>
#include "Persona.hpp"
using namespace std;

class ColaSTL {
private:
    queue<Persona> cola;
public:
    void encolar(const Persona& p) { cola.push(p); }
    bool desencolar(Persona& salida) {
        if (cola.empty()) return false;
        salida = cola.front();
        cola.pop();
        return true;
    }
    bool verFrente(Persona& salida) const {
        if (cola.empty()) return false;
        salida = cola.front();
        return true;
    }
    bool vacia() const { return cola.empty(); }
    size_t tamanio() const { return cola.size(); }
    void mostrar() const {
        if (cola.empty()) { cout << "(cola vacia)" << endl; return; }
        queue<Persona> copia = cola;       // std::queue no se puede recorrer
        bool primero = true;
        while (!copia.empty()) {
            cout << (primero ? "FRENTE -> " : "           ") << copia.front() << endl;
            copia.pop();
            primero = false;
        }
    }
};

int main() {
    ColaSTL cola;
    int op = -1;
    do {
        cout << "\n--- COLA (std::queue) ---\n1.Encolar 2.Desencolar 3.Ver frente 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
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
