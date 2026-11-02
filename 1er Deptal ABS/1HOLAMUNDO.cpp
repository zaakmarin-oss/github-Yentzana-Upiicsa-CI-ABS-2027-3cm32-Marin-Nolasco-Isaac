#include <iostream>
using namespace std;

class HolaMundo {
public:
    void mostrarMensaje() {
        cout << "Hola mundo" << endl;
    }
};

int main() {
    HolaMundo mensaje;
    mensaje.mostrarMensaje();

    return 0;
}
