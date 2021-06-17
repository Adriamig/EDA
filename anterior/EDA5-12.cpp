// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    // leer los datos de la entrada
    List<int> l;
    int n, eliminado;
    cin >> n;
    while (n != -1) {
        l.push_back(n);
        cin >> n;
    }
    cin >> eliminado;
    if (!l.empty()) {

        for (List<int>::Iterator it = l.begin(); it != l.end(); ++it) {
            cout << it.elem();
            cout << " ";
        }
        cout << "\n";
        List<int>::Iterator it = l.begin();
        while (it != l.end()) {
            if (it.elem() == eliminado) it = l.erase(it);
            ++it;
        }
        // escribir sol
        for (List<int>::Iterator it = l.begin(); it != l.end(); ++it) {
            cout << it.elem();
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}