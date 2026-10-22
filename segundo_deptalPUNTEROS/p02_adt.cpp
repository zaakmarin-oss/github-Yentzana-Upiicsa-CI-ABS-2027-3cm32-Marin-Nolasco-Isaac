// Practica 2 - ADT (Tipo Abstracto de Datos)
// Un ADT define los datos (ocultos) y las operaciones (interfaz publica).
// Se define una interfaz abstracta generica y dos implementaciones.
#include <iostream>
#include <string>
#include "Persona.hpp"
using namespace std;

// Interfaz abstracta: el contrato del ADT contenedor
template <typename T>
class ContenedorADT {
public:
    virtual ~ContenedorADT() {}
    virtual bool insertar(const T& dato) = 0;
    virtual bool extraer(T& salida) = 0;
    virtual bool estaVacio() const = 0;
    virtual int  tamanio() const = 0;
    virtual void mostrar() const = 0;
};

// Implementacion 1: comportamiento LIFO
template <typename T, int MAX = 10>
class ContenedorLIFO : public ContenedorADT<T> {
    T datos[MAX]; int n;
public:
    ContenedorLIFO() : n(0) {}
    bool insertar(const T& d) override { if (n == MAX) return false; datos[n++] = d; return true; }
    bool extraer(T& s) override { if (n == 0) return false; s = datos[--n]; return true; }
    bool estaVacio() const override { return n == 0; }
    int  tamanio() const override { return n; }
    void mostrar() const override { for (int i = n - 1; i >= 0; i--) cout << "  " << datos[i] << endl; }
};

// Implementacion 2: comportamiento FIFO
template <typename T, int MAX = 10>
class ContenedorFIFO : public ContenedorADT<T> {
    T datos[MAX]; int n;
public:
    ContenedorFIFO() : n(0) {}
    bool insertar(const T& d) override { if (n == MAX) return false; datos[n++] = d; return true; }
    bool extraer(T& s) override {
        if (n == 0) return false;
        s = datos[0];
        for (int i = 1; i < n; i++) datos[i - 1] = datos[i];
        n--; return true;
    }
    bool estaVacio() const override { return n == 0; }
    int  tamanio() const override { return n; }
    void mostrar() const override { for (int i = 0; i < n; i++) cout << "  " << datos[i] << endl; }
};

// El cliente solo conoce la interfaz, no la implementacion
void probar(ContenedorADT<Persona>& c, const string& nombre) {
    cout << "\n=== " << nombre << " ===" << endl;
    c.insertar(Persona("Ana", "Lopez", "Ruiz", "F", 20));
    c.insertar(Persona("Luis", "Perez", "Gomez", "M", 22));
    c.insertar(Persona("Sara", "Diaz", "Mora", "F", 19));
    cout << "Tamanio: " << c.tamanio() << "\nContenido:" << endl;
    c.mostrar();
    Persona p;
    if (c.extraer(p)) cout << "Extraido: " << p << endl;
    cout << "Tamanio ahora: " << c.tamanio() << endl;
}

int main() {
    ContenedorLIFO<Persona> pila;
    ContenedorFIFO<Persona> cola;
    probar(pila, "ADT con comportamiento LIFO");
    probar(cola, "ADT con comportamiento FIFO");
    return 0;
}
