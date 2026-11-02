#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

vector<string> sierpinski(int nivel) {
    if (nivel == 0) {
        vector<string> figura;
        figura.push_back("*");
        return figura;
    }

    vector<string> anterior = sierpinski(nivel - 1);
    vector<string> figura;
    int ancho = anterior[0].length();
    int espacios = (ancho + 1) / 2;
    int espaciosDerecha = ancho + 1 - espacios;

    for (size_t i = 0; i < anterior.size(); i++) {
        figura.push_back(string(espacios, ' ') +
                         anterior[i] +
                         string(espaciosDerecha, ' '));
    }
    for (size_t i = 0; i < anterior.size(); i++) {
        figura.push_back(anterior[i] + " " + anterior[i]);
    }
    return figura;
}

void cantor(vector<string>& figura, int fila, int columna, int tamano) {
    if (tamano == 1) {
        figura[fila][columna] = '*';
        return;
    }
    int parte = tamano / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 && j != 1) {
                cantor(figura, fila + i * parte, columna + j * parte, parte);
            }
        }
    }
}

bool guardarBMP(const string& archivo, const vector<string>& figura,
                int celda, unsigned char r, unsigned char g, unsigned char b) {
    int filas = figura.size();
    int cols  = figura[0].size();
    int ancho = cols * celda;
    int alto  = filas * celda;

    int relleno = (4 - (ancho * 3) % 4) % 4;      
    int tamImagen = (ancho * 3 + relleno) * alto;
    int tamArchivo = 54 + tamImagen;

    unsigned char cab[54] = {0};
    cab[0] = 'B'; cab[1] = 'M';
    cab[2] = tamArchivo; cab[3] = tamArchivo >> 8;
    cab[4] = tamArchivo >> 16; cab[5] = tamArchivo >> 24;
    cab[10] = 54;
    cab[14] = 40;
    cab[18] = ancho; cab[19] = ancho >> 8; cab[20] = ancho >> 16; cab[21] = ancho >> 24;
    cab[22] = alto;  cab[23] = alto >> 8;  cab[24] = alto >> 16;  cab[25] = alto >> 24;
    cab[26] = 1;
    cab[28] = 24;
    cab[34] = tamImagen; cab[35] = tamImagen >> 8;
    cab[36] = tamImagen >> 16; cab[37] = tamImagen >> 24;

    ofstream out(archivo.c_str(), ios::binary);
    if (!out) return false;
    out.write((char*)cab, 54);

    for (int y = alto - 1; y >= 0; y--) {
        for (int x = 0; x < ancho; x++) {
            bool pintado = figura[y / celda][x / celda] == '*';
            unsigned char px[3];
            if (pintado) { px[0] = b; px[1] = g; px[2] = r; }
            else         { px[0] = px[1] = px[2] = 255; }   
            out.write((char*)px, 3);
        }
        for (int k = 0; k < relleno; k++) out.put(0);
    }
    return true;
}

int main() {
    int nivel;

    cout << "Ingresa el nivel del fractal (1 a 5): ";
    cin >> nivel;

    if (nivel < 1 || nivel > 5) {
        cout << "Nivel no valido." << endl;
        return 0;
    }

    int celdaSier   = 512 / (1 << (nivel + 1));
    if (celdaSier < 4) celdaSier = 4;

    int tamano = 1;
    for (int i = 0; i < nivel; i++) tamano *= 3;
    int celdaCantor = 600 / tamano;
    if (celdaCantor < 4) celdaCantor = 4;

    vector<string> triangulo = sierpinski(nivel);
    if (guardarBMP("sierpinski.bmp", triangulo, celdaSier, 0, 70, 200))
        cout << "Se genero sierpinski.bmp" << endl;

    vector<string> polvo(tamano, string(tamano, ' '));
    cantor(polvo, 0, 0, tamano);
    if (guardarBMP("cantor.bmp", polvo, celdaCantor, 200, 30, 30))
        cout << "Se genero cantor.bmp" << endl;

#if defined(_WIN32)
    system("start sierpinski.bmp");
    system("start cantor.bmp");
#elif defined(__APPLE__)
    system("open sierpinski.bmp");
    system("open cantor.bmp");
#else
    system("xdg-open sierpinski.bmp >/dev/null 2>&1");
    system("xdg-open cantor.bmp >/dev/null 2>&1");
#endif

    return 0;
}