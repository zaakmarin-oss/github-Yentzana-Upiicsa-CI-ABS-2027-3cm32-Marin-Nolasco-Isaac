// Practica 8 - PILA dinamica con las librerias del IDE (std::stack)
#include <iostream>
#include <stack>
#include "Persona.hpp"
using namespace std;

class PilaSTL {
private:
    stack<Persona> pila;
public:
    void push(const Persona& p) { pila.push(p); }
    bool pop(Persona& salida) {
        if (pila.empty()) return false;
        salida = pila.top();
        pila.pop();
        return true;
    }
    bool peek(Persona& salida) const {
        if (pila.empty()) return false;
        salida = pila.top();
        return true;
    }
    bool vacia() const { return pila.empty(); }
    size_t tamanio() const { return pila.size(); }
    void mostrar() const {
        if (pila.empty()) { cout << "(pila vacia)" << endl; return; }
        stack<Persona> copia = pila;       // std::stack no se puede recorrer
        bool primero = true;
        while (!copia.empty()) {
            cout << (primero ? "TOPE -> " : "        ") << copia.top() << endl;
            copia.pop();
            primero = false;
        }
    }
};

int main() {
    PilaSTL pila;
    int op = -1;
    do {
        cout << "\n--- PILA (std::stack) ---\n1.Push 2.Pop 3.Peek 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1: cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break; pila.push(p); break;
        case 2:
            if (pila.pop(p)) cout << "Sacado: " << p << endl;
            else cout << "Pila vacia." << endl;
            break;
        case 3:
            if (pila.peek(p)) cout << "Tope: " << p << endl;
            else cout << "Pila vacia." << endl;
            break;
        case 4: pila.mostrar(); break;
        case 5: cout << "Elementos: " << pila.tamanio() << endl; break;
        }
    } while (op != 0);
    return 0;
}
