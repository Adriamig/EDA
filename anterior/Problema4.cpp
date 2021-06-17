// Adrián Migueles D'Ambrosio
// VJ37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int>& resolver(vector<int> const& v1, vector<int> const& v2) {
    
    vector<int> sol(v1.size());

    for (long unsigned int i = 0; i < v1.size(); i++) {
        sol[i] = v1[i];
    }
    long unsigned int i = 0;
    while (i < v2.size()) {
        long unsigned int j = 0;
        bool dentro = false;
        while (j < sol.size() && !dentro) {
            if (v2[i] == sol[j]) dentro = true;
            j++;
        }
        if (!dentro) {
            vector<int> copia = sol;
            sol.resize(sol.size() + 1);
            for (long unsigned int x = 0; x < sol.size(); x++) {

            }
        }
        i++;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int x1, x2;

    cin >> x1 >> x2;

    vector<int> v1(x1);

    vector<int> v2(x2);

    for (int& i : v1) cin >> i;

    for (int& i : v2) cin >> i;

    vector<int> sol = resolver(v1, v2);

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
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