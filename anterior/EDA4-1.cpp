// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "horas.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, const horas& h) {
    if (h.getHora() < 10) out << "0";
    out << h.getHora() << ":";
    if (h.getMin() < 10) out << "0";
    out << h.getMin() << ":";
    if (h.getSeg() < 10) out << "0";
    out << h.getSeg();
    return out;
}

std::istream& operator>>(std::istream& in, horas& h) {
    int hor, m, s;
    char c;
    in >> hor >> c >> m >> c >> s;
    h = horas(hor, m, s);
    return in;
}

// función que resuelve el problema
horas resolver(const vector<horas> v, const horas h, int prin, int fin) {
    if (fin - prin == 1) {
        return v[prin];
    }
    else if (fin - prin == 2) {
        if (v[prin] < h) return v[prin + 1];
        else return v[prin];
    }
    else {
        int mitad = (prin + fin) / 2;
        if (v[mitad] < h) return resolver(v, h, mitad + 1, fin);
        else if (h < v[mitad - 1]) return resolver(v, h, prin, mitad);
        else return v[mitad];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int horaTrenes;
    int horaConsultar;

    cin >> horaTrenes >> horaConsultar;
    if (!std::cin)
        return false;

    vector<horas> vTrenes(horaTrenes);
    vector<horas> vCons(horaConsultar);

    for (horas& x : vTrenes) cin >> x;
    for (horas& x : vCons) cin >> x;
    for (int i = 0; i < vCons.size(); i++) {
        if (!vCons[i].horaCorrecta()) cout << "ERROR\n";
        else {
            if (vTrenes[vTrenes.size() - 1] < vCons[i])  cout << "NO\n";
            else {
                horas sol = resolver(vTrenes, vCons[i], 0, vTrenes.size());
                cout << sol << "\n";
            }
        }
    }
    
    cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}