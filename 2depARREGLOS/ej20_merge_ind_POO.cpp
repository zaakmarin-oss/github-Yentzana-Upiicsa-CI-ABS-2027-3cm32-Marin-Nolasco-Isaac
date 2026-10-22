// Practica 20 - 2do Departamental - merge ind - PROGRAMACION ORIENTADA A OBJETOS (POO)
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

// ---- Nuevo tipo de dato (POO): clase Auto con precio y anio ----
class Auto {
private:
    double precio;
    int anio;
public:
    Auto(double precio = 0, int anio = 0) : precio(precio), anio(anio) {}
    double getPrecio() const { return precio; }
    int getAnio() const { return anio; }

    // Criterio de orden: primero por precio, si empatan, por anio
    bool operator<(const Auto& otro) const {
        if (precio != otro.precio) return precio < otro.precio;
        return anio < otro.anio;
    }
    friend ostream& operator<<(ostream& o, const Auto& a) {
        return o << "[$" << fixed << setprecision(2) << a.precio << ", " << a.anio << "]";
    }
};

// ---- Clase Dato: caracteres, letras o numeros de CUALQUIER longitud ----
class Dato {
private:
    string txt;
    static bool esNumero(const string& s) {
        size_t i = 0;
        if (s.size() > 1 && (s[0] == '-' || s[0] == '+')) i = 1;
        if (i >= s.size()) return false;
        for (; i < s.size(); i++)
            if (!isdigit((unsigned char)s[i])) return false;
        return true;
    }
    // Compara dos numeros escritos como texto (soporta negativos): -1, 0, 1
    static int compararNumeros(string a, string b) {
        bool na = (a[0] == '-'), nb = (b[0] == '-');
        if (a[0] == '-' || a[0] == '+') a = a.substr(1);
        if (b[0] == '-' || b[0] == '+') b = b.substr(1);
        a.erase(0, min(a.find_first_not_of('0'), a.size() - 1));
        b.erase(0, min(b.find_first_not_of('0'), b.size() - 1));
        if (a == "0") na = false;
        if (b == "0") nb = false;
        if (na != nb) return na ? -1 : 1;
        int r;
        if (a.size() != b.size()) r = (a.size() < b.size()) ? -1 : 1;
        else r = (a < b) ? -1 : (a == b ? 0 : 1);
        return na ? -r : r;
    }
public:
    Dato(const string& t = "") : txt(t) {}
    string getTexto() const { return txt; }
    // Orden: primero los numeros (por valor), despues el texto (por ASCII)
    bool operator<(const Dato& otro) const {
        bool na = esNumero(txt), nb = esNumero(otro.txt);
        if (na && nb) return compararNumeros(txt, otro.txt) < 0;
        if (na != nb) return na;
        return txt < otro.txt;
    }
    friend ostream& operator<<(ostream& o, const Dato& d) { return o << d.txt; }
};

// ---- Clase para capturar datos por teclado ----
class Captura {
public:
    static int leerEntero() {
        int x;
        while (!(cin >> x)) {
            if (cin.eof()) exit(0);
        cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor invalido, intente de nuevo: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return x;
    }
    static double leerReal() {
        double x;
        while (!(cin >> x)) {
            if (cin.eof()) exit(0);
        cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor invalido, intente de nuevo: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return x;
    }
    static void leer(Dato& d, int i) {         // acepta numeros de varios digitos
        string linea;
        while (true) {
            cout << "Dato " << i + 1 << ": ";
            if (!getline(cin, linea)) exit(0);
            size_t ini = linea.find_first_not_of(" \t");
            size_t fin = linea.find_last_not_of(" \t");
            if (ini != string::npos) { d = Dato(linea.substr(ini, fin - ini + 1)); return; }
            cout << "Escribe al menos un caracter.\n";
        }
    }
    static void leer(int& x, int i) {         // acepta negativos
        cout << "Entero " << i + 1 << ": ";
        x = leerEntero();
    }
    static void leer(Auto& a, int i) {
        cout << "Auto " << i + 1 << "\n  Precio: ";
        double precio = leerReal();
        cout << "  Anio: ";
        int anio = leerEntero();
        a = Auto(precio, anio);
    }
};

// Clase de merge sort indirecto: se ordenan los PUNTEROS, no los datos
template<typename T>
class MergeSortIndirecto {
private:
    static void mezclar(T* p[], T* aux[], int ini, int med, int fin) {
        int i = ini, j = med + 1, k = ini;
        while (i <= med && j <= fin) {
            if (*p[j] < *p[i]) aux[k++] = p[j++];
            else               aux[k++] = p[i++];
        }
        while (i <= med) aux[k++] = p[i++];
        while (j <= fin) aux[k++] = p[j++];
        for (k = ini; k <= fin; k++) p[k] = aux[k];
    }
    static void rec(T* p[], T* aux[], int ini, int fin) {
        if (ini >= fin) return;
        int med = (ini + fin) / 2;
        rec(p, aux, ini, med);
        rec(p, aux, med + 1, fin);
        mezclar(p, aux, ini, med, fin);
    }
public:
    static void ordenar(T* p[], int n) {
        T** aux = new T*[n];
        rec(p, aux, 0, n - 1);
        delete[] aux;
    }
};

template<typename T>
class Prueba {
public:
    static void imprimir(const string& t, T a[], int n) {
        cout << t;
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    static void imprimirInd(const string& t, T* p[], int n) {
        cout << t;
        for (int i = 0; i < n; i++) cout << *p[i] << " ";
        cout << "\n";
    }
    static void ejecutar(const string& nombre, T datos[], int n) {
        cout << "=== " << nombre << " ===\n";
        T** p = new T*[n];                   // arreglo de punteros
        for (int i = 0; i < n; i++) p[i] = &datos[i];
        imprimir("Original (antes):          ", datos, n);
        MergeSortIndirecto<T>::ordenar(p, n);
        imprimirInd("Ordenado (via punteros):    ", p, n);
        imprimir("Original (sin modificar):  ", datos, n);
        delete[] p;
        cout << "\n";
    }
    static void procesar(const string& nombre) {
        cout << "\n--- " << nombre << " ---\n";
        int n;
        do {
            cout << "Cantidad de elementos (>= 1): ";
            n = Captura::leerEntero();
        } while (n < 1);
        T* datos = new T[n];
        for (int i = 0; i < n; i++) Captura::leer(datos[i], i);
        cout << "\n";
        ejecutar(nombre, datos, n);
        delete[] datos;
    }
};

int main() {
    int op;
    do {
        cout << "===== MENU =====\n"
             << "1. Ordenar caracteres o numeros (cualquier longitud)\n"
             << "2. Ordenar enteros (acepta negativos)\n"
             << "3. Ordenar autos (por precio y anio)\n"
             << "0. Salir\n"
             << "Opcion: ";
        op = Captura::leerEntero();
        switch (op) {
            case 1: Prueba<Dato>::procesar("Caracteres / numeros"); break;
            case 2: Prueba<int>::procesar("Enteros"); break;
            case 3: Prueba<Auto>::procesar("Autos"); break;
            case 0: cout << "Fin del programa.\n"; break;
            default: cout << "Opcion invalida.\n\n";
        }
    } while (op != 0);
    return 0;
}
