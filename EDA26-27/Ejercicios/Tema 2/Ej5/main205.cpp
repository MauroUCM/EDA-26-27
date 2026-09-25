// Mauro Martinez Montes
// EDA33
// Coste: 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Aqui la funcion recursiva que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin) {
    if (fin - ini <= 1) {
        if (datos[ini] % 2 == 0) {
            return 1;
        }
        else return -1;
    }

    int mid = (fin + ini) / 2,
        totDiff = resolver(datos, ini, mid) + resolver(datos, mid, fin);

    return totDiff;
}

// Tratar cada caso
bool resuelveCaso() {
    // Lectura de los datos
    int num;
    cin >> num;
    if (num == 0) return false;
    vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        cin >> v[i];
    }

    // Escribir los resultados
    int diff = resolver(v, 0, v.size());
    if (abs(diff) <= 2) cout << "SI" << '\n';
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