#include <iostream>
#include <string>
using namespace std;

struct AutoPE {
    double precio;
    int anio;
};

struct PersonaPE {
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad;
};

class AutoPOO {
private:
    double precio;
    int anio;

public:
    AutoPOO() : precio(0), anio(0) {}
};

class PersonaPOO {
private:
    string nombre, apellidoPaterno, apellidoMaterno, genero;
    int edad;

public:
    PersonaPOO() : edad(0) {}
};

int main() {
    cout << "TAMANOS EN BYTES\n\n";

    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;

    cout << "\nTIPOS CREADOS\n";
    cout << "Auto PE: " << sizeof(AutoPE) << endl;
    cout << "Auto POO: " << sizeof(AutoPOO) << endl;
    cout << "Persona PE: " << sizeof(PersonaPE) << endl;
    cout << "Persona POO: " << sizeof(PersonaPOO) << endl;

    cout << "\nOTROS\n";
    cout << "Objeto string: " << sizeof(string) << endl;
    cout << "Puntero a int: " << sizeof(int*) << endl;
    cout << "Puntero a PersonaPOO: " << sizeof(PersonaPOO*) << endl;

    return 0;
}
