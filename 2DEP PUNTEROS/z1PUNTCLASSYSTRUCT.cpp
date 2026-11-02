
#include <iostream>
#include <string>
using namespace std;

class Coche {
private:
    string marca;
    double precio;
    int anio;
    Coche* siguiente;

public:
    Coche(const string& m = "", double p = 0, int a = 0)
        : marca(m), precio(p), anio(a), siguiente(NULL) {
    }

    void setSiguiente(Coche* s) {
        siguiente = s;
    }

    Coche* getSiguiente() const {
        return siguiente;
    }

    void mostrar() const {
        cout << marca << " | $" << precio
             << " | " << anio << endl;
    }
};

class Persona {
private:
    string nombre, ap, am, genero;
    int edad;
    Persona* siguiente;
    Persona* conocido;
    Coche* coche;

public:
    Persona(const string& n = "", const string& a = "",
            const string& m = "", const string& g = "",
            int e = 0)
        : nombre(n), ap(a), am(m), genero(g), edad(e),
          siguiente(NULL), conocido(NULL), coche(NULL) {
    }

    void setSiguiente(Persona* s) {
        siguiente = s;
    }

    Persona* getSiguiente() const {
        return siguiente;
    }

    void setConocido(Persona* c) {
        conocido = c;
    }

    Persona* getConocido() const {
        return conocido;
    }

    void setCoche(Coche* c) {
        coche = c;
    }

    Coche* getCoche() const {
        return coche;
    }

    void mostrar() const {
        cout << nombre << " " << ap << " " << am
             << " | " << genero << " | "
             << edad << " anios" << endl;
    }

    string getNombre() const {
        return nombre;
    }
};

int main() {
    Persona personas[3] = {
        Persona("Ana", "Lopez", "Ruiz", "F", 20),
        Persona("Luis", "Perez", "Gomez", "M", 22),
        Persona("Sara", "Diaz", "Mora", "F", 19)
    };

    Coche coches[3] = {
        Coche("Nissan", 250000, 2020),
        Coche("Mazda", 320000, 2022),
        Coche("VW", 280000, 2021)
    };

    // Enlazar personas y coches
    for (int i = 0; i < 2; i++) {
        personas[i].setSiguiente(&personas[i + 1]);
        coches[i].setSiguiente(&coches[i + 1]);
    }

    // Asignar un coche a cada persona
    for (int i = 0; i < 3; i++) {
        personas[i].setCoche(&coches[i]);
    }

    // Ana conoce a Sara
    personas[0].setConocido(&personas[2]);

    cout << "--- Recorrido indirecto de personas ---" << endl;

    for (Persona* p = &personas[0];
         p != NULL;
         p = p->getSiguiente()) {

        p->mostrar();

        if (p->getCoche() != NULL) {
            cout << "   Coche: ";
            p->getCoche()->mostrar();
        } else {
            cout << "   Sin coche asignado" << endl;
        }
    }

    cout << "\n--- Recorrido indirecto de coches ---" << endl;

    for (Coche* c = &coches[0];
         c != NULL;
         c = c->getSiguiente()) {

        c->mostrar();
    }

    cout << "\n--- Acceso por referencia al mismo tipo ---" << endl;

    if (personas[0].getConocido() != NULL) {
        Persona& ref = *personas[0].getConocido();

        cout << personas[0].getNombre() << " conoce a: ";
        ref.mostrar();
    } else {
        cout << "Ana no tiene conocidos registrados." << endl;
    }

    cout << "\n--- Memoria dinamica con punteros ---" << endl;

    Persona* nueva = new Persona("Mario", "Cruz", "Vega", "M", 25);

    nueva->setSiguiente(&personas[0]);
    nueva->mostrar();

    if (nueva->getSiguiente() != NULL) {
        cout << "Su siguiente es: "
             << nueva->getSiguiente()->getNombre() << endl;
    }

    delete nueva;
    nueva = NULL;

    return 0;
}

