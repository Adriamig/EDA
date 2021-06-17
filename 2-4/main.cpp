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
	if (n == 0)
		return v[ini];
	else if (n == 1)
		return (v[ini] % 2 == 1) ? v[ini] : v[fin];
	else {
		const int mit = (fin + ini) / 2;
		if (v[mit] == v[ini] + (n/2) * 2)
			return resolver(v, mit, fin);
		else
			return resolver(v, ini, mit);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	vector<int> v;

	int numV;
	cin >> numV;
	for (int i = 0; i < numV; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (!std::cin)
		return false;

	if (!v.empty()) {

		int sol = resolver(v, 0, numV - 1);

		// escribir sol

		cout << sol << endl;
	}
	else
		cout << endl;

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