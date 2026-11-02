#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int multiplicar(int a, int b) {
    if (b == 0) {
        return 0;
    }

    if (b < 0) {
        return -multiplicar(a, -b);
    }

    return a + multiplicar(a, b - 1);
}

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    }

    if (exponente < 0) {
        return 0;
    }

    return base * potencia(base, exponente - 1);
}

int dividirEntero(int a, int b) {
    if (b == 0) {
        return 0;
    }

    if (a < b) {
        return 0;
    }

    return 1 + dividirEntero(a - b, b);
}

int main() {
    int n, a, b;

    cout << "Ingresa un numero para factorial y Fibonacci: ";
    cin >> n;

    if (n < 0) {
        cout << "Usa un numero mayor o igual a cero." << endl;
    } else {
        cout << "Factorial: " << factorial(n) << endl;
        cout << "Fibonacci: " << fibonacci(n) << endl;
    }

    cout << endl << "Ingresa dos numeros positivos: ";
    cin >> a >> b;

    cout << "Multiplicacion por sumas sucesivas: "
         << multiplicar(a, b) << endl;

    cout << "Potencia (primer numero elevado al segundo): "
         << potencia(a, b) << endl;

    if (a >= 0 && b > 0) {
        cout << "Division entera por restas sucesivas: "
             << dividirEntero(a, b) << endl;
    } else {
        cout << "Para division, usa numeros no negativos "
             << "y divisor mayor que cero." << endl;
    }

    return 0;
}
