// Mauro Martinez Montes
// EDA33
// Coste: O(log*n): n = tamaño vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    if (fin - ini <= 1) {
        return v[ini];
    }

    int mid = (fin + ini) / 2;
    if (v[mid] % 2 != 0) return v[mid];
    if (v[mid] != v[0] + (mid * 2)) return resolver(v, ini, mid);
    else return resolver(v, mid, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    if (num == 0)
        return false;

    vector<int> v(num);
    for (int& e : v) cin >> e;

    // escribir sol
    cout << resolver(v, 0, v.size()) << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej10/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
