// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, const int ini, const int fin) {

	const int n = fin - ini;
	if (n == 0) {
		return v[fin] + 1;
	}
	else if (n == 1) {
		return (v[ini] + 1 == v[fin]) ? v[fin] + 1 : v[ini] + 1;
	}
	else {
		const int mit = (fin + ini) / 2;
		if (v[ini] + n / 2 < v[mit])
			return resolver(v, ini, mit);
		else if (v[ini] + n / 2 > v[mit])
			return resolver(v, mit, fin);
		else {
			int menor = resolver(v, ini, mit);
			int mayor = resolver(v, mit, fin);
			return (menor < v[mit]) ? menor : mayor;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numV;
	std::cin >> numV;
	vector<int> v;
	for (int i = 0; i < numV; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (!v.empty()) {
		int sol = resolver(v, 0, numV - 1);
		// escribir sol

		cout << sol << endl;
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