#include <iostream>
using namespace std;

class Estadisticas {
private:
    double suma = 0;
    double maximo, minimo;

public:
    void calcular() {
        double numero;

        for (int i = 1; i <= 5; i++) {
            cout << "Ingresa el numero " << i << ": ";
            cin >> numero;

            suma += numero;

            if (i == 1) {
                maximo = numero;
                minimo = numero;
            } else {
                if (numero > maximo)
                    maximo = numero;

                if (numero < minimo)
                    minimo = numero;
            }
        }
    }

    void mostrarResultados() {
        cout << "Suma: " << suma << endl;
        cout << "Promedio o media: " << suma / 5 << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {
    Estadisticas datos;

    datos.calcular();
    datos.mostrarResultados();

    return 0;
}
