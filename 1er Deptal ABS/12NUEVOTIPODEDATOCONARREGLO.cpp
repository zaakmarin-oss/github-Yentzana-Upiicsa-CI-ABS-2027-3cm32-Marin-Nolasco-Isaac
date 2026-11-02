#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    int edad;
};

struct Coche {
    string marca;
    int anio;
    double precio;
};

int main() {
    Persona personas[3];
    Coche coches[3];

    cout << "REGISTRO DE 3 PERSONAS" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Nombre de la persona " << i + 1 << ": ";
        cin >> personas[i].nombre;

        cout << "Apellido: ";
        cin >> personas[i].apellido;

        cout << "Edad: ";
        cin >> personas[i].edad;
    }

    cout << endl << "REGISTRO DE 3 COCHES" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Marca del coche " << i + 1 << ": ";
        cin >> coches[i].marca;

        cout << "Anio: ";
        cin >> coches[i].anio;

        cout << "Precio: ";
        cin >> coches[i].precio;
    }

    cout << endl << "LISTA DE PERSONAS" << endl;

    for (int i = 0; i < 3; i++) {
        cout << personas[i].nombre << " "
             << personas[i].apellido
             << ", edad: " << personas[i].edad << endl;
    }

    cout << endl << "LISTA DE COCHES" << endl;

    for (int i = 0; i < 3; i++) {
        cout << coches[i].marca
             << ", anio: " << coches[i].anio
             << ", precio: " << coches[i].precio << endl;
    }

    return 0;
}
