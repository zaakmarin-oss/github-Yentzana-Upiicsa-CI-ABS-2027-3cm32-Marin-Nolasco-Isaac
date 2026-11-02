#include <iostream>
#include <string>
using namespace std;

struct PersonaPE {
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad = 0;
};

struct AutoPE {
    double precio = 0;
    int anio = 0;
};

bool capturar(PersonaPE* p) {
    cout << "Nombre: ";
    getline(cin >> ws, p->nombre);

    cout << "Apellido paterno: ";
    getline(cin, p->apellidoPaterno);

    cout << "Apellido materno: ";
    getline(cin, p->apellidoMaterno);

    cout << "Genero: ";
    getline(cin, p->genero);

    cout << "Edad: ";
    return static_cast<bool>(cin >> p->edad) && p->edad >= 0;
}

bool capturar(AutoPE* a) {
    cout << "Precio y anio: ";
    return static_cast<bool>(cin >> a->precio >> a->anio)
        && a->precio >= 0 && a->anio > 0;
}

void mostrar(const PersonaPE* p) {
    cout << p->nombre << " " << p->apellidoPaterno << " "
         << p->apellidoMaterno << " | " << p->genero
         << " | Edad: " << p->edad << endl;
}

void mostrar(const AutoPE* a) {
    cout << "Precio: " << a->precio
         << " | Anio: " << a->anio << endl;
}

class PersonaPOO {
private:
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad = 0;

public:
    void asignar(const PersonaPE& p) {
        nombre = p.nombre;
        apellidoPaterno = p.apellidoPaterno;
        apellidoMaterno = p.apellidoMaterno;
        genero = p.genero;
        edad = p.edad;
    }

    void mostrar() const {
        cout << nombre << " " << apellidoPaterno << " "
             << apellidoMaterno << " | " << genero
             << " | Edad: " << edad << endl;
    }
};

class AutoPOO {
private:
    double precio = 0;
    int anio = 0;

public:
    void asignar(const AutoPE& a) {
        precio = a.precio;
        anio = a.anio;
    }

    void mostrar() const {
        cout << "Precio: " << precio
             << " | Anio: " << anio << endl;
    }
};

int main() {
    const int CAPACIDAD = 50;

    PersonaPE personasPE[CAPACIDAD];
    AutoPE autosPE[CAPACIDAD];
    PersonaPOO personasPOO[CAPACIDAD];
    AutoPOO autosPOO[CAPACIDAD];

    PersonaPE* pPersonasPE = personasPE;
    AutoPE* pAutosPE = autosPE;
    PersonaPOO* pPersonasPOO = personasPOO;
    AutoPOO* pAutosPOO = autosPOO;

    int cantidadPersonas, cantidadAutos;

    cout << "Cantidad de personas (1 a 50): ";
    if (!(cin >> cantidadPersonas)) return 1;

    cout << "Cantidad de autos (1 a 50): ";
    if (!(cin >> cantidadAutos)) return 1;

    if (cantidadPersonas < 1 || cantidadPersonas > CAPACIDAD ||
        cantidadAutos < 1 || cantidadAutos > CAPACIDAD) {
        cout << "Cantidad no valida.\n";
        return 1;
    }

    for (int i = 0; i < cantidadPersonas; ++i) {
        cout << "\nPersona " << i + 1 << endl;

        if (!capturar(pPersonasPE + i)) return 1;

        (pPersonasPOO + i)->asignar(*(pPersonasPE + i));
    }

    for (int i = 0; i < cantidadAutos; ++i) {
        cout << "\nAuto " << i + 1 << endl;

        if (!capturar(pAutosPE + i)) return 1;

        (pAutosPOO + i)->asignar(*(pAutosPE + i));
    }

    cout << "\nACCESO INDIRECTO EN PE\n";

    for (int i = 0; i < cantidadPersonas; ++i)
        mostrar(pPersonasPE + i);

    for (int i = 0; i < cantidadAutos; ++i)
        mostrar(pAutosPE + i);

    cout << "\nACCESO INDIRECTO EN POO\n";

    for (int i = 0; i < cantidadPersonas; ++i)
        (pPersonasPOO + i)->mostrar();

    for (int i = 0; i < cantidadAutos; ++i)
        (pAutosPOO + i)->mostrar();

    return 0;
}
