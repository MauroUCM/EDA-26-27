// Mauro Martinez Montes
// EDA33
// Coste: O(log(n)): n = tamaño del vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, const int& prim, int ini, int fin) {
    if (fin - ini == 1) {
        return v[ini];
    }

    int mid = (fin + ini) / 2;
    if (v[mid] != prim + mid) return resolver(v, prim, ini, mid);
    else return resolver(v, prim, mid, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    vector<int> v(num);
    for (int& e : v) cin >> e;

    // escribir sol
    cout << resolver(v, v[0], 0, v.size()) << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej14/1.in");
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