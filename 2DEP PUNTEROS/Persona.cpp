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
        if (is && p.edad < 0) is.setstate(std::ios::failbit);   
        return is;
    }
};

inline void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline bool leerEntero(int& x) {
    while (!(std::cin >> x)) {
        if (std::cin.eof()) return false;
        std::cout << "Entrada invalida, escriba un numero: ";
        limpiarEntrada();
    }
    return true;
}

inline bool leerPersona(Persona& p) {
    while (!(std::cin >> p)) {
        if (std::cin.eof()) return false;
        std::cout << "Datos invalidos (5 campos sin espacios internos; edad numerica >= 0).\n"
                     "Intente de nuevo: ";
        limpiarEntrada();
    }
    return true;
}


