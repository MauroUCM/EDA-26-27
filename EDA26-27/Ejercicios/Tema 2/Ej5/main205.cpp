// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Aqui la funcion recursiva que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin, bool& isCaus) {
    if (fin - ini <= 1) {   // caso base
        if (datos[ini] % 2 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int mid = (ini + fin) / 2,
        izq = resolver(datos, ini, mid, isCaus),
        dra = resolver(datos, mid, fin, isCaus);

    if (abs(dra - izq) > 2) isCaus = false;

    return izq + dra;
}

// Tratar cada caso
bool resuelveCaso() {
    // Lectura de los datos
    int aux;
    bool isCaus = true;

    cin >> aux;
    if (aux == 0) return false;
    vector<int> v(aux);
    for (int i = 0; i < aux; ++i) {
        cin >> v[i];
    }

    aux = abs(resolver(v, 0, v.size(), isCaus));

    // Escribir los resultados
    if (isCaus) cout << "SI" << '\n';
    else cout << "NO\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej5/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada.

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}