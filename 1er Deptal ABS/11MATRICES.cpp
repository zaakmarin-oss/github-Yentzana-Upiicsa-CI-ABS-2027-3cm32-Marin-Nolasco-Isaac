#include <iostream>
using namespace std;

class EstadisticasArreglo {
private:
    static const int CANTIDAD = 5;
    double numeros[CANTIDAD]{};

public:
    bool capturar() {
        for (int i = 0; i < CANTIDAD; ++i) {
            cout << "Numero " << i + 1 << ": ";

            if (!(cin >> numeros[i]))
                return false;
        }

        return true;
    }

    double obtenerSuma() const {
        double suma = 0;

        for (int i = 0; i < CANTIDAD; ++i)
            suma += numeros[i];

        return suma;
    }

    double obtenerPromedio() const {
        return obtenerSuma() / CANTIDAD;
    }

    double obtenerMaximo() const {
        double mayor = numeros[0];

        for (int i = 1; i < CANTIDAD; ++i) {
            if (numeros[i] > mayor)
                mayor = numeros[i];
        }

        return mayor;
    }

    double obtenerMinimo() const {
        double menor = numeros[0];

        for (int i = 1; i < CANTIDAD; ++i) {
            if (numeros[i] < menor)
                menor = numeros[i];
        }

        return menor;
    }

    void mostrarResultados() const {
        cout << "\nSuma: " << obtenerSuma() << endl;
        cout << "Promedio: " << obtenerPromedio() << endl;
        cout << "Media aritmetica: " << obtenerPromedio() << endl;
        cout << "Maximo: " << obtenerMaximo() << endl;
        cout << "Minimo: " << obtenerMinimo() << endl;
    }
};

int main() {
    EstadisticasArreglo estadisticas;

    if (!estadisticas.capturar()) {
        cout << "Entrada no valida.\n";
        return 1;
    }

    estadisticas.mostrarResultados();

    return 0;
}
