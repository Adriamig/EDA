// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "SetOfInts3.h"

using namespace std;


// función que resuelve el problema
SetOfInts3 resolver(SetOfInts3& v, int num) {
    SetOfInts3 sol;
    for (int i = 0; i < num; i++) {
        sol.add(v.getMin());
        v.removeMin();
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;

    cin >> num;
    if (!std::cin)
        return false;
    SetOfInts3 v;
    int n;
    cin >> n;
    while (n != -1) {
        v.add(n);
        cin >> n;
    }

    SetOfInts3 sol = resolver(v, num);

    cout << sol << "\n";

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