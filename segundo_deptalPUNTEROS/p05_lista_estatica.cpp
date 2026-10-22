// Practica 5 - LISTA estatica por medio de un arreglo
#include <iostream>
#include "Persona.hpp"
using namespace std;

template <typename T, int MAX = 10>
class ListaEstatica {
private:
    T datos[MAX];
    int n;
public:
    ListaEstatica() : n(0) {}
    bool vacia() const { return n == 0; }
    bool llena() const { return n == MAX; }
    int  tamanio() const { return n; }

    // pos va de 0 a n (n = al final)
    bool insertar(int pos, const T& d) {
        if (llena() || pos < 0 || pos > n) return false;
        for (int i = n; i > pos; i--) datos[i] = datos[i - 1];
        datos[pos] = d;
        n++;
        return true;
    }
    bool insertarFinal(const T& d) { return insertar(n, d); }
    bool eliminar(int pos, T& salida) {
        if (pos < 0 || pos >= n) return false;
        salida = datos[pos];
        for (int i = pos; i < n - 1; i++) datos[i] = datos[i + 1];
        n--;
        return true;
    }
    int buscar(const T& d) const {          // -1 si no existe
        for (int i = 0; i < n; i++) if (datos[i] == d) return i;
        return -1;
    }
    bool obtener(int pos, T& salida) const {
        if (pos < 0 || pos >= n) return false;
        salida = datos[pos];
        return true;
    }
    void mostrar() const {
        if (vacia()) { cout << "(lista vacia)" << endl; return; }
        for (int i = 0; i < n; i++) cout << i << ": " << datos[i] << endl;
    }
};

int main() {
    ListaEstatica<Persona, 10> lista;
    int op = -1, pos = 0;
    do {
        cout << "\n--- LISTA ESTATICA ---\n1.Insertar en posicion 2.Insertar al final 3.Eliminar posicion\n"
                "4.Buscar 5.Obtener 6.Mostrar 7.Tamanio 0.Salir\nOpcion: ";
        if (!leerEntero(op)) break;
        Persona p;
        switch (op) {
        case 1:
            cout << "Posicion: "; if (!leerEntero(pos)) break;
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            if (!lista.insertar(pos, p)) cout << "No se pudo insertar." << endl;
            break;
        case 2:
            cout << "Nombre ApPat ApMat Genero Edad: "; if (!leerPersona(p)) break;
            if (!lista.insertarFinal(p)) cout << "Lista llena." << endl;
            break;
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
