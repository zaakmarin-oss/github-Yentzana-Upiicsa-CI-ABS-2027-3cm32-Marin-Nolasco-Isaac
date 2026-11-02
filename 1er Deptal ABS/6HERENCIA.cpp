#include <iostream>
#include <stdexcept>
using namespace std;

class Calculadora {
protected:
    long long primero, segundo;

public:
    Calculadora(long long a = 0, long long b = 1)
        : primero(a), segundo(b) {}

    virtual ~Calculadora() = default;

    long long sumar(long long a, long long b) {
        return a + b;
    }

    long long restar(long long a, long long b) {
        return a - b;
    }

    long long multiplicar() {
        return multiplicar(primero, segundo);
    }

    virtual long long multiplicar(long long a, long long b) {
        return a * b;
    }

    long long multiplicar(long long a, long long b, long long c) {
        return multiplicar(multiplicar(a, b), c);
    }

    long long dividir() {
        return dividir(primero, segundo);
    }

    virtual long long dividir(long long a, long long b) {
        if (b == 0)
            throw invalid_argument("Division entre cero.");
        return a / b;
    }

    long long dividir(long long a, long long b, long long c) {
        return dividir(dividir(a, b), c);
    }

    virtual long long potencia(long long base, long long exponente) {
        if (exponente < 0)
            throw invalid_argument("Se requiere exponente no negativo.");

        long long resultado = 1;

        for (long long i = 0; i < exponente; ++i)
            resultado *= base;

        return resultado;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    using Calculadora::Calculadora;
    using Calculadora::multiplicar;
    using Calculadora::dividir;

    long long multiplicar(long long a, long long b) override {
        bool negativo = b < 0;
        if (negativo) b = -b;

        long long resultado = 0;

        for (long long i = 0; i < b; ++i)
            resultado += a;

        return negativo ? -resultado : resultado;
    }

    long long potencia(long long base, long long exponente) override {
        if (exponente < 0)
            throw invalid_argument("Se requiere exponente no negativo.");

        long long resultado = 1;

        for (long long i = 0; i < exponente; ++i)
            resultado = multiplicar(resultado, base);

        return resultado;
    }

    long long dividir(long long a, long long b) override {
        if (b == 0)
            throw invalid_argument("Division entre cero.");

        bool negativo = (a < 0) != (b < 0);

        long long restante = a < 0 ? -a : a;
        long long divisor = b < 0 ? -b : b;
        long long cociente = 0;

        while (restante >= divisor) {
            restante -= divisor;
            ++cociente;
        }

        return negativo ? -cociente : cociente;
    }
};

int main() {
    long long a, b, exponente;

    cout << "Dos enteros entre -100 y 100: ";
    if (!(cin >> a >> b)) return 1;

    cout << "Exponente entre 0 y 9: ";
    if (!(cin >> exponente)) return 1;

    if (a < -100 || a > 100 || b < -100 || b > 100 ||
        exponente < 0 || exponente > 9) {
        cout << "Datos fuera del rango permitido.\n";
        return 1;
    }

    CalculadoraNueva nueva(a, b);
    Calculadora& calculadora = nueva;

    cout << "Suma: " << calculadora.sumar(a, b) << endl;
    cout << "Resta: " << calculadora.restar(a, b) << endl;
    cout << "Multiplicacion por sumas: "
         << calculadora.multiplicar(a, b) << endl;

    cout << "Potencia por multiplicaciones: "
         << calculadora.potencia(a, exponente) << endl;

    try {
        long long cociente = calculadora.dividir(a, b);
        long long residuo = a - calculadora.multiplicar(cociente, b);

        cout << "Cociente por restas: " << cociente << endl;
        cout << "Residuo: " << residuo << endl;
    }
    catch (const invalid_argument& error) {
        cout << error.what() << endl;
    }

    return 0;
}
