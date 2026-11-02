#include <iostream>
using namespace std;

class Promedio {
private:
    double numeros[5];
    double suma = 0;
    double maximo, minimo;

public:
    void ingresarNumeros() {
        double *p = numeros;

        for (int i = 0; i < 5; i++) {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> *(p + i);

            suma += *(p + i);

            if (i == 0) {
                maximo = *(p + i);
                minimo = *(p + i);
            } else {
                if (*(p + i) > maximo)
                    maximo = *(p + i);

                if (*(p + i) < minimo)
                    minimo = *(p + i);
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
    Promedio datos;

    datos.ingresarNumeros();
    datos.mostrarResultados();

    return 0;
}
