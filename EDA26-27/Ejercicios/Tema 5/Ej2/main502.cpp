// Mauro Martinez Montes
// EDA33
// Coste: O(n), siendo n el número de elementos de la cola

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>

using namespace std;

// función que resuelve el problema
void resolver(const int& siz, deque<int>& sol) {
    int aux;

    for (int i = 0; i < siz; i++) {
        cin >> aux;
        if (aux >= 0) sol.push_back(aux);
        else sol.push_front(aux);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int siz;
    cin >> siz;

    if (siz == 0)
        return false;

    deque<int> sol;
    resolver(siz, sol);

    // escribir sol
    for (int a : sol) cout << a << " ";
    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 5/Ej2/1.in");
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
