
#include <iostream>
#include <string>
#include "Persona.cpp"

using namespace std;

template <typename T>
class ContenedorADT {
public:
    virtual ~ContenedorADT() {}

    virtual bool insertar(const T& dato) = 0;
    virtual bool extraer(T& salida) = 0;
    virtual bool estaVacio() const = 0;
    virtual int tamanio() const = 0;
    virtual void mostrar() const = 0;
};

template <typename T, int MAX = 10>
class ContenedorLIFO : public ContenedorADT<T> {
private:
    T datos[MAX];
    int n;

public:
    ContenedorLIFO() : n(0) {}

    bool insertar(const T& d) {
        if (n >= MAX)
            return false;

        datos[n] = d;
        n++;
        return true;
    }

    bool extraer(T& s) {
        if (n == 0)
            return false;

        n--;
        s = datos[n];
        return true;
    }

    bool estaVacio() const {
        return n == 0;
    }

    int tamanio() const {
        return n;
    }

    void mostrar() const {
        for (int i = n - 1; i >= 0; i--) {
            cout << "  " << datos[i] << endl;
        }
    }
};

template <typename T, int MAX = 10>
class ContenedorFIFO : public ContenedorADT<T> {
private:
    T datos[MAX];
    int n;

public:
    ContenedorFIFO() : n(0) {}

    bool insertar(const T& d) {
        if (n >= MAX)
            return false;

        datos[n] = d;
        n++;
        return true;
    }

    bool extraer(T& s) {
        if (n == 0)
            return false;

        s = datos[0];

        for (int i = 1; i < n; i++) {
            datos[i - 1] = datos[i];
        }

        n--;
        return true;
    }

    bool estaVacio() const {
        return n == 0;
    }

    int tamanio() const {
        return n;
    }

    void mostrar() const {
        for (int i = 0; i < n; i++) {
            cout << "  " << datos[i] << endl;
        }
    }
};

void probar(ContenedorADT<Persona>& c, const string& nombre) {
    cout << "\n=== " << nombre << " ===" << endl;

    c.insertar(Persona("Ana", "Lopez", "Ruiz", "F", 20));
    c.insertar(Persona("Luis", "Perez", "Gomez", "M", 22));
    c.insertar(Persona("Sara", "Diaz", "Mora", "F", 19));

    cout << "Tamanio: " << c.tamanio() << endl;
    cout << "Contenido:" << endl;

    c.mostrar();

    Persona p;

    if (c.extraer(p)) {
        cout << "Extraido: " << p << endl;
    }

    cout << "Tamanio ahora: " << c.tamanio() << endl;
}

int main() {
    ContenedorLIFO<Persona> pila;
    ContenedorFIFO<Persona> cola;

    probar(pila, "ADT con comportamiento LIFO");
    probar(cola, "ADT con comportamiento FIFO");

    return 0;
}

