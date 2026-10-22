// Practica 1 - Punteros para el manejo indirecto con clases y estructuras
// Como el ejercicio 12 (lista de personas y coches), pero dentro de la clase
// se incluye un puntero al mismo tipo de dato.
#include <iostream>
#include <string>
using namespace std;

class Coche {
private:
    string marca;
    double precio;
    int anio;
    Coche* siguiente;          // puntero al mismo tipo de dato
public:
    Coche(const string& m = "", double p = 0, int a = 0)
        : marca(m), precio(p), anio(a), siguiente(nullptr) {}
    void setSiguiente(Coche* s) { siguiente = s; }
    Coche* getSiguiente() const { return siguiente; }
    void mostrar() const {
        cout << marca << " | $" << precio << " | " << anio << endl;
    }
};

class Persona {
private:
    string nombre, ap, am, genero;
    int edad;
    Persona* siguiente;        // puntero al mismo tipo de dato
    Persona* conocido;         // otra referencia al mismo tipo de dato
    Coche* coche;              // acceso indirecto al coche de la persona
public:
    Persona(const string& n = "", const string& a = "", const string& m = "",
            const string& g = "", int e = 0)
        : nombre(n), ap(a), am(m), genero(g), edad(e),
          siguiente(nullptr), conocido(nullptr), coche(nullptr) {}

    void setSiguiente(Persona* s) { siguiente = s; }
    Persona* getSiguiente() const { return siguiente; }
    void setConocido(Persona* c) { conocido = c; }
    Persona* getConocido() const { return conocido; }
    void setCoche(Coche* c) { coche = c; }
    Coche* getCoche() const { return coche; }

    void mostrar() const {
        cout << nombre << " " << ap << " " << am << " | " << genero
             << " | " << edad << " anios" << endl;
    }
    string getNombre() const { return nombre; }
};

int main() {
    // Arreglos de objetos (ejercicio 12)
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

    // Enlazado: cada objeto apunta a otro del mismo tipo
    for (int i = 0; i < 2; i++) {
        personas[i].setSiguiente(&personas[i + 1]);
        coches[i].setSiguiente(&coches[i + 1]);
    }
    for (int i = 0; i < 3; i++) personas[i].setCoche(&coches[i]);
    personas[0].setConocido(&personas[2]);   // Ana conoce a Sara

    cout << "--- Recorrido indirecto de personas (via siguiente) ---" << endl;
    for (Persona* p = &personas[0]; p != nullptr; p = p->getSiguiente()) {
        p->mostrar();
        cout << "   Coche: ";
        p->getCoche()->mostrar();
    }

    cout << "\n--- Recorrido indirecto de coches ---" << endl;
    for (Coche* c = &coches[0]; c != nullptr; c = c->getSiguiente())
        c->mostrar();

    cout << "\n--- Acceso por referencia al mismo tipo ---" << endl;
    Persona& ref = *personas[0].getConocido();
    cout << personas[0].getNombre() << " conoce a: ";
    ref.mostrar();

    cout << "\n--- Memoria dinamica con punteros ---" << endl;
    Persona* nueva = new Persona("Mario", "Cruz", "Vega", "M", 25);
    nueva->setSiguiente(&personas[0]);
    nueva->mostrar();
    cout << "Su siguiente es: " << nueva->getSiguiente()->getNombre() << endl;
    delete nueva;
    return 0;
}
