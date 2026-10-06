// Mauro Martinez Montes
// EDA33
// Coste: O(log(n)): n = tamaño del vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    if (fin - ini <= 1) return ini;

    int mid = (ini + fin) / 2;
    if (v[mid] == v[mid + 1]) {
        return resolver(v, ini, mid);
    }
    else if (v[mid] != v[mid - 1]) {
        return mid;
    }
    else {
        return resolver(v, mid, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& e : v) cin >> e;

    // Mostrar el resultado
    cout << resolver(v, 0, v.size()) << "\n";
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej13/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}