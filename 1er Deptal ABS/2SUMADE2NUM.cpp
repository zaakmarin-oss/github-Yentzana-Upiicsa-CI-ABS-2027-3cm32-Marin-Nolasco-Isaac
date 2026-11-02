#include <iostream>
using namespace std;

class Suma {
public:
    int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    int num1, num2;

    cout << "Ingresa el primer numero: ";
    cin >> num1;

    cout << "Ingresa el segundo numero: ";
    cin >> num2;

    Suma operacion;

    cout << "La suma es: "
         << operacion.sumar(num1, num2) << endl;

    return 0;
}
