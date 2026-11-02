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
        return a / b;
    }
};

int main() {
    Calculadora calculadora;
    int opcion;
    double a, b;

    do {
        cout << "\n1. Sumar\n2. Restar\n3. Multiplicar"
             << "\n4. Dividir\n0. Salir\nOpcion: ";

        if (!(cin >> opcion)) return 1;
        if (opcion == 0) break;

        if (opcion < 1 || opcion > 4) {
            cout << "Opcion no valida.\n";
            continue;
        }

        cout << "Ingresa dos numeros: ";
        if (!(cin >> a >> b)) return 1;

        switch (opcion) {
        case 1:
            cout << "Resultado: " << calculadora.sumar(a, b);
            break;
        case 2:
            cout << "Resultado: " << calculadora.restar(a, b);
            break;
        case 3:
            cout << "Resultado: " << calculadora.multiplicar(a, b);
            break;
        case 4:
            if (b == 0)
                cout << "No se puede dividir entre cero.";
            else
                cout << "Resultado: " << calculadora.dividir(a, b);
            break;
        }

        cout << endl;
    } while (opcion != 0);

    return 0;
}
