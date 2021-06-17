// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const& v, long unsigned int pos) {

    if (pos == v.size()) return true;
    else {
        int maximo = v[0], minimo = v[pos + 1];
        long unsigned int i = 1;
        while (i <= pos) {
            if (v[i] > maximo) maximo = v[i];
            i++;
        }
        i = pos + 2;
        while (i < v.size()) {
            if (v[i] < minimo) minimo = v[i];
            i++;
        }
        if (maximo < minimo) return true;
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int x;

    long unsigned int pos;

    cin >> x >> pos;

    vector<int> v(x);

    for (int& i : v) cin >> i;

    bool sol = resolver(v, pos);

    if (sol)  cout << "SI" << "\n";
    else cout << "NO" << "\n";
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