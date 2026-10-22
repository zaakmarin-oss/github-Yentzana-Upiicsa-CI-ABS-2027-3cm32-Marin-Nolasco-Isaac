// Persona.hpp - Tipo de dato creado (ejercicio 7): nombre, ap, am, genero, edad
// Incluye tambien funciones de lectura segura para los menus (evitan ciclos
// infinitos cuando el usuario escribe un dato invalido o se acaba la entrada).
#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>
#include <string>
#include <limits>

class Persona {
private:
    std::string nombre, ap, am, genero;
    int edad;
public:
    Persona(const std::string& n = "", const std::string& a = "",
            const std::string& m = "", const std::string& g = "", int e = 0)
        : nombre(n), ap(a), am(m), genero(g), edad(e) {}

    bool operator==(const Persona& o) const {
        return nombre == o.nombre && ap == o.ap && am == o.am &&
               genero == o.genero && edad == o.edad;
    }
    friend std::ostream& operator<<(std::ostream& os, const Persona& p) {
        return os << p.nombre << " " << p.ap << " " << p.am
                  << " | " << p.genero << " | " << p.edad << " anios";
    }
    friend std::istream& operator>>(std::istream& is, Persona& p) {
        is >> p.nombre >> p.ap >> p.am >> p.genero >> p.edad;
        if (is && p.edad < 0) is.setstate(std::ios::failbit);   // edad negativa = invalida
        return is;
    }
};

// Descarta el resto de la linea y deja el flujo listo para volver a leer.
inline void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Lee un entero. Si el usuario escribe algo que no es numero, avisa y repite.
// Devuelve false solo si se acabo la entrada (Ctrl+Z / Ctrl+D).
inline bool leerEntero(int& x) {
    while (!(std::cin >> x)) {
        if (std::cin.eof()) return false;
        std::cout << "Entrada invalida, escriba un numero: ";
        limpiarEntrada();
    }
    return true;
}

// Lee una Persona (Nombre ApPat ApMat Genero Edad). Si hay error, avisa y repite.
// Devuelve false solo si se acabo la entrada.
inline bool leerPersona(Persona& p) {
    while (!(std::cin >> p)) {
        if (std::cin.eof()) return false;
        std::cout << "Datos invalidos (5 campos sin espacios internos; edad numerica >= 0).\n"
                     "Intente de nuevo: ";
        limpiarEntrada();
    }
    return true;
}
#endif
