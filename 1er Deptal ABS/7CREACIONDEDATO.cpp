#include <iostream>
#include <string>
using namespace std;

struct Auto {
    string precio;
    int anio;
};

struct Persona {
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
};

int main() {
    Auto auto1;
    Persona persona1;

    cout << "Datos del auto" << endl;
    cout << "Precio: ";
    cin >> auto1.precio;

    cout << "Anio: ";
    cin >> auto1.anio;

    cout << endl << "Datos de la persona" << endl;

    cout << "Nombre: ";
    cin >> persona1.nombre;

    cout << "Apellido paterno: ";
    cin >> persona1.apellidoPaterno;

    cout << "Apellido materno: ";
    cin >> persona1.apellidoMaterno;

    cout << "Genero: ";
    cin >> persona1.genero;

    cout << "Edad: ";
    cin >> persona1.edad;

    cout << endl << "Auto: " << auto1.precio
         << ", anio " << auto1.anio << endl;

    cout << "Persona: " << persona1.nombre << " "
         << persona1.apellidoPaterno << " "
         << persona1.apellidoMaterno << endl;

    cout << "Genero: " << persona1.genero
         << ", edad: " << persona1.edad << endl;

    return 0;
}
