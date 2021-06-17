// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;
// función que resuelve el problema
/*Queue<int> resolver(Queue<int> colegas, int pringado) {
    Queue<int> q;
    bool encontrado = false;
    while (!colegas.empty()) {
        if (!encontrado && colegas.front() == pringado) {
            q.push_back(pringado);
            colegas.pop_front();
            int i;
            cin >> i;
            while (i != -1) {
                q.push_back(i);
                cin >> i;
            }
            encontrado = true;
        }
        else {
            q.push_back(colegas.front());
            colegas.pop_front();
        }
    }
    if (!encontrado) {
        int i;
        cin >> i;
        while (i != -1) {
            cin >> i;
        }
    }
    return q;
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int i, pringado;
    cin >> i;
    Queue<int> cola;
    while (i != -1)
    {
        cola.push_back(i);
        cin >> i;
    }
    cin >> pringado;
    Queue<int> colegas;
    cin >> i;
    while (i != -1)
    {
        colegas.push_back(i);
        cin >> i;
    }
    cout << cola << "\n";
    cola.resolver(colegas, pringado);
    cout << cola << "\n";
    // escribir sol
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