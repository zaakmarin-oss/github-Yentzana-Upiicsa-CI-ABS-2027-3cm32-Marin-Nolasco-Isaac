// Practica 3 - PILA estatica por medio de un arreglo
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T, int MAX = 5>
class PilaEstatica {
private:
    T datos[MAX];
    int tope;                       // indice del ultimo elemento (-1 = vacia)
public:
    PilaEstatica() : tope(-1) {}
    bool vacia() const { return tope == -1; }
    bool llena() const { return tope == MAX - 1; }
    int  tamanio() const { return tope + 1; }

    bool push(const T& d) {
        if (llena()) return false;
        datos[++tope] = d;
        return true;
    }
    bool pop(T& salida) {
        if (vacia()) return false;
        salida = datos[tope--];
        return true;
    }
    bool peek(T& salida) const {
        if (vacia()) return false;
        salida = datos[tope];
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(pila vacia)" << endl; return; }
        for (int i = tope; i >= 0; i--)
            cout << (i == tope ? "TOPE -> " : "        ") << datos[i] << endl;
    }
};

int main() {
    PilaEstatica<Persona, 5> pila;
    int op = -1;
    do {
        cout << "\n--- PILA ESTATICA ---\n1.Push 2.Pop 3.Peek 4.Mostrar 5.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1:
            if (pila.llena()) { cout << "Pila llena (desbordamiento)." << endl; break; }
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            pila.push(p); break;
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
