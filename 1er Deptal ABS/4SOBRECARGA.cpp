#include <iostream>
#include <stdexcept>
using namespace std;

class Calculadora {
private:
    double primero, segundo;

public:
    Calculadora(double a, double b) : primero(a), segundo(b) {}

    double sumar() {
        return sumar(primero, segundo);
    }

    double sumar(double a, double b) {
        return a + b;
    }

    double sumar(double a, double b, double c) {
        return a + b + c;
    }

    double restar() {
        return restar(primero, segundo);
    }

    double restar(double a, double b) {
        return a - b;
    }

    double restar(double a, double b, double c) {
        return a - b - c;
    }

    double multiplicar() {
        return multiplicar(primero, segundo);
    }

    double multiplicar(double a, double b) {
        return a * b;
    }

    double multiplicar(double a, double b, double c) {
        return a * b * c;
    }

    double dividir() {
        return dividir(primero, segundo);
    }

    double dividir(double a, double b) {
        if (b == 0)
            throw invalid_argument("Division entre cero.");

        return a / b;
    }

    double dividir(double a, double b, double c) {
        if (b == 0 || c == 0)
            throw invalid_argument("Division entre cero.");

        return (a / b) / c;
    }
};

int main() {
    double a, b, c;

    cout << "Ingresa tres numeros: ";
    if (!(cin >> a >> b >> c)) return 1;

    Calculadora calculadora(a, b);

    cout << "\nSUMA\n";
    cout << "0 parametros: " << calculadora.sumar() << endl;
    cout << "2 parametros: " << calculadora.sumar(a, b) << endl;
    cout << "3 parametros: " << calculadora.sumar(a, b, c) << endl;

    cout << "\nRESTA\n";
    cout << "0 parametros: " << calculadora.restar() << endl;
    cout << "2 parametros: " << calculadora.restar(a, b) << endl;
    cout << "3 parametros: " << calculadora.restar(a, b, c) << endl;

    cout << "\nMULTIPLICACION\n";
    cout << "0 parametros: " << calculadora.multiplicar() << endl;
    cout << "2 parametros: " << calculadora.multiplicar(a, b) << endl;
    cout << "3 parametros: " << calculadora.multiplicar(a, b, c) << endl;

    cout << "\nDIVISION\n";

    try {
        cout << "0 parametros: " << calculadora.dividir() << endl;
        cout << "2 parametros: " << calculadora.dividir(a, b) << endl;
        cout << "3 parametros: " << calculadora.dividir(a, b, c) << endl;
    }
    catch (const invalid_argument& error) {
        cout << error.what() << endl;
    }

    return 0;
}
