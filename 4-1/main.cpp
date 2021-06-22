// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"

using namespace std;

// función que resuelve el problema
int resolver(vector<Horas> v, const int size, Horas h) {
	int pos = -1; int i = 0;
	while (i < size && pos == -1) {
		if (h <= v[i]) pos = i;
		i++;
	}
	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nV, mV;

	cin >> nV >> mV;

	vector<Horas> vT;
	for (int i = 0; i < nV; i++) {
		Horas h;
		cin >> h;
		vT.push_back(h);
	}

	vector<Horas> vC;
	for (int i = 0; i < mV; i++) {
		Horas h;
		cin >> h;
		vC.push_back(h);
	}

	if (!std::cin)
		return false;

	if (!vT.empty() && !vC.empty()) {
		// escribir sol
		for (int i = 0; i < mV; i++) {
			if (vC[i].horaValida()) {
				int sol = resolver(vT, nV, vC[i]);
				if (sol == -1) cout << "NO" << endl;
				else cout << vT[sol] << endl;
			}
			else
				cout << "ERROR" << endl;
		}

		cout << "---" << endl;
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