// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"

using namespace std;


// función que resuelve el problema
template<class T>
Set<T> resolver(int k) {
    Set<T> sol;
    T n;
    cin >> n;
    int i = 0;
    while (n != -1) {
        if (i < k) {
            sol.add(n);
            i++;
        }
        else if (sol.getMin < n) {
            sol.add(n);
            sol.removeMin();
        }
        cin >> n;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    if (!std::cin)
        return false;
    char c;
    int k;
    cin >> c >> k;

    if (c == 'N') {
        Set<int> v = resolver<int>(k);
        if (!v.isEmpty()) {
            cout << v << "\n";
        }
    }

    else if (c == 'P') {
        Set<string> v = resolver<string>(k);
        if (!v.isEmpty()) {
            cout << v << "\n";
        }
    }

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