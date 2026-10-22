// Practica 18 - 2do Departamental - quick - PROGRAMACION ESTRUCTURADA (PE)
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

// ---- Nuevo tipo de dato (Programacion Estructurada): auto con precio y anio ----
struct Auto {
    double precio;
    int anio;
};

// Criterio de orden: primero por precio, si empatan, por anio
bool operator<(const Auto& a, const Auto& b) {
    if (a.precio != b.precio) return a.precio < b.precio;
    return a.anio < b.anio;
}

ostream& operator<<(ostream& o, const Auto& a) {
    return o << "[$" << fixed << setprecision(2) << a.precio << ", " << a.anio << "]";
}

// ---- Dato de texto: caracteres, letras o numeros de CUALQUIER longitud ----
struct Dato {
    string txt;
};

bool esNumero(const string& s) {
    size_t i = 0;
    if (s.size() > 1 && (s[0] == '-' || s[0] == '+')) i = 1;
    if (i >= s.size()) return false;
    for (; i < s.size(); i++)
        if (!isdigit((unsigned char)s[i])) return false;
    return true;
}

// Compara dos numeros escritos como texto (soporta negativos): -1, 0, 1
int compararNumeros(string a, string b) {
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

// Orden: primero los numeros (por valor), despues el texto (por ASCII)
bool operator<(const Dato& a, const Dato& b) {
    bool na = esNumero(a.txt), nb = esNumero(b.txt);
    if (na && nb) return compararNumeros(a.txt, b.txt) < 0;
    if (na != nb) return na;
    return a.txt < b.txt;
}

ostream& operator<<(ostream& o, const Dato& d) { return o << d.txt; }

// ---- Captura de datos por teclado ----
int leerEntero() {
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

double leerReal() {
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

void leerDato(Dato& d, int i) {            // acepta numeros de varios digitos
    string linea;
    while (true) {
        cout << "Dato " << i + 1 << ": ";
        if (!getline(cin, linea)) exit(0);
        size_t ini = linea.find_first_not_of(" \t");
        size_t fin = linea.find_last_not_of(" \t");
        if (ini != string::npos) { d.txt = linea.substr(ini, fin - ini + 1); return; }
        cout << "Escribe al menos un caracter.\n";
    }
}

void leerDato(int& x, int i) {              // acepta negativos
    cout << "Entero " << i + 1 << ": ";
    x = leerEntero();
}

void leerDato(Auto& a, int i) {
    cout << "Auto " << i + 1 << "\n  Precio: ";
    a.precio = leerReal();
    cout << "  Anio: ";
    a.anio = leerEntero();
}

// Quick sort (directo)
template<typename T>
int particion(T a[], int ini, int fin) {
    int med = (ini + fin) / 2;
    T t = a[med]; a[med] = a[fin]; a[fin] = t;   // pivote al final
    T pivote = a[fin];
    int i = ini - 1;
    for (int j = ini; j < fin; j++) {
        if (a[j] < pivote) {
            i++;
            T x = a[i]; a[i] = a[j]; a[j] = x;
        }
    }
    T x = a[i + 1]; a[i + 1] = a[fin]; a[fin] = x;
    return i + 1;
}

template<typename T>
void quickRec(T a[], int ini, int fin) {
    if (ini < fin) {
        int p = particion(a, ini, fin);
        quickRec(a, ini, p - 1);
        quickRec(a, p + 1, fin);
    }
}

template<typename T>
void quickSort(T a[], int n) { quickRec(a, 0, n - 1); }

template<typename T>
void imprimir(const string& t, T a[], int n) {
    cout << t;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

template<typename T>
void probar(const string& nombre, T datos[], int n) {
    cout << "=== " << nombre << " ===\n";
    imprimir("Antes:   ", datos, n);
    quickSort(datos, n);
    imprimir("Despues: ", datos, n);
    cout << "\n";
}

template<typename T>
void procesar(const string& nombre) {
    cout << "\n--- " << nombre << " ---\n";
    int n;
    do {
        cout << "Cantidad de elementos (>= 1): ";
        n = leerEntero();
    } while (n < 1);
    T* datos = new T[n];
    for (int i = 0; i < n; i++) leerDato(datos[i], i);
    cout << "\n";
    probar(nombre, datos, n);
    delete[] datos;
}

int main() {
    int op;
    do {
        cout << "===== MENU =====\n"
             << "1. Ordenar caracteres o numeros (cualquier longitud)\n"
             << "2. Ordenar enteros (acepta negativos)\n"
             << "3. Ordenar autos (por precio y anio)\n"
             << "0. Salir\n"
             << "Opcion: ";
        op = leerEntero();
        switch (op) {
            case 1: procesar<Dato>("Caracteres / numeros"); break;
            case 2: procesar<int>("Enteros"); break;
            case 3: procesar<Auto>("Autos"); break;
            case 0: cout << "Fin del programa.\n"; break;
            default: cout << "Opcion invalida.\n\n";
        }
    } while (op != 0);
    return 0;
}
