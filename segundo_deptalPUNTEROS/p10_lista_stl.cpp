// Practica 10 - LISTA dinamica con las librerias del IDE (std::list)
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "Persona.hpp"
using namespace std;

class ListaSTL {
private:
    list<Persona> lista;
public:
    bool vacia() const { return lista.empty(); }
    size_t tamanio() const { return lista.size(); }

    bool insertar(int pos, const Persona& p) {
        if (pos < 0 || pos > (int)lista.size()) return false;
        auto it = lista.begin();
        advance(it, pos);
        lista.insert(it, p);
        return true;
    }
    bool insertarFinal(const Persona& p) { lista.push_back(p); return true; }
    bool eliminar(int pos, Persona& salida) {
        if (pos < 0 || pos >= (int)lista.size()) return false;
        auto it = lista.begin();
        advance(it, pos);
        salida = *it;
        lista.erase(it);
        return true;
    }
    int buscar(const Persona& p) const {
        auto it = find(lista.begin(), lista.end(), p);
        if (it == lista.end()) return -1;
        return (int)distance(lista.begin(), it);
    }
    bool obtener(int pos, Persona& salida) const {
        if (pos < 0 || pos >= (int)lista.size()) return false;
        auto it = lista.begin();
        advance(it, pos);
        salida = *it;
        return true;
    }
    void mostrar() const {
        if (lista.empty()) { cout << "(lista vacia)" << endl; return; }
        int i = 0;
        for (const Persona& p : lista) cout << i++ << ": " << p << endl;
    }
};

int main() {
    ListaSTL lista;
    int op = -1, pos = 0;
    do {
        cout << "\n--- LISTA (std::list) ---\n1.Insertar en posicion 2.Insertar al final 3.Eliminar posicion\n"
                "4.Buscar 5.Obtener 6.Mostrar 7.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            if (!lista.insertar(pos, p)) cout << "Posicion invalida." << endl;
            break;
        case 2:
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            lista.insertarFinal(p); break;
        case 3:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            if (lista.eliminar(pos, p)) cout << "Eliminado: " << p << endl;
            else cout << "Posicion invalida." << endl;
            break;
        case 4:
            cout << "Nombre ApPat ApMat Genero Edad a buscar: "; if (!leerPersona(p)) break;
            pos = lista.buscar(p);
            if (pos >= 0) cout << "Encontrado en posicion " << pos << endl;
            else cout << "No encontrado." << endl;
            break;
        case 5:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            if (lista.obtener(pos, p)) cout << p << endl;
            else cout << "Posicion invalida." << endl;
            break;
        case 6: lista.mostrar(); break;
        case 7: cout << "Elementos: " << lista.tamanio() << endl; break;
        }
    } while (op != 0);
    return 0;
}
