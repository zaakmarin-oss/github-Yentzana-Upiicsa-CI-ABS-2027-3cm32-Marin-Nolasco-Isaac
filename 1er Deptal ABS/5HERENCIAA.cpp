#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) {
        return a + b;
    }

    double restar(double a, double b) {
        return a - b;
    }

    double multiplicar(double a, double b) {
        return a * b;
    }

    double dividir(double a, double b) {
        if (b == 0) {
            cout << "No se puede dividir entre cero." << endl;
            return 0;
        }
        return a / b;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    void mostrarMensaje() {
        cout << "CalculadoraNueva: hereda las operaciones de Calculadora." << endl;
    }
};

int main() {
    CalculadoraNueva calc;
    double a, b;

    calc.mostrarMensaje();

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    cout << "Suma: " << calc.sumar(a, b) << endl;
    cout << "Resta: " << calc.restar(a, b) << endl;
    cout << "Multiplicacion: " << calc.multiplicar(a, b) << endl;
    cout << "Division: " << calc.dividir(a, b) << endl;

    return 0;
}
