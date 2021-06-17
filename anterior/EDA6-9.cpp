// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"


bool resuelve(Arbin<int> arbol) {
    if (arbol.esVacio()) return true;
    else if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) return true;
    else if (arbol.hijoIz().esVacio()) {
        bool der = resuelve(arbol.hijoDr());
        if (arbol.raiz() < arbol.hijoDr().raiz() && der) return true;
        else return false;
    }
    else if (arbol.hijoDr().esVacio()) {
        bool iz = resuelve(arbol.hijoIz());
        if (arbol.raiz() < arbol.hijoIz().raiz() && iz) return true;
        else return false;
    }
    else {
        bool der = resuelve(arbol.hijoDr());
        bool iz = resuelve(arbol.hijoIz());

        if (der && iz && arbol.raiz() > arbol.hijoIz().raiz() && arbol.raiz() > arbol.hijoDr().raiz() && arbol.hijoIz().raiz() < arbol.hijoDr().raiz()) return true;
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<int> arbol = Arbin<int>().leerArbol(-1);

    if (resuelve(arbol)) cout << "SI\n";
    else cout << "NO\n";
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