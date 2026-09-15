// Mauro Martinez Montes
// EDA33
// Coste: lineal O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos, int& pos) {
    int izqMax = datos[0];

    for (int c = 0; c < datos.size(); c++) {
        if (c <= pos) {
            if (izqMax < datos[c]) 
                izqMax = datos[c];
        }
        else if (datos[c] <= izqMax) 
            return false;
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int pos, siz, aux;

    cin >> siz >> pos;
    for (int i = 0; i < siz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (resolver(datos, pos)) cout << "SI\n";
    else cout << "NO\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej3/1.in");
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