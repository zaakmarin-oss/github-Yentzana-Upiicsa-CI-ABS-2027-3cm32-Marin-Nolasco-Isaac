#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// PROGRAMACION ESTRUCTURADA

struct AutoPE {
    double precio;
    int anio;
};

struct PersonaPE {
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
};

void capturar(AutoPE& autoMovil) {
    cout << "Precio del auto: ";
    if (!(cin >> autoMovil.precio) || autoMovil.precio < 0)
        throw invalid_argument("Precio no valido.");

    cout << "Anio del auto: ";
    if (!(cin >> autoMovil.anio) || autoMovil.anio <= 0)
        throw invalid_argument("Anio no valido.");
}

void capturar(PersonaPE& persona) {
    cout << "Nombre: ";
    getline(cin >> ws, persona.nombre);

    cout << "Apellido paterno: ";
    getline(cin, persona.apellidoPaterno);

    cout << "Apellido materno: ";
    getline(cin, persona.apellidoMaterno);

    cout << "Genero: ";
    getline(cin, persona.genero);

    cout << "Edad: ";
    if (!(cin >> persona.edad) || persona.edad < 0)
        throw invalid_argument("Edad no valida.");
}

void mostrar(const AutoPE& autoMovil) {
    cout << "Precio: " << autoMovil.precio
         << " | Anio: " << autoMovil.anio << endl;
}

void mostrar(const PersonaPE& persona) {
    cout << persona.nombre << " "
         << persona.apellidoPaterno << " "
         << persona.apellidoMaterno
         << " | Genero: " << persona.genero
         << " | Edad: " << persona.edad << endl;
}

// PROGRAMACION ORIENTADA A OBJETOS

class AutoPOO {
private:
    double precio;
    int anio;

public:
    AutoPOO(double p, int a) : precio(p), anio(a) {}

    void mostrar() const {
        cout << "Precio: " << precio
             << " | Anio: " << anio << endl;
    }
};

class PersonaPOO {
private:
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad;

public:
    PersonaPOO(const PersonaPE& p)
        : nombre(p.nombre),
          apellidoPaterno(p.apellidoPaterno),
          apellidoMaterno(p.apellidoMaterno),
          genero(p.genero),
          edad(p.edad) {}

    void mostrar() const {
        cout << nombre << " " << apellidoPaterno
             << " " << apellidoMaterno
             << " | Genero: " << genero
             << " | Edad: " << edad << endl;
    }
};

int main() {
    AutoPE autoPE{};
    PersonaPE personaPE{};

    try {
        cout << "DATOS DEL AUTO\n";
        capturar(autoPE);

        cout << "\nDATOS DE LA PERSONA\n";
        capturar(personaPE);

        AutoPOO autoPOO(autoPE.precio, autoPE.anio);
        PersonaPOO personaPOO(personaPE);

        cout << "\nVERSION PE\n";
        mostrar(autoPE);
        mostrar(personaPE);

        cout << "\nVERSION POO\n";
        autoPOO.mostrar();
        personaPOO.mostrar();
    }
    catch (const invalid_argument& error) {
        cout << error.what() << endl;
        return 1;
    }

    return 0;
}
