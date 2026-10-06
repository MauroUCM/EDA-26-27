// Mauro Martinez Montes
// EDA33
// Coste: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
char resolver(const vector<char>& v, const char& fir, const char& las, int ini, int fin) {
    if (fin - ini <= 1) {
        return v[ini] + 1;
    }

    return v[ini] + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char first, last;
    
    cin >> first >> last;
    vector<char> v(last - first);
    for (char& e : v) cin >> e;
    
    // escribir sol
    cout << resolver(v, first, last, 0, v.size()) << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej11/1.in");
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